#include "funkcijos.h"

void failu_generavimas(int Studentu_sk)
{
    string pav = "Studentai_" + std::to_string(Studentu_sk) + ".txt";
    std::ofstream fr(pav);

    RandInt rnd{3, 20};
    int kiek_paz = rnd();
    
    std::ostringstream buferis;
    buferis << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
    for (int i = 0; i < kiek_paz; i++)
    {
        buferis << left << setw(20) << "ND" + std::to_string(i+1);
    }
    buferis << left << setw(20) << "Egz." << endl;

    RandInt random{1, 10};
    for (int i = 0; i < Studentu_sk; i++)
    {
        Studentas A;
        A.Vardas = "Vardas" + std::to_string(i+1);
        A.Pavarde = "Pavarde" + std::to_string(i+1);
        
        for (int j = 0; j < kiek_paz; j++)
        {
            int pazimys = random();
            A.paz.push_back(pazimys);
        }
        A.egz_paz = random();
        buferis << left << setw(20) << A.Vardas << setw(20) << A.Pavarde;
        for(auto x : A.paz)
        {
            buferis << left << setw(20) << x;
        }
        buferis << left << setw(20) << A.egz_paz << endl;
    }

    fr << buferis.str();
    fr.close();
}

void skaiciuoti_viska(Studentas &x)
{
    double sum = accumulate(x.paz.begin(), x.paz.end(), 0.0);
    x.Vidurkis = sum /(x.paz.size()*1.0) * 0.4 + x.egz_paz * 0.6;

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
    x.Mediana= mediana * 0.4 + x.egz_paz * 0.6;    
}

