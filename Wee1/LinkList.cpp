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

// Truy cập phần tử tại chỉ số pos (0, 1, 2, ...)
int truyCap(Node* head, int pos) {
    Node* p = head;
    for (int i = 0; i < pos && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        cout << "INVALID";
        return -1;
    }
    return p->data;
}

// Duyệt xuôi
void duyetXuoi(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

// Duyệt ngược
void duyetNguoc(Node* tail) {
    Node* p = tail;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->prev;
    }
    cout << endl;
}

// Chèn vào đầu danh sách
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

// Chèn vào cuối danh sách
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

// Chèn vào giữa: chèn giá trị x vào vị trí chỉ số pos
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

// Xóa phần tử đầu
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

// Xóa phần tử cuối
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

// Xóa phần tử ở giữa tại vị trí chỉ số pos
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

    chenCuoi(head, tail, 20);
    chenCuoi(head, tail, 40);
    chenDau(head, tail, 10);
    chenGiua(head, tail, 2, 30);
    chenCuoi(head, tail, 50);

    duyetXuoi(head);
    duyetNguoc(tail);

    cout << truyCap(head, 2) << endl;

    xoaDau(head, tail);
    cout << "List sau khii xoa dau :";
    duyetXuoi(head);

    xoaGiua(head, tail, 1);
    cout << "List sau khi xoa giua :";
    duyetXuoi(head);

    xoaCuoi(head, tail); 
    cout << "List sau khi xoa cuoi :";
    duyetXuoi(head);
    duyetNguoc(tail);

    return 0;
}
