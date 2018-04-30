#include "helpers2.hpp" // for helpers::loadDNA
#include "dna.hpp" // for dna::analyzeDNA
using DNA = dna::DNA;


int main( int argc , char **argv )
{
    if( argc != 2 )
    {
        std::cout << "Invalid usage!" << std::endl;
        return 1;
    }
    else
    {
        int size = 0;
        //char *dnaArray1 = helpers::getDNA( argv[1] , 0 , size );
        DNA dnaArray1{ helpers::getDNA( argv[1] , 0 , size ),size,0,0,0,0};

        //char *complementarySeq = dna::analyzeDNA( &dnaArray1[0] , size , DNA->counterA , DNA->counterC , DNA->counterG , DNA->counterT );
        
        DNA CompSeq{ dna::analyzeDNA( dnaArray1 )};

        // We may need to make a new character array, but with a null terminated character to be able to print on screen.
        char *complementarySeqTerminated = new char[ size + 1 ];
        std::copy( &CompSeq.ptr[0] , &CompSeq.ptr[size - 1] , &complementarySeqTerminated[0] );
        complementarySeqTerminated[ size ] = '\0';

        std::cout <<"Adenine (A) content:" << dnaArray1.counterA << std::endl
                 << "Guanine (G) content:" << dnaArray1.counterG << std::endl
                 << "Cytocine(C) content:" << dnaArray1.counterC << std::endl
                 << "Thymine (T) content:" << dnaArray1.counterT << std::endl << std::endl
                 << "Complementary Sequence:" << std::endl << complementarySeqTerminated << std::endl<<" Original Sequence : "<<std::endl<<dnaArray1.ptr<<std::endl;
        //complememtary sequence last letter doesn't match the original dnaArray1 sequence's first letter??????
        
        // Clean up.
        
        delete [] complementarySeqTerminated;
        return 0;
    }
}
