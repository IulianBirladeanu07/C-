#define _CRT_SECURE_NO_WARNINS
#include<iostream>
#include<string>
#include<list>
#include<iterator>

using namespace std;

class Agentie
{
	string nume;
	float pret;
	bool tenis;
public:
	Agentie() {};
	Agentie(string nume, float pret, bool tenis)
	{
		this->nume = nume;
		this->pret = pret;
		this->tenis = tenis;
	}

	virtual void afisare()
	{
		cout << "--------------------" << endl;
		cout << "Nume:" << this->nume <<endl;
		cout << "Pret:" << this->pret<<endl;
		if (this->tenis == 1)
			cout << "Tenis:da" << endl;
		else
			cout << "Tenis:nu" << endl;
	}
	friend void stergere(list<Agentie*> &Agen);
	friend void sortare(list<Agentie*> &Agen);
};

class Hotel :public Agentie
{
	int nr_stele;
	bool piscina;
	bool sauna;
public:
	Hotel() {};
	Hotel(string nume, float pret, bool tenis, int nr_stele, bool piscina, bool sauna) :Agentie(nume, pret, tenis)
	{
		this->nr_stele = nr_stele;
		this->piscina = piscina;
		this->sauna = sauna;
	}
	void afisare()
	{
		Agentie::afisare();
		cout << "Numar stele:" << this->nr_stele << endl;
		if (this->piscina == 1)
			cout << "Piscina:da" << endl;
		else
			cout << "Piscina:nu" << endl;
		if (this->sauna == 1)
			cout << "Sauna:da" << endl;
		else
			cout << "Sauna:nu" << endl;
		cout << "--------------------" << endl;
	}
};

class Pensiune :public Agentie
{
	int nr_margarete;
public:
	Pensiune() {};
	Pensiune(string nume, float pret, bool tenis, int nr_margarete) :Agentie(nume, pret, tenis)
	{
		this->nr_margarete = nr_margarete;
	}

	void afisare()
	{
		Agentie::afisare();
		cout << "Numar margarete:" << this->nr_margarete << endl;
		cout << "--------------------" << endl;
	}
};

void inserare(list<Agentie*> &Agen)
{
	string nume;
	float pret;
	bool tenis;
	int nr_stele;
	bool piscina;
	bool sauna;
	int nr_margarete;
	Agentie *a;

	cout << "Dati numele:";
	cin >> nume;
	cout << "Dati pretul(>1000 hotel, <1000 pensiune):";
	cin >> pret;
	cout << "Are teren de tenis? 1-da, 0-nu:";
	cin >> tenis;
	if (pret > 1000)
	{
		cout << "Dati numarul de stele:";
		cin >> nr_stele;
		cout << "Are piscina? 1-da, 0-nu:";
		cin >> piscina;
		cout << "Are sauna? 1-da, 0-nu:";
		cin >> sauna;
		Hotel* H = new Hotel(nume, pret, tenis, nr_stele, piscina, sauna);
		a = H;
		Agen.push_back(a);
	}
	else
	{
		cout << "Dati numarul de margarete:";
		cin >> nr_margarete;
		Pensiune *P = new Pensiune(nume, pret, tenis, nr_margarete);
		a = P;
		Agen.push_back(a);
	}
}

void afisare(list<Agentie*> Agen)
{
	for (auto i = Agen.begin(); i != Agen.end(); i++)
	{
		Agentie* a = *i;
		a->afisare();
	}
}

void stergere(list<Agentie*> &Agen)
{
	string num;
	cout << "Dati numele pe care doriti sa il stergeti:";
	cin >> num;
	for (auto i = Agen.begin(); i != Agen.end(); i++)
	{
		Agentie *a = *i;
		if (a->nume.compare(num) == 0)
		{
			Agen.erase(i);
			return;
		}
	}
}

void sortare(list<Agentie*> &Agen)
{
	Agen.sort([](Agentie *a, Agentie *b) {return a->nume < b->nume; });
	
}

int main()
{
	list<Agentie*> Agen;
	int opt;
	do
	{
		cout << "0.Iesire" << endl;
		cout << "1.Inserare oferte" << endl;
		cout << "2.Afisare oferte" << endl;
		cout << "3.Afisare oferte ordonate dupa nume" << endl;
		cout << "4.Sterge oferta dupa pret" << endl;
		cout << "Optiunea dumneavoastra este:";
		cin >> opt;
		switch (opt)
		{
		case 0:exit(0);
			break;
		case 1: inserare(Agen);
			break;
		case 2:afisare(Agen);
			break;
		case 3:sortare(Agen);
			afisare(Agen);
			break;
		case 4:stergere(Agen);
			break;
		default:cout << "Optiune gresita!!!!" << endl;
			break;
		}

	} while (opt!=0);
	system("pause");
	return 0;
}