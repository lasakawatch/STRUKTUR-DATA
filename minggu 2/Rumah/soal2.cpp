#include <iostream>

using namespace std;

int main() {
    int n, i, max, *ptr, *ptrMax;

    cout << "Masukkan jumlah nilai: ";
    cin >> n;

    int data[n]; // Array untuk menyimpan data

    // Input data
    for (i = 0; i < n; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": ";
        cin >> data[i];
    }

    // Inisialisasi pointer dan nilai maksimum
    ptr = data; // Pointer menunjuk ke elemen pertama array
    ptrMax = ptr; // Pointer untuk menyimpan alamat nilai maksimum
    max = *ptr; // Asumsikan nilai pertama adalah maksimum

    // Mencari nilai maksimum
    for (i = 1; i < n; i++) {
        ptr++; // Pindahkan pointer ke elemen berikutnya
        if (*ptr > max) { // Jika nilai saat ini lebih besar dari maksimum
            max = *ptr; // Update nilai maksimum
            ptrMax = ptr; // Simpan alamat nilai maksimum
        }
    }

    // Menampilkan nilai maksimum dan alamatnya
    cout << "Nilai maksimum: " << max << endl;
    cout << "Alamat nilai maksimum: " << (void*)ptrMax << endl;

    return 0;
}