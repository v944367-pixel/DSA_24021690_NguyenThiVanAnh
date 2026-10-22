#include <iostream>
#include "List.h"
using namespace std;

struct Queue {
    List a;

    bool isEmpty() {
        return a.size == 0;
    }

    void push(int x) {
        chenCuoi(a, x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        int val = truyCap(a, 0);
        xoaDau(a);
        return val;
    }

    int front() {
        if (isEmpty()) {
            cout << "Queue rong" << endl;
            return -1;
        }
        return truyCap(a, 0);
    }
};
