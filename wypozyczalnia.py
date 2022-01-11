"""
class Material:
    def __init__(self, autor_imie, autor_nazwisko, tytul, rok_wydania, liczba_stron, gatunek, rezyser_imie, rezyser_nazwisko, aktor1_imie, aktor1_nazwisko, aktor2_imie, aktor2_nazwisko, aktor3_imie, aktor3_nazwisko, czas_trwania, jest_dostepne, ma_napisy):
        self.autor_imie = autor_imie
        self.autor_nazwisko = autor_nazwisko
        self.tytul = tytul
        self.rok_wydania = rok_wydania
        self.liczba_stron = liczba_stron
        self.gatunek = gatunek
        self.rezyser_imie = rezyser_imie
        self.rezyser_nazwisko = rezyser_nazwisko
        self.aktor1_imie = aktor1_imie
        self.aktor1_nazwisko = aktor1_nazwisko
        self.aktor2_imie = aktor2_imie
        self.aktor2_nazwisko = aktor2_nazwisko
        self.aktor3_imie = aktor3_imie
        self.aktor3_nazwisko = aktor3_nazwisko
        self.czas_trwania = czas_trwania
        self.jest_dostepne = jest_dostepne
        self.ma_napisy = ma_napisy

"""

class Ksiazka:
    def __init__(self, id, autor_imie, autor_nazwisko, tytul, gatunek, rok_wydania, liczba_stron, jest_dostepne):
        self.id = id
        self.autor_imie = autor_imie
        self.autor_nazwisko = autor_nazwisko
        self.tytul = tytul
        self.gatunek = gatunek
        self.rok_wydania = rok_wydania
        self.liczba_stron = liczba_stron
        self.jest_dostepne = bool(jest_dostepne)

    def Pokaz_pozycje(self):
        print("ID: " + str(self.id))
        print("Autor: " + self.autor_imie + " " + self.autor_nazwisko)
        print("Tytul: " + self.tytul)
        print("Gatunek: " + self.gatunek)
        print("Rok wydania: " + str(self.rok_wydania))
        print("Liczba stron: " + str(self.liczba_stron))
        if self.jest_dostepne == True:
            print("Dostepne: Tak")
        else:
            print("Dostepne: Nie")
        print()


class Film:
    def __init__(self, id, rezyser_imie, rezyser_nazwisko, tytul, rok_wydania, gatunek, aktor1_imie, aktor1_nazwisko, aktor2_imie, aktor2_nazwisko, aktor3_imie, aktor3_nazwisko, czas_trwania, jest_dostepne, ma_napisy):
        self.id = id
        self.rezyser_imie = rezyser_imie
        self.rezyser_nazwisko = rezyser_nazwisko
        self.tytul = tytul
        self.rok_wydania = rok_wydania
        self.gatunek = gatunek
        self.aktor1_imie = aktor1_imie
        self.aktor1_nazwisko = aktor1_nazwisko
        self.aktor2_imie = aktor2_imie
        self.aktor2_nazwisko = aktor2_nazwisko
        self.aktor3_imie = aktor3_imie
        self.aktor3_nazwisko = aktor3_nazwisko
        self.czas_trwania = czas_trwania
        self.jest_dostepne = bool(jest_dostepne)
        self.ma_napisy = bool(ma_napisy)

    def Pokaz_pozycje(self):
        print("ID: " + str(self.id))
        print("Rezyser: " + self.rezyser_imie + " " + self.rezyser_nazwisko)
        print("Tytul: " + self.tytul)
        print("Rok wydania: " + str(self.rok_wydania))
        print("Gatunek: " + self.gatunek)
        print("Aktor 1: " + self.aktor1_imie + " " + self.aktor1_nazwisko)
        print("Aktor 2: " + self.aktor2_imie + " " + self.aktor2_nazwisko)
        print("Aktor 3: " + self.aktor3_imie + " " + self.aktor3_nazwisko)
        print("Czas trwania: " + str(self.czas_trwania))
        if self.ma_napisy == True:
            print("Dostepne: Tak")
        else:
            print("Dostepne: Nie")
        if self.jest_dostepne == True:
            print("Dostepne: Tak")
        else:
            print("Dostepne: Nie")
        print()


class Czytelnik:
    def __init__(self, numer, imie, nazwisko, plec, wiek, ilosc_wypozyczonych):
        self.numer = numer
        self.imie = imie
        self.nazwisko = nazwisko
        self.plec = plec
        self.wiek = wiek
        self.ilosc_wypozyczonych = ilosc_wypozyczonych

    def Pokaz_czytelnika(self):
        print("ID: " + str(self.numer))
        print("Imie: " + self.imie)
        print("Nazwisko: " + self.nazwisko)
        print("Plec: " + self.plec)
        print("Wiek: " + str(self.wiek))
        print("Ilosc wypozyczonych: " + str(self.ilosc_wypozyczonych))
        print()

def menu():
    print("Wybierz operacje do wykonania: ")
    print("1. Pokaz czytelnikow: ")
    print("2. Pokaz materialy: ")
    print("3. Pokaz czytelnikow i materialy: ")
    print("4. Wypozycz material: ")
    print("5. Oddaj material: ")
    print("6. Pokaz aktualne wypozyczenia: ")
    print("7. Wyjdz z aplikacji: ")

cz0 = Czytelnik(0, "Adam", "Celej", "mezczyzna", 20, 0)
cz1 = Czytelnik(1, "Adam", "Kokosza", "mezczyzna", 20, 0)
cz2 = Czytelnik(3, "Julia", "Nowak", "kobieta", 22, 0)
cz3 = Czytelnik(3, "Alicja", "Kowalska", "kobieta", 16, 0)
cz4 = Czytelnik(4, "Blanka", "Wysocka", "kobieta", 22, 0)
czytelnik_set = [cz0, cz1, cz2, cz3, cz4]
#for x in czytelnik_set:
#    print(x.Pokaz_czytelnika())

k0 = Ksiazka(20, "Henryk", "Sienkiewicz", "Potop", "Powiesc historyczna", 2017, 984, 1)
k1 = Ksiazka(21,"Henryk", "Sienkiewicz", "Ogniem i mieczem", "Powiesc historyczna", 2016, 606, 1)
k2 = Ksiazka(22, "Henryk", "Sienkiewicz", "Pan Wolodyjowski", "Powiesc historyczna", 2018, 1080, 1)
f0 = Film(23, "Ridley", "Scott", "Gladiator", 2000, "Dramat historyczny", "Russell", "Crowe", "Joaquin", "Phoenix", "Richard", "Harris", 155, 1, 1)
material_set =[k0, k1, k2, f0]
#for x in material_set:
#    print(x.Pokaz_pozycje())
var = wypozyczenia[5][6]
operacja = 0
menu()
wybor = input()
#for wybor != 7:
if wybor == 1:
    for x in czytelnik_set:
        print(x.Pokaz_czytelnika())
elif wybor == 2:
    for x in material_set:
        print(x.Pokaz_pozycje())
elif wybor == 3:
    for x in czytelnik_set:
        print(x.Pokaz_czytelnika())
    for x in material_set:
        print(x.Pokaz_pozycje())
elif wybor == 4:
    czytelnik_id = input("Wybierz id czytelnika ktory bedzie wypozyczal: ")
    material_id = input("Wybierz id materialu do wypozyczenia: ")
    #for x in  czytelnik_set:
    #    if x.numer  == czytelnik_id

