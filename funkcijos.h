#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "antrastes.h"

struct Studentas {
    string Vardas="A", Pavarde="BB";
    vector <int> paz;
    int egz_paz;
    double rez;
    double Vidurkis, Mediana;
};

void failu_generavimas(int Studentu_sk);
void studentu_skirstymas(vector < Studentas > &grupe);
void isvedimas_i_du_failus (vector < Studentas > &vargsiukai, vector < Studentas > &kietakai);
void skaiciuoti_viska(Studentas &x);
void skaityti_faila_automatiskai(string pav, vector<Studentas>& grupe);
void skaityti_faila(vector < Studentas > &grupe);
void duomenu_ivedimas(vector < Studentas > &grupe);
void vidurkis(Studentas &x);
void mediana(Studentas &x);
void skaiciu_generevimas(Studentas &A);
void rezultatai (vector < Studentas > &grupe);
void rezultatu_isvedimas(vector < Studentas > &grupe);
bool pagal_varda(const Studentas &a, const Studentas &b);
bool pagal_pavarde(const Studentas &a, const Studentas &b);
bool pagal_vid_did(const Studentas &a, const Studentas &b);
bool pagal_vid_maz(const Studentas &a, const Studentas &b);
bool pagal_med_did(const Studentas &a, const Studentas &b);
bool pagal_med_maz(const Studentas &a, const Studentas &b);
void rikiavimas(vector < Studentas > &grupe);
void meniu(vector < Studentas > &grupe);

#endif