#include <iostream>
using namespace std;

int A[12] = { 2,4,10,24,32,34,1,9,17,31,33,129 };

void prin() {
    cout << "| ";
    for (int i{ 0 }; i < size(A); i++) {
        cout << A[i] << " | ";
    }
    cout << "\n";
}

void merge(int* p, int* q) {

    int aux{ 0 };
    int* end = q + (q - p);
    for (; q < end; q++) {

        for (; p < q; p++) {

            if (*p > *q) {
                aux = *p;
                *p = *q;
                *q = aux;

                for (int* r = p + 1; r < q; r++) {
                    aux = *r;
                    *r = *q;
                    *q = aux;
                }
            }
        }
        p = p - (end - q);
    }
}

int main()
{
    prin();
    merge(A, A + (sizeof(A) / sizeof(A[0])) / 2);
    prin();
}