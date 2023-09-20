#include <iostream>

using namespace std;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[right];
    while (i <= j) {
        while (arr[i] < pivot)++i;
        while (arr[j] > pivot)--j;
        if (i <= j) {
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    if (left < j)quickSort(arr, left, j);
    if (i < right)quickSort(arr, i, right);
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int left = 0, right = n - 1;
    quickSort(a, left, right);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
