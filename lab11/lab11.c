#include <stdio.h>
#include <stdlib.h>
#define N 11

int size_of_seq(const int* arr);

int* max_seq(const int* arr, int count_of_seq);

int main() {
    int sending_arr[N] = { 1, 4, -2, 3, 5, 7, -2, 12, 4, 3, 2 };
    int count_of_seq = size_of_seq(sending_arr);

    int* result = max_seq(sending_arr, count_of_seq);

    return 0;
}

int size_of_seq(const int* arr) {
    int count = 1;
    for (int i = 0; i < N; i++) {
        while (arr[i] < arr[i + 1]) {
            i++;
        }
        if (arr[i] > arr[i + 1]) {
            i++;
            count++;
        }

    }

    return count;
}

int* max_seq(const int* arr, int count_of_seq) {

    int index = 0;
    int count = 1;
    int* info_array = (int*)malloc(count_of_seq * 2 * sizeof(int));


    for (int i = 0, j = 0; i < N; i++) {

        index = i;
        while (arr[i] < arr[i + 1]) {
            count++;
            i++;
        }

        if (arr[i] > arr[i + 1]) {         
            info_array[j] = index;
            info_array[j + 1] = count;

            j += 2;
            count = 1;
        }
        else
            i++;
    }

    int temp_count = 0;

    for (int k = 0; k < count_of_seq * 2; k += 2) {
        if (info_array[k + 1] > temp_count) {
            temp_count = info_array[k + 1];
            index = k;
        }
    }

    int* result = (int*)malloc(info_array[index + 1] * sizeof(int));

    for (int k = info_array[index], i = 0; k < info_array[index] + info_array[index + 1]; k++, i++) {
        result[i] = arr[k];
    }

    printf("\n");
    for (int i = 0; i < info_array[index + 1]; i++) {
        printf("%d ", result[i]);
    }
    return result;
}