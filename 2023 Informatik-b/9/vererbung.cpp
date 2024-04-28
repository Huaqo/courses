#include <iostream>
#include <string>

/*
KLassenhierarchie

1. tier
    Attribute: gewicht, groesse
    Methoden: fortbewegen(), atmen(), essen()
1.1. saeugetier
1.1.1. hund
    Attribute: gattung
    Methoden: anbellen(tier t), fortpflanzen(hund h)
1.1.1.1. pudel
1.2. insekt
1.2.1. biene
*/

/*
Klasse Tier: Basis-Klasse in der Klassenstruktur.
Kann genutzt werden, um allgemeine Eigenschaften und Verhaltensweisen von Tieren abzubilden.
Wir haben die Methoden essen(), atmen(), und fortbewegen() als virtual in der Basisklasse Tier definiert, was bedeutet, dass sie in den abgeleiteten Klassen überschrieben werden koennen, wenn dies gewünscht wird.
*/
class Tier
{
public:
    int gewicht;
    int groesse;

    // Konstruktor: Kann aufgerufen werden, um ein neues Tierobjekt mit definiertem Gewicht und Groesse zu erstellen.
    // Gibt ein neues Tierobjekt zurück.
    // Fügt dem Programmzustand ein neues Tierobjekt hinzu.
    Tier(int gewicht, int groesse) : gewicht(gewicht), groesse(groesse) {}

    // Destruktor: Wird aufgerufen, wenn ein Tierobjekt geloescht wird.
    // Gibt nichts zurück.
    // Entfernt das Tierobjekt aus dem Zustand des Programms.
    ~Tier() {}

    // Kann aufgerufen werden, um das Verhalten eines Tiers zu simulieren, sich fortzubewegen.
    // Gibt Text zurück und hat keine Effekte.
    virtual void fortbewegen()
    {
        std::cout << "Tier bewegt sich fort." << std::endl;
    }

    // Kann aufgerufen werden, um das Verhalten eines Tiers zu simulieren, zu atmen.
    // Gibt Text zurück und hat keine Effekte.
    virtual void atmen()
    {
        std::cout << "Tier atmet." << std::endl;
    }

    // Kann aufgerufen werden, um das Verhalten eines Tiers zu simulieren, zu essen.
    // Gibt Text zurück und hat keine Effekte.
    virtual void essen()
    {
        std::cout << "Tier isst." << std::endl;
    }

    // Kann aufgerufen werden, um das Gewicht des Tiers zu ermitteln.
    // Gibt das Gewicht des Tiers als Integer zurück.
    // Ändert den Zustand des Programms nicht.
    int getGewicht()
    {
        return gewicht;
    }

    // Kann aufgerufen werden, um die Groesse des Tiers zu ermitteln.
    // Gibt die Groesse des Tiers als Integer zurück.
    // Ändert den Zustand des Programms nicht.
    int getGroesse()
    {
        return groesse;
    }
};

// Klasse Saeugetier (Säugetier): Erbt von der Klasse Tier.
// Kann genutzt werden, um ein spezifisches Tier zu erstellen, das ein Säugetier ist.
class Saeugetier : public Tier
{
public:
    // Konstruktor: Kann aufgerufen werden, um ein neues Saeugetier-Objekt mit definiertem Gewicht und Groesse zu erstellen.
    // Gibt ein neues Saeugetier-Objekt zurück.
    // Fügt dem Programmzustand ein neues Saeugetier-Objekt hinzu.
    Saeugetier(int gewicht, int groesse) : Tier(gewicht, groesse) {}
};

// Klasse Hund: Erbt von der Klasse Saeugetier.
// Kann genutzt werden, um ein spezifisches Tier zu erstellen, das ein Hund ist.
class Hund : public Saeugetier
{

public:
    std::string gattung;

    // Konstruktor: Kann aufgerufen werden, um ein neues Hund-Objekt mit definiertem Gewicht, Groesse und Gattung zu erstellen.
    // Gibt ein neues Hund-Objekt zurück.
    // Fügt dem Programmzustand ein neues Hund-Objekt hinzu.
    Hund(int gewicht, int groesse, std::string gattung) : Saeugetier(gewicht, groesse), gattung(gattung) {}

    // Destruktor: Wird aufgerufen, wenn ein Hund-Objekt geloescht wird.
    // Gibt nichts zurück.
    // Entfernt das Hund-Objekt aus dem Zustand des Programms.
    ~Hund() {}

    // Kann aufgerufen werden, um das Verhalten eines Hundes zu simulieren, ein anderes Tier anzubellen.
    // Gibt Text zurück und hat keine Effekte.
    void anbellen(Tier t)
    {
        std::cout << "Hund bellt anderen Hund an" << std::endl;
    }

    // Kann aufgerufen werden, um das Verhalten eines Hundes zu simulieren, sich fortzupflanzen.
    // Gibt Text zurück und hat keine Effekte.
    void fortpflanzen(Hund h)
    {
        std::cout << "Hund pflanzt sich mit anderem Hund fort" << std::endl;
    }

    // Kann aufgerufen werden, um die Gattung des Hundes zu ermitteln.
    // Gibt die Gattung des Hundes als String zurück.
    // Ändert den Zustand des Programms nicht.
    std::string getGattung()
    {
        return gattung;
    }
};

// Klasse Pudel: Erbt von der Klasse Hund.
// Kann genutzt werden, um ein spezifisches Tier zu erstellen, das ein Pudel ist.
class Pudel : public Hund
{
public:
    // Konstruktor: Kann aufgerufen werden, um ein neues Pudel-Objekt mit definiertem Gewicht, Groesse und Gattung zu erstellen.
    // Gibt ein neues Pudel-Objekt zurück.
    // Fügt dem Programmzustand ein neues Pudel-Objekt hinzu.
    Pudel(int gewicht, int groesse, std::string gattung) : Hund(gewicht, groesse, gattung) {}

    // Destruktor: Wird aufgerufen, wenn ein Pudel-Objekt geloescht wird.
    // Gibt nichts zurück.
    // Entfernt das Pudel-Objekt aus dem Zustand des Programms.
    ~Pudel() {}
};

int main()
{
    Pudel Bello(10, 45, "Pudel");
    Pudel Strolch(20, 60, "Pudel");

    int gewichtBello = Bello.getGewicht();
    int groesseBello = Bello.getGroesse();
    std::string gattungBello = Bello.getGattung();

    std::cout << "Ein Hund der gattung " << gattungBello << ", mit der groesse " << groesseBello << " und mit dem Gewicht " << gewichtBello << " wurde erstellt" << std::endl;

    Bello.essen();
    Bello.atmen();
    Bello.fortbewegen();
    Bello.anbellen(Strolch);
    Bello.fortpflanzen(Strolch);
}
