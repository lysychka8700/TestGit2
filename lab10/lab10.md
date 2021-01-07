#define _CRT_SECURE_NO_WARNINGS

>file main.cpp
>brief Виконання лабораторної роботи 7
>author Lysytsyna Alexandra
>version 1
>date 01.01.2020

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

>Функція для визначення щастливого числа

void checkForLuckyNumber();

>Функція вивода числа у консоль за допомогою масиву

void massive();


>Функція приймає різну кількість параметрів та перевіряє скільки попередніх чисел меньших від поточних
>@param amountOfArgument : кількість параметрів яку приймає функція
>@param ...: змінна кількість int параметрів для перевірки
>@return result: повертає відповідь - скільки попередніх чисел меньших від поточних

int numericalPairСounter(int, ...);


>Головна функція з якої починається робота,запускаємо для перевірки функції за завданням
 
int main(void) {

    setlocale(LC_ALL, "Rus");

    massive();
    printf("\n\nThe number of elements that are less than the next %d\n\n", numericalPairСounter(5, 1, 2, 3, 4, 5));
    checkForLuckyNumber();

    return 0;
}
```
void checkForLuckyNumber() {

    int number = 0;
    printf("Enter a number: ");
    scanf("%d", &number);

    if (number < 99999 || number>999999)
    {
        printf("Incorrect: Enter 6 numbers\n\n");
        checkForLuckyNumber();
        return;
    }
```
```
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

    return;
}
```
```
void massive() {
    int digit;
    printf("Enter a number: ");
    scanf_s("%d", &digit);
    int thousands = digit / 1000;
    int hundreds = digit / 100 % 10;
    int dozens = digit / 10 % 10;
    int single = digit % 10;

    char numberStr[5][9][30] =
    {
      {"Тисяча", " Две тисячи", " Три тисячи"," Четыре тисячи"," Пять тисяч"," Шесть тисяч"," Семь тисяч"," Восемь тисяч"," Девять тисяч"},
      {" сто", " двести", " триста"," четыреста"," пятьсот"," шестьсот"," семьсот"," восемьсот"," девятьсот"},
      {" десять", " двадцать", " тридцать"," сорок"," пятьдесят"," шестдисят"," семдисят"," восимдесят"," девяносто"},
      {" одинадцать", " двенадцать", " тринадцать "," четырнадцать"," пятнадцать"," шестнадцать"," семнадцадь"," восимнадцать"," девятнадцать"},
      {" один", " два", " три "," четыре"," пять"," шесть"," семь"," восемь"," девять"}
    };


    printf("%s", numberStr[0][thousands - 1]);
    printf("%s", numberStr[1][hundreds - 1]);
    if (dozens == 1) {
        printf("%s", numberStr[3][single - 1]);
    }
    else {
        printf("%s", numberStr[2][dozens - 1]);
        printf("%s", numberStr[4][single - 1]);
    }

    return;
}
```
```
int numericalPairСounter(int amountOfArgument, ...)
{
    int result = 0;
    va_list args;
    va_start(args, amountOfArgument);

    int* arr = new int[amountOfArgument];
    for (int i = 0; i < amountOfArgument; ++i)
    {
        arr[i] = va_arg(args, int);
    }
    for (int i = 0; i < amountOfArgument - 1; i++) {
        if (arr[i] < arr[i + 1])
            result++;
    }
    va_end(args);

    return result;
}
```