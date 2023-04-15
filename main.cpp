#include <iostream>
using namespace std;

int A[12] = {2, 4, 10, 24, 32, 34, 1, 9, 17, 31, 33, 129};

void prinPir() {
  cout << "| ";
  for (int *i = A; i < A + (sizeof(A) / sizeof(A[0])); i++) {
    cout << *i << "| ";
  }
  cout << "\n";
}

void merge(int *p, int *q) {

  int aux{0};
  int *end = q + (q - p);

  while (p < q && q < end) {
    if (*p < *q) {
      p++;
    } else {
      for (int *r = p; r < q; r++) {
        aux = *r;
        *r = *q;
        *q = aux;
      }
      p++;
      q++;
    }
  }
}

int main() {
  prinPir();
  merge(A, A + (sizeof(A) / sizeof(A[0])) / 2);
  prinPir();
}