#include <iostream>
#include <iomanip>
#include <string>
#include <numeric>
#include <algorithm>
#include <limits>
#include <random>
#include "RandInt.hpp"

using std:: string;
using std:: cout;
using std:: cin;
using std:: accumulate;
using std:: setw;
using std:: left;
using std:: right;
using std:: endl;

struct Studentas {
    string Vardas="A", Pavarde="BB";
    int* paz = nullptr;
    int paz_sk = 0;
    int egz_paz = 0;
    double rez;
};

void pazymio_ivedimas(Studentas &S, int naujas_paz)
{
    int* naujas = new int[S.paz_sk + 1];

    for (int i = 0; i < S.paz_sk; i++)
    {
        naujas[i] = S.paz[i];
    }
    naujas[S.paz_sk] = naujas_paz;
    delete[] S.paz;
    S.paz = naujas;
    S.paz_sk++;
}

void studento_ivedimas(Studentas* &grupe, int &kiek, Studentas naujas)
{
    Studentas* new_grupe = new Studentas[kiek + 1];

    for (int i = 0; i < kiek; i++)
    {
        new_grupe[i].Vardas = grupe[i].Vardas;
        new_grupe[i].Pavarde = grupe[i].Pavarde;
        new_grupe[i].paz_sk = grupe[i].paz_sk;
        new_grupe[i].egz_paz = grupe[i].egz_paz;
        new_grupe[i].rez = grupe[i].rez;

        new_grupe[i].paz = grupe[i].paz;
        grupe[i].paz = nullptr;
    }
    new_grupe[kiek] = naujas;
    delete[] grupe;
    grupe = new_grupe;
    kiek++;
}

void duomenu_ivedimas(Studentas* &grupe, int &studentu_sk)
{
    while(true)
    {
        Studentas A;
        A.paz = nullptr;
        int n, temp;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Įveskite studento vardą (jeigu įvedetė visus norimus studentus įrašykite 'x'): ";
        getline(cin, A.Vardas);
        if (A.Vardas == "x")
        {
            break;
        }
        cout << "Įveskite studento pavardę: ";
        getline(cin, A.Pavarde);

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
                pazymio_ivedimas(A, temp);     
            }
        }
        
        cout << "Įveskite egzamino pažymį: ";
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

        studento_ivedimas(grupe, studentu_sk, A);
    }  
    
}

void vidurkis(Studentas &x)
{
    double sum = 0;
    
    for (int i = 0; i < x.paz_sk; i++)
    {
        sum += x.paz[i];
    }
    x.rez = sum /(x.paz_sk*1.0) * 0.4 + x.egz_paz * 0.6;
}

void mediana(Studentas &x)
{
    double mediana;
    std::sort(x.paz, x.paz + x.paz_sk);

    if (x.paz_sk % 2 == 0)
    {
        mediana = (x.paz[x.paz_sk / 2 - 1] + x.paz[x.paz_sk / 2]) / 2.0;
    }
    else
    {
        mediana = x.paz[x.paz_sk / 2];
    }
    x.rez = mediana * 0.4 + x.egz_paz * 0.6;
}

void skaiciu_generevimas(Studentas &A)
{

    RandInt rnd{1, 10};
    int kiek = rnd();
    A.paz = new int [kiek];
    A.paz_sk = kiek;

    for (int i = 0; i < kiek; i++)
    {
       A.paz[i] = rnd();
    }

    A.egz_paz = rnd();

}

void rezultatai (Studentas* &grupe, int studentu_sk)
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
        for (int i = 0; i < studentu_sk; i++)
        {
            vidurkis(grupe[i]);
            cout << left << setw(20) << grupe[i].Pavarde << setw(20) << grupe[i].Vardas << setw(20) << std::fixed << std::setprecision(2) << grupe[i].rez << endl;

        }
    }
    else
    {
        cout << std::setw(20) << "Galutinis (Med.)" << endl;
        cout << "-----------------------------------------------------------" << endl;
        for (int i = 0; i < studentu_sk; i++)
        {
        mediana(grupe[i]);
        cout << left << setw(20) << grupe[i].Pavarde << setw(20) << grupe[i].Vardas << setw(20) << std::fixed << std::setprecision(2) << grupe[i].rez << endl;
        }

    }

}

void meniu(Studentas* &grupe, int &studentu_sk)
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
                duomenu_ivedimas(grupe, studentu_sk);
                rezultatai (grupe, studentu_sk);
                
                break;

            case 2:
            {
                cout << "Pasirinkote generuoti pažymius " << endl;
                cout << "-----------------------------------------------------------" << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while(true)
                {
                    Studentas A;
                    A.paz = nullptr;
                    A.paz_sk = 0;
                    int n, temp;
                    cout << "Įveskite studento vardą (jeigu įvedetė visus norimus studentus įrašykite 'x'): ";
                    getline(cin, A.Vardas);
                    if (A.Vardas == "x")
                    {
                        break;
                    }
                    cout << "Įveskite studento pavardę: ";
                    getline(cin, A.Pavarde);
                    skaiciu_generevimas(A);
                    studento_ivedimas(grupe, studentu_sk, A);
                } 
                rezultatai (grupe, studentu_sk);

                break;
            }    
            case 3:
            {
                cout << "Pasirinkote generuoti studentų vardus, pavardes ir pažymius " << endl;
                cout << "-----------------------------------------------------------" << endl;
                int max = 10;
                RandInt rnd{1, max};
                int kiek = rnd();

                for (int i = 0; i < kiek; i++) 
                {
                    Studentas A;
                    A.paz = nullptr;
                    A.paz_sk = 0;
                    RandInt rnd_index(0, 9); 

                    string vardai[10] = {"Emilija", "Alma", "Viktorija", "Egle", "Ieva", "Petras", "Jonas", "Titas", "Matas", "Lukas"};
                    string pavardes_m[10] = {"Pavardaite1", "Pavardaite2", "Pavardaite3", "Pavardaite4", "Pavardaite5", "Pavardaite6", "Pavardaite7", "Pavardaite8", "Pavardaite9", "Pavardaite10"};
                    string pavardes_v[10] = {"Pavardenis1", "Pavardenis2", "Pavardenis3", "Pavardenis4", "Pavardenis5", "Pavardenis6", "Pavardenis7", "Pavardenis8", "Pavardenis9", "Pavardenis10"};
                    A.Vardas = vardai[rnd_index()];

                    if (*A.Vardas.rbegin() == 's') 
                    {
                        A.Pavarde = pavardes_v[rnd_index()];
                    } 
                    else 
                    {
                        A.Pavarde = pavardes_m[rnd_index()];
                    }
                    skaiciu_generevimas(A);
                    studento_ivedimas(grupe, studentu_sk, A);
                }
                rezultatai (grupe, studentu_sk);

                break;
            }    
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

    Studentas * grupe = nullptr;
    int studentu_sk = 0;
    meniu (grupe, studentu_sk);

    for (int i = 0; i < studentu_sk; i++)
    {
        delete[] grupe[i].paz;
    }

    delete[] grupe;
    
    return 0;
}