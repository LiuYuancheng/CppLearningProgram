#include <iostream>
#include <string.h>
#include "24hours.hpp"

//two way to define a constants:
const int TEST_MD1 = true;
#define TEST_MD2 true;

enum ERR_CODE{
    SUCCESS,
    ERROR
};

enum COLOR
{
    RED,
    BLUE,
    GREEN
}; // default re
// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

inline int add(int, int); // defined the function as inline if we need to use it several times.
bool isLeapYear(int);
void matrixDisplay();
void swapPointer(int *x, int *y);
void swapReference(int &x, int &y);
ERR_CODE factor(int , int&, int&);
int loadInt();
sampleCat catFunOne(sampleCat theCat);
sampleCat* catFunTwo(sampleCat* theCat);

// =======================================================================
// Class: 24hours.hpp::Tricycle
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

//=============================================================================
Rectangle::Rectangle(int newTop, int newLeft, int newBtm, int newRight)
{
    top = newTop;
    left = newLeft;
    bottom = newBtm;
    right = newRight;

    upperL.setX(left);
    upperL.setY(top);

    upperR.setX(right);
    upperR.setX(top);

    lowerL.setX(left);
    lowerL.setY(bottom);

    lowerR.setX(right);
    lowerR.setY(bottom);
}

void Rectangle::setTop(int newT)
{
    top = newT;
    upperL.setY(top);
    upperR.setY(top);
}

void Rectangle::setLeft(int newL)
{
    left = newL;
    upperL.setX(left);
    lowerL.setX(left);
}

void Rectangle::setBottom(int newB)
{
    bottom = newB;
    lowerL.setY(bottom);
    lowerR.setY(bottom);
}

void Rectangle::setRight(int newR)
{
    right = newR;
    upperR.setX(right);
    lowerR.setX(right);
}

void Rectangle::setUpperL(Point location)
{
    upperL = location;
    upperR.setY(location.getY());
    lowerL.setX(location.getX());
    top = location.getY();
    left = location.getX();
}

void Rectangle::setUpperR(Point location)
{
    upperR = location;
    upperL.setY(location.getY());
    lowerR.setX(location.getX());
    top = location.getY();
    right = location.getX();
}

void Rectangle::setLowerL(Point location)
{
    lowerL = location;
    lowerR.setY(location.getY());
    upperL.setX(location.getX());
    bottom = location.getY();
    left = location.getX();
}

void Rectangle::setLowerR(Point location)
{
    lowerR = location;
    upperR.setX(location.getY());
    lowerL.setY(location.getY());
    bottom = location.getY();
    right = location.getX();
}

//=============================================================================
sampleCat::sampleCat(){
    std::cout << " Instruction will be called when 'New' object is define.\n";
    itsAge = new int(1);
    itsWeight = new int(5);
}

sampleCat::sampleCat(sampleCat &)
{
    std::cout << " sample cat copy instructor.\n";
    itsAge = new int(1);
    itsWeight = new int(5);
}

sampleCat::~sampleCat(){
    std::cout << " Desctruction  will be called when 'delete' the object.\n";
    delete itsAge;
    delete itsWeight;
}

//=============================================================================
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

int add(int x, int y)
{
    // add integer x and integer y then return the sum value
    std::cout << "Calculating ... \n";
    return x + y;
}
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
void section8()
{
    std::cout << "Section 8: Creating and deleting the object.\n";
    Tricycle wichita(5);
    wichita.pedal();
    wichita.pedal();
    wichita.brake();
    wichita.pedal();
}

//-----------------------------------------------------------------------------
void section9()
{
    std::cout << "Section 9: Moving into Advanced Classes.\n";
    Rectangle cRectangl(100, 20, 50, 80);
    std::cout << "The initl rectangle area is : " << cRectangl.getArea() << "\n";
    char choice;
    do
    {
        std::cout << "> L : update the left value.\n";
        std::cout << "> R : update the right value. \n";
        std::cout << "> T : update the Top value. \n";
        std::cout << "> B : update the bottom value. \n";
        std::cout << "> A : Calculate the area. \n";
        std::cout << "> D : Display 4 points of the rect. \n";
        std::cout << "> S : Stop the function. \n";

        std::cout << "Enter the choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'L':
            cRectangl.setLeft(loadInt());
            break;
        case 'R':
            cRectangl.setRight(loadInt());
            break;
        case 'T':
            cRectangl.setTop(loadInt());
            break;
        case 'B':
            cRectangl.setBottom(loadInt());
            break;
        case 'A':
            std::cout << " The rectangle area :" << cRectangl.getArea() << "\n";
            break;
        case 'S':
            std::cout << "Function stopping ... \n";
            break;
        default:
            std::cout << "The choice [ " << choice << "] is not valid.\n";
            break;
        }
    } while (choice != 'S');
}

int loadInt()
{
    int x;
    std::cout << "Enter the number: ";
    std::cin >> x;
    return x;
}

