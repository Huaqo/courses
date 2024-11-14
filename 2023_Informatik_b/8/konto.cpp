#include <iostream>
#include <vector>

class Konto
{
private:
    unsigned pin;
    int kontostand;

public:
    Konto(unsigned pin, int kontostand) : pin(pin), kontostand(kontostand) {}

    void abheben(unsigned pin, unsigned betrag)
    {
        if (this->pin == pin)
        {
            kontostand = kontostand - betrag;
        }
        else
        {
            std::cout << "Falsche Pin.\n";
        }
    }

    void einzahlen(unsigned pin, unsigned betrag)
    {
        if (this->pin == pin)
        {
            std::cout << "Alter Kontostand: " << kontostand << std::endl;
            kontostand = kontostand + betrag;
            std::cout << "Neuer Kontostand: " << kontostand << std::endl;
        }
        else
        {
            std::cout << "Falsche Pin.\n";
        }
    }

    void mehr_einzahlen(unsigned pin, std::vector<unsigned> betraege)
    {
        if (this->pin == pin)
        {
            for (unsigned i; i < betraege.size(); i++)
                kontostand = kontostand + betraege[i];
        }
        else
        {
            std::cout << "Falsche Pin.\n";
        }
    }

    ~Konto()
    {
        std::cout << "Konto wurde gelöscht.\n";
    }
};

int main()
{
    int betrag;
    std::cin >> betrag;
    Konto meinKonto(1234, 6000);
    meinKonto.einzahlen(1234, betrag);
}