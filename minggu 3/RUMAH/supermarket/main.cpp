#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Barang.h"
#include "Pelanggan.h"
#include "Kasir.h"
#include "Order.h"


Pelanggan* cariPelanggan(const std::vector<Pelanggan>& pelanggan, const std::string& nama) {
    for (const auto& p : pelanggan) {
        if (nama == p.getNama()) {
            return const_cast<Pelanggan*>(&p);
        }
    }
    return nullptr;
}

Barang* cariBarang(const std::vector<Barang>& barang, const std::string& namaBarang) {
    for (const auto& b : barang) {
        if (namaBarang == b.getNama()) {
            return const_cast<Barang*>(&b);
        }
    }
    return nullptr;
}


int main() {
    int N, M;
    std::cin >> N;
    std::vector<Barang> barang; 
    for (int i = 0; i < N; ++i) {
        std::string namaBarang;
        int hargaBarang, beratBarang, stock;
        std::cin >> namaBarang >> hargaBarang >> beratBarang >> stock;
        barang.push_back(Barang(namaBarang, hargaBarang, beratBarang, stock));
    }

    std::cin >> M;
     std::vector<Pelanggan> pelanggan; 
    for (int j = 0; j < M; ++j) {
        std::string namaPelanggan;
        int uang;
        std::cin >> namaPelanggan >> uang;
        pelanggan.push_back(Pelanggan(namaPelanggan, uang, 5000));
    }

    int P;
    std::cin >> P;
    std::cin.ignore(); 
    for (int k = 0; k < P; ++k) {
        std::string command;
        std::getline(std::cin, command); 

        std::istringstream iss(command);
        iss >> command;

        if (command == "ADD") {
            std::string namaPelanggan, namaBarang;
            int banyakBarangDiambil;
            iss >> namaPelanggan >> namaBarang >> banyakBarangDiambil;

            Pelanggan* plg = cariPelanggan(pelanggan, namaPelanggan);
            Barang* brg = cariBarang(barang, namaBarang);
            if (plg && brg) {
                std::cout << plg->addBarang(*brg, banyakBarangDiambil);
            }
        } else if (command == "TOTAL_HARGA") {
            std::string namaPelanggan;
            iss >> namaPelanggan;
            Pelanggan* plg = cariPelanggan(pelanggan, namaPelanggan);
            if (plg) {
                std::cout << "Total harga belanjaan " << plg->getNama() << " adalah " << plg->totalHargaBarang() << std::endl;
            }
        } else if (command == "KASIR") {
            std::string namaPelanggan;
            iss >> namaPelanggan;
            Pelanggan* plg = cariPelanggan(pelanggan, namaPelanggan);
            if (plg) {
                Kasir::kasir(*plg);
            }
        } else if (command == "CEK_UANG") {
            std::string namaPelanggan;
            iss >> namaPelanggan;
            Pelanggan* plg = cariPelanggan(pelanggan, namaPelanggan);
            if (plg) {
                std::cout << plg->cekUang();
            }
        }
    }

    return 0;
}