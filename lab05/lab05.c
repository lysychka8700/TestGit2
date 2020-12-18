#include <stdio.h> 
int main()
{
    int a = 3*4;
    int b = 8*5;
    
    while ( (b>0) && (a>0) ) 
    {
        if (a > b)
         a = a-b;
        else
         b = b-a;
         
        // std::cout << a << ";" << b << std::endl;//
        printf( "%d;%d\n ",a,b ) ;
         
    }
} 