#include<iostream>
#include<string>
#include<list>
#include<algorithm>
#include<vector>

using namespace std;

class Port {

	string nume;
	string culoare;
	unsigned int tip;

public:

	Port(){}
	Port(string nume,string culoare,unsigned int tip)
	:nume(nume),culoare(culoare),tip(tip){}

	virtual void afisare() {

		cout << "------------------------" << endl;
		cout << "Nume: " << nume << endl;
		cout << "Culoare: " << culoare << endl;
		cout << "Tip(0-Vapor croaziera,1-Vapor marfa): " << tip << endl;
	}
	friend void listareLocuri(list<Port*>li);
	friend void afisare(list<Port*>li);
	friend void afisareCroaziera(list<Port*>li);
	friend void afisareMarfa(list<Port*>li);
	friend void stergere(list<Port*>&li);
	friend void cautareClase(list<Port*>li);
	friend void sortare(list<Port*>&li);
	friend ostream &operator<<(ostream &out, Port* &p);
};
	
class Supraincarcare {

public:
	string nume;
	string culoare;
	friend  istream & operator >>(istream &in, Supraincarcare &a);
};

	class vaporCroaziera :public Port {
		unsigned nrLocuri;
		unsigned int nrClase;
		unsigned int anFabricatie;

	public:
		vaporCroaziera(string nume, string culoare, unsigned int tip, unsigned int nrLocuri, unsigned int nrClase, unsigned int anFabricatie)
		:Port(nume,culoare,tip),nrLocuri(nrLocuri),nrClase(nrClase),anFabricatie(anFabricatie){}

		void afisare() {

			Port::afisare();
			cout << "Numar locuri: " << nrLocuri << endl;
			cout << "Numar clase: " << nrClase << endl;
			cout << "An fabricatie: " << anFabricatie << endl;

		}

		friend void sortare(list<Port*>&li);
		friend void cautareClase(list<Port*>li);
	};

	class vaporMarfa :public Port {

		unsigned int viteza;
		unsigned int capacitateCub;
		unsigned int capacitateTone;

	public:
		vaporMarfa() {}
		vaporMarfa(string nume,string culoare,unsigned int tip,unsigned int viteza,unsigned int capacitateCub,unsigned int capacitateTone)
		:Port(nume, culoare, tip), viteza(viteza),capacitateCub(capacitateCub),capacitateTone(capacitateTone){}

		void afisare() {

			Port::afisare();
			cout << "Viteza: " << viteza << endl;
			cout << "Capacitate transport(m^3): " << capacitateCub << endl;
			cout << "Capacitate transport(tone): " << capacitateTone << endl;


		}
		friend void afisareRapid(list<Port*>li);
	};
	istream &operator >>(istream &in, Supraincarcare &a) {

		cout << "Nume: "; cin >> a.nume;
		cout << "Culoare: "; cin >> a.culoare;
		return in;

	}
	ostream &operator<<(ostream &out, Port* &p) {
		p->afisare();
		return out;
	}

	void adaugare(list<Port*>&li) {


		string nume;
		string culoare;
		unsigned int tip;
		unsigned nrLocuri;
		unsigned int nrClase;
		unsigned int anFabricatie;
		unsigned int viteza;
		unsigned int capacitateCub;
		unsigned int capacitateTone;

		Port *P;
		Supraincarcare s;
		cin >> s;
		do 
		{
		  cout << "Tip(0-Vapor croaziera,1-Vapor marfa): "; cin >> tip;
		} while (tip != 0 && tip != 1);

		if (tip == 0) {
			cout << "Numar locuri: "; cin >> nrLocuri;
			cout << "Numar clase: "; cin >> nrClase;
			cout << "An fabricatie: "; cin >> anFabricatie;

			vaporCroaziera *c = new vaporCroaziera(s.nume, s.culoare, tip, nrLocuri, nrClase, anFabricatie);
			P = c;
			li.push_back(P);

		}
		else if (tip == 1) {
			cout << "Viteza: "; cin >> viteza;
			cout << "Capacitate transport(m^3): "; cin >> capacitateCub;
			cout << "Capacitate transport(tone): "; cin >> capacitateTone;

			vaporMarfa *m = new vaporMarfa(s.nume, s.culoare, tip, viteza, capacitateCub, capacitateTone);
			P = m;
			li.push_back(P);

		}
	}
	void afisare(list<Port*>li) {
		for (auto i = li.begin(); i != li.end(); i++) {

			Port *P = *i;
				P->afisare();
		}
	}
	void afisareCroaziera(list<Port*>li) {

		for (auto i = li.begin(); i != li.end(); i++) {

			Port *P = *i;
			if (P->tip == 0) {

				cout << P;
			}
		}
	}

		void afisareMarfa(list<Port*>li) {

			for (auto i = li.begin(); i != li.end(); i++) {

				Port *P = *i;
				if (P->tip == 1) {

					cout << P;
				}
			}
	}



	void listareLocuri(list<Port*>li) {

		for (auto i = li.begin(); i != li.end(); i++) {

			Port *P = *i;
			if (P->tip == 0) {

				P->afisare();
			}

		}
	}

	
	void stergere(list<Port*>&li) {

		string nume;
		cout << "Dati numele pe care doriti sa l stergeti: "; cin >> nume;

		for (auto i = li.begin(); i != li.end(); i++) {

			Port *P = *i;
			if (P->nume.compare(nume) == 0) {

				li.erase(i);
				return;

			}
		}
	}

	void sortare(list<Port*>&li) {

		li.sort([](Port*a, Port*b) {
		
			vaporCroaziera*c = (vaporCroaziera*)a;
			vaporCroaziera*d = (vaporCroaziera*)b;
			return(c->nrLocuri < d->nrLocuri);
		}
		);

	}


	void afisareRapid(list<Port*>li) {

		vector<unsigned int> viteza;
		for (auto i = li.begin(); i != li.end(); i++) {

			Port*P = *i;
			vaporMarfa *v = (vaporMarfa*)P;

			viteza.push_back(v->viteza);

		}

		for (auto j = li.begin(); j != li.end(); j++) {

			Port*P = *j;
			vaporMarfa *v = (vaporMarfa*)P;
			if (v->viteza == *max_element(viteza.begin(), viteza.end())) {
				P->afisare();
			}
		}

	}


	void cautareClase(list<Port*>li){
	
		bool gasit = false;

		unsigned int nrClase;
		cout << "Numar clase: "; cin >> nrClase;
	
		for (auto i = li.begin(); i != li.end(); i++) {

			Port *P = *i;
			vaporCroaziera *v = (vaporCroaziera*)P;

			if (v->nrClase== nrClase) {
				gasit = true;
				P->afisare();

			}
		}
	}



int main() {


	int opt;
	list<Port*>li;

	do
	{
		cout << "0.Iesire" << endl;
		cout << "1.Adaugare" << endl;
		cout << "2.Afisare vapoare pe 2 categorii(se aleg vapor de marfa sau croaziera)" << endl;
		cout << "3.Listarea vapoare Croaziera dupa nr.locuri" << endl;
		cout << "4.Stergerea dupa nume" << endl;
		cout << "5.Afisarea celui mai rapid vapor de marfa" << endl;
		cout << "6.Cautarea dupa nrClase" << endl;

		cout << "Optiunea dvs. este: "; cin >> opt;
		cout << "-----------------------------" << endl;
		switch (opt) {

		case 0:exit(0);
			break;
		case 1:adaugare(li);
			break;
		case 2:
			cout << "------------Croaziera------------" << endl;
			afisareCroaziera(li);
			cout << "--------------Marfa-------------" << endl;
			afisareMarfa(li);
			break;
		case 3:listareLocuri(li);
			break;
		case 4:stergere(li);
			afisare(li);
			break;
		case 5:afisareRapid(li);
			break;
		case 6:cautareClase(li);
			break;
		}
	
	
	} while (1);













	return 0;
}