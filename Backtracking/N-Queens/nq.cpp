#include <iostream>
#include <math.h>
#include <stdio.h>

using namespace std;

// Testing using Version Control.

int board[20], c;

int main() {
  int n;
  void queen(int row, int n);

  cout << " - N Queens Problem Using Backtracking -";
  cout << "\n\nEnter number of Queens:";
  cin >> n;
  queen(1, n);
  cout << endl;
  return 0;
}

void print(int n) {
  int i, j;
  cout << "\n\nSolution" << ++c << "\n\n";

  for (i = 1; i <= n; ++i)
    cout << "\t" << i;

  for (i = 1; i <= n; ++i) {
    cout << "\n\n" << i;
    for (j = 1; j <= n; ++j) {
      if (board[i] == j)
        cout << "\tQ";
      else
        cout << "\t-";
    }
  }
}

int place(int row, int column) {
  int i;
  for (i = 1; i <= row - 1; ++i) {
    if (board[i] == column)
      return 0;
    else if (abs(board[i] - column) == abs(i - row))
      return 0;
  }

  return 1;
}

void queen(int row, int n) {
  int column;
  for (column = 1; column <= n; ++column) {
    if (place(row, column)) {
      board[row] = column;
      if (row == n) // dead end
        print(n);
      else
        queen(row + 1, n);
    }
  }
}
