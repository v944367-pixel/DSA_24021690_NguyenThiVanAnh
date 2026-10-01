#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* taoNode(int x) {
    Node* p = new Node;
    p->data = x;
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

void duyetNguoc(Node* head) {
    if (head == NULL) return;
    duyetNguoc(head->next);
    cout << head->data << " ";
}

// 2. CHEN PHAN TU
void chenDau(Node*& head, int x) {
    Node* p = taoNode(x);
    p->next = head;
    head = p;
}

void chenCuoi(Node*& head, int x) {
    Node* p = taoNode(x);
    if (head == NULL) {
        head = p;
        return;
    }
    Node* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = p;
}

void chenGiua(Node*& head, int pos, int x) {
    if (pos <= 0 || head == NULL) {
        chenDau(head, x);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    Node* p = taoNode(x);
    p->next = curr->next;
    curr->next = p;
}

// 3. XOA PHAN TU
void xoaDau(Node*& head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void xoaCuoi(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* curr = head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }
    delete curr->next;
    curr->next = NULL;
}

void xoaGiua(Node*& head, int pos) {
    if (head == NULL) return;
    if (pos == 0) {
        xoaDau(head);
        return;
    }
    Node* curr = head;
    for (int i = 0; i < pos - 1 && curr->next != NULL; i++) {
        curr = curr->next;
    }
    if (curr->next == NULL) return;
    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

int main() {
    Node* head = NULL;

    chenDau(head, 10);
    chenCuoi(head, 40);
    chenGiua(head, 1, 20);
    chenCuoi(head, 50);

    cout << "Duyet xuoi: ";
    duyetXuoi(head);

    cout << "Duyet nguoc: ";
    duyetNguoc(head);
    cout << endl;

    cout << "Phan tu vi tri 2: " << truyCap(head, 2) << endl;

    xoaDau(head);
    xoaGiua(head, 1);
    xoaCuoi(head);

    cout << "Sau khi xoa: ";
    duyetXuoi(head);

    return 0;
}
