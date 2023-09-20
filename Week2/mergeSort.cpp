#include <iostream>

using namespace std;

int a[1000];

void mergeSort(int arr[], int left, int right) {
	if (left == right) {
		return ;
	}
	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid+1, right);
	int i = left, j = mid + 1;
	int cur = 0;

	while (i <= mid || j <= right) {
		if (i > mid) {
			a[cur++] = arr[j++];
		} else if (j > right) {
			a[cur++] = arr[i++];
		} else if (arr[i] < arr[j]) {
			a[cur++] = arr[i++];
		} else {
			a[cur++] = arr[j++];
		}
	}
	for (int i = 0; i < cur; i++)
		arr[left + i] = a[i];
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    mergeSort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
