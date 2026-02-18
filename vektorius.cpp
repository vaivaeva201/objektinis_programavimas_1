#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>
#include <random>
#include "RandInt.hpp"

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
    vector <int> paz;
    int egz_paz;
    double rez;
};

void duomenu_ivedimas(vector < Studentas > &grupe) //getline !!!!!!!!
{
    Studentas A;

    while(true)
    {
        int n, temp;
        cout << "Įveskite studento vardą (jeigu įvedetė visus norimus studentus įrašykite 'x'): ";
        cin >> A.Vardas;
        if (A.Vardas == "x")
        {
            break;
        }
        cout << "Įveskite studento pavardę: ";
        cin >> A.Pavarde;

        cout << "Įveskite semestro pažymius (jeigu įvedetė visus norimus pažymius įrašykite '-1'):" << endl;
        while (true)
        {
            cin >> temp;
            if (temp == -1)
                break;
            if (cin.fail() || cin.peek() != '\n' || temp < 1 || temp > 10)
            {
                cout << "Neteisingas pažymys! Įveskite sveikąjį skaičių nuo 1 iki 10: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                A.paz.push_back(temp);                
            }
        }
        
        cout << "Įveskite egzamoni pažymį: ";
        while (true)
        {
            cin >> A.egz_paz;   

            if (cin.fail() || cin.peek() != '\n' || A.egz_paz < 1 || A.egz_paz > 10)
            {
                cout << "Neteisingas pažymys! Įveskite sveikąjį skaičių nuo 1 iki 10: ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;
            }
        }

        grupe.push_back(A);
        A.paz.clear();
    }  
    
}

void vidurkis(Studentas &x)
{
    double sum = accumulate(x.paz.begin(), x.paz.end(), 0.0);
    x.rez = sum /(x.paz.size()*1.0) * 0.4 + x.egz_paz * 0.6;
}

void mediana(Studentas &x)
{
    double mediana;
    sort(x.paz.begin(), x.paz.end());

    if (x.paz.size() % 2 == 0)
    {
        mediana = (x.paz[x.paz.size() / 2 - 1] + x.paz[x.paz.size() / 2]) / 2.0;
    }
    else
    {
        mediana = x.paz[x.paz.size() / 2];
    }
    x.rez = mediana * 0.4 + x.egz_paz * 0.6;
}

void skaiciu_generevimas(Studentas &A) //???????????????
{

    RandInt rnd{1, 10};
    int kiek = rnd();
    for (int i = 0; i < kiek; i++)
    {
       A.paz.push_back(rnd());
    }

    A.egz_paz = rnd();

}

void rezultatai (vector < Studentas > &grupe)
{
    int formatas;
    cout << "Prašau pasirinkite ar norite galutinį balą skaičiuoti su vidurkiu ar mediana. (Vidurkiu - 0, mediana - 1): ";
    while (true)
    {
        cin >> formatas;

        if (cin.fail() || cin.peek() != '\n' || (formatas != 1 && formatas !=0))
        {
            cout << "Neteisingas skaičius! Įveskite 0 arba 1: ";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }

    cout << left << setw(20) << "Pavardė" << setw(20) << "Vardas";

    if (formatas == 0)
    {
        cout << std::setw(20) << "Galutinis (Vid.)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (auto &x : grupe)
        {
            vidurkis(x);
            cout << left << setw(20) << x.Pavarde << setw(20) << x.Vardas << setw(20) << std::fixed << std::setprecision(2) << x.rez << endl;

        }
    }
    else
    {
        cout << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (auto &x : grupe)
        {
        mediana(x);
        cout << left << setw(20) << x.Pavarde << setw(20) << x.Vardas << setw(20) << std::fixed << std::setprecision(2) << x.rez << endl;
        }

    }

}

void meniu(vector < Studentas > &grupe)
{
    int pasirinkimas = 0;

    while(pasirinkimas != 4)
    {    
        cout << endl;
        cout << "Pasirinkite programos eigą: " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "1 - Viską įvesti ranka;" << endl;
        cout << "2 - Generuoti pažymius;" << endl;
        cout << "3 - Generuoti studentų vardus, pavardes ir pažymius;" << endl;
        cout << "4 - Baigti darbą;" << endl;
        cout << endl;

        while (true)
        {
        cin >> pasirinkimas;
            if (cin.fail() || cin.peek() != '\n' || pasirinkimas < 1 || pasirinkimas > 4)
            {
                cout << "Prašau įveskite vieną iš duotų variantų ";
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else
            {
                break;               
            }
        }

        switch(pasirinkimas)
        {
            case 1:
                cout << "Pasirinkote viską įvesti ranka " << endl;
                cout << "-----------------------------------------------------------" << endl;
                duomenu_ivedimas(grupe);
                rezultatai (grupe);
                
                break;

            case 2:
            {
                cout << "Pasirinkote generuoti pažymius " << endl;
                cout << "-----------------------------------------------------------" << endl;

                while(true)
                {
                    Studentas A;
                    int n, temp;
                    cout << "Įveskite studento vardą (jeigu įvedetė visus norimus studentus įrašykite 'x'): ";
                    cin >> A.Vardas;
                    if (A.Vardas == "x")
                    {
                        break;
                    }
                    cout << "Įveskite studento pavardę: ";
                    cin >> A.Pavarde;
                    skaiciu_generevimas(A);
                    grupe.push_back(A);
                    A.paz.clear();
                } 
                rezultatai (grupe);

                break;
            }    
            case 3:
                cout << "Pasirinkote generuoti studentų vardus, pavardes ir pažymius " << endl;
                cout << "-----------------------------------------------------------" << endl;
                break;
            case 4:
                cout << "Pasirinkote baigti darbą " << endl;
                cout << "-----------------------------------------------------------" << endl;
                break;
            default: 
                cout << "Prašau įveskite vieną iš duotų variantų " << endl; 
        }  
    }          
}


int main(){

    vector < Studentas > grupe;
    meniu (grupe);
    
    return 0;
}