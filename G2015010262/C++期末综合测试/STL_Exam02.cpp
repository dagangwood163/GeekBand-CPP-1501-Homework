// STL_Exam02.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

/// <summary>
/// 
/// </summary>
struct Programmer
{
  wstring Name;
  int Id;

  Programmer ( const int id, const wstring name )
  : Id ( id ), Name ( name )
  {
  }

  void Print () const
  {
    wcout << L"[" << Id << L"]:" << Name << endl;
  } 
  
};

/// <summary>
/// 
/// </summary>
struct ProgrammerIdGreater
{
  inline bool operator()( const Programmer& left, const Programmer& right )
  {    
    return left.Id > right.Id;
  }
};

/// <summary>
/// 
/// </summary>
struct ProgrammerNameComparer
{
  inline bool operator()( const Programmer& left, const Programmer& right )
  {
    if (left.Name.compare ( right.Name ) < 0)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main ()
{

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  set<Programmer, ProgrammerIdGreater> ProgrammerSet;

  ProgrammerSet.insert ( Programmer ( 1, L"Scott Meyers" ) );
  ProgrammerSet.insert ( Programmer ( 2, L"Martin Fowler" ) );
  ProgrammerSet.insert ( Programmer ( 3, L"Bill Gates" ) );
  ProgrammerSet.insert ( Programmer ( 4, L"P.J. Plaught" ) );
  ProgrammerSet.insert ( Programmer ( 5, L"Stanley B. Lippman" ) );
  ProgrammerSet.insert ( Programmer ( 6, L"Andrei Alexandrescu" ) );

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  for_each ( ProgrammerSet.begin ( ), ProgrammerSet.end ( ), mem_fun_ref (&Programmer::Print));
  

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  Programmer P1 = Programmer ( 3, L"Bill Gates" );
  set<Programmer, ProgrammerIdGreater>::iterator it = ProgrammerSet.find ( P1 );


  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  if (it != ProgrammerSet.end ())
  {
    //ProgrammerSet.erase ( P1 );
    //Programmer P2 = Programmer ( 3, L"David Vandevoorde" );
    //ProgrammerSet.insert ( P2 );

    const_cast<Programmer&>(*it).Name = L"David Vandevoorde";       
  }
  for_each ( ProgrammerSet.begin ( ), ProgrammerSet.end ( ), mem_fun_ref ( &Programmer::Print ) );

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  set<Programmer, ProgrammerNameComparer> Set2;
  Set2.insert ( Programmer ( 1, L"Scott Meyers" ) );
  Set2.insert ( Programmer ( 2, L"Martin Fowler" ) );
  Set2.insert ( Programmer ( 3, L"Bill Gates" ) );
  Set2.insert ( Programmer ( 4, L"P.J. Plaught" ) );
  Set2.insert ( Programmer ( 5, L"Stanley B. Lippman" ) );
  Set2.insert ( Programmer ( 6, L"Andrei Alexandrescu" ) );

  

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  for_each ( Set2.begin ( ), Set2.end ( ), mem_fun_ref ( &Programmer::Print ) );


  return 0;
  
}