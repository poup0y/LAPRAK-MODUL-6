
#include <iostream>
#include "Doublylist.h"
using namespace std;

int main() {
    List L;
    infotype x;
    address P;

    CreateList(L);

    x.nopol = "D001";
    x.warna = "Hitam";
    x.thnbuat = 2020;
    insertLast(L, alokasi(x));

    x.nopol = "D002";
    x.warna = "Kuning";
    x.thnbuat = 2019;
    insertLast(L, alokasi(x));

    x.nopol = "D003";
    x.warna = "Putih";
    x.thnbuat = 2022;
    insertLast(L, alokasi(x));

    x.nopol = "D004";
    x.warna = "Hitam";
    x.thnbuat = 2023;
    insertLast(L, alokasi(x));

    cout << "DATA LIST 1" << endl;
    printInfo(L);

    cout << "Masukkan nomor polisi yang dicari: ";
    cin >> x.nopol;

    P = findElm(L, x);

    if (P != nullptr) {
        cout << "\nData kendaraan ditemukan" << endl;
        cout << "Nomor Polisi : " << P->info.nopol << endl;
        cout << "Warna        : " << P->info.warna << endl;
        cout << "Tahun        : " << P->info.thnbuat << endl;
    } else {
        cout << "Nomor polisi tidak ditemukan." << endl;
    }

    x.nopol = "D003";
    P = findElm(L, x);

    cout << "\nMenghapus nomor polisi D003" << endl;

    if (P != nullptr) {
        if (P == L.First) {
            deleteFirst(L, P);
        } else if (P == L.Last) {
            deleteLast(L, P);
        } else {
            address Prec = P->prev;
            deleteAfter(Prec, P);
        }

        dealokasi(P);
        cout << "Data D003 berhasil dihapus." << endl;
    } else {
        cout << "Data D003 tidak ditemukan." << endl;
    }

    cout << "\nDATA LIST 2" << endl;
    printInfo(L);

    while (L.First != nullptr) {
        deleteFirst(L, P);
        dealokasi(P);
    }

    return 0;
}
