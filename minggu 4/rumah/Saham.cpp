#include "Saham.h"
#include "Pacilnomo.h"

Saham::Saham(std::string nama, std::string jenis, int jumlah, double harga, double pertumbuhan, double dividen)
    : Aset(nama, jenis, jumlah, harga), pertumbuhan(pertumbuhan), dividen(dividen) {}

void Saham::nextYear(Pacilnomo& pacilnomo) {
    grow();
    harga += harga * pertumbuhan;
}

void Saham::grow() {
    int a = 0x4b;
    int c = 0x4a;
    int m = 2;
    pertumbuhan = ((a * (int)pertumbuhan + c) % m) - 1;
    pertumbuhan = pertumbuhan < 0 ? (int)pertumbuhan % -m : pertumbuhan;
}

std::string Saham::toString() const {
    std::stringstream ss;
    ss << "- SHM\n"; 
    ss << "  Tipe: Saham\n";
    ss << "  Harga: " << std::fixed << std::setprecision(2) << getHarga() << "\n";
    ss << "  Jumlah: " << getJumlah() << "\n";
    ss << "  Dividen: " << getDividen() << "\n";
    ss << "  Pertumbuhan: " << std::fixed << std::setprecision(2) << pertumbuhan << "\n";
    return ss.str();
}