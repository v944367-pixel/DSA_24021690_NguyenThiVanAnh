#include <iostream>
using namespace std;

void merge(int a[], int head, int mid, int tail) {
    int b[100];
    int c[100];
    for (int i = head; i <= mid; i++) {
        b[i] = a[i];
    }
    for (int i = mid + 1; i <= tail; i++) {
        c[i] = a[i];
    }

    int i = head;
    int j = mid + 1;
    int k = head;

  while (i <= mid && j <= tail) {
        if (b[i] <= c[j]) {
            a[k] = b[i];
            i++;
        } else {
            a[k] = c[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        a[k] = b[i];
        i++;
        k++;
    }

    while (j <= tail) {
        a[k] = c[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int head, int tail) {
    if (head < tail) {
        int mid = (head + tail) / 2;

        mergeSort(a, head, mid);
        mergeSort(a, mid + 1, tail);

        merge(a, head, mid, tail);
    }
}
