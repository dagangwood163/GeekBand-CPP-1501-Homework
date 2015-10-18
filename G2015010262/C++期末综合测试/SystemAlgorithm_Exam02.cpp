// SystemAlgorithm_Exam02.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

/// <summary>
/// 
/// </summary>
/// <param name="S1"></param>
/// <param name="S2"></param>
/// <returns></returns>
bool stringreversecompare ( string S1, string S2 )
{
  bool result = true;

  int n1 = S1.length ( );
  int n2 = S2.length ( );
  
  if (n1 != n2)
  {
    result = false;
    return result;
  }
  
  if (S1.compare ( S2 ) == 0)
  {
    result = false;
    return result;
  }

  for (unsigned i = 0; i < n1; ++i)
  {
    if (S1.at ( i ) != S2.at ( n1 - i - 1 ))
    {
      result = false;
      return result;
    }
  }
  
  return result;
}

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main ()
{

  list<string> Strings;

  Strings.push_back ( "abc" );
  Strings.push_back ( "cba" );
  Strings.push_back ( "abc" );
  Strings.push_back ( "Aaa" );
  Strings.push_back ( "aaa" );
  Strings.push_back ( "aaa" );
  Strings.push_back ( "aaabbf" );
  Strings.push_back ( "AAa" );
  
  int totalnum = 0;
  
  while (Strings.size () > 0)
  {
    string S1 = Strings.front ();
    string S2;

    bool found2 = false;

    for (list<string>::const_iterator it = Strings.begin ( ); it != Strings.end ( ); it++)
    {
      if (stringreversecompare ( S1, *it ))
      {
        found2 = true;
        S2 = *it;
        break;
      }
    }

    Strings.remove ( S1 );

    if (found2)
    {
      Strings.remove ( S2 );
    }
    totalnum++;
  }

  cout << totalnum << endl;

  return 0;
}


