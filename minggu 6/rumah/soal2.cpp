#include <iostream>
#include <string>
#include <limits> // Untuk mendapatkan nilai maksimum integer

using namespace std;

struct Node {
    int nomor_ka;
    string tujuan_akhir;
    int jam_keberangkatan;
    int harga_tiket;
    Node* prev;
    Node* next;
};

class JadwalKereta {
private:
    Node* head;
    Node* tail;

public:
    JadwalKereta() {
        head = nullptr;
        tail = nullptr;
    }

    void tambahJadwal(int nomor_ka, string tujuan_akhir, int jam_keberangkatan, int harga_tiket) {
        Node* newNode = new Node;
        newNode->nomor_ka = nomor_ka;
        newNode->tujuan_akhir = tujuan_akhir;
        newNode->jam_keberangkatan = jam_keberangkatan;
        newNode->harga_tiket = harga_tiket;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void infoTujuan() {
        Node* temp = head;
        bool tujuanAda[100] = {false}; // Asumsi maksimal 100 tujuan unik
        int jumlahTujuan = 0;

        while (temp != nullptr) {
            if (!tujuanAda[temp->tujuan_akhir[0]]) { 
                tujuanAda[temp->tujuan_akhir[0]] = true;
                jumlahTujuan++;
            }
            temp = temp->next;
        }

        if (jumlahTujuan > 0) {
            cout << "KA di stasiun ini memiliki tujuan akhir:" << endl;
            temp = head;
            while (temp != nullptr) {
                if (tujuanAda[temp->tujuan_akhir[0]]) {
                    cout << temp->tujuan_akhir << endl;
                    tujuanAda[temp->tujuan_akhir[0]] = false; 
                }
                temp = temp->next;
            }
        } else {
            cout << "Tidak ada jadwal KA." << endl;
        }
    }

    void tujuanKelas(string tujuan, string kelas) {
        Node* temp = head;
        bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->tujuan_akhir == tujuan) {
                int kelasKA = temp->nomor_ka / 100;

                if ((kelas == "Eksekutif" && kelasKA == 1) ||
                    (kelas == "Bisnis" && kelasKA == 2) ||
                    (kelas == "Ekonomi" && kelasKA == 3)) {

                    cout << "KA " << temp->nomor_ka << " berangkat pukul " 
                         << temp->jam_keberangkatan << " dengan harga tiket " 
                         << temp->harga_tiket << endl;
                    ditemukan = true;
                }
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Tidak ada jadwal KA yang sesuai." << endl;
        }
    }

    void tujuanJam(string tujuan, int jam) {
        Node* temp = head;
        bool ditemukan = false;

        while (temp != nullptr) {
            if (temp->tujuan_akhir == tujuan && temp->jam_keberangkatan <= jam) {
                cout << "KA " << temp->nomor_ka << " berangkat pukul "
                     << temp->jam_keberangkatan << " dengan harga tiket "
                     << temp->harga_tiket << endl;
                ditemukan = true;
            }
            temp = temp->next;
        }

        if (!ditemukan) {
            cout << "Tidak ada jadwal KA yang sesuai." << endl;
        }
    }

    void tujuanKelasTermurah(string tujuan, string kelas) {
        Node* temp = head;
        int hargaTermurah = numeric_limits<int>::max(); 
        Node* keretaTermurah = nullptr; 

        while (temp != nullptr) {
            if (temp->tujuan_akhir == tujuan) {
                int kelasKA = temp->nomor_ka / 100;

                if ((kelas == "Eksekutif" && kelasKA == 1) ||
                    (kelas == "Bisnis" && kelasKA == 2) ||
                    (kelas == "Ekonomi" && kelasKA == 3)) {

                    if (temp->harga_tiket < hargaTermurah) {
                        hargaTermurah = temp->harga_tiket;
                        keretaTermurah = temp;
                    } 
                }
            }
            temp = temp->next;
        }

        if (keretaTermurah != nullptr) {
            cout << "KA " << keretaTermurah->nomor_ka << " berangkat pukul "
                 << keretaTermurah->jam_keberangkatan << " dengan harga tiket "
                 << keretaTermurah->harga_tiket << endl;
        } else {
            cout << "Tidak ada jadwal KA yang sesuai." << endl;
        }
    }

    void tujuanJamTermurah(string tujuan, int jam) {
        Node* temp = head;
        int hargaTermurah = numeric_limits<int>::max(); 
        Node* keretaTermurah = nullptr; 

        while (temp != nullptr) {
            if (temp->tujuan_akhir == tujuan && temp->jam_keberangkatan <= jam) {
                if (temp->harga_tiket < hargaTermurah) {
                    hargaTermurah = temp->harga_tiket;
                    keretaTermurah = temp; 
                }
            }
            temp = temp->next;
        }

        if (keretaTermurah != nullptr) {
            cout << "KA " << keretaTermurah->nomor_ka << " berangkat pukul "
                 << keretaTermurah->jam_keberangkatan << " dengan harga tiket "
                 << keretaTermurah->harga_tiket << endl;
        } else {
            cout << "Tidak ada jadwal KA yang sesuai." << endl;
        }
    }
};

int main() {
    JadwalKereta jadwal;
    int nomor_ka, jam_keberangkatan, harga_tiket;
    string tujuan_akhir, perintah, kelas, input;

    cout << "Selamat datang! Silakan masukkan jadwal KA:" << endl;
    while (true) {
        cin >> input;
        if (input == "selesai") {
            break;
        } else {
            nomor_ka = stoi(input); 
            cin >> tujuan_akhir >> jam_keberangkatan >> harga_tiket;
            jadwal.tambahJadwal(nomor_ka, tujuan_akhir, jam_keberangkatan, harga_tiket);
        }
    }

    cout << endl;
    cout << "Perintah yang tersedia:" << endl << endl;
    cout << "INFO_TUJUAN" << endl;
    cout << "TUJUAN_KELAS <tujuan_akhir> <kelas_kereta>" << endl;
    cout << "TUJUAN_JAM <tujuan_akhir> <jam_keberangkatan>" << endl;
    cout << "TUJUAN_KELAS_TERMURAH <tujuan_akhir> <kelas_kereta>" << endl;
    cout << "TUJUAN_JAM_TERMURAH <tujuan_akhir> <jam_keberangkatan>" << endl;
    cout << "EXIT" << endl << endl;

    while (true) {
        cout << "Masukkan perintah: ";
        cin >> perintah;

        if (perintah == "INFO_TUJUAN") {
            jadwal.infoTujuan();
        } else if (perintah == "TUJUAN_KELAS") {
            cin >> tujuan_akhir >> kelas;
            jadwal.tujuanKelas(tujuan_akhir, kelas);
        } else if (perintah == "TUJUAN_JAM") {
            cin >> tujuan_akhir >> jam_keberangkatan;
            jadwal.tujuanJam(tujuan_akhir, jam_keberangkatan);
        } else if (perintah == "TUJUAN_KELAS_TERMURAH") {
            cin >> tujuan_akhir >> kelas;
            jadwal.tujuanKelasTermurah(tujuan_akhir, kelas);
        } else if (perintah == "TUJUAN_JAM_TERMURAH") {
            cin >> tujuan_akhir >> jam_keberangkatan;
            jadwal.tujuanJamTermurah(tujuan_akhir, jam_keberangkatan);
        } else if (perintah == "EXIT") {
            cout << "Terima kasih sudah menggunakan program ini!" << endl;
            break;
        } else {
            cout << "Perintah yang dimasukkan tidak valid." << endl;
        }
    }

    return 0;
}