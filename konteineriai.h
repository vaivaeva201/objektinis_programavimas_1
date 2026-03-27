#ifndef KONTEINERIAI_H
#define KONTEINERIAI_H
#include "antrastes.h"
#include <list>
#include <type_traits>

using std:: deque;
using std:: list;

template < typename Container >
void skaityti_failus (string pav, Container& grupe)
{

    std::ifstream fd(pav);
    if (!fd) 
    {
        std::cerr << "Klaida: nepavyko atidaryti failo!" << endl;
        return;
    }

    string eil;
    getline(fd, eil);

    while(getline(fd, eil)) 
    {
        if(eil.empty()) continue;
        Studentas A;
        std::istringstream eilute(eil);
        eilute >> A.Vardas >> A.Pavarde;
        
        int pazymys;
        while (eilute >> pazymys) 
        {
            A.paz.push_back(pazymys);
        }
        
        if (!A.paz.empty()) 
        {
            A.egz_paz = A.paz.back();
            A.paz.pop_back();
            skaiciuoti_viska(A);
            grupe.push_back(std::move(A));
        }
    }
    fd.close();
}


template < typename Container >
void rusiavimas_did (Container& grupe)
{
    if constexpr (std::is_same_v<Container, std::list<Studentas>>)
    {
        grupe.sort([](const Studentas &a, const Studentas &b) 
        {
            return a.Vidurkis > b.Vidurkis;
        });
    } 
    else 
    {
        sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) 
        {
            return a.Vidurkis > b.Vidurkis;
        });

    }
}

template < typename Container >
void stunedu_skirstymas (Container& grupe)
{
    Container vargsiukai;
    Container kietakai;

    if constexpr (std::is_same_v<Container, std::vector<Studentas>>) 
    {
        vargsiukai.reserve(grupe.size() / 2);
        kietakai.reserve(grupe.size() / 2);
    }

    for (auto &x : grupe) 
    {
        if (x.Vidurkis < 5.0)
            vargsiukai.push_back(std::move(x));
        else
            kietakai.push_back(std::move(x));
    }
    
    if constexpr(std::is_same_v<Container, vector<Studentas>> || std::is_same_v<Container, deque<Studentas>>)
    {
        vargsiukai.shrink_to_fit();
        kietakai.shrink_to_fit();
        grupe.shrink_to_fit();
    }

    grupe.clear(); 
}

template <typename Container>
void pirma_strategija(Container& grupe){
    Container vargsiukai;
    Container kietakai;

    for (const auto &s : grupe)
    {
        if (s.Vidurkis < 5){
            vargsiukai.push_back(s);
        } else if (s.Vidurkis >= 5){
            kietakai.push_back(s);
        }
    }

    if constexpr(std::is_same_v<Container, vector<Studentas>> || std::is_same_v<Container, deque<Studentas>>){
        vargsiukai.shrink_to_fit();
        kietakai.shrink_to_fit();
    }
}

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

    }

    cout << tipas << " rezultatai (vidurkis is 3 bandymu):" << endl;
    cout << "  Nuskaitymas užtruko: " << nuskaitym / 3.0 << " s" << endl;
    cout << "  Rikiavimas užtruko:   " << rikiav / 3.0 << " s" << endl;
    cout << "  Skirstymas užtruko:   " << skirst / 3.0 << " s" << endl;
    cout << "  Bendras veikimos laikas:      " << (nuskaitym + rikiav + skirst) / 3.0 << " s" << endl;
}

template <typename Container>
void strategiju_tyrimas (string failas, Container& grupe, string tipas)
{
    double nuskaitym = 0, rikiav = 0, skirst = 0;



    for (int i = 0; i < 1; i++) 
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

    }
    cout << "Programa su " << tipas << " vidutiniškai užtruko:      " << nuskaitym + rikiav + skirst << " s" << endl;
}

#endif