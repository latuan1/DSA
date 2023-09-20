#include <iostream>

using namespace std;

struct dNode {
    int data;
    dNode* next;
    dNode* prev;

    dNode(int _data) {
        data = _data;
        next = NULL;
        prev = NULL;
    }
};

struct dLinkedList {
    dNode* head;
    dNode* tail;

    dLinkedList() {
        head = NULL;
        tail = NULL;
    }

    void insert_node(int node_data) {
        dNode* node = new dNode(node_data);

        if (!head) {
            head = node;
        } else {
            tail->next = node;
            node->prev = tail;
        }

        tail = node;
    }
};

int count_triplets(dNode* head) {
    dNode* p = head;
    int counT = 0;
    while (p->next->next != NULL) {
        if (p->data + p->next->data + p->next->next->data == 0) counT++;
        p = p->next;
    }
    return counT;
}

int main() {
    int n;
    cin >> n;
    dLinkedList* llist = new dLinkedList();
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        llist->insert_node(input);
    }
    cout << count_triplets(llist->head);
}
