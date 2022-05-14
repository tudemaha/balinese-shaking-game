#include <iostream>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

struct Nama {
    int no;
    string nama;
};

void header();
void table(Nama anggota[]);
int acakDadu();
int winGame(int dadu[], Nama anggota[], string pilihan[]);

int main() {
    float modal, currentBalance = 0;
    string pilihan[2];
    int dadu[3];
    int jumlahMenang;
    char choice;
    srand(time(0));

    Nama anggota[6] = {
        {1, "hantu"},
        {2, "kebo"},
        {3, "monyet"},
        {4, "orang"},
        {5, "macan"},
        {6, "ayam"}
    };

    start:
    header();

    cout << endl;
    table(anggota);

    cout << endl << "Taruhan: ";
    cin >> modal;

    cout << endl;
    for(int i = 0; i < 2; i++) {
        cout << "Pasang " << i + 1 << " (masukan 0 jika tidak ingin menambahkan): ";
        cin >> pilihan[i];
    }

    for(int i = 0; i < 3; i++) {
        dadu[i] = acakDadu();
    }


    cout << endl << "Dadu yang keluar: ";
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 6; j++) {
            if(dadu[i] == anggota[j].no) cout << anggota[j].nama << " ";
        }
    }

    jumlahMenang = winGame(dadu, anggota, pilihan);

    cout << endl << endl << "Jml menang: ";
    if(jumlahMenang == 0) {
        if(currentBalance == 0) {
            currentBalance = 0;
        } else {
            currentBalance -= modal;
        }
    } else {
        currentBalance += jumlahMenang * modal + modal;
    }

    cout << currentBalance << endl;

    insert_exit:
    cout << endl << "Main lagi? (y/n): ";
    cin >> choice;
    if(choice == 'Y' or choice == 'y') goto start;
    else if(choice == 'N' or choice == 'n') exit(0);
    else goto insert_exit;


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

int acakDadu() {
    return rand() % 6 + 1;
}

int winGame(int dadu[], Nama anggota[], string pilihan[]) {
    int menang = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(pilihan[i] == anggota[dadu[j] - 1].nama) menang++;
        }
    }

    return menang;
}