#include "declaraciones.h"
#include "procedimientos.cpp"

void dummmy(int valor){
	cout << "Como prueba se ingresa el " << valor << endl;
}

int main(int argc, char** argv) {

    cout << " " << endl;
//getDigitoMenor
    cout << "----- getDigitoMenor -----" << endl;
    //output 1
	int num;
    cout << "Digite un entero: ";
    cin >> num;
    // Call the getDigitoMenor from procedimientos.cpp
    int lowest = getDigitoMenor(num);
    cout << "El menor digito es: " << lowest << endl;

    //output 2
    int num2;
    cout << "Digite un entero: ";
    cin >> num2;
    // Call the getDigitoMenor from procedimientos.cpp
    int lowest2 = getDigitoMenor(num2);
    cout << "El menor digito es: " << lowest2 << endl;

    //output 3
    int num3;
    cout << "Digite un entero: ";
    cin >> num3;
    // Call the getDigitoMenor from procedimientos.cpp
    int lowest3 = getDigitoMenor(num3);
    cout << "El menor digito es: " << lowest3 << endl;
    
    cout << " " << endl;

//getMayor
    cout << "----- getMayor -----" << endl;
    int arr[] = {5, 3, 8, 1, 7, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    // Call the getMayor function from procedimientos.cpp
    int max = getMayor(arr, size);
    cout << "el valor maximo del primer arreglo es: " << max << endl;

    int arr_2[] = {5, 3, 81, 11, 0};
    int size_2 = sizeof(arr_2) / sizeof(arr_2[0]);
    // Call the getMayor function from procedimientos.cpp
    int max2 = getMayor(arr_2, size_2);
    cout << "el valor maximo del segundo arreglo es: " << max2 << endl;

    int arr_3[] = {9, 1002, 81, 11, 0, 3, 0, 10};
    int size_3 = sizeof(arr_3) / sizeof(arr_3[0]);
    // Call the getMayor function from procedimientos.cpp
    int max3 = getMayor(arr_3, size_3);
    cout << "el valor maximo del segundo arreglo es: " << max3 << endl;

    cout << " " << endl;
    
//invertirArreglo
    cout << "----- invertirArreglo -----" << endl;
    int arrI[] = {1, 2, 3, 4, 5}; // declare an array of integers
    int n = sizeof(arrI) / sizeof(arrI[0]); // calculate the length of the array using the sizeof operator and store it in a variable
    cout << "Arreglo original 1: ";
    for (int i = 0; i < n; i++) { // iterate over each element of the array
        cout << arrI[i] << " "; // print every element of the original array
    }
    invertirArreglo(arrI, n); // call the invertArray function that is stored in procedimientos.cpp
    cout << "\nArreglo invertido 1: ";
    for (int i = 0; i < n; i++) { // iterate over each element of the array
        cout << arrI[i] << " "; // print out the value of the reversed array
    }
    cout << endl;

    //output 2
    int arrI2[] = {10, 20, 30, 40}; // declare an array of integers
    int n2 = sizeof(arrI2) / sizeof(arrI2[0]); // calculate the length of the array using the sizeof operator and store it in a variable
    cout << "Arreglo original 2: ";
    for (int i = 0; i < n2; i++) { // iterate over each element of the array
        cout << arrI2[i] << " "; // print every element of the original array
    }
    invertirArreglo(arrI2, n2); // call the invertArray function that is stored in procedimientos.cpp
    cout << "\nArreglo invertido 2: ";
    for (int i = 0; i < n2; i++) { // iterate over each element of the array
        cout << arrI2[i] << " "; // print out the value of the reversed array
    }
    cout << endl;

    //output 3
    int arrI3[] = {10, 20, 30, 40}; // declare an array of integers
    int n3 = sizeof(arrI3) / sizeof(arrI3[0]); // calculate the length of the array using the sizeof operator and store it in a variable
    cout << "Arreglo original 2: ";
    for (int i = 0; i < n3; i++) { // iterate over each element of the array
        cout << arrI3[i] << " "; // print every element of the original array
    }
    invertirArreglo(arrI3, n3); // call the invertArray function that is stored in procedimientos.cpp
    cout << "\nArreglo invertido 2: ";
    for (int i = 0; i < n3; i++) { // iterate over each element of the array
        cout << arrI3[i] << " "; // print out the value of the reversed array
    }
    cout << endl;

    cout << " " << endl;



//concatenarArreglos
    cout << "----- concatenarArreglos -----" << endl;
    //output 1
    cout << "ejemplo 1: ";
    int arr1[] = {1, 2, 3}; // define an example array
    int arr2[] = {4, 5, 6, 7}; // define another example array
    int size_arr1 = sizeof(arr1) / sizeof(arr1[0]); //define size of example array 1
    int size_arr2 = sizeof(arr2) / sizeof(arr2[0]); //define size of example array 2
    concatenarArreglos(arr1, size_arr1, arr2, size_arr2); // call the concatenateArrays function with the example arrays as input parameters    

    //output 2
    cout << "ejemplo 2: ";
    int arr1_2[] = {10}; 
    int arr2_2[] = {41, 52}; 
    int size_arr1_2 = sizeof(arr1_2) / sizeof(arr1_2[0]); 
    int size_arr2_2 = sizeof(arr2_2) / sizeof(arr2_2[0]); 
    concatenarArreglos(arr1_2, size_arr1_2, arr2_2, size_arr2_2);

    //output 3
    cout << "ejemplo 3: ";
    int arr1_3[] = {1, 10, 100, 1000, 10000, 100000}; 
    int arr2_3[] = {1, 22, 333, 4444, 56789}; 
    int size_arr1_3 = sizeof(arr1_3) / sizeof(arr1_3[0]); 
    int size_arr2_3 = sizeof(arr2_3) / sizeof(arr2_3[0]); 
    concatenarArreglos(arr1_3, size_arr1_3, arr2_3, size_arr2_3);

	dummy(10);
	dummy(20);
	return 0;
}
