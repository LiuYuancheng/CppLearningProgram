#include <iostream>
#include <unistd.h>
#include <math.h>
#include <string.h>
#include "24string.hpp"
#include "24linkList.hpp"

//-----------------------------------------------------------------------------
// Name:        24hours.hpp
//
// Purpose:     The header file used by <24hours.cpp> which holds all the defined 
//              class code.
//              
// Author:      Yuancheng Liu
//
// Created:     2020/08/02
// Copyright:   < Sams Teach Your self C++ in 24 hours>
// License:     N.A.
//-----------------------------------------------------------------------------

//=============================================================================
class Tricycle
{
public:
    Tricycle(int initialSpeed);
    ~Tricycle();
    int getSpeed() const { return speed; };
    void setSpeed(int speed);
    void pedal()
    {
        setSpeed(speed + 1);
        sleep(0.5);
        std::cout << "nPedaling: increase speed to:" << getSpeed() << " mph\n";
    };

    void brake()
    {
        setSpeed(speed - 1);
        sleep(0.5);
        std::cout << "nBrakeing: decrease speed to:" << getSpeed() << " mph\n";
    };

private:
    int speed = 0;
};
//=============================================================================
class Tricycle2
{
public:
    Tricycle2();
    Tricycle2(const Tricycle2 &);
    ~Tricycle2();
    int getSpeed() const { return *speed; };
    void setSpeed(int s) { *speed = s; };
    void pedal()
    {
        setSpeed(*speed + 1);
        sleep(0.5);
        std::cout << "nPedaling: increase speed to:" << getSpeed() << " mph\n";
    };

    void brake()
    {
        setSpeed(*speed - 1);
        sleep(0.5);
        std::cout << "nBrakeing: decrease speed to:" << getSpeed() << " mph\n";
    };
    Tricycle2 operator=(const Tricycle2 &);

private:
    int *speed;
};

//=============================================================================
class Point
{
public:
    void setX(int newX) { x = newX; };
    void setY(int newY) { y = newY; };
    int getX() const { return x; };
    int getY() const { return y; };

private:
    int x, y;
};

//=============================================================================
class Rectangle
{
public:
    Rectangle(int newTop, int newLeft, int newBtm, int newRight);
    ~Rectangle(){};
    int getTop() const { return top; };
    int getLeft() const { return left; };
    int getBottom() const { return bottom; };
    int getRight() const { return right; };
    Point getUpperL() const { return upperL; };
    Point getLowwrL() const { return lowerL; };
    Point getUpperR() const { return upperR; };
    Point getLowerR() const { return lowerR; };
    int getArea() const { return ((right - left) * (top - bottom)); };

    void setTop(int newT);
    void setLeft(int newL);
    void setRight(int newR);
    void setBottom(int newB);
    void setUpperL(Point location);
    void setUpperR(Point location);
    void setLowerL(Point location);
    void setLowerR(Point location);

private:
    int top;
    int left;
    int bottom;
    int right;
    Point upperL;
    Point upperR;
    Point lowerL;
    Point lowerR;
};
//=============================================================================
class Rectangle2
{
public:
    Rectangle2(int w, int h);
    ~Rectangle2(){};
    void drawShape() const;
    void drawShape(int w, int h, bool useCrtVal = false) const;

private:
    int width;
    int height;
};

//=============================================================================
class sampleCat
{
public:
    sampleCat();
    sampleCat(sampleCat&);
    ~sampleCat();
    int GetAge() const { return *itsAge; };
    int GetWeight() const { return *itsWeight; };
    void SetAge(int newAge) { *itsAge = newAge; };
    void SetWeigth(int newW) { *itsWeight = newW; };

private:
    int *itsAge;
    int *itsWeight;
};

//=============================================================================
class Counter
{
public:
    Counter();
    Counter(int initVal);
    ~Counter();
    int getValue() const { return val; };
    void setValue(int v) { val = v; };
    void increase() { ++val; };
    const Counter operator+(const Counter & );
    const Counter &operator++();   //prefix
    const Counter operator++(int); //posfix

    operator unsigned int(); 

private:
    int val;
};

//=============================================================================
enum BREED
{
    YORKIE,
    CAIRN,
    DANDIE,
    SHETLAND,
    DIBERMAN,
    LAB
};

class Mammal
{
public:
    Mammal() : age(2), weight(5)
    {
        std::cout << "Mammal constructor \n";
    };
    Mammal(const Mammal &rhs);
    Mammal(int newAge, int newWeight);
    virtual ~Mammal()
    {
        std::cout << "Mammal destructor \n";
    };

