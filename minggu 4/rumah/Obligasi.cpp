#include "Obligasi.h"
#include "Pacilnomo.h"

Obligasi::Obligasi(std::string nama, std::string jenis, int jumlah, double harga, double bunga, int maturity)
    : Aset(nama, jenis, jumlah, harga), bunga(bunga), maturity(maturity), matured(false) {}

void Obligasi::nextYear(Pacilnomo& pacilnomo) {
    if (maturity > 0) {
        maturity--;
        if (maturity == 0) {
            matured = true;
        }
    }
}

std::string Obligasi::toString() const {
    std::stringstream ss;
    ss << "- OBL\n";
    ss << "  Tipe: Obligasi\n";
    ss << "  Harga: " << std::fixed << std::setprecision(2) << getHarga() << "\n";
    ss << "  Jumlah: " << getJumlah() << "\n";
    ss << "  Bunga: " << getBunga() << "\n";
    ss << "  Jatuh Tempo: " << (matured ? "true" : "false") << "\n";
    return ss.str();
}