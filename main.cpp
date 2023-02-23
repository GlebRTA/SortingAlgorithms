#include <iostream>

using namespace std;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void sortByBubble(int* arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void sortBySelection(int* arr, int n) {

    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

}

void sortByInsert(int* arr, int n) {

    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && arr[j] > arr[j + 1]; j--) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
        }
    }
}

void printSortTypes() {
    cout << "Choose type of sorting array: " << endl;
    cout << "Input 1 to bubble sort" << endl;
    cout << "Input 2 to selection sort" << endl;
    cout << "Input 3 to insert sort" << endl;
}


int main() {
    int n;
    cout << "Input array length" << endl;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Input " << i + 1 << ". array element" << endl;
        cin >> arr[i];
    }
    printSortTypes();
    int type;
    cin >> type;

    cout << "Array before sorting: " << endl;
    printArray(arr, 5);
    switch (type) {
        case 1:
            sortByBubble(arr, 5);
            break;
        case 2:
            sortBySelection(arr, 5);
            break;
        case 3:
            sortByInsert(arr, 5);
            break;
        default:
            cout << "Incorrect input type" << endl;
    }

    cout << "Array after sorting: " << endl;
    printArray(arr, 5);

    delete [] arr;
    return 0;
}

