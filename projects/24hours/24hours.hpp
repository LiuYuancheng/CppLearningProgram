#include <iostream>
#include <unistd.h>
#include <math.h>
#include <string.h>

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

    void wagTail() { std::cout << "Tail wagging!\n"; };
    void begForFood() { std::cout << "Begging for food\n"; };
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
enum
{
    kIsSmaller,
    kIsLarger,
    kIsSame
};

//-
class Data
{
public:
    Data(int newVal) : value(newVal){};
    ~Data(){};
    int compare(const Data &);
    void show() { std::cout << value << "\n"; };

private:
    int value;
};

int Data::compare(const Data &otherData)
{
    if (value < otherData.value)
    {
        return kIsSmaller;
    }
    else if (value > otherData.value)
    {
        return kIsSmaller;
    }
    else
    {
        return kIsSame;
    }
}

//--
class Node;
class HeadNode;
class TailNode;
class InternalNode;

//-
class Node
{
public:
    Node(){};
    virtual ~Node(){};
    virtual Node *insert(Data *data) = 0;
    virtual void show() = 0;

private:
};

//-
class InternalNode : public Node
{
public:
    InternalNode(Data *newData, Node *newNode);
    virtual ~InternalNode()
    {
        delete data;
        delete next;
    };
    virtual Node *insert(Data *data);
    virtual void show()
    {   
        std::cout << "- InternalNode show: \n";
        data->show();
        next->show();
    };

private:
    Data *data;
    Node *next;
};

InternalNode::InternalNode(Data *newData, Node *newNode) : data(newData), next(newNode)
{
    std::cout << "Internal Node init \n";
}

Node *InternalNode::insert(Data *otherdata)
{
    std::cout << "x";
    int result = data->compare(*otherdata);
    switch (result)
    {
    case kIsSame:
    case kIsLarger:
    {
        InternalNode *dataNode = new InternalNode(otherdata, this);
        return dataNode;
    }
    case kIsSmaller:
        next = next->insert(otherdata);
        return this;
    }
    
    return this;
}

//-
class TailNode : public Node
{
public:
    TailNode(){};
    virtual ~TailNode(){};
    virtual Node *insert(Data *data);
    virtual void show(){
        std::cout << "- TailNode show: \n";
    };

private:
};

Node *TailNode::insert(Data *data)
{
    std::cout << ">";
    InternalNode *dataNode = new InternalNode(data, this);
    return dataNode;
}

//-
class HeadNode : public Node
{
public:
    HeadNode();
    virtual ~HeadNode() { delete next; };
    virtual Node *insert(Data *data);
    virtual void show() { 
        std::cout << "- HeadNode show: ";
        next->show(); };
private:
    Node *next;
};

HeadNode::HeadNode()
{
    next = new TailNode;
}

Node *HeadNode::insert(Data *data)
{
    next = next->insert(data);
    return this;
}

//-
class LinkedList
{
public:
    LinkedList();
    ~LinkedList(){};
    void insert(Data *data);
    void showAll() { 
        std::cout << "linkedList show: ";
        head->show(); };

private:
    HeadNode *head;
};

LinkedList::LinkedList()
{
    head = new HeadNode;
}

void LinkedList::insert(Data *pdata)
{
    head->insert(pdata);
}
//=============================================================================
class StCat
{
public:
    StCat(int newAge = 1):age(newAge) { catCount++; };
    virtual ~StCat() { catCount--; };
    virtual int getAge() { return age; };
    virtual void setAge(int newAge) { age = newAge; };
    static int getCatCount(){return catCount;};
private:
    int age;
    static int catCount;
};

int StCat::catCount = 0;

//=============================================================================
class String
{
public:
    String();
    String(const char *const);
    String(const String &);
    ~String();

    // overload operators
    char &operator[](int offset);
    char operator[](int offset) const;
    String operator+(const String &);
    void operator+=(const String &);
    String &operator=(const String &);

private:
    String(int);
    char *value;
    int len;
};
