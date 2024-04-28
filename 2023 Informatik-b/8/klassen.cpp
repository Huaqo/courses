#include <string>
#include <iostream>

/*
EScooter
-------------------------
- Marke: std::string
- PS: int
- Akku: int
-------------------------
+ EScooter(m: std::string, p: int, a: int)
+ ~EScooter()
+ getModell(): std::string
+ getPS(): int
+ getAkku(): int
+ setPS(p: int): void
+ operator<(other: EScooter): bool
*/
class EScooter
{
private:
    // Attribute
    std::string Marke;
    int PS;
    int Akku;

public:
    /*
    Voraussetzungen: Die Funktion kann mit einem String und zwei Integers aufgerufen werden.
    Ergebnis: Es wird kein Ergebnis zurückgegeben.
    Effekt: Ein neues EScooter-Objekt wird mit den angegebenen Marken-, PS- und Akkuwerten erstellt.
    */
    EScooter(std::string m, int p, int a) : Marke(m), PS(p), Akku(a) {}

    /*
    Voraussetzungen: Keine. Der Destruktor wird aufgerufen, wenn ein EScooter-Objekt gelöscht wird.
    Ergebnis: Es wird kein Ergebnis zurückgegeben.
    Effekt: Das EScooter-Objekt wird aus dem Speicher entfernt.
    */
    ~EScooter() {}

    /*
    Voraussetzungen: Diese Methoden können aufgerufen werden, um die entsprechenden Attribute eines EScooter-Objekts zu erhalten.
    Ergebnis: Jede Methode gibt den entsprechenden Attributwert zurück.
    Effekt: Kein weiterer Effekt.
    */
    std::string getModell()
    {
        return Marke;
    }

    int getPS()
    {
        return PS;
    }

    int getAkku()
    {
        return Akku;
    }

    /*
    Voraussetzungen: Die Methode kann aufgerufen werden, um den PS-Wert eines EScooter-Objekts zu ändern.
    Ergebnis: Es wird kein Ergebnis zurückgegeben.
    Effekt: Der PS-Wert des EScooter-Objekts wird auf den übergebenen Wert gesetzt.
    */
    void setPS(int p)
    {
        PS = p;
    }

    /*
    Voraussetzungen: Die Methode kann aufgerufen werden, um zwei EScooter-Objekte auf der Basis ihrer PS-Werte zu vergleichen.
    Ergebnis: Die Methode gibt ein boolsches Ergebnis zurück, das angibt, ob das aktuelle EScooter-Objekt weniger PS hat als das andere.
    Effekt: Kein weiterer Effekt.
    */
    bool operator<(const EScooter &other) const
    {
        return PS < other.PS;
    }
};

/*
Kochfeld
-------------------------
- Marke: std::string
- AnzahlBrenner: int
- istEingeschaltet: bool
-------------------------
+ Kochfeld(m: std::string, b: int)
+ ~Kochfeld()
+ getMarke(): std::strinsg
+ getAnzahlBrenner(): int
+ einschalten(): void
+ ausschalten(): void
+ istAn(): bool
*/
class Kochfeld
{
private:
    std::string Marke;
    int AnzahlBrenner;
    bool istEingeschaltet;

public:
    // Konstruktor
    Kochfeld(std::string m, int b) : Marke(m), AnzahlBrenner(b), istEingeschaltet(false) {}

    // Destruktor
    ~Kochfeld() {}

    // Methoden
    std::string getMarke() const
    {
        return Marke;
    }

    int getAnzahlBrenner() const
    {
        return AnzahlBrenner;
    }

    void einschalten()
    {
        istEingeschaltet = true;
    }

    void ausschalten()
    {
        istEingeschaltet = false;
    }

    bool istAn() const
    {
        return istEingeschaltet;
    }
};

int main()
{
    // Test EScooter
    EScooter meinScooter("voi", 250, 100);
    std::cout << "Marke: " << meinScooter.getModell() << std::endl;
    std::cout << "PS: " << meinScooter.getPS() << std::endl;
    std::cout << "Akku: " << meinScooter.getAkku() << std::endl;
    EScooter andererScooter("lime", 300, 120);
    std::cout << "Ist mein Scooter schwächer als der andere? " << (meinScooter < andererScooter ? "Ja" : "Nein") << std::endl;
    meinScooter.setPS(350);
    std::cout << "Nach dem Tuning: " << std::endl;
    std::cout << "PS: " << meinScooter.getPS() << std::endl;
    std::cout << "Ist mein Scooter jetzt schwächer als der andere? " << (meinScooter < andererScooter ? "Ja" : "Nein") << std::endl;

    // Test Kochfeld
    Kochfeld meinKochfeld("Bosch", 4);
    std::cout << "Marke: " << meinKochfeld.getMarke() << std::endl;
    std::cout << "Anzahl der Brenner: " << meinKochfeld.getAnzahlBrenner() << std::endl;
    std::cout << "Ist das Kochfeld eingeschaltet? " << (meinKochfeld.istAn() ? "Ja" : "Nein") << std::endl;
    meinKochfeld.einschalten();
    std::cout << "Ist das Kochfeld eingeschaltet? " << (meinKochfeld.istAn() ? "Ja" : "Nein") << std::endl;
    meinKochfeld.ausschalten();
    std::cout << "Ist das Kochfeld eingeschaltet? " << (meinKochfeld.istAn() ? "Ja" : "Nein") << std::endl;
}