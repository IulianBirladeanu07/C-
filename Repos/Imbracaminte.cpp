//#include<iostream>
//#include<fstream>
//#include<string>
//#include<list>
//#include<algorithm>
//
//
//using namespace std;
//
//
//enum tipArt { 
//	costum = 0,
//	pantalon=1,
//	fusta=2,
//	camasa=3
//};
//
//enum categorie {
//	cravate = 0,
//    esarfe=1,
//    bratari=2,
//    gablonzuri=3
//};
//
//class magazinHaine {
//
//	string nume;
//	string culoare;
//	unsigned int pret;
//	unsigned int tip;
//	
//
//public:
//
//	magazinHaine(string nume,unsigned int pret,string culoare,unsigned int tip)
//		:nume(nume),pret(pret),culoare(culoare),tip(tip) {}
//
//	virtual void afisare() {
//
//		cout << "-----------------" << endl;
//		cout << "Nume: " << nume << endl;
//		cout << "Pret: " << pret << endl;
//		cout << "Culoare: " << culoare << endl;
//		cout << "Tip(0-Articol vestimentar,1-accesoriu): " << tip << endl;
//	}
//
//
//	friend ostream& operator<<(ostream& out, magazinHaine*& m);
//	friend void cautare(list<magazinHaine*>li);
//	friend void cautarePret(list<magazinHaine*>li);
//	friend void stergere(list<magazinHaine*>& li);
//
//};
//
//class articolVestimentar :public magazinHaine {
//	
//	
//	unsigned int marime;
//	int tipArticol;
//
//public:
//	articolVestimentar(string nume, unsigned int pret, string culoare, unsigned int tip,unsigned int marime,unsigned int tipArticol )
//		:magazinHaine(nume,pret,culoare,tip),marime(marime),tipArticol(tipArticol) {}
//
//	void afisare() {
//		magazinHaine::afisare();
//		cout << "Marime: " << marime << endl;
//		cout << "Tip Articol(0-Costum,1-Pantalon,2-Fusta,3-Camasa): " << tipArticol << endl;
//	}
//	friend void stergere(list<magazinHaine*>& li);
//};
//
//
//class Accesorii:public magazinHaine{
//
//	string material;
//	unsigned int categorie;;
//
//public:
//	Accesorii(string nume, unsigned int pret, string culoare, unsigned int tip, string material,unsigned int categorie)
//		:magazinHaine(nume, pret, culoare, tip),material(material) {}
//
//	void afisare() {
//		magazinHaine::afisare();
//		cout << "Material: " << material << endl;
//		cout << "Categoria(0-Cravate,1-Esarfe,2-Bratari,3-Gablonzuri): " << categorie << endl;
//	}
//
//};
//
//class Supraincarcare {
//
//public: 
//	string nume;
//	string culoare;
//	unsigned int pret;
//	
//	friend istream& operator>>(istream& in, Supraincarcare& s);
//
//};
//
//
//istream& operator>>(istream& in, Supraincarcare& s) {
//
//	cout << "Nume: "; cin >> s.nume;
//	cout << "Pret: "; cin >> s.pret;
//	cout << "Culoare: "; cin >> s.culoare;
//	return in;
//
//}
//
//ostream& operator<<(ostream& out, magazinHaine*& m) {
//
//	m->afisare();
//	return out;
//}
//
//void adaugare(list<magazinHaine*>& li) {
//	
//	unsigned int tip;
//	unsigned int marime;
//	unsigned int tipArticol;
//	unsigned int categorie;
//	string material;
//	Supraincarcare s;
//	magazinHaine* M;
//
//	cin >> s;
//
//	do {
//		cout << "Tip(0-Articole vestimentar,1-accesoriu): "; cin >> tip;
//	} while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//		cout << "Marime: "; cin >> marime;
//		cout << "Tip Articol(0-Costum,1-Pantalon,2-Fusta,3-Camasa): "; cin >> tipArticol;
//		articolVestimentar* a = new articolVestimentar(s.nume, s.pret, s.culoare, tip, marime,tipArticol);
//		M = a;
//		li.push_back(M);
//
//	}
//	else if (tip == 1) {
//		cout << "Material: "; cin >> material;
//		cout << "Categoria(0-Cravate,1-Esarfe,2-Bratari,3-Gablonzuri): "; cin >> categorie;
//		Accesorii* ac = new Accesorii(s.nume, s.pret, s.culoare, tip, material, categorie);
//		M = ac;
//		li.push_back(M);
//	}
//}
//void afisare(list<magazinHaine*>li) {
//
//	for (auto i = li.begin(); i!=li.end(); i++) {
//
//		magazinHaine* M = *i;
//		cout << M;
//
//	}
//
//}
//void citireFisier(list<magazinHaine*>& li) {
//	
//	ifstream f("date.txt");
//	unsigned int tip;
//	unsigned int marime;
//	unsigned int tipArticol;
//	unsigned int categorie;
//	string material;
//	string nume;
//	string culoare;
//	unsigned int pret;
//	magazinHaine* M;
//
//	while (!f.eof()) {
//		f >> nume >> culoare >> pret;
//
//		do {
//			 f>> tip;
//		} while (tip != 0 && tip != 1);
//
//		if (tip == 0) {
//			
//			f>> marime;
//			f >> tipArticol;
//
//			articolVestimentar* a = new articolVestimentar(nume, pret, culoare, tip, marime, tipArticol);
//	
//			M = a;
//			li.push_back(M);
//
//		}
//		else if (tip == 1) {
//			f>> material;
//			f >> categorie;
//			Accesorii* ac = new Accesorii(nume,pret,culoare, tip, material, categorie);
//			M = ac;
//			li.push_back(M);
//		}
//	}
//}
//
//void cautare(list<magazinHaine*>li) {
//
//	bool gasit = false;
//	string nume;
//	cout << "Numele pe care doriti sa l cautati: "; cin >> nume;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine* M = *i;
//		if (M->nume.compare(nume) == 0) {
//
//			gasit = true;
//			cout << M;
//		}
//
//	}
//}
//
//void stergere(list<magazinHaine*>& li) {
//
//	string nume;
//	cout << "Dati numele pe care doriti sa l stergeti: "; cin >> nume;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine* M = *i;
//		if (M->nume.compare(nume) == 0) {
//
//			li.erase(i);
//			M->afisare();
//			return;
//		}
//		else cout << "Nu se gaseste!!" << endl;
//	}
//}
//
//void cautarePret(list<magazinHaine*>li) {
//
//	
//	
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine* M = *i;
//		if (M->pret>500) {
//
//			M->afisare();
//		}
//
//	}
//}
////nu mi plac exceptiile=>nu le implementez;
//int main() {
//
//	int opt;
//	list<magazinHaine*>li;
//
//	do
//	{
//		cout << "----------------" << endl;
//		cout << "0.Iesire" << endl;
//		cout << "1.Adaugare" << endl;
//		cout << "2.Citire din fisier" << endl;
//		cout << "3.Afisare" << endl;
//		cout << "4.Cautarea dupa nume" << endl;
//		cout << "5.Stergerea dupa nume" << endl;
//		cout << "Sa se implementeze supraincarcare intrare/iesire" << endl;
//
//		cout << "Optiunea dvs. este: "; cin >> opt;
//		cout << endl;
//
//		switch (opt) {
//
//		case 0:exit(0);
//			break;
//		case 1:adaugare(li);
//			break;
//		case 2:citireFisier(li);
//			break;
//		case 3:afisare(li);
//			break;
//		case 4:cautare(li);
//			break;
//		case 5:stergere(li);
//			break;
//
//
//		}
//
//
//
//
//
//
//	} while (1);
//
//
//
//
//	return 0;
//}