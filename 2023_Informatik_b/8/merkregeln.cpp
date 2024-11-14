/*
(a) Attribute und Hilfsmethoden sollen als private deklariert sein.
Dies gewährleistet die Datenkapselung und Datenintegrität, indem sichergestellt wird, dass interne Zustände und Hilfsmethoden nicht direkt von außerhalb der Klasse modifiziert werden können.
*/

class BeispielKlassePriPub
{
private:
    int attribut; // Privates Attribut

    void hilfsMethode()
    { // Private Hilfsmethode
        attribut *= 2;
    }

public:
    BeispielKlassePriPub() : attribut(5) {}

    void offentlicheMethode()
    {
        hilfsMethode();
    }
};

/*
(b) Methoden, die public sind, sowie die Konstruktoren als auch der Destruktor sollen spezifiziert sein. (Hier müssen Sie keine Code-Beispiele angeben.)
Dies bietet eine schriftliche Schnittstelle für andere um die Klasse richtig benutzen zu können.
*/

/*
(c) Das Signalwort const soll immer dort benutzt werden, wo es sinnvoll ist.
Durch Verwendung von const können wir sicherstellen, dass eine Methode den internen Zustand des Objekts nicht ändert. Dies kann besonders hilfreich sein, wenn wir das Objekt in einer Situation verwenden möchten, in der es unverändert bleiben muss.
*/

class BeispielKlasseConst
{
private:
    int attribut;

public:
    BeispielKlasseConst(int wert) : attribut(wert) {}

    // Eine const Methode, die das Attribut nicht ändern kann
    int getAttribut() const
    {
        return attribut;
    }
};

/*
(d) Jede Klasse, die mit new eigenen Speicher alloziert, soll einen Destruktor, einen Copy-Konstruktor und einen Copy-Assignment-Operator implementieren.
Dies sind die großen vier in C++. Wenn eine dieser Operationen benötigt wird, werden wahrscheinlich alle benötigt werden. Sie helfen dabei, Speicherlecks zu verhindern und sicherzustellen, dass das Objekt korrekt kopiert wird.
*/

class BeispielKlasse3
{
private:
    int *attribut;

public:
    // Konstruktor
    BeispielKlasse3(int wert) : attribut(new int(wert)) {}

    // Destruktor
    ~BeispielKlasse3()
    {
        delete attribut;
    }

    // Kopierkonstruktor
    BeispielKlasse3(const BeispielKlasse3 &andere) : attribut(new int(*(andere.attribut))) {}

    // Kopierzuweisungsoperator
    BeispielKlasse3 &operator=(const BeispielKlasse3 &andere)
    {
        if (this != &andere)
        {
            delete attribut;
            attribut = new int(*(andere.attribut));
        }
        return *this;
    }
};

/*
(e) Benutze Call-by-Reference in Verbindung mit const statt Call-by-Value, wenn das übergebene Objekt nicht verändert werden soll.
Dies ist nützlich, um teure Kopien von großen Objekten zu vermeiden und gleichzeitig sicherzustellen, dass das ursprüngliche Objekt unverändert bleibt.
*/

class AndereKlasse
{
    // Definition für AndereKlasse
};

class BeispielKlasse4
{
public:
    void irgendeineMethode(const AndereKlasse &objekt) const
    {
        // kann objekt hier verwenden, aber es nicht ändern
    }
};
