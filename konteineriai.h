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


#endif