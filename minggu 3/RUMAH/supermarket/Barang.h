#ifndef BARANG_H 
#define BARANG_H

#include <string>

struct Barang {
private:
    std::string nama;
    int harga;
    int beratBarang;
    int stock;

public:
    // Konstruktor default (tambahkan ini)
    Barang() = default;

    // Konstruktor dengan parameter
    Barang(const std::string& nama, int harga, int beratBarang, int stock)
        : nama(nama), harga(harga), beratBarang(beratBarang), stock(stock) {}

    bool cekStock(int requestedStock) const {
        return stock >= requestedStock;
    }

    // Getters dan Setters
    std::string getNama() const {
        return nama;
    }

    int getStock() const {
        return stock;
    }

    void setStock(int kuantitas) {
        stock = kuantitas;
    }

    int getBeratBarang() const {
        return beratBarang;
    }

    int getHarga() const {
        return harga;
    }
};

#endif 