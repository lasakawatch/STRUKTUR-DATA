#include <iostream>

using namespace std;
struct Pasangan {
  int i;
  int j;
};
int hitungPasanganOK(int nums[], int panjang) {
  int jumlah = 0;
  Pasangan pasanganOK[10]; 

  for (int i = 0; i < panjang; i++) {
    for (int j = i + 1; j < panjang; j++) {
      if (nums[i] == nums[j]) {
        
        pasanganOK[jumlah].i = i;
        pasanganOK[jumlah].j = j;
        jumlah++; 
      }
    }
  }
  return jumlah;
}
int main() {
  int panjang;

  cout << "Masukkan indeks array: ";
  cin >> panjang;

  int nums[panjang]; 

  cout << "Masukkan elemen array:" << endl;
  for (int i = 0; i < panjang; ++i) {
    cin >> nums[i]; 
  }
  cout << "Output: " << hitungPasanganOK(nums, panjang) << endl;
  return 0;
}