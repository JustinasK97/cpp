#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
ofstream out("rez.txt");
    struct komanda{
    string vardas;
    float laikas;
    int metai;
    };
    void kiekElementu(int &kiekis, const char byla[]);
    void skaito(komanda Struktura[], int kiekis, const char byla[]);
    void raso(komanda Struktura[], int kiekis, string txt);
    void kuria(komanda Struktura[], int kiekis, komanda BendriDuomenys[], int nuoKiek);

int main()
{
    int kiek1, kiek2;
    const char duomenys1[] = "duom.txt";
    const char duomenys2[] = "duom2.txt";
    kiekElementu(kiek1, duomenys1);
    kiekElementu(kiek2, duomenys2);
    komanda begikai1[kiek1], begikai2[kiek2], bendraKomanda[kiek1+kiek2];
    int kiekisViso;
    kiekisViso=kiek1+kiek2;
    skaito(begikai1, kiek1, duomenys1);
    skaito(begikai2, kiek2, duomenys2);
    raso(begikai1, kiek1, "Pirma Komanda\n");
    raso(begikai2, kiek2, "Antra Komanda\n");
    kuria(begikai1, kiek1, bendraKomanda, 0);
    kuria(begikai2, kiek2, bendraKomanda, kiek1);
    raso(bendraKomanda, kiekisViso, "Bendra Komanda\n");

    out.close();
    return 0;
}
//-------------------------------------------------------------
void kiekElementu(int &kiekis, const char byla[])
{
    ifstream in(byla);
    komanda LaikStruktura[1];
    kiekis=0;
    while(!in.eof()){
        in>>LaikStruktura[0].vardas>>LaikStruktura[0].laikas>>LaikStruktura[0].metai;
        kiekis++;
    }
    in.seekg(0);
    in.close();

}
//-----------------------------------------------------------
void skaito(komanda Struktura[], int kiekis, const char byla[])
{
    ifstream in(byla);
    for(int i=0; i<kiekis; i++){
        in>>Struktura[i].vardas>>Struktura[i].laikas>>Struktura[i].metai;
    }
    in.close();
}
//------------------------------------------------------------------
void raso(komanda Struktura[], int kiekis, string txt)
{
    out<<txt;
    for(int i=0; i<kiekis; i++){
        out<<setw(20)<<left<<Struktura[i].vardas<<setw(4)<<right<<Struktura[i].laikas<<setw(4)<<right<<Struktura[i].metai;
        out<<endl;
    }
}
//--------------------------------------------------------------------
void kuria(komanda Struktura[], int kiekis, komanda BendriDuomenys[], int nuoKiek)
{
    for(int i=0; i<kiekis; i++){
       BendriDuomenys[nuoKiek].vardas=Struktura[i].vardas;
       BendriDuomenys[nuoKiek].laikas=Struktura[i].laikas;
       BendriDuomenys[nuoKiek].metai=Struktura[i].metai;
       nuoKiek++;
    }

}
