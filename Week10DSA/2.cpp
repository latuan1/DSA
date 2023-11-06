#include <iostream>
#include <vector>

using namespace std;

int maxProfit(int weight[], int profit[], int n, int capacity) {
    int table[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                table[i][j] = 0;
            } else if (weight[i - 1] <= j) {
                table[i][j] = max(profit[i - 1] + table[i - 1][j - weight[i - 1]], table[i - 1][j]);
            } else {
                table[i][j] = table[i - 1][j];
            }
        }
    }
    return table[n][capacity];
}

int main() {
    int n;
    cin >> n;
    int weight[n];
    int profit[n];
    for (int i = 0 ; i < n; i++) {
        cin >> weight[i] >> profit[i];
    }
    int capacity;
    cin >> capacity;
    cout << maxProfit(weight, profit, n, capacity);
}
