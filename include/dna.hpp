#ifndef DNA_HPP
#define DNA_HPP

#include <algorithm>
#include "arrays.hpp"

namespace dna
{
    char *complementarySequence( char *, int  );
    char complementaryBase( char base )
    {
        switch ( base )
                {
                    case 'A':
                      { 
                        return 'T' ;
                      } break;
                    case 'T':
                      { 
                        return 'A' ;
                      } break;  
                    case 'C':
                      { 
                        return 'G' ;
                      } break;
                    default :
                      { 
                        return 'C' ;
                      } 

                }
    }
   //old function with more comlex logic
   /*char *complementarySequence( char *base, int size )
    {
        char *complementarySequence = new char[size];
        //1.copying the original sequence to the complementary sequence array
        std::copy( &base[0] , &base[size-1] , &complementarySequence[0] );
        //2.flipping the copied (target) sequence
        for( int i = 0 ; i < size/2 ; i++ )
        {
            char temp = complementarySequence[i];  // so i dont lose values while flipping 
            complementarySequence[i] = complementarySequence[size-i-1];
            complementarySequence[size-i-1] = temp;
        }
        //3.using complementary base function to get complementary sequence
        for( int i = 0 ; i < size ; i++ )
        {
            complementarySequence[i] = complementaryBase( complementarySequence[i] );
        }
        return complementarySequence;

        delete [] complementarySequence;
    }*/

    char *analyzeDNA( char *base, int size, int &countA, int &countC, int &countG, int &countT )
    {
        countA = arrays::countCharacter( &base[0], size, 'A' );
        countC = arrays::countCharacter( &base[0], size, 'C' );
        countG = arrays::countCharacter( &base[0], size, 'G' );
        countT = arrays::countCharacter( &base[0], size, 'T' );
        return complementarySequence( &base[0] , size );
    }

    struct DNA
    {
        char *ptr;
        int size;  
        int counterA;
        int counterC;
        int counterG;
        int counterT;     
    };

    //new function with less logic
    char *complementarySequence( char *base, int size )
    {
        char *CompSeq = new char[size];
        for( int i = 0; i < size; i++ )
        {
          CompSeq[i] = complementaryBase( base[ size-1-i ] );
        }
        return CompSeq;
    }

    DNA analyzeDNA( DNA &seq )
    {
      
      seq.counterA= arrays::countCharacter( &seq.ptr[0], seq.size, 'A');
      seq.counterC= arrays::countCharacter( &seq.ptr[0], seq.size, 'C');
      seq.counterT= arrays::countCharacter( &seq.ptr[0], seq.size, 'T');
      seq.counterG= arrays::countCharacter( &seq.ptr[0], seq.size, 'G');
      DNA compSeq{ complementarySequence(&seq.ptr[0], seq.size), seq.size, seq.counterA, seq.counterC, seq.counterG, seq.counterT};
      return compSeq;
    }

}



#endif // DNA_HPP
