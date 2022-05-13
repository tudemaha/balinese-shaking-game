#include <iostream>

using namespace std;

struct Nama {
    int no;
    string nama;
};

void header();
void table(Nama anggota[]);

int main() {
    Nama anggota[6] = {
        {1, "Hantu"},
        {2, "Kebo"},
        {3, "Monyet"},
        {4, "Orang"},
        {5, "Macan"},
        {6, "Ayam"}
    };

    header();

    cout << endl << "Pilihan:" << endl;
    table(anggota);

    return 0;
}

void header() {
    cout << "===========================================" << endl;
    cout << "||    PROGRAM PERMAINAN KOCOK-KOCOKAN    ||" << endl;
    cout << "===========================================" << endl;
}

void table(Nama anggota[]) {
    cout << "+----------------+---------------+---------------+" << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++){
            cout << "|  " << anggota[i * 3 + j].nama << "\t ";
        }
        cout << "|" << endl;
        cout << "+----------------+---------------+---------------+";
        cout << endl;
    }
    
}