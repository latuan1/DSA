#include <bits/stdc++.h>

using namespace std;

int countPairs(int a[], int n) {
    int index = 1, countPairs = 0;
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i - 1])index++;
        else if (index >= 2) {
            countPairs = countPairs + index * (index - 1) / 2;
            index = 1;
        }
    }
    if (index >= 2)countPairs = countPairs + index * (index - 1) / 2;
    return countPairs;
}

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << countPairs(a, n);
}
