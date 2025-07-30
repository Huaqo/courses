#include <iostream>

class Maschine
{
private:
    bool status;
    bool kaputt;

public:
    Maschine(bool status, bool kaputt) : status(status), kaputt(kaputt) {}
    virtual ~Maschine() {}

    void schalter()
    {
        status = !status;
    }
    virtual void schrotten()
    {
        kaputt = true;
    }
    bool ist_an()
    {
        return status && !kaputt;
    }
};

class Waschmaschine : public Maschine
{
private:
public:
    Waschmaschine(bool status, bool kaputt) : Maschine(status, kaputt) {}
    ~Waschmaschine() {}
    void waschen()
    {
        if (ist_an())
        {
            std::cout << "Die Waschmaschine wäscht die Wäsche ...\n";
        }
        else
        {
            std::cout << "Die Waschmaschine ist aus oder kaputt ...\n";
        }
    }
};

class Spuellmaschine : public Maschine
{
private:
public:
    Spuellmaschine(bool status, bool kaputt) : Maschine(status, kaputt) {}
    ~Spuellmaschine() {}
    void spuelen()
    {
        if (ist_an())
        {
            std::cout << "Die Spüllmaschine spüllt ...\n";
        }
        else
        {
            std::cout << "Die Spüllmaschine ist aus oder kaputt ...\n";
        }
    }
};
