#include <iostream>

using namespace std;

int Stack[100];
int top = -1;

void push(int x) {
    if (top >= 99) {
        cout << "Full";
    }
    else {
        top++;
        Stack[top] = x;
    }
}

void pop() {
    if (top < 0) {
        cout << "Empty";
    }
    else {
        top--;
    }
}

void print() {
    for (int i = 0; i <= top; i++) {
        cout << Stack[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string selection;
        cin >> selection;
        if (selection == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (selection == "pop") {
            pop();
        }
    }
    print();
}
