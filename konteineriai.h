#ifndef KONTEINERIAI_H
#define KONTEINERIAI_H
#include "antrastes.h"
#include <list>

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



#endif