#include <iostream>
#include <math.h>
#include <stdlib.h>

int coun = 0;

using namespace std;

void swap(int *xp, int *yp) {
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}
int main() {
  int data[500000], m;
  cout << "Enter no. of elements\t";
  cin >> m;

  for (int c = 0; c < m; c++) {
    data[c] = rand();
  }

  for (int i = 0; i < m - 1; i++) {
    int min = i;
    for (int j = i + 1; j < m; j++) {
      if (data[j] < data[min]) {
        min = j;
      }
    }
    swap(&data[min], &data[i]);
  }
  cout << "sorted array";
  for (int k = 0; k < m; k++) {
    cout << "\t" << data[k];
  }

  return 0;
}
