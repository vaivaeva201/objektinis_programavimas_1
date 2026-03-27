#include "antrastes.h"
#include "funkcijos.h"
#include "konteineriai.h"

template <typename Container>
void tyrimas (string failas, Container& grupe, string tipas)
{
    double nuskaitym = 0, rikiav = 0, skirst = 0;

    cout << "Testuojamas " << tipas  << endl;

    for (int i = 0; i < 3; i++) 
    {

        auto s = std::chrono::high_resolution_clock::now();
        skaityti_failus(failas, grupe);
        auto e = std::chrono::high_resolution_clock::now();
        nuskaitym += std::chrono::duration<double>(e - s).count();

        s = std::chrono::high_resolution_clock::now();
        rusiavimas_did(grupe);
        e = std::chrono::high_resolution_clock::now();
        rikiav += std::chrono::duration<double>(e - s).count();

        s = std::chrono::high_resolution_clock::now();
        stunedu_skirstymas(grupe);
        e = std::chrono::high_resolution_clock::now();
        skirst += std::chrono::duration<double>(e - s).count();

       // grupe.clear(); varg.clear(); kiet.clear();
    }

    cout << tipas << " rezultatai (vidurkis is 3 bandymu):" << endl;
    cout << "  Nuskaitymas užtruko: " << nuskaitym / 3.0 << " s" << endl;
    cout << "  Rikiavimas užtruko:   " << rikiav / 3.0 << " s" << endl;
    cout << "  Skirstymas užtruko:   " << skirst / 3.0 << " s" << endl;
    cout << "  Bendras veikimos laikas:      " << (nuskaitym + rikiav + skirst) / 3.0 << " s" << endl;
}

int main(){

    vector < Studentas > studentai_v;
    list < Studentas > studentai_l;
    deque < Studentas > studentai_d;

    int n = 10000;
    string failas = "Studentai_" + std::to_string(n) + ".txt";

    tyrimas(failas, studentai_v, "vekor");
    tyrimas(failas, studentai_l, "list");
    tyrimas(failas, studentai_d, "deque");
    


    return 0;
}