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

private:
    int val;
};