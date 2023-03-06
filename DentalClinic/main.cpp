/**

Talpiga Andrei-Vlad
Grupa 131
Compilator: Code-Blocks

**/

#include <iostream>
#include <vector>

using namespace std;

class Pers
{
    string nume;
    string prenume;
    int varsta;

public:

    Pers()
    {
        this-> nume = "";
        this-> prenume = "";
        this-> varsta = 0;
    }

    Pers(string nume, string prenume, int varsta)
    {
        this-> nume = nume;
        this-> prenume = prenume;
        this-> varsta = varsta;
    }

    virtual ~Pers(){};

    virtual void citire()
    {
        cout<<"Nume: ";
        cin>>nume;
        cout<<endl;

        cout<<"Prenume: ";
        cin>>prenume;
        cout<<endl;

        cout<<"Varsta: ";
        cin>>varsta;
        cout<<endl;
    }

    virtual void afisare()
    {
        cout<<"Nume: "<<nume;
        cout<<endl;

        cout<<"Prenume: "<<prenume;
        cout<<endl;

        cout<<"Varsta: "<<varsta;
        cout<<endl;
    }

    int getVarsta()
    {
        return varsta;
    }


};

class Pacient: public Pers
{
    string medi; // medicamentatie

public:

    Pacient():Pers()
    {
        this-> medi = "";
    }

    Pacient(string nume, string prenume, int varsta, string medi): Pers(nume, prenume, varsta)
    {
        this-> medi = medi;
    }

    virtual ~Pacient(){};

    virtual void citire()
    {
        Pers::citire();

        cout<<"Medicamentatie: ";
        cin>>medi;
        cout<<endl;
    }

    virtual void afisare()
    {
        Pers::afisare();

        cout<<"Medicamentatie: "<<medi;
        cout<<endl;
    }
};

class Dentist: public Pers
{
    int vechime;
    string specializare;

public:

    Dentist(): Pers()
    {
        this-> vechime = 0;
        this-> specializare = "";
    }

    Dentist(string nume, string prenume, int varsta, int vechime, string specializare): Pers(nume, prenume, varsta)
    {
        this-> vechime = vechime;
        this-> specializare = specializare;
    }

    ~Dentist(){};

    void citire()
    {
        Pers::citire();

        cout<<"Vechime: ";
        cin>>vechime;
        cout<<endl;

        cout<<"Specializare: ";
        cin>>specializare;
        cout<<endl;
    }

    void afisare()
    {
        Pers::afisare();

        cout<<"Vechime: "<<vechime;
        cout<<endl;

        cout<<"Specializare: "<<specializare;
        cout<<endl;
    }
};

class Recep: public Pers
{
    int grad;
    string studii;

public:

    Recep(): Pers()
    {
        this-> grad = 0;
        this-> studii = "";
    }

    Recep(string nume, string prenume, int varsta, int grad, string studii): Pers(nume, prenume, varsta)
    {
        this-> grad = grad;
        this-> studii = studii;
    }

    ~Recep(){};

    void citire()
    {
        Pers::citire();

        cout<<"Grad: ";
        cin>>grad;
        cout<<endl;

        try
        {
            if(grad < 1 || grad > 3)
                throw(grad);
        }

        catch(int gr)
        {
            cout<<"Reintroduceti gradul: ";
            cin>>gr;
            grad = gr;
        }

        cout<<endl;

        cout<<"Studii: ";
        cin>>studii;
        cout<<endl;
    }

    void afisare()
    {
        Pers::afisare();

        cout<<"Grad: "<<grad;
        cout<<endl;

        cout<<"Studii: "<<studii;
        cout<<endl;
    }
};

class Tratament
{
    string specialitate;
    int durata;
    int pret;
    string medicamente;

public:

    Tratament()
    {
        this-> specialitate = "";
        this-> durata = 0;
        this-> pret = 0;
        this-> medicamente = "";
    }

