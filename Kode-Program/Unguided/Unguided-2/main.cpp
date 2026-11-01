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

    infotype cari;
    cout << "Masukkan Kode Buku yang dicari : ";
    cin >> cari.kodeBuku;

    address P = findElm(L, cari);
    if (P != Nil) {
        cout << endl;
        cout << "Kode Buku    : " << P->info.kodeBuku << endl;
        cout << "Judul        : " << P->info.judul << endl;
        cout << "Tahun Terbit : " << P->info.thnTerbit << endl;
    } else {
        cout << "Buku dengan kode " << cari.kodeBuku << " tidak ditemukan." << endl;
    }
    return 0;
}