#ifndef ARRAYS_HPP
#define ARRAYS_HPP

#include <iostream>
#include "mathematics.hpp"
namespace arrays
{
    void printALL( double *base, int arraySize )
    {
        for( int i = 0; i < arraySize; i++)
        {
            std::cout<< " array elements are : "<< base[i]<<std::endl;
        }
    }
    
    double maxArray( double *base, int arraySize )
    {
        double max = base[0];
        for( int i = 1; i < arraySize; i++)
        {
            if( base[i] > max )
            {
                max = base[i];
            }
        }
        return max;
    }

    double minArray( double *base, int arraySize )
    {
        double min = base[0];
        for( int i = 1; i < arraySize; i++)
        {
            if( base[i] < min )
            {
                min = base[i];
            }
        }
        return min;
    }

    double meanArray( double *base, int arraySize )
    {
        double sum = 0;
        for ( int i = 0; i < arraySize; i++)
        {
            sum = sum + base[i];
        }
        double mean = sum / arraySize;
        return mean;
    }

    double varianceArray( double *base, int arraySize )
    {
        double mean = meanArray( &base[0], arraySize ); // calculates mean of array
        double sum = 0;
        for ( int i = 0; i < arraySize; i++)
        {
            double t = mathematics::square( mean - base[i] );
            sum = sum + t ;
        }
        double variance = sum / arraySize;
        return variance;

    }

    int countCharacter( char *basePointer , int size , char query )
    {
        int counter = 0;
        for ( int i = 0 ; i < size ; i++ )
        {
            if ( basePointer[i] == query )
            {
                counter++;
            }
        }
        return counter;
    }

    struct DoubleArray
    {
        double *ptr;
        int size;
    };

    struct CharacterArray
    {
        char *ptr;
        int size;
    };

    void printALL( DoubleArray array )
    {
        printALL( array.ptr, array.size);

    }

    double maxArray( DoubleArray array )
    {
        maxArray(array.ptr, array.size);

    }

    double minArray( DoubleArray array )
    {
        minArray(array.ptr, array.size);
    }

    // Since calling on the original functions is easier i shall solve the rest that way

    double meanArray ( DoubleArray array)
    {
        meanArray( array.ptr, array.size );
    }

    double varianceArray( DoubleArray array )
    {
        varianceArray( array.ptr, array.size );
    }

}


#endif // ARRAYS_HPP
