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

#include <iostream> // Include the iostream library for input/output operations

using namespace std; // Use the standard namespace

int main() {
    int n, i;      // Declare n for the number of elements, i for loop counter
    int max;        // Declare max to store the maximum value
    int *ptr, *ptrMax; // Declare pointers ptr and ptrMax

    cout << "Masukkan jumlah nilai: "; // Prompt the user to enter the number of values
    cin >> n;                         // Read the number of values from the user

    int data[n]; // Declare a variable-length array to store the data (Note: VLAs are non-standard)

    // Input data
    for (i = 0; i < n; i++) {
        cout << "Masukkan nilai ke-" << i + 1 << ": "; // Prompt for each value
        cin >> data[i];                               // Read and store each value in the array
    }

    // Initialize pointer and maximum value
    ptr = data;     // Point ptr to the first element of the array
    ptrMax = ptr;    // Point ptrMax to the first element (initial assumption for maximum)
    max = *ptr;    // Initialize max with the value of the first element

    // Find the maximum value
    for (i = 1; i < n; i++) {
        ptr++;          // Move ptr to the next element
        if (*ptr > max) {  // Check if the current element is greater than the current maximum
            max = *ptr;    // Update max with the new maximum value
            ptrMax = ptr;   // Update ptrMax to point to the new maximum element
        }
    }

    // Display the maximum value and its address
    cout << "Nilai maksimum: " << max << endl;                // Print the maximum value
    cout << "Alamat nilai maksimum: " << (void*)ptrMax << endl; // Print the address of the maximum value (casted to void*)

    return 0; // Indicate successful program execution
}