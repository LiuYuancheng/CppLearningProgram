#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

//#include "24string.hpp"
//#include "24linkList.hpp"

#include <openssl/bio.h>

using namespace std;

#include "generic_service/CKeGateWay.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmkcppapp_MainActivity_InitKeyExchange(
        JNIEnv *env,
        jobject /* this */) {
    std::string filename = "etst";
    return env->NewStringUTF(filename.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmkcppapp_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string filename = "QS_Encryption_key";
    return env->NewStringUTF(filename.c_str());
}

void OnShared(string ss, std::string sessionid) {
    static int key_id = 0;
    std::cout << "INFO: Shared secrets: KEY_ID = " << key_id << std::endl;
    //LOG(INFO) << "Shared secretes, KEY_ID = " << key_id;
    //BIO_dump_fp(stdout, ss.data(), ss.length());
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmkcppapp_MainActivity_keyExchangeJNI(
        JNIEnv *env,
        jobject /* this */) {

    std::string keyStr = "biXhp3Ha1fgxVEp48zHrvVoXMStmxPuAPHo3TVz5lHU=";
    // Add the key exchange code here
    //std::string cfgfile("Config.txt"), ipTablefile("IPtable.txt");
    std::string cfgfile("/storage/emulated/0/Download/gw_Alice.cfg"), ipTablefile("/storage/emulated/0/Download/IPTable.cfg");
    //google::InitGoogleLogging(argv[0]);
    //google::InstallFailureSignalHandler();

    //FLAGS_log_dir = "../logs/";

    if (CKeGateWay::Start(cfgfile, ipTablefile, OnShared)){
        //LOG(FATAL) << "Gateway fails to start!";
        return env->NewStringUTF(keyStr.c_str());
    }
    //cout << "Gateway started." << endl;
    //LOG(INFO) << "Gateway started.";
    //pause();
    return env->NewStringUTF(keyStr.c_str());

    //return env->NewStringUTF(keyStr.c_str());
}

std::string ConvertJString(JNIEnv* env, jstring str)
{
    // Convert Jstring to C++ std::string.
    if ( !str ) std::string();
    const jsize len = env->GetStringUTFLength(str);
    const char* strChars = env->GetStringUTFChars(str, (jboolean *)0);
    std::string Result(strChars, len);
    env->ReleaseStringUTFChars(str, strChars);
    return Result;
}

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_cmkcppapp_MainActivity_loadConfigfileJNI(
        JNIEnv *env,
        jobject /* this */,
        jstring filepath) {
    std::string phonefilePath = ConvertJString(env, filepath);

    std::ifstream inFile;
    inFile.open(phonefilePath); //open the input file
    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string data = strStream.str(); //str holds the content of the file

    return env->NewStringUTF(data.c_str());
}

