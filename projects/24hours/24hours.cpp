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

// In vscode select Terminal> Run build Task > C/C++:g++.exe build atice file to compile.

//=============================================================================
inline int add(int, int); // defined the function as inline if we need to use it several times.
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
bool isLeapYear(int);
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
void matrixDisplay();
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

int loadInt();
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
void swapPointer(int *x, int *y);
void swapReference(int &x, int &y);
ERR_CODE factor(int , int&, int&);

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
sampleCat catFunOne(sampleCat theCat);
sampleCat* catFunTwo(sampleCat* theCat);
const sampleCat * const catFunThree(const sampleCat *const theCat);
const sampleCat & catFunFour(const sampleCat & theCat);

void section13(){
    std::cout << "Section 13: Passing be Reference efficiency.\n";
    std::cout << "Init a sample cat\n";
    
    sampleCat catA;
    catA.SetAge(5);
    std::cout << "Call function one\n";
    catFunOne(catA);
    std::cout << "Call function two\n";
    catFunTwo(&catA);
    std::cout << "Cat A age = " << catA.GetAge() << "\n";
    std::cout << "Call function three\n";
    catFunThree(&catA);
    std::cout << "Call function four\n";
    catFunFour(catA);
}

sampleCat catFunOne(sampleCat theCat){
    std::cout << "Function 1 return the Cat \n";
    return theCat;
}

sampleCat* catFunTwo(sampleCat *theCat){
    std::cout << "Function2 return the Cat \n";
    return theCat;
}

const sampleCat * const catFunThree(const sampleCat *const theCat){
    std::cout << "In function3 age = " << theCat->GetAge() << "\n";
    return theCat;
}

const sampleCat & catFunFour(const sampleCat & theCat){
    std::cout << "In function3 age = " << theCat.GetAge() << "\n";
    return theCat;
}
//-----------------------------------------------------------------------------
//Section 14: Calling advance function.

// class Rectangle2
Rectangle2::Rectangle2(int w, int h)
{
    width = w;
    height = h;
}

void Rectangle2::drawShape() const
{
    drawShape(width, height);
}

