#include <stdio.h> 
int main()
{
    int a = 3*4;
    int b = 8*5;
    do
    {
         if (a > b)
         a = a-b;
        else
         b = b-a;
    }
    while ( (b>0) && (a>0) ) ;
    {
       std::cout << a << ";" << b << std::endl;
        printf( "%d;%d\n ",a,b ) ;
         
    }
} 