void skaityti_faila(vector < Studentas > &grupe)
{
    string failas;
    std:: ifstream fd;
    while (true)
    {
        system("ls *.txt");
        cout<<"Ivesk failo pavadinima: ";
        cin>>failas;

        try
        {
            fd.open(failas);
            if (!fd)
            {
                    throw std::runtime_error("Klaida: nepavyko atidaryti failo!");
            }
            break;
        }
        catch (const std::runtime_error &e)
	    {
		    std::cerr << e.what() << endl;
            fd.clear();
	    }
    }

    auto start = std::chrono::high_resolution_clock::now();

    std:: stringstream buferis;
    string eil;

    if (!fd)
    {
        std:: cerr << "Klaida: nepavyko atidaryti failo!" << endl;
        return;
    }
    buferis << fd.rdbuf();
    fd.close();
    getline(buferis, eil);

    while(getline(buferis, eil))
    {
        Studentas A;
        std:: istringstream eilute(eil);
        eilute >> A.Vardas >> A.Pavarde;
        int pazymys;
        while (eilute >> pazymys)
        {
            A.paz .push_back(pazymys);
        }
        A.egz_paz = A.paz.back();
        A.paz.pop_back();
        skaiciuoti_viska(A);
        grupe.push_back(A);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    cout << "Failo nuskaitymas ir skaičiavimai užtruko: " << diff.count() << " s" << endl;
}

void duomenu_ivedimas(vector < Studentas > &grupe)
{
    Studentas A;

    while(true)
    {
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
            try
            {
                cin >> temp;
                if(cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Įvedėte ne skaičių.");
                }
                if (temp == -1)
                    break;
                if(temp < 1 || temp > 10)
                    throw std::out_of_range("Neteisingas pažymys! Įveskite sveikąjį skaičių nuo 1 iki 10.");
                A.paz.push_back(temp);
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
        }
        
        cout << "Įveskite egzamino pažymį: ";
        while (true)
        {   
            try
            {
                cin >> A.egz_paz;   
                if(cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Įvedėte ne skaičių.");
                }
                if(A.egz_paz < 1 || A.egz_paz > 10)
                    throw std::out_of_range("Neteisingas pažymys! Įveskite sveikąjį skaičių nuo 1 iki 10.");
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
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

void skaiciu_generevimas(Studentas &A)
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
        try
        {
            cin >> formatas;   
                if(cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Įvedėte ne skaičių.");
                }
                if(formatas != 1 && formatas != 0)
                    throw std::out_of_range("Neteisingas skaičius! Įveskite 0 arba 1.");
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
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

void rezultatu_isvedimas(vector < Studentas > &grupe)
{

    std::ostringstream buferis;
    buferis << left << setw(20) << "Pavardė" << setw(20) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;
    buferis << "----------------------------------------------------------------------------" << endl;

    for (auto &x : grupe) {
        buferis << left << setw(20) << x.Pavarde << setw(20) << x.Vardas << setw(20) << std::fixed << std::setprecision(2) << x.Vidurkis << setw(20) << std::fixed << std::setprecision(2) << x.Mediana << endl;
    }

    int pasirinkimas = 0;

    cout << "Pasirinkite kur norite matyti rezultatus: " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "1 - Komandinėje eilutėje;" << endl;
    cout << "2 - Faile;" << endl;
    cout << endl;

    while (true)
    { 
        try
        {
            cin >> pasirinkimas;   
                if(cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Įvedėte ne skaičių.");
                }
                if(pasirinkimas < 1 ||  pasirinkimas > 2)
                    throw std::out_of_range("Neteisingas pasirinkimas! Prašau įveskite vieną iš duotų variantų.");
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
    }

    switch(pasirinkimas)
    {
        case 1:
            cout << buferis.str();
            break;
        case 2:
        {
            std::ofstream fr("studentuRezultatai.txt");
            fr << buferis.str();
            fr.close();
            break;
        }    
        default: 
                cout << "Prašau įveskite vieną iš duotų variantų " << endl; 

    }   

}

bool pagal_varda(const Studentas &a, const Studentas &b) 
{ 
    return a.Vardas < b.Vardas; 
}

bool pagal_pavarde(const Studentas &a, const Studentas &b) 
{ 
    return a.Pavarde < b.Pavarde; 
}

bool pagal_vid_did(const Studentas &a, const Studentas &b) 
{ 
    return a.Vidurkis < b.Vidurkis; 
}

bool pagal_vid_maz(const Studentas &a, const Studentas &b) 
{ 
    return a.Vidurkis > b.Vidurkis; 
}

bool pagal_med_did(const Studentas &a, const Studentas &b) 
{ 
    return a.Mediana < b.Mediana; 
}

bool pagal_med_maz(const Studentas &a, const Studentas &b) 
{ 
    return a.Mediana > b.Mediana; 
}

void rikiavimas(vector < Studentas > &grupe)
{
    int pasirinkimas = 0;
    cout << "Pasirinkite rikiavimo būdą:" << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "1 - Rikiuoti pagal vardą;" << endl;
    cout << "2 - Rikiuoti pagal pavardę;" << endl;
    cout << "3 - Rikiuoti pagal vidurkį (nuo mažiausio iki didžiausio);" << endl;
    cout << "4 - Rikiuoti pagal vidurkį (nuo didžiausio iki mažiausio);" << endl;
    cout << "5 - Rikiuioti pagal mediana (nuo mažiausio iki didžiausio);" << endl;
    cout << "6 - Rikiuoti pagal mediana (nuo didžiausio iki mažiausio);" << endl;
    cout << endl;

    while (true)
    { 
        try
        {
            cin >> pasirinkimas;   
                if(cin.fail() || cin.peek() != '\n')
                {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    throw std::invalid_argument("Įvedėte ne skaičių.");
                }
                if(pasirinkimas < 1 ||  pasirinkimas > 6)
                    throw std::out_of_range("Neteisingas pasirinkimas! Prašau įveskite vieną iš duotų variantų.");
                break;
            }
            catch(const std::invalid_argument& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cerr << e.what() << " Įveskite dar kartą: " << endl;
            }
    }

    switch (pasirinkimas)
    {
    case 1:
        std::sort(grupe.begin(), grupe.end(), pagal_varda);
        break;
    case 2:
        std::sort(grupe.begin(), grupe.end(), pagal_pavarde);
        break;
    case 3:
        std::sort(grupe.begin(), grupe.end(), pagal_vid_did);
        break;
    case 4:
        std::sort(grupe.begin(), grupe.end(), pagal_vid_maz);
        break;
    case 5:
        std::sort(grupe.begin(), grupe.end(), pagal_med_did);
        break;
    case 6:
        std::sort(grupe.begin(), grupe.end(), pagal_med_maz);
        break;
    default:
        cout << "Prašau įveskite vieną iš duotų variantų " << endl; 
    }
}

void meniu(vector < Studentas > &grupe)
{
    int pasirinkimas = 0;

    while(pasirinkimas != 5)
    {    
        cout << endl;
        cout << "Pasirinkite programos eigą: " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "1 - Viską įvesti ranka;" << endl;
        cout << "2 - Generuoti pažymius;" << endl;
        cout << "3 - Generuoti studentų vardus, pavardes ir pažymius;" << endl;
        cout << "4 - Nuskaityti duomenis iš failo;" << endl;
        cout << "5 - Baigti darbą;" << endl;
        cout << endl;

        while (true)
        { 
            try
            {
                cin >> pasirinkimas;   
                    if(cin.fail() || cin.peek() != '\n')
                    {
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        throw std::invalid_argument("Įvedėte ne skaičių.");
                    }
                    if(pasirinkimas < 1 ||  pasirinkimas > 5)
                        throw std::out_of_range("Neteisingas pasirinkimas! Prašau įveskite vieną iš duotų variantų.");
                    break;
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << e.what() << " Įveskite dar kartą: " << endl;
                }
                catch(const std::out_of_range& e)
                {
                    std::cerr << e.what() << " Įveskite dar kartą: " << endl;
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
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while(true)
                {
                    Studentas A;
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
                    grupe.push_back(A);
                    A.paz.clear();
                } 
                rezultatai (grupe);

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
                    grupe.push_back(A);
                }
                rezultatai (grupe);

                break;
            } 
            case 4:
                cout << "Pasirinkote nuskaityti duomenis iš failo " << endl;
                cout << "-----------------------------------------------------------" << endl;
                skaityti_faila(grupe);
                rikiavimas(grupe);
                rezultatu_isvedimas(grupe);

                break;   
            case 5:
                cout << "Pasirinkote baigti darbą " << endl;
                cout << "-----------------------------------------------------------" << endl;

                break;
            default: 
                cout << "Prašau įveskite vieną iš duotų variantų " << endl; 
        }  
    }          
}