    Tratament(string specialitate, int durata, int pret, string medicamente)
    {
        this-> specialitate = specialitate;
        this-> durata = durata;
        this-> pret = pret;
        this-> medicamente = medicamente;
    }

    virtual ~Tratament(){};

    virtual void cit()
    {
        cin >> specialitate;
        cin >> durata;
        cin >> pret;
        cin >> medicamente;
    }

    virtual void afis()
    {
        cout << specialitate;
        cout << durata;
        cout << pret;
        cout << medicamente;
    }

    void setSpec(string specialitate)
    {
        this-> specialitate = specialitate;
    }

    string getSpec()
    {
        return specialitate;
    }
};

class Edon: public Tratament
{
    int durataedon;

public:

    Edon(): Tratament()
    {
        this-> durataedon = 0;
    }

    Edon(string specialitate, int durata, int pret, string medicamente, int durataedon): Tratament(specialitate, durata, pret, medicamente)
    {
        this-> durataedon = durataedon;
    }

    ~Edon(){};

    setSpec(string edon = "Edontotie");

/*    void dublu()
    {
        if(getVarsta() < 18)
        {
            this-> durataedon = durataedon*2;
        }
    }
    */

};

class General: public Tratament
{
    string mod;

public:

    General(): Tratament()
    {
        this-> mod = "";
    }

    General(string specialitate, int durata, int pret, string medicamente, string mod): Tratament(specialitate, durata, pret, medicamente)
    {
        this-> mod = mod;
    }

    ~General(){};

    setSpec(string gen = "General");
};

class Aparat: public Tratament
{
    string aparat;

public:

    Aparat(): Tratament()
    {
        this-> aparat = "";
    }

    Aparat(string specialitate, int durata, int pret, string medicamente, string aparat): Tratament(specialitate, durata, pret, medicamente)
    {
        this-> aparat = aparat;
    }

    ~Aparat(){};

    setSpec(string apa = "Aparat");
};

void dosar(int nr)
{
    int i;
    vector <Pers*> v;
    string tip;
    int t[101];

    for(i = 0; i < nr; i++)
    {
        cout<<"Tip persoana "<<i+1<<": ";
        cout<<"p - pacient, d - dentist, r - receptioner: ";
        cin>>tip;



        if(tip == "p"){
            v.push_back(new Pacient());
            t[i] = 1;
        }

        if(tip == "d"){
            v.push_back(new Dentist());
            t[i] = 2;
        }

        if(tip == "r"){
            v.push_back(new Recep());
            t[i] = 3;
        }
    }

    i=0;

    for(auto p = v.begin(); p != v.end(); p++, i++)
    {
        cout<<"Persoana "<<i+1<<": ";

        if(t[i] == 1)
            cout<<"pacient:"<<endl;

        if(t[i] == 2)
            cout<<"dentist:"<<endl;

        if(t[i] == 3)
            cout<<"receptioner:"<<endl;

        (*p)->citire();
    }

i=0;

    for(auto p = v.begin(); p != v.end(); p++, i++)
    {
        cout<<"Persoana "<<i+1<<": ";

        if(t[i] == 1)
        {
            cout<<"pacient:"<<endl;

            vector <Tratament*> trat;

            int nrTrat, j;

            cin>>nrTrat;

            for(j = 0;j<nrTrat;j++)

                trat.push_back(new Tratament());

            for(auto k = trat.begin(); k!=trat.end();k++)
                (*k)->cit();

            for(auto k = trat.begin(); k!=trat.end();k++)
                (*k)->afis();
        }

        if(t[i] == 2)
            cout<<"dentist:"<<endl;

        if(t[i] == 3)
            cout<<"receptioner:"<<endl;

        (*p)->afisare();
    }
}

int main()
{
    int n;

    cout<<"Numar persoane: ";
    cin>>n;
    cout<<endl;

    dosar(n);

    return 0;
}
