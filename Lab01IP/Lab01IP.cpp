#include <iostream>
#include <string>
using namespace std;

class Persoana //clasa abstracta
{
private:
    string nume;
    int varsta;
    virtual void degeaba()=0;
};

class Didactic //interfata
{
    virtual void informatii()=0;
};

class Profesor : public Didactic
{
private:
    string nume;
    string rank;
public:
    Profesor() {}
    Profesor(string name, string pozitie) : nume(name), rank(pozitie) {}
    void setName(string name) 
    {
        nume=name;
    }
    string getName()
    {
        return nume;
    }
    void setRank(string pozitie)
    {
        rank=pozitie;
    }
    string getRank()
    {
        return rank;
    }
    void informatii() override
    {
        cout<<"Profesorul "<<nume<<" cu pozitia de "<<rank<<" este angajat la facultate."<<endl;
    }
    void preda()
    {
        cout<<"Profesorul "<<nume<<" nu are studenti pe care ii poate invata."<<endl;
    }
    void preda(int numar)
    {
        if(numar>0)
            cout<<"Profesorul "<<nume<<" preda pentru "<<numar<<" studenti."<<endl;
    }
    void preda(string name)
    {
        cout<<"Profesorul "<<nume<<" este mentor pentru studentul/studenta "<<name<<'.'<<endl;
    }
};

class Facultate
{
private:
    string nume;
    Profesor secretar;
public:
    Facultate() {}
    Facultate(string name, string profname, string rank) : nume(name), secretar(profname, rank) {}
    void compozitie()
    {
        cout<<"Cuprind fiecare birou din incinta."<<endl;
    }
    void setName(string name)
    {
        nume=name;
    }
    string getName()
    {
        return nume;
    }
};

class Birou : public Facultate
{
public:
    Birou() {}
    void compozitie()
    {
        cout<<"Sunt un birou si fac parte dintr-o facultate. Nu sunt compus."<<endl;
    }
};

class Rutina
{
private:
    string activitate_dimineata;
    string activitate_amiaza;
    string activitate_seara;
public:
    Rutina(string dim, string amiaza, string seara) : activitate_dimineata(dim), activitate_amiaza(amiaza), activitate_seara(seara) {}
};

class Student : public Persoana
{
private:
    string nume;
    int nota;
    int varsta;
    Rutina rutina;
public:
    Student(string name, int age, int new_nota, string a_dim, string a_amiaza, string a_seara) : nume(name), varsta(age), nota(new_nota), rutina(a_dim, a_amiaza, a_seara) {}
    void degeaba()
    {
        cout<<"Nimic."<<endl;
    }
    void setName(string name)
    {
        nume=name;
    }
    string getName()
    {
        return nume;
    }
    void setAge(int age)
    {
        varsta=age;
    }
    int getAge()
    {
        return varsta;
    }
    void setNota(int new_nota)
    {
        nota=new_nota;
    }
    int getNota()
    {
        return nota;
    }
};

int main()
{
    Facultate facultate1("UAIC","Pintea Camat","secretar");
    Facultate facultate2("FEEA","Tudor Gherasim","secretar");
    cout<<facultate1.getName()<<endl;
    facultate2.setName("IEEIA");
    cout<<facultate2.getName()<<endl;
    Profesor prof1("Mihai Sandulescu","laborant");
    prof1.informatii();
    Profesor prof2("Andrei Jmicean","asistent");
    prof2.setName("Andrei Licean");
    prof1.setRank("profesor de curs");
    prof1.informatii();
    prof2.informatii();
    prof1.preda();
    prof2.preda(15);
    prof2.preda("Anabela Felicia");
    Student student1("Lica Tomofaru",22,8,"mers cu bicicleta","facultate","petrecere");
    Facultate* facultate3 = new Facultate("AC","Andoria Hamadum","secretar");
    facultate3->compozitie();
    Birou* birou1 = new Birou;
    birou1->compozitie();
}