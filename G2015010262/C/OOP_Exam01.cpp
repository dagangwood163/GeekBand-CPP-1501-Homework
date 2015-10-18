// Exam01.cpp : Defines the entry point for the console application.
//

/// <summary>
/// 
/// </summary>
#include <iostream>
using namespace std;

/// <summary>
/// 
/// </summary>
class Shape
{
public:
  Shape ( int no_) : no(no_) {};
  int no;
};

/// <summary>
/// 
/// </summary>
class Point
{
public:
  Point ( int X_, int Y_ ) : x(X_), y(Y_) {};
  int x;
  int y;
};

/// <summary>
/// 
/// </summary>
class Polygon : public Shape{
public:
    Polygon (int x_, int y_, int no_);
    Polygon (const Polygon& Poly);
    Polygon& operator = (const Polygon& Poly);
    ~Polygon ( );
protected:
    Point* points;    
};

/// <summary>
/// 
/// </summary>
/// <param name="x_"></param>
/// <param name="y_"></param>
/// <param name="no_"></param>
inline Polygon::Polygon ( int x_, int y_, int no_ ) :Shape (no_)
{
  this->points = new Point (x_, y_);
}

/// <summary>
/// 
/// </summary>
/// <param name="Poly"></param>
inline Polygon::Polygon ( const Polygon& Poly ) :Shape (Poly)
{
  if (Poly.points != nullptr)
  {
    this->points = new Point ( *Poly.points );
  }
  else
  {
    this->points = nullptr;
  }
}

/// <summary>
/// 
/// </summary>
/// <param name="Poly"></param>
/// <returns></returns>
inline Polygon& Polygon::operator = (const Polygon& Poly)
{
  if (this == &Poly)
  {
    return *this;
  }

  Shape::operator = (Poly);

  if (Poly.points != nullptr)
  {
    if (this->points != nullptr)
    {
      *points = *Poly.points;
    }
    else
    {
      points = new Point ( *Poly.points );
    }

  }
  else
  {
    delete points;
    this->points = nullptr;
  }

  return *this;

}

/// <summary>
/// 
/// </summary>
inline Polygon::~Polygon ()
{
  delete points;
  this->points = nullptr;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main ()
{
  Polygon p1 ( 1, 2, 3  );
  Polygon p2 ( p1 );
  Polygon p3 = p2;

  return 0;
}




