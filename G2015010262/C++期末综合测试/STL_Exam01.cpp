// STL_Exam01.cpp : Defines the entry point for the console application.
//

/// <summary>
/// 
/// </summary>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <iterator> 
using namespace std;

struct myclass {           // function object type:
  void operator() ( int i ) { std::cout << i << endl; }
} PrintVectorValue;

int main ()
{
  
  vector<int> v1 = { 0, 0, 30, 20, 0, 0, 0, 0, 10, 0 };
  vector<int> v2;
  vector<int> v3;

  vector<int>::iterator it = find_if ( v1.begin (), v1.end (), std::bind2nd ( not_equal_to<int> (), 0 ) );

  while (it != v1.end ())
  {
      v2.push_back ( *it );
      it = find_if ( next ( it ), v1.end (), std::bind2nd ( not_equal_to<int> (), 0 ) );      
  }   

  for (vector<int>::iterator it2 = v2.begin (); it2 != v2.end (); it2++)
  {
    cout << *it2 << endl;
  }

  copy_if ( v1.begin ( ), v1.end ( ), back_inserter(v3), std::bind2nd ( not_equal_to<int> ( ), 0 ) );

  for_each ( v3.begin (), v3.end (), PrintVectorValue );
  
  return 0;

}
