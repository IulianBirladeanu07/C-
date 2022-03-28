//#include<iostream>
//#include<list>
//#include<string>
//#include<algorithm>
//#include<fstream>
//
//using namespace std;
//
//class Recomandare {
//	string nume;
//	string numeRecomandant;
//	unsigned int cantitatea;
//	unsigned int tip;
//
//	public:
//
//		Recomandare() {}
//		Recomandare(string nume,string numeRecomandant,unsigned int cantitatea,unsigned int tip)
//		:nume(nume),numeRecomandant(numeRecomandant),cantitatea(cantitatea),tip(tip){}
//
//		virtual void afisare() {
//
//			cout << "-----------------------" << endl;
//			cout << "Nume: " << nume << endl;
//			cout << "Nume recomandant: " << numeRecomandant << endl;
//			cout << "Cantitatea: " << cantitatea << endl;
//			cout << "Tip(0-Echipamente,1-Medicamente): " << tip << endl;
//
//		}
//		friend ostream &operator<<(ostream &out, Recomandare* &a);
//		friend void cautareMedicament(list<Recomandare*>li);
//		friend void stergereEchipament(list<Recomandare*>&li);
//		friend void modificareCantitate(list<Recomandare*>li);
//
//};
//ostream &operator<<(ostream &out, Recomandare* &a) {
//	a->afisare();
//	return out;
//}
//
//
//class Echipamente :public Recomandare {
//
//	unsigned int esteNecesar;
//	unsigned int greutate;
//
//public:
//	Echipamente() {}
//	Echipamente(string nume,string numeRecomandant,unsigned int cantitatea,unsigned int tip,unsigned int esteNecesar,unsigned int greutate)
//	:Recomandare(nume,numeRecomandant,cantitatea,tip),esteNecesar(esteNecesar),greutate(greutate){}
//
//	void afisare() {
//
//		Recomandare::afisare();
//		cout << "Este necesar?(da/nu): " << esteNecesar << endl;
//		cout << "Greutatea: " << greutate << endl;
//	}
//	friend void modificareCantitate(list<Recomandare*>li);
//};
//
//class Medicamente :public Recomandare {
//
//	string descriere;
//	string contraIndicatii;
//
//public:
//
//	Medicamente() {}
//	Medicamente(string nume, string numeRecomandant, unsigned int cantitatea, unsigned int tip,string descriere,string contraIndicatii)
//		:Recomandare(nume, numeRecomandant, cantitatea, tip), descriere(descriere),contraIndicatii(contraIndicatii){}
//
//	void afisare() {
//
//		Recomandare::afisare();
//		cout << "Descriere: " << descriere << endl;
//		cout << "Contra indicatii: " << contraIndicatii << endl;
//	}
//
//	friend void cautareMedicament(list<Recomandare*>li);
//};
//
//
//class Supraincarcare {
//
//public:
//	string nume;
//	string numeRecomandant;
//	unsigned int cantitatea;
//	friend istream &operator>>(istream &in, Supraincarcare &s);
//
//};
//
//istream &operator>>(istream &in, Supraincarcare &s) {
//
//	cout << "Nume: "; cin >> s.nume;
//	cout << "Nume recomandant: "; cin >> s.numeRecomandant;
//	cout << "Cantitatea: "; cin >> s.cantitatea;
//	return in;
//}
//
//
//void adaugare(list<Recomandare*>&li) {
//	unsigned int tip;
//	unsigned int esteNecesar;
//	unsigned int greutate;
//	string descriere;
//	string contraIndicatii;
//
//	Supraincarcare s;
//	Recomandare *R;
//
//	cin >> s;
//	do {
//		cout << "Tip:(0-Echipamente,1-Medicamente): "; cin >> tip;
//	} while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//		do {
//			cout << "Este necesar(1/0): "; cin >> esteNecesar;
//		} while (esteNecesar != 0 && esteNecesar != 1);
//		cout << "Greutatea: "; cin >> greutate;
//		Echipamente *e = new Echipamente(s.nume, s.numeRecomandant, s.cantitatea, tip, esteNecesar, greutate);
//		
//		R = e;
//		li.push_back(R);
//
//	}
//	else if (tip == 1) {
//		cout << "Contraindicatii: "; cin >> contraIndicatii;
//		cout << "Descriere: "; cin >> descriere;
//		Medicamente *m = new Medicamente(s.nume, s.numeRecomandant, s.cantitatea, tip, contraIndicatii, descriere);
//	
//		R = m;
//		li.push_back(R);
//	}
//}
//void citireFisier(list<Recomandare*>&li) {
//	
//	ifstream f("DATE.txt");
//
//	unsigned int tip;
//	unsigned int esteNecesar;
//	unsigned int greutate;
//	string descriere;
//	string contraIndicatii;
//	string nume;
//	string numeRecomandant;
//	unsigned int cantitatea;
//	
//	Recomandare *R;
//
//	
//
//
//	while (!f.eof()) {
//	
//		f >> nume >> numeRecomandant >> cantitatea;
//		do {
//			 f >> tip;
//		} while (tip != 0 && tip != 1);
//
//		if (tip == 0) {
//
//			do {
//			   f>> esteNecesar;
//			} 
//			while (esteNecesar != 0 && esteNecesar != 1);
//
//			f>> greutate;
//			Echipamente *e = new Echipamente(nume, numeRecomandant, cantitatea, tip, esteNecesar, greutate);
//
//			R = e;
//			li.push_back(R);
//
//		}
//		else if (tip == 1) {
//			f>> contraIndicatii;
//			f>> descriere;
//			Medicamente *m = new Medicamente(nume, numeRecomandant, cantitatea, tip, contraIndicatii, descriere);
//
//			R = m;
//			li.push_back(R);
//		}
//	}
//}
//
//void afisare(list<Recomandare*>li) {
//
//	for (auto i = li.begin(); i!=li.end(); i++) {
//
//		Recomandare *R = *i;
//		cout << R;
//	}
//}
//
//void cautareMedicament(list<Recomandare*>li) {
//
//	bool gasit = false;
//	string descriere;
//	cout << "Descrierea cautata: "; cin >> descriere;
//	
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Recomandare *R = *i;
//		Medicamente *m = (Medicamente*)R;
//
//		if (m->descriere.compare(descriere) == 0) {
//			gasit = true;
//			R->afisare();
//
//		}
//
//		
//	}
//	if (!gasit) {
//		cout << "Nu s a gasit!!" << endl;
//	}
//}
//
//
//
//
//void stergereEchipament(list<Recomandare*>&li) {
//
//	string nume;
//	cout << "Dati numele pe care doriti sa l stergeti: "; cin >> nume;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Recomandare *R = *i;
//		
//		if (R->tip == 0)
//		{
//			if (R->nume.compare(nume) == 0) {
//
//				li.erase(i);
//				return;
//			}
//		}
//
//	}
//
//}
//
//void modificareCantitate(list<Recomandare*>li) {
//	
//	unsigned int cantitatea;
//	do {
//		cout << "1-pentru a creste cantitatea cu 2,0-pentru a scade cantitatea cu 2: "; cin >> cantitatea;
//	}
//	while(cantitatea != 0 && cantitatea != 1);
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Recomandare *R = *i;
//		Echipamente *e = (Echipamente*)R;
//
//		if (cantitatea == 0 && e->esteNecesar == 1) {
//
//			R->cantitatea -= 2;
//			
//		}
//		else if (cantitatea == 1 && e->esteNecesar == 1)
//
//			R->cantitatea += 2;
//
//		if (R->cantitatea - 2 == 0) {
//			cout << "Cantitatea a ajuns la 0!!" << endl;
//		}
//	}
//}
//
////Nu mi plac exceptiile=nu le implementez;
//
//
//
//int main() {
//
//	int opt;
//	list<Recomandare*>li;
//
//
//	do {
//		cout << "-----------------------" << endl;
//		cout << "0.Iesire" << endl;
//		cout << "1.Adaugare manuala" << endl;
//		cout << "2.Citire din fisier" << endl;
//		cout << "3.Afisare" << endl;
//		cout << "4.Cautarea unui medicament dupa descriere" << endl;
//		cout << "5.Stergerea unui echipament dupa nume" << endl;
//		cout << "6.Modificarea cantitatii(+/-2) pentru echipamentele absolut necesare" << endl;
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
//			afisare(li);
//			break;
//		case 3:afisare(li);
//			break;
//		case 4:cautareMedicament(li);
//			afisare(li);
//			break;
//		case 5:stergereEchipament(li);
//			afisare(li);
//			break;
//		case 6:modificareCantitate(li);
//			afisare(li);
//			break;
//		default:cout << "Optiunea este gresita!!" << endl;
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
//	return 0;
//}