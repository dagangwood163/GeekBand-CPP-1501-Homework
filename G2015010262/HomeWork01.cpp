#include <iostream>

class Shape
{
	int no;
};

class Point
{
	int x;
	int y;
public:
	Point(int x_, int y_) : x(x_), y(y_) {};
	Point(const Point &p_) :x(p_.x), y(p_.y){};
};

class Rectangle :public Shape
{
	int width;
	int height;
	Point* leftUp;

public:
	Rectangle(int width_, int height_, int x_, int y_);
	Rectangle(const Rectangle& other);
	Rectangle& operator = (const Rectangle& other);
	~Rectangle();
};

Rectangle::Rectangle(int width_, int height_, int x_, int y_)
	: width(width_), height(height_) 
{
	leftUp = new Point(x_, y_);
}

Rectangle::Rectangle(const Rectangle& other)
	: width(other.width), height(other.height) 
{
	leftUp = new Point(*other.leftUp);
}

Rectangle& Rectangle::operator=(const Rectangle& other) 
{
	if (this == &other) return *this;

	width =  other.width;
	height = other.height;
	leftUp = new Point(*other.leftUp);
	return *this;
}

Rectangle::~Rectangle() {
	if (leftUp)	{
		delete leftUp;
	}
}
int main()
{
	Rectangle Rect01(100, 200, 50, 200);
	Rectangle Rect02(Rect01);
	Rectangle Rect03=Rect02;

	return 0;
<<<<<<< HEAD
}
=======
}

>>>>>>> refs/remotes/origin/master
