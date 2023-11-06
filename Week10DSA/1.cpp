#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct item {
    int weight;
    int profit;
};

bool compareItems(const item& a, const item& b) {
    return 1.0 * a.profit / a.weight > 1.0 * b.profit / b.weight;
}

vector<item> selectedItem(item items[], int n, int capacity) {
    vector<item> selected;
    sort(items, items + n, compareItems);
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            selected.push_back(items[i]);
            capacity = capacity - items[i].weight;
        } else {
            break;
        }
    }
    return selected;
}

int main() {
    int n;
    cin >> n;
    item items[n];
    for (int i = 0 ; i < n; i++) {
        int a, b;
        cin >> a >> b;
        items[i].weight = a;
        items[i].profit = b;
    }
    int capacity;
    cin >> capacity;
    vector<item> selected = selectedItem(items, n, capacity);
    for (int i = 0; i < selected.size(); i++) {
        cout << selected[i].weight << " ";
    }
}