    int getAge() const { return age; };
    void setAge(int newAge) { age = newAge; };

    int getWeight() const { return weight; };
    void setWeight(int newWeight) { weight = newWeight; };

    virtual void speak() const { std::cout << "Mammal sound!\n"; };
    virtual Mammal *clone() { return new Mammal(*this); };

    void sleep() const { std::cout << "Shhh, I'm sleeping \n"; };
    void move() const { std::cout << "Mammal moved one step\n"; };
    void move(int dist) const { std::cout << "Mammal moved " << dist << "meter\n"; };

private:
    int age;
    int weight;
};

class Dog : public Mammal
{
public:
    Dog() : Mammal(), breed(YORKIE)
    {
        std::cout << "Dog constructor \n";
    };
    Dog(int newAge, int newWeight);
    Dog(BREED newBreed);
    Dog(const Dog &rhs);
    virtual ~Dog()
    {
        std::cout << "Dog destructor \n";
    };
    BREED getBreed() const { return breed; };
    void setBreed(BREED newBreed) { breed = newBreed; };

    virtual Mammal *clone() { return new Dog(*this); };

    void wagTail() const{ std::cout << "Tail wagging!\n"; };
    void begForFood() const{ std::cout << "Begging for food\n"; };
    void speak() const { std::cout << "Woof \n"; };
    void move() const { std::cout << "Dog moves 5 steps \n"; };
    void move(int dist) const { Mammal::move(dist); };

protected:
    BREED breed;
};

class Cat : public Mammal
{

public:
    Cat()
    {
        std::cout << "Cat constructor \n";
    };
    Cat(const Cat &rhs);
    ~Cat()
    {
        std::cout << "Cat destructor \n";
    };

    void speak() const { std::cout << "Meow\n"; };
    void purr() const {std::cout << "Rrrrrrrrrrrrr~\n";};
    virtual Mammal *clone() { return new Cat(*this); };
};

class Horse : public Mammal
{
public:
    void speak() const { std::cout << "Whinny\n"; };
};

class Pig : public Mammal
{
public:
    void speak() const { std::cout << "Oink\n"; };
};
//=============================================================================
class Shape
{
public:
    Shape(){};
    virtual ~Shape(){};
    virtual long getArea() = 0;
    virtual long getPerim() = 0;
    virtual void draw() = 0;
};

void Shape::draw(){
    std::cout << "Abstract drawing mechanism! \n";
}

class Circle : public Shape
{
public:
    Circle(int newRadius) : radius(newRadius){};
    ~Circle(){};
    long getArea() { return M_PI * radius * radius; };
    long getPerim() { return 2 * M_PI * radius; };
    void draw();

private:
    int radius;
    int circumference;
};

class Rectangle3 : public Shape
{
public:
    Rectangle3(int w, int l) : width(w), length(l){};
    virtual ~Rectangle3(){};
    virtual long getArea() { return width * length; };
    virtual long getPerim() { return 2 * (width + length); };
    virtual int getWidth() { return width; };
    virtual int getLength() { return length; };
    virtual void draw();

private:
    int width;
    int length;
};

class Square : public Rectangle3
{
public:
    Square(int len) : Rectangle3(len, len){};
    Square(int width, int len) : Rectangle3(width, len)
    {
        if (getWidth() != getLength())
        {
            std::cout << "Not a square, create a rectangle object.\n";
        }
    };
    ~Square() {}
    long getPerim()
    {
        return 4 * getLength();
    }
};
//=============================================================================
enum COLOR
{
    RED,
    BLUE,
    GREEN,
    Red,
    Green,
    Blue,
    Yellow,
    White,
    Black,
    Brown
};

class Animal
{
public:
    Animal(int);
    virtual ~Animal() { std::cout << "Animal desctructor.\n"; };
    virtual int getAge() const { return age; };
    virtual void setAge(int newAge) { age = newAge; };
    virtual void sleep() const = 0;
    virtual void eat() const = 0;
    virtual void reproduce() const = 0;
    virtual void move() const = 0;
    virtual void speak() const = 0;

private:
    int age;
};

Animal::Animal(int newAge) : age(newAge)
{
    std::cout << "Animal constructor. \n";
}

class A_Mammal : public Animal
{
public:
    A_Mammal(int newAge) : Animal(newAge)
    {
        std::cout << "A_Mammal constructor.\n";
    }
    ~A_Mammal()
    {
        std::cout << "A_Mammal desctructor.\n";
    }
    virtual void reproduce()
    {
        std::cout << "A_Mammal reproduction \n";
    }
};

