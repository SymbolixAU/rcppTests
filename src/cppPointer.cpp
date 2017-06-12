#include <Rcpp.h>
using namespace Rcpp;

// The goal is to implement a function that updates the elements of a logical vector
// by reference/pointing

/**
 *  The basics:
 *  http://www.cplusplus.com/articles/z6vU7k9E/
 *
 *  & == reference
 *  * == pointer
 *
 *  A pointer variable is a variable which holds the memory address of
 *  some other variable.
 *
 *  - int i;
 *  - int* pInt = &i;  // pInt "points to" i
 *  - int* pInt2 = new int;  // pInt2 "points to" an unnamed int.
 *
 *  A reference variable is a variable which "refers to" another
 *  named or unnamed variable
 *
 *  void foo( const std::string& str ) {}
 *
 *  std::string s1;
 *  std::string& s1ref = s1;   // s1ref "refers" to s1
 *
 * // Here, we construct an unnamed, temporary string object to call foo.
 * // foo's "str" parameter now "refers to" this unnamed object.
 * foo( std::string( "Hello World" ) );
 *
 **/

//LogicalVector cppValue(LogicalVector valLv );
//void cppPointer(LogicalVector* ptrLv);

LogicalVector cppValue(LogicalVector valLv ){
  int n = valLv.size();
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      valLv[i] = true;
    }
  }
  return valLv;
}

void cppReference(LogicalVector& refLv){
  int n = refLv.size();
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      refLv[i] = true;
    }
  }
}


// [[Rcpp::export]]
LogicalVector rcppChangeVector(int vectorSize){
  LogicalVector lv(vectorSize); // all elements will default to false
  return cppValue(lv);
}

// [[Rcpp::export]]
LogicalVector rcppChangeVectorReference(int vectorSize){
  LogicalVector lv(vectorSize);
  cppReference(lv);
  return lv;
}




