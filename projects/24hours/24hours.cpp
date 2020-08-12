#include <iostream>

//two way to define a constants:
const int TEST_MD1 = true;
#define TEST_MD2 true; 

enum COLOR {RED, BLUE, GREEN}; // default re
// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

int add(int x, int y)
{
    // add integer x and integer y then return the sum value
    std::cout << "Calculating ... \n";
    return x + y;
}

void section3()
{
    std::cout << "Section 3 Creating Variable and Constants \n";
    std::cout << " - The size of Integer : \t" << sizeof(int) << "bytes \n";
    std::cout << " - The size of short : \t\t" << sizeof(short) << "bytes \n";
    std::cout << " - The size of long : \t\t" << sizeof(long) << "bytes \n";
    std::cout << " - The size of char : \t\t" << sizeof(char) << "bytes \n";
    std::cout << " - The size of float : \t\t" << sizeof(float) << "bytes \n";
    std::cout << " - The size of double : \t" << sizeof(double) << "bytes \n";
    std::cout << " - The size of long long int : \t" << sizeof(long long int) << "bytes \n";    
}


int main()
{
    std::cout << "section2: sum two int together: \n";
    std::cout << " 123 + 456 =" << add(123,456) <<"\n";
    section3();
    std::cout << " Constant val 'RED' = \t" << RED <<"\n";
    std::cout << " Constant val 'GREEN' = \t" << GREEN <<"\n";
    std::cout << " Constant val 'BLUE' = \t" << BLUE <<"\n";


    return 0;
}
