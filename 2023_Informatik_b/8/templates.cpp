#include <vector>
#include <iostream>
#include <string>

template <typename SchluesselTyp, typename WertTyp>
class schluesselWertPaar
{
private:
    SchluesselTyp schluessel;
    WertTyp wert;

public:
    schluesselWertPaar() {}
    // Konstruktor
    schluesselWertPaar(SchluesselTyp schluessel, WertTyp wert) : schluessel(schluessel), wert(wert) {}

    // Getter für Schlüssel und Wert
    SchluesselTyp getSchluessel() const
    {
        return schluessel;
    }

    WertTyp getWert() const
    {
        return wert;
    }

    // Setter für Schlüssel und Wert
    void setSchluessel(SchluesselTyp neuerSchluessel)
    {
        schluessel = neuerSchluessel;
    }

    void setWert(WertTyp neuerWert)
    {
        wert = neuerWert;
    }

    // Überladen des < Operators
    bool operator<(const schluesselWertPaar &paar) const
    {
        return schluessel < paar.getSchluessel();
    }
};

template <typename SchluesselTyp, typename WertTyp>
void merge(std::vector<schluesselWertPaar<SchluesselTyp, WertTyp>> &vec, int start, int mid, int end)
{
    int i, j, k;
    int n1 = mid - start + 1;
    int n2 = end - mid;

    std::vector<schluesselWertPaar<SchluesselTyp, WertTyp>> left(n1), right(n2);

    for (i = 0; i < n1; i++)
        left[i] = vec[start + i];
    for (j = 0; j < n2; j++)
        right[j] = vec[mid + 1 + j];

    i = 0;
    j = 0;
    k = start;
    while (i < n1 && j < n2)
    {
        if (left[i] < right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        vec[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        vec[k] = right[j];
        j++;
        k++;
    }
}

template <typename SchluesselTyp, typename WertTyp>
void mergeSort(std::vector<schluesselWertPaar<SchluesselTyp, WertTyp>> &vec, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;

        mergeSort(vec, start, mid);
        mergeSort(vec, mid + 1, end);

        merge(vec, start, mid, end);
    }
}

template <typename SchluesselTyp, typename WertTyp>
int binarySearch(std::vector<schluesselWertPaar<SchluesselTyp, WertTyp>> &vec, int start, int end, SchluesselTyp key)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;

        if (vec[mid].getSchluessel() == key)
            return mid;

        if (vec[mid].getSchluessel() > key)
            return binarySearch(vec, start, mid - 1, key);

        return binarySearch(vec, mid + 1, end, key);
    }

    return -1;
}

int main()
{
    std::vector<schluesselWertPaar<int, std::string>> vec;
    vec.push_back(schluesselWertPaar<int, std::string>(3, "drei"));
    vec.push_back(schluesselWertPaar<int, std::string>(1, "eins"));
    vec.push_back(schluesselWertPaar<int, std::string>(2, "zwei"));
    std::cout << "Vor dem sortieren:\n";
    
    for (const auto &paar : vec)
    {
        std::cout << paar.getSchluessel() << " " << paar.getWert() << std::endl;
    }

    mergeSort(vec, 0, vec.size() - 1);

    std::cout << "Nach dem sortieren:\n";

    for (const auto &paar : vec)
    {
        std::cout << paar.getSchluessel() << " " << paar.getWert() << std::endl;
    }

    int index = binarySearch(vec, 0, vec.size() - 1, 3);

    if (index != -1)
    {
        std::cout << "Gefunden an Position: " << index + 1 << std::endl;
    }
    else
    {
        std::cout << "Nicht gefunden" << std::endl;
    }
}