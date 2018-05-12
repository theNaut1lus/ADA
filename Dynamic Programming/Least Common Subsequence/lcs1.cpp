#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void longest_common_subsequence_algorithm();
void print_sequence(int a, int b);
int co = 0;
int a, b, c, d;
int temp[30][30];
char first_sequence[30], second_sequence[30], longest_sequence[30][30];


int lcs( char *X, char *Y, int m, int n )
{
   if (m == 0 || n == 0)
     return 0;
   if ((X[m] == Y[n])&&(m>0&&n>0))
   {
     return 1 + lcs(X, Y, m-1, n-1);
   }
   else
     return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int main() {
  cout << "\nEnter the First String:\t";
  cin >> first_sequence;
  cout << "\nEnter the Second String:\t";
  cin >> second_sequence;
  cout << "\nLongest Common Subsequence:\t";
  longest_common_subsequence_algorithm();
  print_sequence(c, d);
  cout << endl;
  if (strlen(second_sequence) > strlen(first_sequence)) {
    co--;
  }
  cout << "Length = " << endl;
  co = lcs(first_sequence,second_sequence,strlen(first_sequence),strlen(second_sequence));
cout << co << endl;
  return 0;
}

void longest_common_subsequence_algorithm() {
  c = strlen(first_sequence);
  d = strlen(second_sequence);
  for (a = 0; a <= c; a++) {
    temp[a][0] = 0;
  }
  for (a = 0; a <= d; a++) {
    temp[0][a] = 0;
  }
  for (a = 1; a <= c; a++) {
    for (b = 1; b <= d; b++) {
      if (first_sequence[a - 1] == second_sequence[b - 1]) {
        co++;
        temp[a][b] = temp[a - 1][b - 1] + 1;
        longest_sequence[a][b] = 'c';
      } else if (temp[a - 1][b] >= temp[a][b - 1]) {
        temp[a][b] = temp[a - 1][b];
        longest_sequence[a][b] = 'u';
      } else {
        temp[a][b] = temp[a][b - 1];
        longest_sequence[a][b] = 'l';
      }
    }
  }
}

void print_sequence(int a, int b) {
  if (a == 0 || b == 0) {
    return;
  }
  if (longest_sequence[a][b] == 'c') {
    print_sequence(a - 1, b - 1);
    cout << first_sequence[a - 1];
  } else if (longest_sequence[a][b] == 'u') {
    print_sequence(a - 1, b);
  } else {
    print_sequence(a, b - 1);
  }
}
