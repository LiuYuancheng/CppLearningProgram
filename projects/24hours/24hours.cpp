#include <iostream>

//two way to define a constants:
const int TEST_MD1 = true;
#define TEST_MD2 true; 

enum COLOR {RED, BLUE, GREEN}; // default re
// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

bool isLeapYear(int);
inline int add(int, int);// defined the function as inline if we need to use it several times.


int add(int x, int y)
{
    // add integer x and integer y then return the sum value
    std::cout << "Calculating ... \n";
    return x + y;
}

void section2()
{
    // C++ stand input/output test.
    std::cout << "Section2: sum two int together: \n";
    int x, y;
    std::cout << "Type in the 1st int:";
    std::cin >> x;
    std::cout << "Type in the 2nd int:";
    std::cin >> y;
    std::cout << "Result:\n" << add(x,y) <<"\n";
    std::cout << "========================\n";
}

void section3()
{
    // C++ data type test.
    std::cout << "Section 3 Creating Variable and Constants \n";
    std::cout << " - The size of Integer : \t" << sizeof(int) << "bytes \n";
    std::cout << " - The size of short : \t\t" << sizeof(short) << "bytes \n";
    std::cout << " - The size of long : \t\t" << sizeof(long) << "bytes \n";
    std::cout << " - The size of char : \t\t" << sizeof(char) << "bytes \n";
    std::cout << " - The size of float : \t\t" << sizeof(float) << "bytes \n";
    std::cout << " - The size of double : \t" << sizeof(double) << "bytes \n";
    std::cout << " - The size of long long int : \t" << sizeof(long long int) << "bytes \n";
    // C++ constant
    std::cout << " Constant val 'RED' = \t" << RED <<"\n";
    std::cout << " Constant val 'GREEN' = " << GREEN <<"\n";
    std::cout << " Constant val 'BLUE' = \t" << BLUE <<"\n";
    //
    std::cout << "========================\n";
}

void section4(){
    //
    std::cout << "Section 4 Expression statement and operators \n";
    int x = 5; 
    int sum = ++x; 
    std::cout << "prefix sum = ++x, sum =" << sum << ", x = "<< x <<" \n";
    x = 5;
    sum = x++;
    std::cout << "prefix sum = ++x, sum =" << sum << ", x = "<< x <<" \n";
}

void section5(){
    //
    std::cout << "Section 5 Parameters and Functions\n";
    int year;
    std::cout << "Type in the year int number:";
    std::cin >> year;
    if (isLeapYear(year))
    {
        std::cout << "Year [" << year << " ] is leapyear .\n";
    }
    else
    {
        std::cout << "Year [" << year << " ] is not leapyear .\n";
    }
}

bool isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        if (year % 100 == 0)
        {
            if (year % 400 == 0)
                return true;
            return false;
        }
        return true;
    }
    return false;
}

int main()
{
    section2();
    section3();
    section4();
    section5();
    return 0;
}
