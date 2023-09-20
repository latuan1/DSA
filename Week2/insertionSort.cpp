#include <iostream>

using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0 && arr[i] < arr[j - 1])--j;
        int tmp = arr[i];
        for (int k = i; k > j; k--)
            arr[k] = arr[k - 1];
        arr[j] = tmp;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
