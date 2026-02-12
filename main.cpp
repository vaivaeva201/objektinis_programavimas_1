#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std:: string;
using std:: vector;
using std:: cout;
using std:: cin;

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

    }
}

int main(){

    vector < Studentas > grupe;
    duomenu_ivedimas(grupe);
    
    return 0;
}