//#include<iostream>
//#include<fstream>
//#include<list>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//class Fruct {
//
//	string nume;
//	unsigned int pret;
//	unsigned int valabilitate;
//	unsigned int cantitate;
//	unsigned int tip;
//
//public:
//
//	Fruct() {}
//	Fruct(string nume, unsigned int pret, unsigned int valabilitate, unsigned int cantitate, unsigned int tip)
//		:nume(nume), pret(pret), valabilitate(valabilitate), cantitate(cantitate), tip(tip) {}
//
//	virtual void afisare() {
//
//		cout << "------------------------" << endl;
//		cout << "Nume: " << nume << endl;
//		cout << "Pret: " << pret << endl;
//		cout << "Valabilitate: " << valabilitate << endl;
//		cout << "Cantitate: " << cantitate << endl;
//		cout << "Tip(0-autohton,1-import): " << tip << endl;
//
//	}
//	friend void modificare(list<Fruct*>&li); 
//	friend void cautareValabilitate(list<Fruct*>li);
//	friend void afisareOrdonata(list<Fruct*>li);
//	friend void afisareMax(list<Fruct*>li);
//	friend void sortare(list<Fruct*> &li);
//	};
//
//
//	class Autohton :public Fruct {
//
//		string judetProvenienta;
//		string producator;
//		string dataCulese;
//
//	public:
//
//		Autohton() {}
//		Autohton(string nume, unsigned int pret, unsigned int valabilitate, unsigned int cantitate, unsigned int tip, string judetProvenienta, string producator, string dataCulese)
//			:Fruct(nume, pret, valabilitate, cantitate, tip), judetProvenienta(judetProvenienta), producator(producator), dataCulese(dataCulese) {}
//
//		 void afisare() {
//			 Fruct::afisare();
//			 cout << "Judet provenienta: " << judetProvenienta << endl;
//			 cout << "Producator: " << producator << endl;
//			 cout << "Data culegerii: " << dataCulese << endl;
//			 
//
//
//	}
//};
//	class Import :public Fruct {
//		
//		string taraProvenienta;
//		string importator;
//
//	public:
//		Import() {}
//		Import(string nume, unsigned int pret, unsigned int valabilitate, unsigned int cantitate, unsigned int tip, string taraProvenienta, string importator) 
//		:Fruct(nume, pret, valabilitate, cantitate, tip), taraProvenienta(taraProvenienta),importator(importator){}
//
//		void afisare() {
//
//			Fruct::afisare();
//			cout << "Tara de provenienta: " << taraProvenienta << endl;
//			cout << "Importator: " << importator << endl;
//		
//
//
//		}
//
//	};
//
//	void adaugare(list<Fruct*>&li) {
//		string nume;
//		unsigned int pret;
//		unsigned int valabilitate;
//		unsigned int cantitate;
//		unsigned int tip;
//		string judetProvenienta;
//		string producator;
//		string dataCulese;
//		string taraProvenienta;
//		string importator;
//
//		Fruct *F;
//
//		cout << "Nume: "; cin >> nume;
//		cout << "Pret: "; cin >> pret;
//		cout << "Valabilitate: "; cin >> valabilitate;
//		cout << "Cantitate: "; cin >> cantitate;
//		
//		do {
//			cout << "Tip(0-autohton,1-import): "; cin >> tip;
//		} while (tip != 0 && tip != 1);
//
//		if (tip == 0) {
//
//			cout << "Judetul de provenienta: "; cin >> judetProvenienta;
//			cout << "Producator: "; cin >> producator;
//			cout << "Data culegerii: "; cin >> dataCulese;
//
//			Autohton *a = new Autohton(nume, pret, valabilitate, cantitate, tip, judetProvenienta, producator, dataCulese);
//
//			F = a;
//			li.push_back(F);
//		}
//		else if (tip == 1) {
//
//			cout << "Tara de provenienta: "; cin >> taraProvenienta;
//			cout << "Importator: "; cin >> importator;
//
//			Import *i = new Import(nume, pret, valabilitate, cantitate, tip, taraProvenienta, importator);
//			F = i;
//			li.push_back(F);
//
//		}
//	}
//
//	void afisare(list<Fruct*>li) {
//
//		for (auto i = li.begin(); i != li.end(); i++) {
//
//			Fruct *F = *i;
//
//			F->afisare();
//
//
//		}
//
//	}
//	void modificare(list<Fruct*>&li) {
//		
//		unsigned int cantitate;
//		cout << "Dati cantitatea: "; cin >> cantitate;
//		
//		for (auto i = li.begin(); i != li.end(); i++) {
//
//			Fruct *F = *i;
//
//			if (F->cantitate==cantitate )
//			{
//				li.erase(i);
//				cout << "Vandut!" << endl;
//				return;
//			}
//			else 
//				if (F->cantitate <cantitate ) {
//					cout << "Out of stock!" << endl;
//					
//				}
//				else if (F->cantitate > cantitate) {
//
//					F->cantitate -= cantitate;
//					F->afisare();
//				}
//
//		}
//		
//	}
//
//	void sortare(list<Fruct*> &li) {
//
//		li.sort([](Fruct *a, Fruct *b) {
// return (a->nume.compare(b->nume) < 0);
// 
// });
//	}
//	void afisareOrdonata(list<Fruct*>li) {
//
//		for (auto i = li.begin(); i != li.end(); i++) {
//
//			Fruct *F = *i;
//			F->afisare();
//
//
//		}
//
//	}
//
//	void cautareValabilitate(list<Fruct*>li) {
//		
//		bool gasit = false;
//		unsigned int valabilitate;
//
//		cout << "Dati valabilitatea: "; cin >> valabilitate;
//
//		for (auto i = li.begin(); i != li.end(); i++) {
//
//			Fruct *F = *i;
//
//			if (F->valabilitate == valabilitate) {
//
//				gasit = true;
//				F->afisare();
//
//			}
//		}
//	}
//
//	void afisareMax(list<Fruct*>li) {
//
//		vector<unsigned int> pret;
//
//		for (auto i = li.begin(); i != li.end(); i++) {
//
//			Fruct *F = *i;
//			
//			if(F->tip==1){
//			pret.push_back(F->pret);
//			}
//		}
//	for (auto j = li.begin(); j != li.end(); j++) {
//				Fruct *F = *j;
//			
//				if (F->pret == *max_element(pret.begin(), pret.end()))
//				{
//						F->afisare();
//					}
//				}
//	}
//
//int main() {
//
//	int opt;
//	list<Fruct*>li;
//
//	do {
//		cout << "------------------------------" << endl;
//		cout << "1.Adaugare fruct" << endl;
//		cout << "2.Stergere/vanzare" << endl;
//		cout << "3.Afisare ordonata dupa nume" << endl;
//		cout << "4.Cautare dupa valabilitate" << endl;
//		cout << "5.Afisarea fructe" << endl;
//		cout << "6.Afisare fructului de import cu pretul cel mai mare" << endl;
//
//		cout << "Optiunea dvs. este: "; cin >> opt;
//		cout << "------------------------------" << endl;
//
//
//		switch (opt) {
//
//		case 0:exit(0);
//			break;
//		case 1:adaugare(li);
//			break;
//		case 2:modificare(li);
//			break;
//		case 3:sortare(li);
//			   afisareOrdonata(li);
//			break;
//		case 4:cautareValabilitate(li);
//			break;
//		case 5:afisare(li);
//			break;
//		case 6:afisareMax(li);
//			break;
//
//		}
//	} while (1);
//
//
//
//
//
//
//
//
//
//
//	return 0;
//}