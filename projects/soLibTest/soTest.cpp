#include <stdio.h>
#include <iostream>
#include <dlfcn.h>

extern "C" typedef int (*print_value)( int x);

int main(void){
  	void* lib = dlopen("./libhello.so", RTLD_LAZY);
  	print_value hello = (print_value)dlsym( lib, "print_value" );

  	hello(10);
	dlclose(lib);
	//std::cout << (*printVal)(10);
	//dlclose(lib);
	return 0;
}
