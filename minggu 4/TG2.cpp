#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;

    cout << "Masukkan jumlah elemen array: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah elemen harus positif!" << endl;
        return 1;
    }

    vector<int> arr(n);

    cout << "Input elm array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int middleIndex = n / 2;

    cout << "Nilai tengah return ke dua dari array: ";
    
    if (n % 2 == 0) { 
        cout << arr[middleIndex] << endl;
    } else {  
        cout << arr[middleIndex - 1] << endl; 
    }

    return 0;
}
