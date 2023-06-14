#include <iostream>
#include <vector>
using namespace std;

class penerbit;
class pengarang {
public:
    string nama;
    vector<penerbit*> daftar_penerbit;
    vector<string> daftar_buku;
    pengarang(string pNama) :nama(pNama) {
        cout << "Pengarang \"" << nama << "\" ada\n";
    }
    ~pengarang() {
        cout << "Pengarang \"" << nama << "\" tidak ada\n";
    }
    void tambahPenerbit(penerbit*);
    void tambahBuku(string);
    void cetakPenerbit();
    void cetakBuku();
};

class penerbit {
public:
    string nama;
    vector<pengarang*> daftar_pengarang;
    penerbit(string pNama) :nama(pNama) {
        cout << "Penerbit \"" << nama << "\" ada\n";
    }
    ~penerbit() {
        cout << "Penerbit \"" << nama << "\" tidak ada\n";
    }
    void tambahPengarang(pengarang*);
    void cetakPengarang();
};

void pengarang::tambahPenerbit(penerbit* pPenerbit) {
    daftar_penerbit.push_back(pPenerbit);
}
void pengarang::tambahBuku(string pBuku) {
    daftar_buku.push_back(pBuku);
}
void pengarang::cetakPenerbit() {
    cout << "Daftar Penerbit yang diikuti \"" << this->nama << "\":\n";
    for (auto& a : daftar_penerbit) {
        cout << a->nama << "\n";
    }
    cout << endl;
}
void pengarang::cetakBuku() {
    cout << "Daftar buku yang dikarang \"" << this->nama << "\":\n";
    for (auto& a : daftar_buku) {
        cout << a << "\n";
    }
    cout << endl;
}
void penerbit::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
    pPengarang->tambahPenerbit(this);
}
void penerbit::cetakPengarang() {
    cout << "Daftar pengarang dari penerbit \"" << this->nama << "\":\n";
    for (auto& a : daftar_pengarang) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

class buku {
public:
    string nama;
    vector<pengarang*> daftar_pengarang;

    buku(string pNama) :nama(pNama) {
        cout << "Buku \"" << nama << "\" ada\n";
    }
    ~buku() {
        cout << "Buku \"" << nama << "\" tidak ada\n";
    }

    void tambahPengarang(pengarang*);
    void cetakPengarang();
};

void buku::tambahPengarang(pengarang* pPengarang) {
    daftar_pengarang.push_back(pPengarang);
    pPengarang->tambahBuku(this->nama);
}

int main() {
    penerbit* varPenerbit1 = new penerbit("Gama Press");
    penerbit* varPenerbit2 = new penerbit("Intan Pariwira");
    pengarang* varPengarang1 = new pengarang("Joko");
    pengarang* varPengarang2 = new pengarang("Lia");
    pengarang* varPengarang3 = new pengarang("Asroni");
    pengarang* varPengarang4 = new pengarang("Giga");
    buku* varBuku1 = new buku("Fisika");
    buku* varBuku2 = new buku("Algoritma");
    buku* varBuku3 = new buku("Basisdata");
    buku* varBuku4 = new buku("Dasar Pemrograman");
    buku* varBuku5 = new buku("Matematika");
    buku* varBuku6 = new buku("Multimedia 1");

    varPenerbit1->tambahPengarang(varPengarang1);
    varPenerbit1->tambahPengarang(varPengarang2);
    varPenerbit1->tambahPengarang(varPengarang4);
    varPenerbit2->tambahPengarang(varPengarang3);
    varPenerbit2->tambahPengarang(varPengarang4);

    varBuku1->tambahPengarang(varPengarang1);
    varBuku2->tambahPengarang(varPengarang1);
    varBuku3->tambahPengarang(varPengarang2);
    varBuku4->tambahPengarang(varPengarang3);
    varBuku5->tambahPengarang(varPengarang4);
    varBuku6->tambahPengarang(varPengarang4);

    varPenerbit1->cetakPengarang();
    varPenerbit2->cetakPengarang();
    varPengarang4->cetakPenerbit();
    varPengarang1->cetakBuku();
    varPengarang2->cetakBuku();
    varPengarang3->cetakBuku();
    varPengarang4->cetakBuku();

    delete varPenerbit1;
    delete varPenerbit2;
    delete varPengarang1;
    delete varPengarang2;
    delete varPengarang3;
    delete varPengarang4;
    delete varBuku1;
    delete varBuku2;
    delete varBuku3;
    delete varBuku4;
    delete varBuku5;
    delete varBuku6;

    return 0;
}