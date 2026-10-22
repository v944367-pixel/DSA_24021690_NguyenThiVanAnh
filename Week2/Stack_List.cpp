#include <iostream>
#include "List.h"
using namespace std;

struct Stack {
    List a;
    bool isEmpty() {
        return a.size == 0;
    }

    void push(int x) {
        chenCuoi(a, x);
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        int val = truyCap(a, a.size - 1);
        xoaCuoi(a);
        return val;
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack rong" << endl;
            return -1;
        }
        return truyCap(a, a.size - 1);
    }
};
