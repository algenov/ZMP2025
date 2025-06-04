#include <iostream>
using namespace std;
class Pojazd {
    private:
    string marka;
    string model;
    int rok_produkcji;
    public:
    Pojazd(string mrk, string mdl, int rok_prod){
        marka = mrk;
        model = mdl;
        rok_produkcji = rok_prod;    
    }

    void wyswietl() {
        cout << "Marka: " << marka << ", Model: " << model << ", Rok produkcji: " << rok_produkcji;
    }
};

class Samochod: public Pojazd {
    private:
    int liczba_drzwi;
    public:
    Samochod(string mrk, string mdl, int rok_prod, int lczb_drzwi) : Pojazd(mrk, mdl, rok_prod)
    {
        liczba_drzwi = lczb_drzwi;
    }

    void wyswietl() {
        Pojazd::wyswietl();
        cout << "Liczba drzwi: " << liczba_drzwi << "\n";
    }
};

class Rower: public Pojazd {
    private:
    int liczba_przerzutek;
    public:
    Rower(string mrk, string mdl, int rok_prod, int lczb_przerzutek) : Pojazd(mrk, mdl, rok_prod)
    {
        liczba_przerzutek = lczb_przerzutek;
    }

    void wyswietl() {
        Pojazd::wyswietl();
        cout << "Liczba przerzutek: " << liczba_przerzutek << "\n";
    }
};

int main(){
    string marka_s, model_s, marka_r, model_r;
    int rok_s, rok_r, liczba_drzwi, liczba_przerzutek;
    cout << "Podaj marke samochodu: ";
    cin >> marka_s;
    cout << "Podaj model samochodu: ";
    cin >> model_s;
    cout << "Podaj rok produkcji samochodu: ";
    cin >> rok_s;
    cout << "Podaj liczbe drzwi samochodu: ";
    cin >> liczba_drzwi;
    cout << "Podaj marke roweru: ";
    cin >> marka_r;
    cout << "Podaj model roweru: ";
    cin >> model_r;
    cout << "Podaj rok produkcji roweru: ";
    cin >> rok_r;
    cout << "Podaj liczbe przerzutek roweru: ";
    cin >> liczba_przerzutek;
    Samochod samochod_1(marka_s, model_s, rok_s, liczba_drzwi);
    Rower rower_1(marka_r, model_r, rok_r, liczba_przerzutek);
    cout << "Dane samochodu:\n";
    samochod_1.wyswietl();
    cout << "Dane roweru:\n";
    rower_1.wyswietl();
    return 0;     
}