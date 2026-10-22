#include <iostream>
#include "LinkedList.h"
using namespace std;

struct Queue {
    Node* head = NULL;

    bool isEmpty() {
        return head == NULL;
    }

    void push(int x) {
        chenCuoi(head, x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        int val = head->data;
        xoaDau(head);
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        return head->data;
    }
};
