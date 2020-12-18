#include <stdio.h> 
void cycleFor(int a, int b);
int main()
{
    int a = 20, b = 40;
    cycleFor(a, b);

    return 0;
}
void cycleFor(int a, int b)
{
        for (int i = a; i > 0; i--) {
            if (a % i == 0 && b % i == 0) {
                 printf("nod = %d \n",i);
            }
        }
        return;
    }