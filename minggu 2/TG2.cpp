#include <iostream>
#include <string>

using namespace std;

int main() {
    string str = "Satu string.";
    char* ptr = &str[0]; // Pointer ke awal string

    // Mencetak huruf pada indeks 0, lokasi pointer, dan huruf 'g' dalam satu baris
    cout << *ptr << " " << *ptr << " " << *(ptr + 6) << endl;


    ptr += 2; // Perbarui pointer (pointer + 2)

    // Mencetak pointer (setelah diperbarui) dan huruf 'r' dan 'u' pada baris berbeda
    cout << *ptr << endl; 
    cout << *(ptr + 4) << endl;
    cout << *(ptr + 5) << endl;


    return 0;
}