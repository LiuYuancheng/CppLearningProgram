#include <iostream>
#include <unistd.h>

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
