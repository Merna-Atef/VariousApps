#ifndef ECG_HPP
#define ECG_HPP

#include "arrays.hpp"
namespace ecg 
{
    void analyzeECG( double *base, int arraySize, double &mean, double &variance, double &max, double &min )
    {
        mean = arrays::meanArray( &base[0], arraySize );
        variance = arrays::varianceArray( &base[0], arraySize );
        max = arrays::maxArray( &base[0] , arraySize );
        min = arrays::minArray( &base[0] , arraySize );
        
    }

    using ECGArray = arrays::DoubleArray; 
   
    
    struct Statistics
    {
        double mean;
        double variance;
        double min;
        double max;
    };

    Statistics analyzeECG( ECGArray ecg )
    {
        Statistics analysis;
        analyzeECG( ecg.ptr, ecg.size, analysis.mean, analysis.variance, analysis.max, analysis.min  );
        return analysis;
    }





}


#endif // ECG_HPP
