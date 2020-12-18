#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LEN 15

void centralizer(int zap, char strIn[]);

int main() {


    srand(time(NULL));

   
    int x = 34;
    int y = 97;

    int range_for_rand;
    int min_number_of_range;

   
    if ( x < y ){
        range_for_rand = y - x + 1;
        min_number_of_range = x;
    }
    else if ( x > y ){
        range_for_rand = x - y + 1;
        min_number_of_range = y;
    }


    int zap = '_';                          

    const int array_length = 6;
    char strIn[array_length];              


    int i;

    //Generating random elements
    for (i = 0; i < array_length; i++){
        strIn[i] = rand() % range_for_rand + min_number_of_range;
    }
    strIn[array_length] = '\0';


    char strIn2[array_length];
    for (i = 0; i < array_length; i++){
        strIn2[i] = rand() % range_for_rand + min_number_of_range;
    }
    strIn2[array_length] = '\0';

    centralizer(zap, strIn);
    centralizer(zap, strIn2);

    return 0;
}

void centralizer(int zap, char strIn[]){

    char strResult[LEN];

    int lenIn = 0;

    for (int i = 0; ; i++) {        
        if (strIn[i] == '\0') {
            break;
        } else if (strIn[i] != 0) {
            lenIn++;
        }
    }

    int lenZap = LEN - lenIn - 1;   

    int halfLenZap = lenZap / 2;    


    for (int i = 0; i < halfLenZap; i++) {                         
        strResult[i] = zap;
    }

    for (int i = halfLenZap; i < (halfLenZap + lenIn);) {            
        for (int j = 0; j < lenIn; j++) {
            strResult[i] = strIn[j];
            i++;
        }
    }

    for (int i = (halfLenZap + lenIn); i < LEN - 1; i++) {           
        strResult[i] = zap;
    }

    
    if (lenIn % 2 == 0){
        strResult[LEN - 1] = '\0';
    }                                            
    if (lenIn % 2 == 1){
        strResult[LEN - 2] = '\0';
    }


}