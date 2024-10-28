#ifndef ASET_H
#define ASET_H

#include <string>
#include <iomanip>

class Pacilnomo;

class Aset {
protected:
    std::string nama;
    std::string jenis;
    int jumlah;
    double harga;

public:
    Aset(std::string nama, std::string jenis, int jumlah, double harga)
        : nama(nama), jenis(jenis), jumlah(jumlah), harga(harga) {}

    std::string getNama() const { return nama; }
    std::string getJenis() const { return jenis; }
    double getHarga() const { return harga; }
    int getJumlah() const { return jumlah; }

    virtual void nextYear(Pacilnomo& pacilnomo) = 0;
    virtual std::string toString() const = 0;

    void addToEarnings(Pacilnomo& pacilnomo, double jumlah);
};

#endif // ASET_H