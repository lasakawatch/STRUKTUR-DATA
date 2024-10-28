#ifndef PACILNOMO_H
#define PACILNOMO_H

#include "Aset.h"
#include <string>
#include <iomanip>

class Pacilnomo {
private:
    struct Node {
        Aset* data;
        Node* next;
        Node(Aset* data) : data(data), next(nullptr) {}
    };
    Node* head;
    double earnings;

    void printSeparator() const;
    void daftarAset() const;
    void infoPortofolio() const;
    void nextYear();

public:
    Pacilnomo();
    void addAset(Aset* aset);
    void addToEarnings(double jumlah);
    void run();
};

#endif // PACILNOMO_H