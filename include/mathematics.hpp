#ifndef MATHEMATICS_HPP
#define MATHEMATICS_HPP

#include <cmath> // for std::sqrt

namespace mathematics
{

  double calculation( double a , double b , char operation )
  {
    switch(operation)
     {
        case '+':
        { 
            return a+b ;
        } break;
        case '-':
        { 
            return a-b ;
        } break;
        case '*':
        {
            return a*b ;
        } break;
        case '/':
        { 
            return a/b ;
        } break;
        default:
            return 0 ;
     }
  }

  double heron( double a , double b , double c )
  {
    double s = ( a + b + c )/2 ;
    double area = std::sqrt( s* ( s - a )*( s - b )*( s - c ) );
    return area;
  }
  
  double square( double x )
  {
      return x*x ;
  }

  struct Triangle
  {
      double a;
      double b;
      double c;
  };

  double heron( Triangle t)
  {
     return heron( t.a, t.b, t.c );
  }




}

#endif // MATHEMATICS_HPP
