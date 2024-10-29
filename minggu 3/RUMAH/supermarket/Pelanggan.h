#ifndef PELANGGAN_H
#define PELANGGAN_H

#include <string>
#include <vector>
#include "Barang.h"
#include "Order.h"

struct Pelanggan {
private:
    std::string nama;
    int uang;
    std::vector<Order> keranjang;
    int kapasitasKeranjang = 5000;
    int beratKeranjang = 0; 

public:
    // Konstruktor default (tambahkan ini)
    Pelanggan() = default;

    // Konstruktor dengan parameter
    Pelanggan(const std::string& nama, int uang, int kapasitas)
        : nama(nama), uang(uang), kapasitasKeranjang(kapasitas) {}

    std::string addBarang(const Barang& barang, int banyakBarang) {
        if (!barang.cekStock(banyakBarang)) {
            return nama + " gagal menambahkan " + std::to_string(banyakBarang) + " " + barang.getNama() 
                   +  ", karena stok kurang\n";
        }

        int beratBarangTotal = barang.getBeratBarang() * banyakBarang;
        if (beratKeranjang + beratBarangTotal > kapasitasKeranjang) {
            int banyakBarangMax = (kapasitasKeranjang - beratKeranjang) / barang.getBeratBarang();
            if (banyakBarangMax > 0) {
                beratKeranjang += barang.getBeratBarang() * banyakBarangMax;
                tambahKeKeranjang(barang, banyakBarangMax);
                return nama + " berhasil menambahkan " + std::to_string(banyakBarangMax) + " " + barang.getNama() + "\n";
            } else {
                return nama + " gagal menambahkan " + std::to_string(banyakBarang) + " " + barang.getNama()
                    + ", karena melebihi kapasitas keranjang\n"; 
            }
        } else {
            beratKeranjang += beratBarangTotal;
            tambahKeKeranjang(barang, banyakBarang);
            return nama + " berhasil menambahkan " + std::to_string(banyakBarang) + " " + barang.getNama() + "\n";
        }
    }
    
    void tambahKeKeranjang(const Barang& barang, int banyakBarang) {
        bool barangAda = false;
        for (auto& order : keranjang) {
            if (order.getBarang()->getNama() == barang.getNama()) {
                order.setBanyakBarang(order.getBanyakBarang() + banyakBarang);
                barangAda = true;
                break;
            }
        }

        if (!barangAda) {
            keranjang.push_back(Order(&barang, banyakBarang));
        }
    }


    int totalHargaBarang() const {
        int totalHarga = 0;
        for (const auto& order : keranjang) {
            totalHarga += order.getBarang()->getHarga() * order.getBanyakBarang();
        }
        return totalHarga;
    }

    std::string cekUang() const {
        return "Uang " + nama + " sekarang " + std::to_string(uang) + "\n";
    }

    // Getters dan Setters
    std::string getNama() const {
        return nama;
    }

    void setNama(const std::string& nama) {
        this->nama = nama;
    }

    int getUang() const {
        return uang;
    }

    void setUang(int uang) {
        this->uang = uang;
    }

    std::vector<Order> getKeranjang() const {
        return keranjang;
    }

    void resetKeranjang() {
        keranjang.clear();
        beratKeranjang = 0; 
    }
};


#endif 