//-----------------------------------------------------------------------------
void section10()
{
    std::cout << "Section 10: Pointer and the usage.\n";
    int theValue = 5;
    int *pPointer = &theValue;
    std::cout << "pPointer:" << pPointer << "\n";
    std::cout << "&theValue" << &theValue << "\n";
    std::cout << "*pPointer:" << *pPointer << "\n";
    theValue = 7;
    std::cout << "*pPointer:" << *pPointer << "\n";

    unsigned short int mAge = 5, yAge = 10;
    unsigned short int *pAge = nullptr;

    pAge = &mAge;
    std::cout << "MyAge:\t" << mAge << "\tYourAge\t" << yAge << "\n";
    std::cout << "&MyAge:\t" << &mAge << "\t&YourAge\t" << &yAge << "\n";
    std::cout << "pAge:\t" << pAge << "\t*pAge\t" << *pAge << "\n";

    pAge = &yAge;
    std::cout << "MyAge:\t" << mAge << "\tYourAge\t" << yAge << "\n";
    std::cout << "&MyAge:\t" << &mAge << "\t&YourAge\t" << &yAge << "\n";
    std::cout << "pAge:\t" << pAge << "\t*pAge\t" << *pAge << "\n";
    // delate the pointer to release the memory.
    pPointer = NULL;
    pAge = NULL;
    delete pPointer;
    delete pAge;

    // Heap test code:
    int localV = 5;
    int *pLocal = &localV;
    int *pHeap = new int;
    if (pHeap == NULL)
    {
        std::cout << "Error! no memory for Heap.\n";
        return;
    }
    *pLocal = 7;
    std::cout << "localV:" << localV << "\n";
    std::cout << "*pLocal:" << *pLocal << "\n";
    std::cout << "*pHeap:" << *pHeap << "\n";
    delete pHeap;
    pHeap = new int;
    if (pHeap == NULL)
    {
        std::cout << "Error! no memory for Heap.\n";
        return;
    }
    *pHeap = 9;
    std::cout << "*pHeap:" << *pHeap << "\n";
    delete pHeap;
    delete pLocal;
}

//-----------------------------------------------------------------------------
void section11(){
    std::cout << "Section 11: Pointer and the usage.\n";
    std::cout << "sampleCat frisky;\n";
    sampleCat frisky;

    std::cout << "sampleCat *pRage = new sampleCat;\n";
    sampleCat *pRage = new sampleCat;

    std::cout << "pRage is "<< pRage->GetAge()<<" years old.\n";
    pRage->SetAge(5);
    std::cout << "pRage is "<< pRage->GetAge()<<" years old.\n";
    std::cout << "delete pRage;\n";
    delete pRage;

    std::cout << "Const Pointer test:\n";
    sampleCat* p1 = new sampleCat;
    const sampleCat *p2 = new sampleCat;
    sampleCat* const p3 = new sampleCat;

    std::cout << "p1 weight "<< p1->GetWeight()<<".\n";
    std::cout << "p2 weight "<< p2->GetWeight()<<".\n";
    std::cout << "p3 weight "<< p3->GetWeight()<<".\n";
    p1->SetWeigth(10);
    p3->SetWeigth(10);

    std::cout << "p1 weight "<< p1->GetWeight()<<".\n";
    std::cout << "p2 weight "<< p2->GetWeight()<<".\n";
    std::cout << "p3 weight "<< p3->GetWeight()<<".\n";

    std::cout << "Function end ;\n";
}

//-----------------------------------------------------------------------------
void section12(){
    std::cout << "Section 12: Creating Reference.\n";
    int intOne;
    int &rIntOne = intOne;
    intOne = 5;
    std::cout << "intOne = " << intOne << "\n";
    std::cout << "rIntOne = " << rIntOne << "\n";

    std::cout << "&intOne = " << &intOne << "\n";
    std::cout << "&rIntOne = " << &rIntOne << "\n";
    int x = 5; 
    int y = 10;
    swapPointer(&x, &y);
    std::cout << "x = " << x << ", y = " << y << "\n";
    x = 5; 
    y = 10;
    swapReference(x, y);
    std::cout << "x = " << x << ", y = " << y << "\n";
    int n, sqr, cube;
    std::cout << " Enter a int number: ";
    std::cin >> n;
    if(factor(n, sqr, cube) == SUCCESS){
        std::cout << " n = " << n << "\n";
        std::cout << " square = " << sqr << "\n";
        std::cout << " cube = " << cube << "\n";
    }else{
        std::cout << " Got an error \n ";
    }
}

void swapPointer(int *px, int *py)
{
    // swap x and y by pass in pointer.
    int temp;
    temp = *px;
    *px = *py;
    *py = temp;
}

void swapReference( int &rx, int &ry){
    int temp = rx;
    rx = ry;
    ry = temp;
}

ERR_CODE factor(int n, int &sqr, int &cube){
    sqr = n*n;
    cube = n*n*n;
    return SUCCESS;
}

//-----------------------------------------------------------------------------
void section13(){
    std::cout << "Section 13: Passing be Reference efficiency.\n";
    std::cout << "Init a sample cat\n";
    
    sampleCat catA;
    std::cout << "Call function one\n";
    catFunOne(catA);
    std::cout << "Call function two\n";
    catFunTwo(&catA);
        
}

sampleCat catFunOne(sampleCat theCat){
    std::cout << "Function 1 return the Cat \n";
    return theCat;
}

sampleCat* catFunTwo(sampleCat *theCat){
    std::cout << "Function2 return the Cat \n";
    return theCat;
}

//-----------------------------------------------------------------------------
void callSections(int choice)
{
    switch (choice)
    {
    case 0:
        std::cout << "no more test .... ";
        return;
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
    case 9:
        section9();
        break;
    case 10:
        section10();
        break;
    case 11:
        section11();
        break;
    case 12:
        section12();
        break;
    case 13:
        section13();
        break;

    default:
        std::cout << " he choice [" << choice << "] is not volid\n";
        break;
    }
}


//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
int main()
{
    std::cout << "Welcome to leaning C++ for 24 hours ^_^ \n";
    int choice = 0;
    do
    {
        std::cout << "Enter the section number(2-8) you want to check the test code, 0 for end: ";
        std::cin >> choice;
        callSections(choice);
    } while (choice != 0);
    std::cout << "\n Program finished ";
    return 0;
}
