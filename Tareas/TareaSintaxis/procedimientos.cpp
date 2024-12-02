#include "declaraciones.h"

void dummy(int valor){
	cout << "Como prueba se ingresa el " << valor << endl;
}

int getDigitoMenor(int num) {
    int lowest = num % 10; //get the less significant value as the lowest number initially
    while (num > 0) { //loop over the number to find the lowest value until the numer becomes 0
        int digit = num % 10; //set "digit" as the value to compare
        if (digit < lowest) { //gets the last digit of the integer and compares it to the current lowest
            lowest = digit; //if it finds a lower number than the "lowest", it replaces the lowest value
        }
        num /= 10; 
    }
    return lowest;
}

int getMayor(int arr[], int size) { 
    int max = arr[0]; //set the maximium value to the first element (index 0)
    for(int i = 1; i < size; i++) { //starts index at 1, makes sure element index exists and increments index after comparisson
        if(arr[i] > max) { //compare each index element to the current max value
            max = arr[i]; //if it finds a new maximium value, it updates
        }
    }
    return max;
}

void invertirArreglo(int arrI[], int n) {
    int temp;
    for (int i = 0; i < n / 2; i++) { // iterate over the first half of the array
        temp = arrI[i]; // store the value of the current element in a temporary variable 
        arrI[i] = arrI[n - 1 - i]; // swap the value of the current element(i) for the corresponding inverted value; first for last, second for second last, and so on
        arrI[n - 1 - i] = temp; // set the value of the corresponding element from the end of the array to the value of the temporary variable
    }
}

void concatenarArreglos(int* arr1, int size1, int* arr2, int size2) { 
    int* result = new int[size1 + size2]; // allocate memory for a new array 
    // copy elements of the first array into the result array
    for (int i = 0; i < size1; i++) { // iterate over the elements in the first input array
        result[i] = arr1[i]; // copy the element to the corresponding index in the result array
    }
    // copy elements of the second array into the result array, after the first array
    for (int i = 0; i < size2; i++) { // iterate over the elements in the second input array
        result[size1 + i] = arr2[i]; // copy the element to the corresponding index in the result array, offset by the size of the first array
    }
    // print the concatenated array
    cout << "{"; 
    for (int i = 0; i < size1 + size2; i++) { // iterate over the elements in the result array
        if (i < size1 + size2 - 1) { // if this is not the last element
            cout << result[i] << ", "; // output the element and a comma
        } else { // if this is the last element
            cout << result[i]; // output only the element
        }
    }
    cout << "}" << endl; 
    delete[] result; // deallocate the memory used by the result array
}