#include "mathematics.hpp" // for mathematics::heron
#include <iostream> // for std::cout
#include <algorithm> // for std::atof


// We need main function here!
int main ()
{
    mathematics::Triangle t{0,0,0};
    std::cout<<"Type the lengths of triangle: "<<std::endl;
    std::cin>>t.a>>t.b>>t.c;
    std::cout<<"Area is "<< mathematics::heron( t )<<std::endl;
    return 0;
}
