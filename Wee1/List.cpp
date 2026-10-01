#include <iostream>
using namespace std;
struct Node {
  int data;
  Node* next;
  Node* prev;
};

Node* taoNode(int x) {
  Node *p = new Node;
  p -> data = x;
  p -> prev = NULL;
  p -> next = NULL;
  return p;
}
//Ham truy cap phan tu tai vi tri pos...
int truyCap( Node* head, int pos) {
  Node* p = head;
  for(int i = 0; i < pos && p != NULL; i++){
    p = p -> next;
  }
  if( p == NULL) {
    cout << "Invalid" << endl;
    return -1;
  }
  return p->data;
}

//Ham duyet xuoi
void duyetXuoi( Node* head) {
Node* p = head;
while( p != NULL) {
  cout << p -> data << " ";
  p = p -> next;
}
  cout << endl;
}

// Ham duyet nguoc
void duyetNguoc(Node* tail) {
  Node* p = tail;
  while (p != NULL) {
    cout << p -> data << " ";
    p = p -> prev;
  }
  cout << endl;
}

//THAO TAC CHEN
//Chen vao dau list
void chenDau(Node* &head, Node *& tail, int x) {
  Node *p = taoNode(x);
  if(head == NULL) {
    head = tail = p;
  }
  else {
    p -> next = head;
    head -> prev = p;
    head = p;
  }
}

//Chen vao cuoi list
void chenCuoi(Node *&head, Node *&tail, int x) {
    Node *p = taoNode(x);
    if (tail == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        p->prev = tail;
        tail = p;
    }
}

// Chèn vào giữa: chèn x vào sau một Node q
void chenGiua(Node *&tail, Node *q, int x) {
    if (q == NULL) return;
    if (q == tail) {
        chenCuoi(q, tail, x);
        return;
    }

    Node *p = taoNode(x);
    p->next = q->next;
    p->prev = q;
    q->next->prev = p;
    q->next = p;
}

//THAO TAC XOA
// Xoa dau
void xoaDau(Node *&head, Node *&tail) {
    if (head == NULL) return;

    Node *temp = head;
    if (head == tail) { // Danh sách chỉ có đúng 1 phần tử
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

//Xoa cuoi
void xoaCuoi(Node *&head, Node *&tail) {
    if (tail == NULL) return;

    Node *temp = tail;
    if (head == tail) { // Danh sách chỉ có đúng 1 phần tử
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

//Xoa o giua
void xoaNode(Node *&head, Node *&tail, Node *p) {
    if (p == NULL) return;
    if (p == head) {
        xoaDau(head, tail);
        return;
    }
    if (p == tail) {
        xoaCuoi(head, tail);
        return;
    }

    // Nối tắt 2 bên bỏ qua node p
    p->prev->next = p->next;
    p->next->prev = p->prev;
    delete p;
}

int main(){
  Node *head = NULL;
    Node *tail = NULL;

    chenCuoi(head, tail, 20);
    chenCuoi(head, tail, 40);
    chenDau(head, tail, 10);
    chenGiua(tail, head->next, 30);

    duyetXuoi(head);
    duyetNguoc(tail);

    cout << "Phan tu tai vi tri 2: " << truyCap(head, 2) << endl;

    xoaDau(head, tail);
    xoaCuoi(head, tail);
    xoaNode(head, tail, head->next);/

    cout << "List: ";
    duyetXuoi(head);

    return 0;
}