void Rectangle2::drawShape(int w, int h, bool useCrtVal) const
{
    if (useCrtVal)
    {
        w = width;
        h = height;
    }
    for (int i = 0; i < h; i++ )
    {
        for (int j = 0; j < w; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    
}

// class Tricycle2
Tricycle2::Tricycle2(){
    speed = new int;
    *speed = 5;
}

Tricycle2::Tricycle2(const Tricycle2& rhs){
    speed = new int;
    *speed = rhs.getSpeed();
}

Tricycle2::~Tricycle2(){
    *speed = 0;
    delete speed;
    speed = NULL;
}

void section14(){
    std::cout << "Section 14: Calling advance function.\n";
    Rectangle2 box(30, 5);
    std::cout << "drawShape():\n";
    box.drawShape();
    std::cout << "\ndrawShape(40,6):\n";
    box.drawShape(40, 6);
    std::cout << "\ndrawShape(0,0,true):\n";
    box.drawShape(0, 0, true);
    std::cout << "Create trike name wichita";
    Tricycle2 wichita;
    wichita.pedal();
    std::cout << "Create trike name dallas";
    Tricycle2 dallas(wichita);
    std::cout << "wichita.getSpeed():"<< wichita.getSpeed()<<"\n";
    std::cout << "dallas.getSpeed():" << dallas.getSpeed() <<"\n";
    wichita.setSpeed(10);
    std::cout << "wichita.getSpeed():"<< wichita.getSpeed()<<"\n";
    std::cout << "dallas.getSpeed():" << dallas.getSpeed() <<"\n";
}
//-----------------------------------------------------------------------------
//Section 15: Using Operator Overloading.
Counter::Counter() : val(0) {}
Counter::Counter(int initVal) : val(initVal) {}
Counter::~Counter() { val = 0; }

const Counter Counter::operator+(const Counter& rhs)
{
    return Counter(val +rhs.getValue());
}

const Counter &Counter::operator++()
{
    ++val;
    return *this;
}

const Counter Counter::operator++(int v)
{
    Counter temp(*this);
    ++val;
    return temp;
}

Counter::operator unsigned int(){
    return val;
}

Tricycle2 Tricycle2::operator=(const Tricycle2 &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    delete speed;
    speed = new int;
    *speed = rhs.getSpeed();
    return *this;
}

void section15(){
    std::cout << "Section 15: Using Operator Overloading.\n";
    Counter c;
    std::cout << "c Counter Val = "<< c.getValue() <<"\n";
    c.increase();
    std::cout << "c Counter Val = "<< c.getValue() <<"\n";
    ++c;
    std::cout << "++c Counter Val = "<< c.getValue() <<"\n";
    c++;
    std::cout << "c++ Counter Val = "<< c.getValue() <<"\n";
    Counter a = ++c;
    std::cout << "a Counter Val = "<< a.getValue() <<"\n";
    std::cout << "c Counter Val = "<< c.getValue() <<"\n";
    Counter b = c++;
    std::cout << "b Counter Val = "<< a.getValue() <<"\n";
    std::cout << "c Counter Val = "<< c.getValue() <<"\n";

    std::cout << "Overload '+' operator\n";
    Counter alpha(4), beta(13), gama;
    gama = alpha + beta;
    std::cout << "Alpha = "<< alpha.getValue() <<"\n";
    std::cout << "beta = "<< beta.getValue() <<"\n";
    std::cout << "gama = "<< gama.getValue() <<"\n";

    std::cout << "Overload '=' operator\n";
    Tricycle2 wichita;
    wichita.setSpeed(6);
    std::cout << "wichita Speed : " << wichita.getSpeed() << "\n";
    Tricycle2 dallas;
    std::cout << "dallas Speed : " << dallas.getSpeed() << "\n";
    wichita = dallas;
    std::cout << "Copying dallas to wichita";
    std::cout << "wichita Speed : " << wichita.getSpeed() << "\n";

    std::cout << "Overload 'int' operator\n";
    int intBata = 5;
    Counter delta = intBata;
    std::cout << "deta.getValue  = " << delta.getValue() << "\n";
    Counter epsilon(19);
    int zeta = epsilon;
    std::cout << "zeta = " << zeta << "\n";

}

//-----------------------------------------------------------------------------
//Section 16 inheritance
Mammal::Mammal(int newAge, int newWeight) : age(newAge),
                                            weight(newWeight)
{
    std::cout << "Mamal (int) constructor \n";
}

Dog::Dog(int newAge, int newWeight) : Mammal(newAge, newWeight)
{
    std::cout << "Dog (int) constructor \n";
}

Dog::Dog(BREED newBred) : breed(newBred)
{
    std::cout << "Dog (newBred) constructor \n";
}

void section16()
{
    std::cout << "Section 16: Extend class with inhertance.\n";
    Dog fido;
    fido.speak();
    fido.sleep();
    fido.wagTail();
    fido.begForFood();
    std::cout << "The fido's age is: " << fido.getAge() << "\n";
    Dog rover(5, 10);
    std::cout << "The rover's age is: " << rover.getAge() << "\n";
    Dog yorke(DIBERMAN);
    std::cout << "The yorke's breed is: " << yorke.getBreed() << "\n";
    fido.move();
    fido.Mammal::move(12);
    fido.move(100);
}

//-----------------------------------------------------------------------------
//Section 17 Polymorphism Implemented with virtual methods.

enum ANIMALS
{
    MAMMAL,
    DOG,
    CAT
};
const int numAnimalType = 3;

Mammal::Mammal(const Mammal &rhs) : age(rhs.getAge())
{
    std::cout << "Mammal copy constructor\n";
}

Dog::Dog(const Dog &rhs) : Mammal(rhs)
{
    std::cout << "Dog copy constructor\n";
}

Cat::Cat(const Cat &rhs) : Mammal(rhs)
{
    std::cout << "Cat copy constructor\n";
}

void valueFunc(Mammal mammalVal)
{
    mammalVal.speak();
}

void ptrFunc(Mammal *pMammal)
{
    pMammal->speak();
}

void refFunc(Mammal &rMammal)
{
    rMammal.speak();
}

void section17()
{
    std::cout << "Section 17: Polymorphism Implemented with virtual methodse.\n";
    Mammal *pDog = new Dog;
    pDog->move();
    pDog->speak();
    int funcNum = 0;
    std::cout << "Input the test you want to do: \n1. virtual function\n2.Slicing\n3.virtual contructor \n";
    std::cin >> funcNum;
    if (funcNum == 0)
    {
        Mammal *array[5];
        Mammal *ptr;
        int choice, i;
        for (i = 0; i < 5; i++)
        {
            std::cout << "(1) dog, (2) cat, (3) horse, (4) pig: ";
            std::cin >> choice;
            switch (choice)
            {
            case 1:
                ptr = new Dog;
                break;
            case 2:
                ptr = new Cat;
                break;
            case 3:
                ptr = new Horse;
                break;
            case 4:
                ptr = new Pig;
                break;
            default:
                ptr = new Mammal;
                break;
            }
            array[i] = ptr;
        }

        for (i = 0; i < 5; i++)
        {
            array[i]->speak();
        }
    }
    else if (funcNum == 1)
    {
        std::cout << "slicing test:";
        Mammal *ptr1 = 0;
        int choice1;
        while (true)
        {
            bool fQuit = false;
            std::cout << "(1) dog, (2)cat, (0)quit:";
            std::cin >> choice1;
            switch (choice1)
            {
            case 0:
                fQuit = true;
                break;
            case 1:
                ptr1 = new Dog;
                break;
            case 2:
                ptr1 = new Cat;
                break;
            default:
                ptr1 = new Mammal;
                break;
            }

            if (fQuit)
                break;
            ptrFunc(ptr1);
            refFunc(*ptr1);
            valueFunc(*ptr1);
        }
    }
    else if (funcNum == 3)
    {
        Mammal *array[numAnimalType];
        Mammal *ptr;
        int choice, i;
        for (i = 0; i < numAnimalType; i++)
        {
            std::cout << "(1) dog, (2) cat, (3) mammal";
            std::cin >> choice;
            switch (choice)
            {
            case DOG:
                ptr = new Dog;
                break;
            case CAT:
                ptr = new Cat;
                break;
            default:
                ptr = new Mammal;
                break;
            }
            array[i] = ptr;
        }
        Mammal *otherArray[numAnimalType];
        for (i = 0; i < numAnimalType; i++)
        {
            array[i]->speak();
            otherArray[i] = array[i]->clone();
        }
        for (i = 0; i < numAnimalType; i++)
        {
            otherArray[i]->speak();
        }
    }
}
//-----------------------------------------------------------------------------
//Section 18 Make use of advannced polymorphism

void Circle::draw()
{
    std::cout << "Circle drawing routine here \n";
    Shape::draw();
}

void Rectangle3::draw()
{
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < width; j++)
        {
            std::cout << "x";
        }
        std::cout << "\n";
    }
    Shape::draw();
}