class A_Fish : public Animal
{
public:
    A_Fish(int newAge) : Animal(newAge)
    {
        std::cout << "A_Fish constructor.\n";
    };
    ~A_Fish()
    {
        std::cout << "A_Fish destructor.\n";
    };
    virtual void sleep() const { std::cout << "A_Fish sleep.\n"; };
    virtual void eat() const { std::cout << "A_Fish eat.\n"; };
    virtual void reproduce() const { std::cout << "A_Fish reproduce.\n"; };
    virtual void move() const { std::cout << "A_Fish move.\n"; };
    virtual void speak() const {};
};

class A_Horse : public A_Mammal
{
public:
    A_Horse(int newAge, COLOR newColor) : A_Mammal(newAge), color(newColor)
    {
        std::cout << "A_Horse constructor.\n";
    };
    ~A_Horse()
    {
        std::cout << "A_Horse destructor.\n";
    };
    virtual COLOR getColor() { return color; };
    virtual void sleep() const { std::cout << "A_Horse sleep.\n"; };
    virtual void eat() const { std::cout << "A_Horse eat.\n"; };
    virtual void reproduce() const { std::cout << "A_Horse reproduce.\n"; };
    virtual void move() const { std::cout << "A_Horse move.\n"; };
    virtual void speak() const { std::cout << "A_Horse speak.\n"; };

private:
    COLOR color;
};

class A_Dog : public A_Mammal
{
public:
    A_Dog(int newAge, COLOR newColor) : A_Mammal(newAge), color(newColor)
    {
        std::cout << "A_Dog constructor.\n";
    };
    ~A_Dog()
    {
        std::cout << "A_Horse destructor.\n";
    };
    virtual COLOR getColor(){return color;};
    virtual void sleep() const { std::cout << "A_Dog sleep.\n"; };
    virtual void eat() const { std::cout << "A_Dog eat.\n"; };
    virtual void reproduce() const { std::cout << "A_Dog reproduce.\n"; };
    virtual void move() const { std::cout << "A_Dog move.\n"; };
    virtual void speak() const { std::cout << "A_Dog speak.\n"; };

private:
    COLOR color;
};

//=============================================================================
class StCat
{
public:
    StCat(int newAge = 1) : age(newAge) { catCount++; };
    virtual ~StCat()
    {
        catCount--;
        std::cout << "Deleting " << age << " old cat";
    };
    virtual int getAge() const { return age; };
    virtual void setAge(int newAge) { age = newAge; };
    static int getCatCount() { return catCount; };
    int compare(const StCat &otherStCat)
    {
        if (age < otherStCat.getAge())
            return kIsSmaller;
        if (age > otherStCat.getAge())
            return kIsLarger;
        return kIsSame;
    };

    void show()
    {
        std::cout << "The cat is : " << age << "years old";
    };

private:
    int age;
    static int catCount;
};

int StCat::catCount = 0;

//=============================================================================
class Employee
{
public:
    Employee() : firstName(""), lastName(""), address(""), salary(0){};
    Employee(char * fname, char * lname, char *addr, long sal) : firstName(fname), lastName(lname), address(addr), salary(sal){};
    Employee(const Employee &rhs) : firstName(rhs.getFirstName()),
                                    lastName(rhs.getLastName()),
                                    address(rhs.getAddress()),
                                    salary(rhs.getSalary()){};
    ~Employee(){};

    Employee &operator=(const Employee &);

    const String &getFirstName() const { return firstName; };
    String &getFirstName(){return firstName;};
    const String &getLastName() const { return lastName; };
    String &getLastName(){return lastName;};
    const String &getAddress() const { return address; };
    String &getAddress(){return address;};
    long getSalary() const { return salary; };
    
    void setFirstName(const String &fname) { firstName = fname; };
    void setLastName(const String &lname) { lastName = lname; };
    void setAddress(const String &addr) { address = addr; };
    void setSalary(long newSal) { salary = newSal; };

private:
    String firstName;
    String lastName;
    String address;
    long salary;
};

Employee &Employee::operator=(const Employee &rhs)
{
    if (this == &rhs)
        return *this;
    firstName = rhs.getFirstName();
    lastName = rhs.getLastName();
    address = rhs.getAddress();
    salary = rhs.getSalary();
    return *this;
}

