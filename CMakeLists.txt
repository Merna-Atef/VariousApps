cmake_minimum_required(VERSION 3.5 )

### c++11 standards
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project( sbe201Merna )

include_directories( include data )

add_executable( analyzeDNA apps/analyzeDNA.cpp )
add_executable( analyzeECG apps/analyzeECG.cpp )
add_executable( QueueApp apps/awesome_application.cpp )
add_executable( Parantheses apps/balanced_parentheses.cpp )
add_executable( basic apps/basics.cpp )
add_executable( Calc apps/calculator.cpp )
add_executable( countDNA apps/countDNA.cpp )
add_executable( countWords apps/count_words.cpp )
add_executable( TriangleArea apps/heron.cpp )
add_executable( memory apps/memory.cpp )
add_executable( Infection apps/QueueApplication.cpp )
add_executable( stockSpan apps/stock_span.cpp )
add_executable( testTree apps/test_tree.cpp )
add_executable( uniqueWords apps/unique_words.cpp )





