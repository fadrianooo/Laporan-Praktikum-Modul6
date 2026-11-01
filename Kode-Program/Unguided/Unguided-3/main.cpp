#include "Buku.h"

int main() {
    List L;
    CreateList(L);

    int jumlah = 0;
    while (jumlah < 3) {
        infotype x;
        cout << "masukkan kode buku: ";
        cin >> x.kodeBuku;
        cout << "masukkan judul buku: ";
        cin >> x.judul;
        cout << "masukkan tahun terbit: ";
        cin >> x.thnTerbit;

        if (kodeSudahAda(L, x.kodeBuku)) {
            cout << "kode buku sudah terdaftar" << endl;
        } else {
            insertLast(L, alokasi(x));
            jumlah++;
        }
        cout << endl;
    }

    infotype hapus;
    cout << "Masukkan Kode Buku yang akan dihapus : ";
    cin >> hapus.kodeBuku;

    address P = findElm(L, hapus);
    if (P == Nil) {
        cout << "Buku dengan kode " << hapus.kodeBuku << " tidak ditemukan." << endl;
        return 0;
    }

    if (P == L.First) {
        deleteFirst(L, P);
    } else if (P == L.Last) {
        deleteLast(L, P);
    } else {
        deleteAfter(P->prev, P);
    }
    dealokasi(P);
    cout << "Data dengan kode buku " << hapus.kodeBuku << " berhasil dihapus." << endl << endl;

    cout << "DATA LIST 1" << endl;
    printInfo(L);
    return 0;
}