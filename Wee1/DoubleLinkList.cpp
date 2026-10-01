#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* taoNode(int x) {
    Node* p = new Node;
    p->data = x;
    p->prev = NULL;
    p->next = NULL;
    return p;
}

// 1. TRUY CAP VA DUYET
int truyCap(Node* head, int pos) {
    Node* p = head;
    for (int i = 0; i < pos && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) return -1;
    return p->data;
}

void duyetXuoi(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void duyetNguoc(Node* tail) {
    Node* p = tail;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

// 2. CHEN PHAN TU
void chenDau(Node*& head, Node*& tail, int x) {
    Node* p = taoNode(x);
    if (head == NULL) {
        head = tail = p;
    } else {
        p->next = head;
        head->prev = p;
        head = p;
    }
}

void chenCuoi(Node*& head, Node*& tail, int x) {
    Node* p = taoNode(x);
    if (tail == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

void chenGiua(Node*& head, Node*& tail, int pos, int x) {
    if (pos <= 0 || head == NULL) {
        chenDau(head, tail, x);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) {
        chenCuoi(head, tail, x);
        return;
    }
    Node* p = taoNode(x);
    p->prev = curr->prev;
    p->next = curr;
    curr->prev->next = p;
    curr->prev = p;
}

// 3. XOA PHAN TU
void xoaDau(Node*& head, Node*& tail) {
    if (head == NULL) return;
    Node* temp = head;
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

void xoaCuoi(Node*& head, Node*& tail) {
    if (tail == NULL) return;
    Node* temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

void xoaGiua(Node*& head, Node*& tail, int pos) {
    if (head == NULL) return;
    if (pos == 0) {
        xoaDau(head, tail);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos && curr != NULL; i++) {
        curr = curr->next;
    }
    if (curr == NULL) return;
    if (curr == tail) {
        xoaCuoi(head, tail);
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    chenDau(head, tail, 10);
    chenCuoi(head, tail, 40);
    chenGiua(head, tail, 1, 20);
    chenCuoi(head, tail, 50);

    cout << "Duyet xuoi: ";
    duyetXuoi(head);

    cout << "Duyet nguoc: ";
    duyetNguoc(tail);

    cout << "Phan tu vi tri 2: " << truyCap(head, 2) << endl;

    xoaDau(head, tail);
    xoaGiua(head, tail, 1);
    xoaCuoi(head, tail);

    cout << "Sau khi xoa: ";
    duyetXuoi(head);

    return 0;
}
