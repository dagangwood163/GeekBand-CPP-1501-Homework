// SystemAlgorithm_Exam03.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <vector>
#include <vector>
#include <iomanip>
#include <algorithm> // std::min_element
#include <iterator>  // std::begin, std::end
using namespace std;


/// <summary>
/// 
/// </summary>
struct node
{
  int value; 
  node *left;
  node *right;
};

/// <summary>
/// 
/// </summary>
vector< vector<int> > paths;
vector< vector<node*> > paths2;
vector< vector<int> >  indents;

/// <summary>
/// 
/// </summary>
/// <param name="pRoot"></param>
/// <param name="path"></param>
void FindAllPath ( node *pRoot, vector<int> path )
{
  if (pRoot != NULL)
  {
    path.push_back ( pRoot->value );
    if (pRoot->left == NULL && pRoot->right == NULL)
    {      
      paths.push_back ( path );
      
      return;
    }
    else
    {
      FindAllPath ( pRoot->left, path );
      FindAllPath ( pRoot->right, path );
    }
  }
}

/// <summary>
/// 
/// </summary>
void PrintAllPath ( node *pRoot, vector<node*> path, vector<int> indentarray, int indent=0)
{
  if (pRoot != NULL)
  {
    path.push_back ( pRoot);
    indentarray.push_back ( indent );
    if (pRoot->left == NULL && pRoot->right == NULL)
    {      
      paths2.push_back ( path );      
      indents.push_back ( indentarray );
    }
    else
    {
      PrintAllPath ( pRoot->left, path, indentarray,indent - 1 );
      PrintAllPath ( pRoot->right, path, indentarray,indent + 1 );
    }
    path.pop_back ();    
    indentarray.pop_back ();
  }
}


/// <summary>
/// 
/// </summary>
/// <returns></returns>
int main ()
{

  node* root = new node ();
  root->value = 3;

  root->left = new node ();
  root->left->value = 1;

  root->right = new node ( );
  root->right->value = 5;

  root->left->right = new node ( );
  root->left->right->value = 2;

  root->right->left = new node ( );
  root->right->left->value = 6;

  root->right->right = new node ( );
  root->right->right->value = 7;

  root->right->left->left = new node ( );
  root->right->left->left->value = 8;

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  vector<int> path;
    
  FindAllPath ( root, path );

  for (int i = 0; i < paths.size (); ++i)
  {
    cout << "[";
    
    for (int j = 0; j < paths[i].size (); ++j)
    {
      if (j == paths[i].size () - 1)      {
        cout << paths[i][j];
      }
      else      {
        cout << paths[i][j] << ",";
      }
      
    }
    
    if (i == paths.size () - 1)    {
      cout << "]";
    }
    else    {
      cout << "],";
    }
    
  }  

  /// <summary>
  /// 
  /// </summary>
  /// <returns></returns>
  
  cout<<endl;
  vector<node*> path2;
  vector<int> indentarray;
  PrintAllPath ( root, path2, indentarray );

  for (int i = 0; i < paths2.size (); ++i)
  {
    
    int offset = 0;
    for (int j = 0; j < paths2[i].size (); ++j)
    {
      offset = offset > indents[i][j] ? indents[i][j] : offset;
    }

    offset = abs ( offset ) + 1;

    for (int j = 0; j < paths2[i].size (); ++j)
    {
      cout << setw ( indents[i][j] + offset ) << ' ';
      cout << paths2[i][j]->value << endl;
    }
    cout << "--------" << endl;
  }

  return 0;
}



/// <summary>
/// 
/// </summary>
//void preorder ( node* p, int indent = 0 )
//{
//  if (p != NULL) {
//    
//    std::cout << std::setw ( indent ) << ' ';
//    cout << p->value << "\n ";
//
//    if (p->left) preorder ( p->left, indent + 4 );
//    if (p->right) preorder ( p->right, indent + 4 );
//    if (indent) {
//      //std::cout << std::setw ( indent ) << ' ';
//    }
//    
//  }
//}

//void graphAux ( ostream & out, int indent,  node* subtreeRoot )
//{
//  if (subtreeRoot != 0)
//  {
//    graphAux ( out, indent + 4, subtreeRoot->right );
//    out << setw ( indent ) << " " << subtreeRoot->value << endl;
//    graphAux ( out, indent + 4, subtreeRoot->left );
//  }
//}