#include <iostream>

using namespace std;

int Queue[100];
int Front = 0, Rear = -1;

void enQueue(int x) {
    if (Rear >= 99) {
        cout << "Full";
    }
    else {
        Rear++;
        Queue[Rear] = x;
    }
}

void deQueue() {
    if (Front > Rear) {
        cout << "Empty";
    }
    else {
        Front++;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string selection;
        cin >> selection;
        if (selection == "enqueue") {
            int x;
            cin >> x;
            enQueue(x);
        }
        else if (selection == "dequeue") {
            deQueue();
        }
    }
    for (int i = Front; i <= Rear; i++) cout << Queue[i] << " ";
}
