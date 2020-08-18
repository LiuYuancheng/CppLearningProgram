#include <iostream>
#include <string.h>
#include<unistd.h>

//two way to define a constants:
const int TEST_MD1 = true;
#define TEST_MD2 true; 

enum COLOR {RED, BLUE, GREEN}; // default re
// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

bool isLeapYear(int);
inline int add(int, int); // defined the function as inline if we need to use it several times.
void matrixDisplay();

// =======================================================================
class Tricycle
{
public:
    Tricycle(int initialSpeed);
    ~Tricycle();
    int getSpeed();
    void setSpeed(int speed);
    void pedal();
    void brake();

private:
    int speed = 0;
};

// object constructor.
Tricycle::Tricycle(int initialSpeed)
{
    std::cout << "Constructor: create the object. \n";
    setSpeed(initialSpeed);
}

Tricycle::~Tricycle()
{
    std::cout << "Destructor: destroy the object. \n";
    setSpeed(0);
}

int Tricycle::getSpeed()
{
    return speed;
}

// Set the speed.
void Tricycle::setSpeed(int newSpeed)
{
    if (newSpeed >= 0)
    {
        speed = newSpeed;
    }
    else
    {
        std::cout << "The tricycle has stopped.\n";
        speed = 0;
    }
}

void Tricycle::pedal()
{
    setSpeed(speed + 1);
    sleep(0.5);
    std::cout << "nPedaling: increase speed to:" << getSpeed() << " mph\n";
}

void Tricycle::brake()
{
    setSpeed(speed - 1);
    sleep(0.5);
    std::cout << "nBrakeing: decrease speed to:" << getSpeed() << " mph\n";
}

//=============================================================================

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
    std::cout << "Result:\n"
              << add(x, y) << "\n";
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
    std::cout << " Constant val 'RED' = \t" << RED << "\n";
    std::cout << " Constant val 'GREEN' = " << GREEN << "\n";
    std::cout << " Constant val 'BLUE' = \t" << BLUE << "\n";
    //
    std::cout << "========================\n";
}

void section4()
{
    //
    std::cout << "Section 4 Expression statement and operators \n";
    int x = 5;
    int sum = ++x;
    std::cout << "prefix sum = ++x, sum =" << sum << ", x = " << x << " \n";
    x = 5;
    sum = x++;
    std::cout << "prefix sum = ++x, sum =" << sum << ", x = " << x << " \n";
}

void section5()
{
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

void section6()
{
    std::cout << "Section 6 control the flow of a program.\n";

    int count = 60;
    do
    {
        count++;
    } while (count <= 50);
    matrixDisplay();
}

void section7()
{
    std::cout << "Section 7 array and string.\n";
    // calculate the array size
    int post[] = {10, 20, 30, 40, 50};
    std::cout << "The array post size is :" << sizeof(post) / sizeof(post[0]) << "\n";
    char name[50];
    std::cout << " Please enter your name: \n";
    std::cin >> name;
    char cpName[50];
    strcpy(cpName, name);
    std::cout << " The front 10 chars of the input is : " << cpName << "\n";
}

void section8()
{
    std::cout << "Section 8: Creating and deleting the object.\n";
    Tricycle wichita(5);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.pedal();


}


void matrixDisplay()
{
    int row, colum;
    char c;
    std::cout << "Enter the row number: ";
    std::cin >> row;
    std::cout << "Enter the colum number: ";
    std::cin >> colum;
    std::cout << "Enter the charactor: ";
    std::cin >> c;
    std::cout << "\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < colum; j++)
        {
            std::cout << c;
        }
        std::cout << "\n";
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

void callSections(int choice)
{
    switch (choice)
    {
    case 2:
        section2();
        break;
    case 3:
        section3();
        break;
    case 4:
        section4();
        break;
    case 5:
        section5();
        break;
    case 6:
        section6();
        break;
    case 7:
        section7();
        break;
    case 8:
        section8();
        break;
    default:
        std::cout << " he choice [" << choice << "] is not volid\n";
        break;
    }
}

int main()
{
    std::cout << "Welcome to leaning C++ for 24 hours ^_^ \n";
    int choice = 0;
    do{
        std::cout << "Enter the section number(2-8) you want to check the test code, 0 for end: ";
        std::cin >> choice;
        callSections(choice);
    }while(choice != 0);
    std::cout << "\n Program finished ";
    return 0;
}
