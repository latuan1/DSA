#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node *next;

        Node(int node_data) {
            data = node_data;
            next = nullptr;
        }
};

class SLinkedList {
    public:
        Node *head;

        SLinkedList() {
            this->head = nullptr;
        }

        void print() {
            Node* p = head;
            while (p != NULL) {
                cout << p->data << " ";
                p = p->next;
            }
        }

        void insertNode(int p, int x) {
            Node* newNode = new Node(x);
            if (p == 0) head = newNode;
            else {
                Node* temp = head;
                for (int  i = 1; i < p; i++) temp = temp->next;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }

        void deleteNode(int p) {
            Node* temp = head;
            if (p == 0)head = temp->next;
            else {
                while (p > 1) {
                    temp = temp->next;
                    p--;
                }
            }
            temp->next = temp->next->next;
        }
};

int main() {
    SLinkedList* a = new SLinkedList();
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
            string selection;
        cin >> selection;
        if (selection == "insert") {
            int p, x;
            cin >> p >> x;
            a->insertNode(p, x);
        }
        else if (selection == "delete") {
            int p;
            cin >> p;
            a->deleteNode(p);
        }
    }
    a->print();
}
