//Biblioteka-wypozyczalnia by Adam Celej
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Material{
protected:
    string autor_imie;
    string autor_nazwisko;
    string tytul;
    int rok_wydania;
    int liczba_stron;
public:
    bool dostepne;

protected:
    string gatunek;
    string rezyser_imie;
    string rezyser_nazwisko;
    string aktor1_imie;
    string aktor2_imie;
    string aktor3_imie;
    string aktor1_nazwisko;
    string aktor2_nazwisko;
    string aktor3_nazwisko;
    int czas_trwania;
    bool napisy;

    friend class Czytelnik;
public:

    int id;
    virtual void Pokaz_pozycje() = 0;

    Material() {}
};

class Ksiazka: public Material{
public:
    Ksiazka(int lp, string ai, string an, string t, string gat, int rw, int ls, bool d)
    {
        id = lp;
        autor_imie = ai;
        autor_nazwisko = an;
        tytul = t;
        gatunek = gat;
        rok_wydania = rw;
        liczba_stron = ls;
        dostepne = d;
    }


    void Pokaz_pozycje() override
    {
        cout << "ID: " << id << endl;
        cout << "Autor: " << autor_imie << " " << autor_nazwisko << endl;
        cout << "Tytul: " << tytul << endl;
        cout << "Rok wydania: " << rok_wydania << endl;
        cout << "liczba stron: " << liczba_stron << endl;
        cout << "Dostepne: ";
        if (dostepne == true)
            cout << "Tak" << endl;
        else
            cout << "Nie" << endl;
        cout << "\n";
    }

    Ksiazka() {}
};

class Film: public Material {
public:
    Film(int lp, string tyt, string gat, string ri, string rn, string a1i, string a1n, string a2i, string a2n, string a3i, string a3n, int rw, int czt, bool n, bool d)
    {
        id = lp;
        tytul = tyt;
        gatunek = gat;
        rezyser_imie = ri;
        rezyser_nazwisko = ri;
        aktor1_imie = a1i;
        aktor1_nazwisko = a1n;
        aktor2_imie = a2i;
        aktor2_nazwisko = a2n;
        aktor3_imie = a3i;
        aktor3_nazwisko = a3n;
        rok_wydania = rw;
        czas_trwania = czt;
        napisy = n;
        dostepne = d;
    }

    Film() {}

    void Pokaz_pozycje() override
    {
        cout << "ID: " << id << endl;
        cout << "Rezyser: " << rezyser_imie << " " << rezyser_nazwisko << endl;
        cout << "Tytul: " << tytul << endl;
        cout << "Gatunek: " << gatunek << endl;
        cout << "Aktor 1: " << aktor1_imie << " " << aktor1_nazwisko << endl;
        cout << "Aktor 2: " << aktor2_imie << " " << aktor2_nazwisko << endl;
        cout << "Aktor 3: " << aktor3_imie << " " << aktor3_nazwisko << endl;
        cout << "Rok wydania: " << rok_wydania << endl;
        cout << "Czas trwania: " << czas_trwania << endl;
        cout << "Napisy: ";
        if (napisy == true)
            cout << "Tak" << endl;
        else
            cout << "Nie" << endl;
        cout << "Dostepne: ";
        if (dostepne == true)
            cout << "Tak" << endl;
        else
            cout << "Nie" << endl;
        cout << "\n";
    }
};


class Czytelnik {
public:
    string imie;
    string nazwisko;
    char plec;
    int wiek;
    int ilosc_wypozyczonych;
    int id;

    Czytelnik(string i, string n, char p, int w, int iw, int nr)
    {
        imie = i;
        nazwisko = n;
        while (p != 'm' && p != 'k')
        {
            cout << "Plec musi byc m (mezczyzna) lub k (kobieta). Podaj plec: " <<  endl;
            cin >> p;
        }
        wiek = w;
        while (w<=0)
        {
            cout << "Wiek musi byc liczba dodatnia wieksza od zera. Podaj wiek: " <<  endl;
            cin >> w;
        }
        plec = p;
        wiek = w;
        ilosc_wypozyczonych = iw;
        id = nr;
    }

    void Wypozycz(Material *m) {
        if (m->dostepne) {
            m->dostepne = false;
        }
    }

