// SystemAlgorithm_Exam01.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <queue>
using namespace std;

/// <summary>
/// 
/// </summary>
class MovingAverage
{
public:
  MovingAverage ( int size_ ) :MaxSize ( size_ )
  { 
    this->sum = 0;
  };
  
  double next ( double value )
  {
    if (MQ1.size() < MaxSize)
    {
      MQ1.push ( value );
      sum += value;
    }
    else
    {     
      sum -= MQ1.front ();
      MQ1.pop ( );
      MQ1.push ( value );
      sum += value;
    }
    return sum / (double) MQ1.size();
  }

private:
  int MaxSize;
  queue<double> MQ1;
  double sum;
};

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main ()
{
  MovingAverage* ma = new MovingAverage ( 2 );

  cout << ma->next ( 1 ) << endl;
  cout << ma->next ( 3 ) << endl;
  cout << ma->next ( 4 ) << endl;

  return 0;
}