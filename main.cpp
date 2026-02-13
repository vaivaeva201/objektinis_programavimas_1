#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>

using std:: string;
using std:: vector;
using std:: cout;
using std:: cin;
using std:: accumulate;
using std:: setw;
using std:: left;
using std:: right;
using std:: endl;

struct Studentas {
    string Vardas="A", Pavarde="BB";
    // int *paz;
    vector <int> paz;
    int egz_paz;
    double rez;
};

void duomenu_ivedimas(vector < Studentas > &grupe)
{
    Studentas A;
    int mok_skaicius = 0;
    cout << "Įveskite kiek studentų norėsite įvesti: ";
    cin >> mok_skaicius; 

    for (int i = 0; i < mok_skaicius; i++)
    {
        cout << "Įveskite studento vardą ir pavardę: ";
        cin >> A.Vardas >> A.Pavarde;
        cout << "Įveskite semestro pažymius:\nKiek pažymių bus? ";
        int n, temp;
        cin >> n;

        for (int j= 0; j < n; j++)
        {
            cout << "Iveskite " << j+1 << " pazymi is " << n << ": ";
            cin >> temp;
            A.paz.push_back(temp);
        }
        cout << "Įveskite egzamoni pažymį: ";
        cin >> A.egz_paz;
        grupe.push_back(A);
        A.paz.clear();

    }
}

void vidurkis(Studentas &x)
{

}

void mediana(Studentas &x)
{

}

void rezultatai (vector < Studentas > grupe)
{
    int formatas;
    cout << "Prašau pasirinkite ar norite galutinį balą skaičiuoti su vidurkiu ar mediana. (Vidurkiu - 0, mediana - 1): ";
    cin >> formatas;

    cout << left << std::setw(20) << "Pavardė" << setw(20) << "Vardas";

    if (formatas == 0)
    {
        cout << std::setw(20) << "Galutinis (Vid.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (auto x : grupe)
        {
            vidurkis(x);
            cout << left << setw(20) << x.Pavarde << setw(20) << x.Vardas << setw(20) << std::fixed << std::setprecision(2) << x.rez << endl;

        }
    }
    else
    {
        cout << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "---------------------------------------------------------" << endl;
        for (auto x : grupe)
        {
        mediana(x);
        cout << left << setw(20) << x.Pavarde << setw(20) << x.Vardas << setw(20) << std::fixed << std::setprecision(2) << x.rez << endl;
        }

    }

}

int main(){

    vector < Studentas > grupe;
    duomenu_ivedimas (grupe);
    rezultatai (grupe);
    
    return 0;
}


//isdigit - kaip patikrinti  ar int ivede skaiciu