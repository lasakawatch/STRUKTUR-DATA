#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

// Konstanta untuk konversi waktu
const int MENIT_DALAM_JAM = 60;
const int MENIT_DALAM_HARI = 60 * 24;


int HARI[7];

int JAM[24];


struct Pertemuan {
    string nama_matkul;
    int start_time;
    int end_time;
};


vector<Pertemuan> MATKUL_TERSEDIA;


vector<Pertemuan> jadwal;


void inisialisasiWaktu() {
    for (int i = 0; i < 7; ++i) {
        HARI[i] = i * MENIT_DALAM_HARI;
    }
    for (int i = 0; i < 24; ++i) {
        JAM[i] = i * MENIT_DALAM_JAM;
    }

   
    MATKUL_TERSEDIA = {
       {"Struktur Data", HARI[0] + JAM[8], HARI[0] + JAM[8] + (1 * MENIT_DALAM_JAM) + 40},
        {"Alpro", HARI[0] + JAM[8] + 0, HARI[0] + JAM[9] + 40},
        {"Manbis", HARI[4] + JAM[13] + 1, HARI[4] + JAM[15] + 40},
        {"matdis 1 a", HARI[4] + JAM[9] + 0, HARI[4] + JAM[13] + 0},
        {"matdis 1 b", HARI[12] + JAM[9] + 0, HARI[2] + JAM[10] + 40},
        {"kalkulus 1 c", HARI[2] + JAM[10] + 0, HARI[2] + JAM[12] + 00}
    };
}


void tampilkanMenu() {
    cout << "==================== SUSUN JADWAL ====================" << endl;
    cout << "1. Add matkul" << endl;
    cout << "2. Drop matkul" << endl;
    cout << "3. Cek ringkasan" << endl;
    cout << "4. Lihat daftar matkul" << endl;
    cout << "5. Selesai" << endl;
    cout << "=======================================================" << endl;
}

// Fungsi untuk mengonversi string ke lowercase
string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// Fungsi untuk mencari pertemuan berdasarkan nama matkul
int cariPertemuan(string nama_matkul) {
    for (int i = 0; i < MATKUL_TERSEDIA.size(); i++) {
        if (toLower(MATKUL_TERSEDIA[i].nama_matkul) == toLower(nama_matkul)) {
            return i;
        }
    }
    return -1;
}

// Fungsi untuk menambahkan matkul ke jadwal
void addMatkul() {
    string nama_matkul;
    cout << "Masukkan nama matkul: ";
    getline(cin >> ws, nama_matkul);

    int index = cariPertemuan(nama_matkul);
    if (index == -1) {
        cout << "Matkul tidak ditemukan" << endl;
    } else {
        jadwal.push_back(MATKUL_TERSEDIA[index]);
    }
}

// Fungsi untuk menghapus matkul dari jadwal
void dropMatkul() {
    string nama_matkul;
    cout << "Masukkan nama matkul: ";
    getline(cin >> ws, nama_matkul);

    int index = -1;
    for (int i = 0; i < jadwal.size(); i++) {
        if (toLower(jadwal[i].nama_matkul) == toLower(nama_matkul)) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << "Matkul tidak ditemukan" << endl;
    } else {
        jadwal.erase(jadwal.begin() + index);
    }
}

// Fungsi untuk mengecek ringkasan jadwal
void cekRingkasan() {
    bool bentrok = false;
    for (int i = 0; i < jadwal.size(); i++) {
        for (int j = i + 1; j < jadwal.size(); j++) {
            if ((jadwal[i].start_time < jadwal[j].end_time && jadwal[j].start_time < jadwal[i].end_time)) {
                cout << jadwal[i].nama_matkul << " bentrok dengan " << jadwal[j].nama_matkul << endl;
                bentrok = true;
            }
        }
    }
    if (!bentrok) {
        cout << "Tidak ada matkul yang bermasalah" << endl;
    }
}

// Fungsi untuk menampilkan daftar matkul yang sudah diambil
void lihatDaftarMatkul() {
    if (jadwal.empty()) {
        cout << "Tidak ada matkul yang diambil" << endl;
        return;
    }
     // Urutkan jadwal berdasarkan start_time
    sort(jadwal.begin(), jadwal.end(), [](const Pertemuan &a, const Pertemuan &b) {
        return a.start_time < b.start_time;
    });

    cout << "daftar matkul:" << endl;
    for (const Pertemuan& p : jadwal) {
        int hari = p.start_time / MENIT_DALAM_HARI;
        int jam_mulai = (p.start_time % MENIT_DALAM_HARI) / MENIT_DALAM_JAM;
        int menit_mulai = p.start_time % MENIT_DALAM_JAM;
        int jam_selesai = (p.end_time % MENIT_DALAM_HARI) / MENIT_DALAM_JAM;
        int menit_selesai = p.end_time % MENIT_DALAM_JAM;

        string namaHari;
        switch (hari) {
            case 0: namaHari = "Senin"; break;
            case 1: namaHari = "Selasa"; break;
            case 2: namaHari = "Rabu"; break;
            case 3: namaHari = "Kamis"; break;
            case 4: namaHari = "Jumat"; break;
            case 5: namaHari = "Sabtu"; break;
            default: namaHari = "Minggu";
        }

        cout << p.nama_matkul << " "
             << namaHari << ", "
             << jam_mulai << ":" << (menit_mulai < 10 ? "0" : "") << menit_mulai
             << " s/d "
             << namaHari << ", "
             << jam_selesai << ":" << (menit_selesai < 10 ? "0" : "") << menit_selesai
             << endl;
    }
}


int main() {
    inisialisasiWaktu(); // Inisialisasi array HARI dan JAM, dan MATKUL_TERSEDIA
    int pilihan;

    do {tampilkanMenu();cout << "Masukkan pilihan: "; cin >> pilihan;

        switch (pilihan) {case 1:  addMatkul(); break;case 2: dropMatkul();  break;  case 3: cekRingkasan();  break;
            case 4:lihatDaftarMatkul(); break;case 5:
             cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Maaf, pilihan tidak tersedia" << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}