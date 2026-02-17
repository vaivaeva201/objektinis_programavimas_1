#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

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
    while (true)
            {
                cin >> mok_skaicius; 

                if (cin.fail() || cin.peek() != '\n' || mok_skaicius < 1)
                {
                    cout << "Neteisingas skaičius! Įveskite naturalų skaičių: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            }

    for (int i = 0; i < mok_skaicius; i++)
    {
        int n, temp;
        cout << "Įveskite studento vardą ir pavardę: ";
        cin >> A.Vardas >> A.Pavarde;
        cout << "Įveskite semestro pažymius:\nKiek pažymių bus? ";
        while (true)
            {
                cin >> n; 

                if (cin.fail() || cin.peek() != '\n' || n < 1)
                {
                    cout << "Neteisingas skaičius! Įveskite naturalų skaičių: ";
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            }

        for (int j= 0; j < n; j++)
        {
            cout << "Iveskite " << j+1 << " pazymi is " << n << ": ";
            while (true)
            {
                cin >> temp;

                if (cin.fail() || cin.peek() != '\n' || temp < 1 || temp > 10)
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
            A.paz.push_back(temp);
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

int main(){

    vector < Studentas > grupe;
    duomenu_ivedimas (grupe);
    rezultatai (grupe);
    
    return 0;
}


