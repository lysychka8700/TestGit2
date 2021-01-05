#include <stdio.h>
#include <locale.h>

void func(char[]);

int main() {
    setlocale(LC_ALL, "Rus");
    int digit;
    printf("Ведите число\n");
    scanf("%d", &digit);
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


    func(numberStr[0][thousands - 1]);
    func(numberStr[1][hundreds - 1]);
    if (dozens == 1) {
        func(numberStr[3][single - 1]);
    }
    else {
        func(numberStr[2][dozens - 1]);
        func(numberStr[4][single - 1]);
    }

    return 0;
}

void func(char word[]) {

    int i = 0;

    while (word[i] != '\0') {
        printf("%c", word[i]);
        i++;
    }
}