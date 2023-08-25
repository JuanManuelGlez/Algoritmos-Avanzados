//Juan Manuel González - A00572003
//Daniel Gutierrez Gomez - A01068056
//TC2038
//Merge sort algorithm

#include <bits/stdc++.h>
using namespace std;

void merge(int array[], int const left, int const mid, int const right){
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo =right - mid;


// Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    //Copy data to temp arrays leftArray[] and rightArray[]
    for (int i=0; i<subArrayOne; i++){
        leftArray[i] = array[left + i];
    }
    for (int j=0; j<subArrayTwo; j++){
        rightArray[j] = array[mid + 1 + j];
    }

    auto indexOfSubArrayOne = 0, //Initial index of first sub-array
         indexOfSubArrayTwo = 0; //Initial index of second sub-array
    int indexOfMergedArray = left; //Initial index of merged array
    //Merge temp arrays back into array[left..right]
    while ()



};

int main (int argc, char *argv[]){


}