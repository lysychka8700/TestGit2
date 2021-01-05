#include <stdio.h>

int main() {

    int number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 99999 || number>999999)
    {
        printf("Incorrect: Enter 6 numbers\n\n");
        main();
        
        return 0; 
    }
    

    int firstHalf = number / 1000;
    int secondHalf = number % 1000;

    int firstNumber = firstHalf / 100;
    int secondNumber = firstHalf / 10 % 10;
    int thirdNumber = firstHalf % 100;

    int fourthNumber = secondHalf / 100;
    int fifthNumber = secondHalf / 10 % 10;
    int sixNumber = secondHalf % 100;

    int summFirstHalf = firstNumber + secondNumber + thirdNumber;
    int summSecondHalf = fourthNumber + fifthNumber + sixNumber;

    if (summFirstHalf == summSecondHalf)
    {
        printf("Number is lucky");
    }
    else if (summFirstHalf != summSecondHalf)
    {
        printf("Number is unlucky");
    }

    return 0; 
}