    void Oddaj(Material *m) {
        if (!m->dostepne) {
            m->dostepne = true;
        }
    }
    void Pokaz_czytelnika()
    {
        cout << "ID: " << id << endl;
        cout << "Imie: " << imie << endl;
        cout << "Nazwisko: " << nazwisko << endl;
        cout << "Plec: " << plec << endl;
        cout << "Wiek: " << wiek << endl;
        cout << "Ilosc wypozyczonych: " << ilosc_wypozyczonych << endl;
        cout << "\n";
    }
};

//deklaruje tablice z wypozyczeniami o wielkosci 10 wierszy i 6 kolumn
//Na kazdego czytelnika przypada jeden wiersz z 6 kolumnami (pierwsza kolumna to id czytelnika
//a pozostale to id wypozyczonych przez niego materialow; 0 wolne miejsce do wypozyczenia na koncie)
int Wypozyczenie[10][6];

int main()
{
    int i;
    //Tworzymy kontener sekwencyjny reprezentujacy tablice (w skrocie wektor :P) w którym bedziemy przechowywac czytelnikow
    vector<Czytelnik*> czytelnicy;
    //Tworzymy obiekty i dodajemy je na koniec wektora
    Czytelnik cz0("Adam", "Celej", 'm', 20, 0, 10);
    czytelnicy.push_back(&cz0);
    Czytelnik cz1("Adam", "Kokosza", 'm', 20, 0, 11);
    czytelnicy.push_back(&cz1);
    Czytelnik cz2("Julia", "Nowak", 'k', 22, 0, 12);
    czytelnicy.push_back(&cz2);
    Czytelnik cz3("Alicja", "Kowalska", 'k', 16, 0, 13);
    czytelnicy.push_back(&cz3);
    Czytelnik cz4("Blanka", "Wysocka", 'k', 22, 0, 14);
    czytelnicy.push_back(&cz4);
    Czytelnik cz5("Julia", "Dabrawska", 'k', 22, 0, 15);
    czytelnicy.push_back(&cz5);
    Czytelnik cz6("Ezana", "Asahanu", 'm', 19, 0, 16);
    czytelnicy.push_back(&cz6);
    Czytelnik cz7("John", "Doe", 'm', 30, 0, 17);
    czytelnicy.push_back(&cz7);
    Czytelnik cz8("Valentina", "Delgado", 'f', 32, 0, 18);
    czytelnicy.push_back(&cz8);
    Czytelnik cz9("Filip", "Ramirez", 'm', 26, 0, 19);
    czytelnicy.push_back(&cz9);
    //Tworzymy kontener sekwencyjny reprezentujacy tablice (w skrocie wektor :P) w którym bedziemy przechowywac materialy
    vector<Material*> materialy;
    //Tworzymy obiekty i dodajemy je na koniec wektora
    Ksiazka k0(20, "Henryk", "Sienkiewicz", "Potop", "Powiesc historyczna", 2017, 984, true);
    materialy.push_back(&k0);
    Ksiazka k1(21, "Henryk", "Sienkiewicz", "Ogniem i mieczem", "Powiesc historyczna", 2016, 606, true);
    materialy.push_back(&k1);
    Ksiazka k0(20, "Henryk", "Sienkiewicz", "Potop", "Powiesc historyczna", 2017, 984, true);
    materialy.push_back(&k0);
    Film f0(30, "Gladiator", "Dramat historyczny", "Ridley", "Scott", "Russell", "Crowe", "Joaquin", "Phoenix", "Richard", "Harris", 2000, 155, true, true);
    materialy.push_back(&f0);
    //Menu
    int wybor, operacja=0;
    while (wybor != 7)
    {
        cout << "Wybierz operacje do wykonania: " << endl;
        cout << "1. Pokaz czytelnikow: " << endl;
        cout << "2. Pokaz materialy: " << endl;
        cout << "3. Pokaz czytelnikow i materialy: " << endl;
        cout << "4. Wypozycz material: " << endl;
        cout << "5. Oddaj material: " << endl;
        cout << "6. Pokaz aktualne wypozyczenia: " << endl;
        cout << "7. Wyjdz z aplikacji: " << endl;
        cin >> wybor;
        switch(wybor)
        {
            //Wypisujemy po kolei wszystkie obiekty klasy czytelnik
            case 1:
            {
                system("CLS");
                for (auto czytelnik: czytelnicy)
                    {
                        czytelnik->Pokaz_czytelnika();
                    }
                break;
            }
            //wypisujemy po kolei wszystkie obiekty klasy material
            case 2:
            {
                system("CLS");
                for (auto material : materialy)
                {
                    material->Pokaz_pozycje();
                }
            break;
            }
            //wypisujemy po kolei wszystkie obiekty klas czytelnik i material
            case 3:
            {
                system("CLS");
                for (auto czytelnik: czytelnicy)
                {
                    czytelnik->Pokaz_czytelnika();
                }
                for (auto material : materialy)
                {
                    material->Pokaz_pozycje();
                }
                break;
            }
            case 4:
                {
                    //ci - czytelnik id, mi - material id
                    int ci, mi;
                    cout << "\nWybierz czytelnika: ";
                    cin >> ci;
                    cout << "Wybierz pozycje: ";
                    cin >> mi;
                    cout << "\n";
                    //Tworzymy pusty pointer na czytelnika ktory bedzie wypozyczal material
                    Czytelnik *czytelnikDoWypozyczenia = nullptr;
                    //Petla sprawdzajaca po kolei kazdego czytelnika czy jego id jest rowne temu podanemu przez uzytkownika
                    for (auto czytP : czytelnicy)
                    {
                        if(czytP->id == ci)
                        {
                            czytelnikDoWypozyczenia = czytP;

                            Wypozyczenie[operacja][0] = ci;
                            break;
                        }
                    }
                    //Tworzymy pusty pointer na material ktory bedzie wypozyczany
                    Material *materialDoWypozyczenia = nullptr;
                    //Petla sprawdzajaca po kolei kazdy material czy jego id jest rowne temu podanemu przez uzytkownika
                    for (auto matP : materialy)
                    {
                        if (matP -> id == mi)
                        {
                            materialDoWypozyczenia = matP;
                            for (int i=1;i<=5;i++)
                            {
                                if(Wypozyczenie[operacja][i]==0)
                                {
                                    Wypozyczenie[operacja][i] = mi;
                                    break;
                                }
                            }
                            break;
                        }
                        //else if()
                    }
                    //Przypisujemy material do uzytkownika i wypisujemy dane wypozyczonej pozycji
                    czytelnikDoWypozyczenia->Wypozycz(materialDoWypozyczenia);
                    for (auto material : materialy)
                    {
                        if (material == materialDoWypozyczenia)
                        material->Pokaz_pozycje();
                    }
                    break;

                }

            case 5:
            {
                //mi - material id
                int mi;
                cout << "Wybierz pozycje do oddania: " << endl;
                cin >> mi;
                //Tworzymy pusty pointer na material ktory bedzie oddawany
                Material *materialDoOddania = nullptr;
                //szukamy obiektu o podanym przez uzytkownika id
                for (auto matP : materialy)
                {
                    if (matP -> id == mi)
                    {
                        //Po znalezieniu obiektu przypisujemy jego id do pointera
                        materialDoOddania = matP;
                            //teraz szukamy konta na ktore jest wypozyczony material
                            for (int i=1;i<=5;i++)
                            {
                                for (int j=0;j<10;j++)
                                {
                                    if(Wypozyczenie[j][i]==mi)
                                    {
                                        //Po jego znalezieniu usuwamy material z konta uzytkownika
                                        Wypozyczenie[j][i] = 0;
                                        //i zmieniamy jego atrybut dostepnosci na true
                                        materialDoOddania->dostepne=true;
                                        cout << materialDoOddania->dostepne;
                                        break;
                                    }
                                }
                            }
                        break;
                    }
                }
                break;
            }


            case 6:
            {
                   //oi - id operacji
                    int oi;
                    cout << "Podaj id operacji (licza sie operacje ingerujace w wypozyczenia; oprocz tego pamietaj ze operujesz na tablicach a one zaczynaja sie od zera a wiec pierwsza operacja to operacja 0): ";
                    cin >> oi;
                    for (int i=0;i<6;i++)
                    {
                        cout << Wypozyczenie[oi][i] << " ";
                    }
                    cout << "\n";
                    break;
            }
        }
    }

    return 0;
}

