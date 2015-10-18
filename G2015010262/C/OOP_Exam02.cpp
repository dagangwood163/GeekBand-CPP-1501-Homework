// Exam2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <list>
using namespace std;

class Point;

/// <summary>
/// 
/// </summary>
class IObserver
{
public:
  virtual void update (Point) = 0;
  virtual ~IObserver (){};
};


/// <summary>
/// 
/// </summary>
class Point {
public:
  
  void attach ( IObserver* Obs)
  {
    viewobjects.push_back(Obs);
  }

  void detach ( IObserver* Obs )
  {
    viewobjects.remove ( Obs );
  }

  void change_value (const int x_, const int y_)
  {
    this->x = x_;
    this->y = y_;
    this->notify ();
  }

  virtual void notify ()
  {
    list<IObserver*>::iterator itor = viewobjects.begin ( );
    while (itor != viewobjects.end ( ))
    {
      (*itor)->update ( *this );
      itor++;
    }
  }

  int getX ()
  {
    return x;
  }

  int getY ()
  {
    return y;
  }

private:
  list<IObserver*> viewobjects;
  int x;
  int y;
};


/// <summary>
/// 
/// 
/// </summary>

class ConsoleOutput :public IObserver
{
private:
  Point P;
public:
  void update ( Point P_ )
  {
    this->P = P_;
    cout << "ConsoleOutput:" << endl;
    cout << this->P.getX() << endl;
    cout << this->P.getY ( ) << endl;
  }
  ~ConsoleOutput (){};
};

/// <summary>
/// 
/// </summary>
class WindowsOutput :public IObserver
{
public:
  void update ( Point P_ )
  {
    this->P = P_;
    cout << "WindowsOutput" << endl;
    cout << this->P.getX ( ) << endl;
    cout << this->P.getY ( ) << endl;
  }
  ~WindowsOutput (){};
private:
  Point P;
};


/// <summary>
/// 
/// </summary>

int main ()
{
  Point P;

  P.attach ( new ConsoleOutput );
  P.attach ( new WindowsOutput );

  P.change_value ( 4, 5 );

  P.change_value ( 14, 15 );

  return 0;
}
