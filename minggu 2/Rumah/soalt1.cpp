#include <iostream>
#include <cstring> 

using namespace std;

int main() {
    int n;
    cout << "================================" << endl;
    cout << "        Soal 1. Tugas Pratikum 2" << endl;
    cout << "                30/9/2024:" << endl;
    cout << "         Naufal Saifullah Yusuf" << endl;
    cout << "================================" << endl;

    cout << "indeks max array: ";
    cin >> n;
    cout << "================================" << endl;
    int nums[n]; 
    cout << "elemen array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cout << "================================" << endl;

    // Mencari jumlah baris yang diperlukan dalam 2D array 
    int maxRowCount = 0;
    for (int i = 0; i < n; ++i) {
        int count = 0;
        for (int j = 0; j < i; ++j) {
            if (nums[i] == nums[j]) {
                count++;
            }
        }
        maxRowCount = max(maxRowCount, count);
    }

    int rowCount = maxRowCount + 1;

    // Membuat 2D array dengan jumlah baris minimum
    int result[rowCount][n];
    memset(result, -1, sizeof(result));  

    int rowTracker[rowCount][n];
    memset(rowTracker, 0, sizeof(rowTracker)); 

    // Mengisi 2D array
    for (int i = 0; i < n; ++i) {
        int j;
        for (j = 0; j < rowCount; ++j) {
            if (rowTracker[j][nums[i]] == 0) {
                result[j][i] = nums[i];
                rowTracker[j][nums[i]] = 1; 
                break;
            }
        }
    }

    // Mencetak 2D array
    cout << "Hasil 2D Array:\n";
    for (int i = 0; i < rowCount; ++i) {
        cout << "[";
        for (int j = 0; j < n; ++j) {
            if (result[i][j] != -1) {
                cout << result[i][j] << " ";
            }
        }
        cout << "]\n";
    }

    return 0;
}