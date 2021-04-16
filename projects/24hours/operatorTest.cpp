//-----------------------------------------------------------------------------
// Name:        24hours.hpp
//
// Purpose:     The main program to implement and test all the functions provide 
//              by the C++ book < Sams Teach Your self C++ in 24 hours> .
//              
// Author:      Yuancheng Liu
//
// Created:     2020/08/02
// Copyright:   < Sams Teach Your self C++ in 24 hours>
// License:     N.A
//-----------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <string.h>

int main()
{
    size_t n = 1000;
    char *p = (char*) &n;
    std::string str(p, sizeof(size_t));
    std::cout << "["<< str << "]\n ";
    return 0;
}