void section18()
{
    std::cout << "Section 18: Make use of advannced polymorphism.\n";
    const int numMammal = 3;
    Mammal *zoo[numMammal];
    Mammal *pMamml;
    int choice, i;
    for (i = 0; i < numMammal; i++)
    {
        std::cout << "(1) Dog, (2) Cat : ";
        std::cin >> choice;
        if (choice == 1)
        {
            pMamml = new Dog;
        }
        else
        {
            pMamml = new Cat;
        }
        zoo[i] = pMamml;
    }

    for (i = 0; i < numMammal; i++)
    {
        zoo[i]->speak();
        Cat *pRealCat = dynamic_cast<Cat *>(zoo[i]);
        if (pRealCat)
        {
            pRealCat->purr();
        }
        else
        {
            std::cout << "Zoo[" << i << "]" << zoo[i] << "is not a Cat\n";
        }
        delete zoo[i];
        std::cout << "\n";
    }

    std::cout << "Section 18: Abstract data type:.\n";
    bool fQuit = false;
    Shape *sp;
    while (1)
    {
        std::cout << "(1) Circle, (2) Rectangle, (3)Square, (0) Quite \n";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            fQuit = true;
            break;
        case 1:
            sp = new Circle(5);
            break;
        case 2:
            sp = new Rectangle3(4, 6);
            break;
        case 3:
            sp = new Square(5);
            break;
        default:
            fQuit = true;
            break;
        }
        if (fQuit)
            break;
        sp->draw();
        std::cout << "\n";
    }

    std::cout << "Section 18: Abstract data type 2:.\n";
    Animal *pAnimal = 0;
    fQuit = false;
    while (1)
    {
        std::cout << "(1) A_Dog, (2) A_Horse, (3) A_Fish, (0) Quite \n";
        std::cin >> choice;
        switch (choice)
        {
        case 0:
            fQuit = true;
            break;
        case 1:
            pAnimal = new A_Dog(5, Brown);
            break;
        case 2:
            pAnimal = new A_Horse(4, Black);
            break;
        case 3:
            pAnimal = new A_Fish(5);
            break;
        default:
            fQuit = true;
            break;
        }
        if (fQuit)
            break;
        pAnimal->speak();
        pAnimal->eat();
        pAnimal->reproduce();
        pAnimal->move();
        pAnimal->sleep();
        delete pAnimal;
        std::cout << "\n";
    }
}

//-----------------------------------------------------------------------------
//Section 19 Stroing information in linked lists.
void section19()
{
    std::cout << "Section 19: Storing information in linked list.\n";
    Data *pdata;
    int val;
    LinkedList ll;
    while (true)
    {
        std::cout << "Input value(0 for stop):";
        std::cin >> val;
        if (!val)
            break;
        pdata = new Data(val);
        ll.insert(pdata);
    }

    std::cout << "Linked list:\n";
    ll.showAll();
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
    case 14:
        section14();
        break;
    case 15:
        section15();
        break;
    case 16:
        section16();
        break;
    case 17:
        section17();
        break;
    case 18:
        section18();
        break;
    case 19:
        section19();
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
        std::cout << "Enter the section number(1-17) you want to check the test code, 0 for end: ";
        std::cin >> choice;
        callSections(choice);
    } while (choice != 0);
    std::cout << "\n Program finished ";
    return 0;
}
