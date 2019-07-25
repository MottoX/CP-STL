#include<iostream>
#include<cassert>

using namespace std;
const int N = 10010;
int heap[N];

void pushDown(int pos, int n) {
    while (pos * 2 + 1 < n) {
        int c = pos * 2 + 1;
        if (c + 1 < n && heap[c + 1] > heap[c])
            c++;
        if (heap[c] <= heap[pos]) break;
        swap(heap[pos], heap[c]);
        pos = c;
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) heap[i] = n - i;
    for (int i = n / 2; i >= 0; i--) pushDown(i, n);
    int SIZE = n;
    while (n > 1) {
        swap(heap[0], heap[n - 1]);
        n--;
        pushDown(0, n);
    }
    for (int i = 1; i < SIZE; i++) assert(heap[i] > heap[i - 1]);
    return 0;
}
