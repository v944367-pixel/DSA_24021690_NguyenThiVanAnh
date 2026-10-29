#include <iostream>

using namespace std;

int partition(int a[], int head, int tail) {
    int pivot = a[head];
    for (int i = head + 1, j = tail; ; ) {
        for (; i <= tail; i++) {
            if (a[i] > pivot) {
                break;
            }
        }
        for (; j >= head + 1; j--) {
            if (a[j] < pivot) {
                break;
            }
        }
        if (i >= j) {
            swap(a[head], a[j]);
            return j;
        }
      
        swap(a[i], a[j]);
        i++;
        j--;
    }
}
void quickSort(int a[], int head, int tail) {
    if (head < tail) {
        int pi = partition(a, head, tail);

        quickSort(a, head, pi - 1);
        quickSort(a, pi + 1, tail);
    }
}
