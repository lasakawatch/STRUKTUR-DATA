#include <iostream>
using namespace std;

int main() {
  int X = 0;
  int n;

  cout << "Masukkan jumlah operasi: ";
  cin >> n;

  cout << "Masukkan operasi (++X, X++, --X, X--):" << endl;
  for (int i = 0; i < n; ++i) {
    string operasi;
    cin >> operasi;

    if (operasi == "++X" || operasi == "X++") {
      X++;
    } else if (operasi == "--X" || operasi == "X--") {
      X--;
    } else {
      cout << "Operasi tidak valid: " << operasi << endl;
    }
  }
  cout << "Nilai akhir X: " << X << endl;
  return 0;
}