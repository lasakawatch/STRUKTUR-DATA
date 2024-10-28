#ifndef KASIR_H
#define KASIR_H

#include "Pelanggan.h"
#include <iostream> // Tambahkan header <iostream>

struct Kasir {
    static void kasir(Pelanggan& K) {
        if (K.getKeranjang().empty()) {
            std::cout << "Maaf tidak ada barang di keranjang " << K.getNama() << std::endl;
            return;
        }

        int totalHarga = K.totalHargaBarang();
        if (K.getUang() < totalHarga) {
            std::cout << "Maaf " << K.getNama() << " tidak memiliki cukup uang\n";
            return;
        }

        std::cout << "Pembelian " << K.getNama() << " berhasil:\n";
        for (const auto& order : K.getKeranjang()) {
            std::cout << "* " << order.getBarang()->getNama() << " " 
                      << order.getBanyakBarang() << " = " 
                      << order.getBarang()->getHarga() * order.getBanyakBarang() << std::endl;
        }

        std::cout << "* Total Belanjaan = " << totalHarga << std::endl;
        K.setUang(K.getUang() - totalHarga);
        std::cout << "* Sisa Uang = " << K.getUang() << std::endl;

        // Reset keranjang setelah pembelian
        K.resetKeranjang();
    }
};

#endif 