#include <iostream>

/* The application outputs the number of timeframes needed for an infection to spread in a matrix of:
   1. Infected individuals (insert 2), 2. Healthy individuals (insert 1), and 3. Vaccinated individuals
   (insert 0) till the entire matrix is infected. It also outputs the state of the matrix after the maximum 
   spread of infection. The infection can only spread vertically and horizontally not diagonally.
   The size of the matrix is determined by the user. */

int row = 0;      //global variables for input matrix
int column = 0; 

struct CellCoordinates  
{
    int x = 0;
    int y = 0;
    CellCoordinates *next = nullptr;
    //Methods
    bool isValid () 
    {
        return ( x >= 0 && y >= 0 && x < row && y < column);
    }
};

struct LLQueue
{
    CellCoordinates *head = nullptr;
    CellCoordinates *rear = nullptr;
    //Methods
    void enqueue ( CellCoordinates *cell )
    {

        if ( isEmpty() )
        {
            this->head = cell;
            this->rear = cell;
        }
        else
        {
            rear->next = cell;
            rear = rear->next;
        }

    }

    void dequeue ()
    {
        if ( isEmpty() )
        {
            exit(1);
        }
        else
        {
            CellCoordinates *oldFront = new CellCoordinates;
            oldFront = this->head;
            this->head = this->head->next;
            if(this->head == nullptr)
            {
                this->rear == nullptr;
            }
            delete oldFront;
        }
    }

    bool isEmpty() const
    {
        return ( head == nullptr );
    }
};





int main()
{
    LLQueue infected;
    std::cout << "Insert number of rows and columns : "<< std::endl;
    std::cin >> row >> column;
    int **sample = new int*[row];
    std::cout << " Insert matrix sample in rows then columns : " << std::endl;
    
    for ( int i = 0; i < row ; i++ )
        {
            sample[i] = new int[column];             
        }
    for ( int i = 0; i < row ; i++)
    {
        for ( int j = 0; j < column ; j++)
        {
            std::cin >> sample[i][j];
            if ( sample[i][j] == 2 )
            {   
                CellCoordinates *cell = new CellCoordinates;
                cell->x = i;
                cell->y = j;
                infected.enqueue( cell );
                
            }

        }
    }
    CellCoordinates *separate = new CellCoordinates;
    separate->x = -1;
    separate->y = -1;
    infected.enqueue( separate );
    int timeFrame = 0;
    
    CellCoordinates *tempCell = new CellCoordinates;
    while ( infected.isEmpty() == false )
    {
        bool once = false;
        while ( infected.head->x != -1 && infected.head->y != -1 )
        {
            tempCell = infected.head;
            
            //check down cell if it can be infected and infect it if it can
            tempCell->x--;
            if( tempCell->isValid () && sample[tempCell->x][tempCell->y] == 1 )
            {
                
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[tempCell->x][tempCell->y] = 2;
                newCell->x = tempCell->x;
                newCell->y = tempCell->y;
                infected.enqueue(newCell); // push new infected in queue
            }
            tempCell->x++;  //return to original cell 
            //check up cell
            tempCell->x++; 
            if( tempCell->isValid () && sample[tempCell->x][tempCell->y] == 1 )
            {
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[tempCell->x][tempCell->y] = 2;
                newCell->x = tempCell->x;
                newCell->y = tempCell->y;
                infected.enqueue(newCell); 
            } 
            tempCell->x--;
            //check left
            tempCell->y++;
            if( tempCell->isValid () && sample[tempCell->x][tempCell->y] == 1 )
            {
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[tempCell->x][tempCell->y] = 2;
                newCell->x = tempCell->x;
                newCell->y = tempCell->y;
                infected.enqueue(newCell); 
            } 
            tempCell->y--;
            //check right
            tempCell->y--;
            if( tempCell->isValid () && sample[tempCell->x][tempCell->y] == 1 )
            {
                // increment timeFrame frame only once
                if(!once)
                {
                    timeFrame = timeFrame + 1;
                    once = true;
                }
                CellCoordinates *newCell = new CellCoordinates;
                sample[tempCell->x][tempCell->y] = 2;
                newCell->x = tempCell->x;
                newCell->y = tempCell->y;
                infected.enqueue(newCell);
            } 

            infected.dequeue();
        }
        
         
        //finished first timeFrame i.e. reached separate
        infected.dequeue();

        if ( !infected.isEmpty() )
        {
            CellCoordinates *newSeparate = new CellCoordinates;
            newSeparate->x = -1;
            newSeparate->y = -1;
            infected.enqueue ( newSeparate );
        }
       

    }

    bool healthyRemains = false;
    std::cout << "The final sample after spread of infection is: " << std::endl;
    for ( int i = 0; i < row ; i++)
    {
        for ( int j = 0; j < column ; j++)
        {
            if ( sample[i][j] == 1)
            healthyRemains = true; 
            std::cout << sample[i][j] << " "; 
                     
        }
        std::cout<<std::endl;
    }
    if ( healthyRemains )
    {
        std::cout << "Not all will be infected" << std::endl;
    }
    else
    {
        std::cout << "The minimum time Frame for total infection is "<< timeFrame << std::endl;
    }

  

    return 0;
}












