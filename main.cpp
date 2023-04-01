#include <iostream>
using namespace std;

int A[8] = { 2,4,10,24,1,9,17,129 };

void prin() {
    for (int i{ 0 }; i < 8; i++) {
        cout << A[i] << " | ";
    }
    cout << "\n";
}

void merge(int *p, int *q) {
    
    int aux{ 0 };
    int* end = q+(q-p);
    int* r = p;
    int* p2 = &(*p);
    cout << " p = " << p << " ;q=" << q << " ;end= " << end << " ;r= " << r<< "\n";
    for (; q < end; q++) {
        for (; p < q; p++) {

            if (*p > *q) {

                cout << "p <-> q" << "\n";
                cout << *p << " <-> " << *q << "\n";
                    
                    aux = *p;
                    *p = *q;
                    *q = aux;
                    prin();
                for (int* r = p + 1; r < q; r++) {

                    cout << "*r <-> *q\n";
                    cout << *r << " <-> " << *q << "\n";
                    
                    cout << "r++\n";
                    aux = *r;
                    *r = *q;
                    *q = aux;
                    prin();
                }

            }
            cout << "p++\n";
            cout << "p apunta a = " << *p << "\n";
        }
        cout << "p apunta a = " << *p << "\n";
        cout << "q apunta a = " << *q << "\n";
        p = p - (end - q);
        cout << "p apunta a = " << *p << "\n";
        cout << "q++\n";
    }

}


int main()
{
    prin();
    //int* p = A;
    //int* q = A + 4;
    merge(A, A+(sizeof(A)/sizeof(A[0]))/2);
    prin();

}
