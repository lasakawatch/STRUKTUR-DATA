#ifndef OBLIGASI_H
#define OBLIGASI_H

#include "Aset.h"

class Obligasi : public Aset {
private:
    double bunga;
    int maturity;
    bool matured;

public:
    Obligasi(std::string nama, std::string jenis, int jumlah, double harga, double bunga, int maturity);
    void nextYear(Pacilnomo& pacilnomo) override;
    std::string toString() const override;
    bool isMatured() const { return matured; }
    double getBunga() const { return bunga; } 
};

#endif // OBLIGASI_H