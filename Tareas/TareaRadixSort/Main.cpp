#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Get the digit at the specified position of a number
int getDigit(int number, int position) {
    int divisor = 1;
    for (int i = 0; i < position; i++) {
        divisor *= 10;
    }
    return (number / divisor) % 10;
}

// Perform Radix Sort on a vector
void radixSort(vector<int>& array) {
    int maxNumber = *max_element(array.begin(), array.end());

    for (int position = 0; maxNumber > 0; position++) {
        vector<queue<int>> queues(10);

        for (int i = 0; i < array.size(); i++) {
            int digit = getDigit(array[i], position);
            queues[digit].push(array[i]);
        }

        int index = 0;
        for (int i = 0; i < queues.size(); i++) {
            while (!queues[i].empty()) {
                array[index] = queues[i].front();
                queues[i].pop();
                index++;
            }
        }

        maxNumber /= 10;
    }
}

int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    vector<int> array(size);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    radixSort(array);

    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

