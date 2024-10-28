#ifndef ORDER_H
#define ORDER_H

#include "Barang.h"

struct Order {
private:
    const Barang* barang; // Ubah ke const Barang*
    int banyakBarang;

public:
    // Konstruktor dengan parameter
    Order(const Barang* barang, int banyakBarang) // Ubah ke const Barang*
        : barang(barang), banyakBarang(banyakBarang) {}

    // Getters dan Setters
    const Barang* getBarang() const { // Ubah ke const Barang*
        return barang;
    }

    int getBanyakBarang() const {
        return banyakBarang;
    }

    void setBarang(const Barang* barang) { // Ubah ke const Barang*
        this->barang = barang;
    }

    void setBanyakBarang(int banyakBarang) {
        this->banyakBarang = banyakBarang;
    }
};

#endif