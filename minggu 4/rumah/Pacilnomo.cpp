#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <limits>
#include "Pacilnomo.h"
#include "Saham.h"
#include "Obligasi.h"

// g++ Aset.cpp Obligasi.cpp Pacilnomo.cpp Saham.cpp -o program 
//./program

Pacilnomo::Pacilnomo() : head(nullptr), earnings(0) {}

void Pacilnomo::printSeparator() const {
    std::cout << "====================================================================" << std::endl;
}

void Pacilnomo::daftarAset() const {
    printSeparator();
    Node* current = head;
    int count = 0;
    while (current != nullptr) {
        std::cout << current->data->toString() << std::endl;
        current = current->next;
        count++;
    }
    std::cout << "Kamu memiliki " << count << " total aset:" << std::endl;
    printSeparator();
}

void Pacilnomo::infoPortofolio() const {
    int jumlahSaham = 0;
    int jumlahObligasi = 0;
    double netWorth = 0; 
    Node* current = head;

    netWorth = 0; // Reset nilai netWorth sebelum perhitungan
    while (current != nullptr) {

    while (current != nullptr) {
        if (current->data->getJenis() == "SAHAM") {
            jumlahSaham++;
        } else if (current->data->getJenis() == "OBLIGASI") {
            jumlahObligasi++;
        }
       netWorth += current->data->getHarga() * current->data->getJumlah(); 
        current = current->next;
    
    }
    }
    printSeparator();
    std::cout << "Info Portofolio\n"
              << "Jumlah Jenis Saham: " << jumlahSaham << "\n"
              << "Jumlah Jenis Obligasi: " << jumlahObligasi << "\n"
              << "Total Nilai Portofolio: " << std::fixed << std::setprecision(2) << netWorth << std::endl;
    printSeparator();
}

void Pacilnomo::nextYear() {
    Node* current = head;
    while (current != nullptr) {
        current->data->nextYear(*this);
        if (current->data->getJenis() == "SAHAM") {
            current->data->addToEarnings(*this, static_cast<Saham*>(current->data)->getDividen() * current->data->getJumlah());
        } else if (current->data->getJenis() == "OBLIGASI") {
            current->data->addToEarnings(*this, static_cast<Obligasi*>(current->data)->getBunga() * current->data->getJumlah());
        }
        current = current->next;
    }
}

void Pacilnomo::addAset(Aset* aset) {
    Node* newNode = new Node(aset);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Pacilnomo::addToEarnings(double jumlah) {
    earnings += jumlah;
}

void Pacilnomo::run() {
    int banyakAset;
    std::cout << "Silakan masukkan banyak aset yang tersedia: ";
    std::cin >> banyakAset;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

   for (int i = 0; i < banyakAset; i++) {
        std::cout << "Aset " << i + 1 << ": ";
        std::string barisInput;
        std::getline(std::cin, barisInput); // Baca seluruh baris input

        std::stringstream ss(barisInput);
        std::string namaAset, jenisAset;
        int jumlah, maturity;
        double harga, pertumbuhan, bunga, dividen;

        // Baca nama aset dan jenis aset terlebih dahulu
        ss >> namaAset >> jenisAset; 

        // Baca data sesuai jenis aset
        if (jenisAset == "SAHAM") {
            ss >> jumlah >> harga >> pertumbuhan >> dividen;
            addAset(new Saham(namaAset, jenisAset, jumlah, harga, pertumbuhan, dividen));
        } else if (jenisAset == "OBLIGASI") {
            ss >> jumlah >> harga >> bunga >> maturity;
            addAset(new Obligasi(namaAset, jenisAset, jumlah, harga, bunga, maturity));
        } else {
            std::cerr << "Error: Jenis aset tidak valid." << std::endl;
            // Tangani error input, misalnya keluar dari loop atau meminta input ulang
        }
}
    
    std::cout << "Selamat datang di...\n"
              << " /$$$$$$$                     /$$ /$$\n"
              << "| $$__  $$                   |__/| $$\n"
              << "| $$  \\ $$ /$$$$$$   /$$$$$$$ /$$| $$ /$$$$$$$   /$$$$$$  /$$$$$$/$$$$   /$$$$$$\n"
              << "| $$$$$$$/|____  $$ /$$_____/| $$| $$| $$__  $$ /$$__  $$| $$_  $$_  $$ /$$__  $$\n"
              << "| $$____/  /$$$$$$$| $$      | $$| $$| $$  \\ $$| $$  \\ $$| $$ \\ $$ \\ $$| $$  \\ $$\n"
              << "| $$      /$$__  $$| $$      | $$| $$| $$  | $$| $$  | $$| $$ | $$ | $$| $$  | $$\n"
              << "| $$     |  $$$$$$$|  $$$$$$$| $$| $$| $$  | $$|  $$$$$$/| $$ | $$ | $$|  $$$$$$/\n"
              << "|__/      \\_______/ \\_______/|__/|__/|__/  |__/ \\______/ |__/ |__/ |__/ \\______/\n\n";

    while (true) {
        std::cout << "Silakan pilih salah satu opsi berikut:\n"
                  << "[1] Daftar aset\n"
                  << "[2] Info portofolio\n"
                  << "[3] Lanjut ke tahun berikutnya\n"
                  << "[*] Keluar\n";
        printSeparator();
        std::cout << "Input: ";
        std::string pilihan;
        std::cin >> pilihan;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (pilihan == "1") {
            daftarAset();
        } else if (pilihan == "2") {
            infoPortofolio();
        } else if (pilihan == "3") {
            nextYear();
            std::cout << "Setahun telah berlalu...\n";
            printSeparator();
        } else {
            std::cout << "Terima kasih telah menggunakan layanan Pacilnomo ~ !\n";
            break;
        }
    }
}

int main() {
    Pacilnomo pacilnomo;
    pacilnomo.run();
    return 0;
}