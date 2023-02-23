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

void sortByShell(int* arr, int n) {
    for (int dif = n / 2; dif > 0; dif /= 2) {
        for (int i = dif; i < n; i++) {
            for (int j = i; j >= dif && arr[j - dif] > arr[j]; j -= dif) {
                int temp = arr[j];
                arr[j] = arr[j - dif];
                arr[j - dif] = temp;
            }
        }
    }
}

int partOfSort(int* arr, int start, int end) {
    int mid = arr[(start + end) / 2];
    int i = start;
    int j = end;
    while (i <= j) {
        while (arr[i] < mid) {
            i++;
        }
        while (arr[j] > mid) {
            j--;
        }
        if (i >= j) {
            break;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    return j;
}

void quickSort(int* arr, int start, int end) {
    if (start < end) {
        int temp = partOfSort(arr, start, end);
        quickSort(arr, 0, temp);
        quickSort(arr, temp + 1, end);
    }
}

void printSortTypes() {
    cout << "Choose type of sorting array: " << endl;
    cout << "Input 1 to bubble sort" << endl;
    cout << "Input 2 to selection sort" << endl;
    cout << "Input 3 to insert sort" << endl;
    cout << "Input 4 to Shell sort" << endl;
    cout << "Input 5 to quick sort" << endl;
}


int main() {
    int size;
    cout << "Input array length" << endl;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "Input " << i + 1 << ". array element" << endl;
        cin >> arr[i];
    }
    printSortTypes();
    int type;
    cin >> type;

    cout << "Array before sorting: " << endl;
    printArray(arr, size);

    switch (type) {
        case 1:
            sortByBubble(arr, size);
            break;
        case 2:
            sortBySelection(arr, size);
            break;
        case 3:
            sortByInsert(arr, size);
            break;
        case 4:
            sortByShell(arr, size);
            break;
        case 5:
            quickSort(arr, 0, size - 1);
            break;
        default:
            cout << "Incorrect input type" << endl;
    }

    cout << "Array after sorting: " << endl;
    printArray(arr, size);

    delete [] arr;
    return 0;
}

