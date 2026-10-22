#include <iostream>
#include "LinkList.h"
using namespace std;

struct Stack {
    Node* head = NULL;

    bool isEmpty() {
        return head == NULL;
    }

    void push(int x) {
        chenDau(head, x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        int val = head->data;
        xoaDau(head); 
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        return head->data; 
    }
};
