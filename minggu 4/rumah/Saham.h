#ifndef SAHAM_H
#define SAHAM_H

#include "Aset.h"

class Saham : public Aset {
private:
    double dividen;
    double pertumbuhan;

    void grow();

public:
    Saham(std::string nama, std::string jenis, int jumlah, double harga, double pertumbuhan, double dividen);
    void nextYear(Pacilnomo& pacilnomo) override;
    std::string toString() const override;
    double getDividen() const { return dividen; } // Fungsi getter untuk dividen
};

#endif // SAHAM_H