//=============================================================================
class Condition
{
public:
    Condition(){};
    virtual ~Condition(){};
    virtual void log() = 0;
};

class Normal : public Condition
{
public:
    Normal() { log(); };
    virtual ~Normal(){};
    virtual void log(){std::cout << "Log: normal condition.\n";};
};

class Error : public Condition
{
public: 
    Error(){log();};
    virtual ~Error(){};
    virtual void log(){std::cout << "Log: error condition.\n";};
};

class Alarm : public Condition
{
public:
    Alarm(){log();};
    virtual ~Alarm(){
        log();
        warn();
    };
    virtual void warn() { std::cout << "warning!\n"; };
    virtual void log() { std::cout << "Alarm condition\n"; };
    virtual void call() = 0;
};

class FireAlarm : public Alarm{
public:
    FireAlarm(){log();};
    virtual ~FireAlarm(){};
    virtual void call(){std::cout << "Calling fire deparment.\n";};
    virtual void log(){std::cout << "Log: fire alarm condition.\n";};
};

//=============================================================================

enum SERVICE
{
    PostMaster,
    Interchange,
    Gmail,
    Hotmail,
    AOL,
    Internet
};

typedef unsigned long pDate;

class pAddress
{
public:
    pAddress(SERVICE newService,
             const String &newAddress,
             const String &newDisplay) : service(newService),
                                         addrString(newAddress),
                                         dispString(newDisplay){};
    ~pAddress(){};
    friend std::ostream &operator<<(std::ostream &stream, pAddress &address);
    String &getDisplayString() { return dispString; };

private:
    SERVICE service;
    String addrString;
    String dispString;
};

std::ostream &operator<<(std::ostream &steam, pAddress &address)
{
    steam << address.getDisplayString();
    return steam;
}

class PostMasterMsg
{
public:
    PostMasterMsg();
    PostMasterMsg(const pAddress &newSender,
                  const pAddress &newRecipient,
                  const String &newSubject,
                  const pDate &newCreateDate) : sender(newSender),
                                                recipient(newRecipient),
                                                subject(newSubject),
                                                createDate(newCreateDate),
                                                lastModDate(newCreateDate),
                                                firstRdDate(0),
                                                lastRdDate(0)
    {
        std::cout << "Post master message created. \n";
    };

    ~PostMasterMsg(){};

    void Edit()
    {
        std::cout << "Post master message edit function called. \n";
    };

    pAddress &getSender() { return sender; };
    pAddress &getReceipient() { return recipient; };
    String &getSubject() { return subject; };

private:
    pAddress sender;
    pAddress recipient;
    String subject;
    pDate createDate;
    pDate lastModDate;
    pDate receiptDate;
    pDate firstRdDate;
    pDate lastRdDate;
};

//=============================================================================
const int defaultSize = 10;

class XBoundary
{
public:
    XBoundary(){};
    ~XBoundary(){};
private:
};

class Array
{
public:
    Array(int size = defaultSize);
    Array(const Array &rhs);
    ~Array() { delete[] pType; };

    Array &operator=(const Array &);
    int &operator[](int offset);
    const int &operator[](int offset) const;
    int getSize() const { return size; };
    int getVal(int idx) const {return pType[idx];};
    friend std::ostream &operator<<(std::ostream &, const Array &);

private:
    int *pType;
    int size;
};

Array::Array(int newSize):
size(newSize)
{
    pType = new int[size];
    for (int i = 0; i < size; i++)
        pType[i] = 0;
}

Array::Array(const Array &rhs)
{
    size = rhs.getSize();
    pType = new int[size];
    for (int i = 0; i < size; i++)
        pType[i] = rhs[i];
}


Array &Array::operator=(const Array &rhs)
{
    if (this == &rhs)
        return *this;
    delete[] pType;
    size = rhs.getSize();
    pType = new int[size];
    for (int i = 0; i < size; i++)
        pType[i] = rhs[i];
    return *this;
}

int &Array::operator[](int offset)
{
    int size = getSize();
    if (offset >= 0 && offset < size)
        return pType[offset];
    throw XBoundary();
    return pType[offset];
}

const int &Array::operator[](int offset) const
{
    int size = getSize();
    if (offset >= 0 && offset < size)
        return pType[offset];
    throw XBoundary();
    return pType[offset];
}

std::ostream &operator<<(std::ostream & output, const Array & array){
    for(int i=0; i<array.getSize(); i++){
        output << "[" << i << "] :" << array[i] << "\n"; 
    }
    return output;
}