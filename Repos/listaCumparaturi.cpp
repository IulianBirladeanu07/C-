//#include<iostream>
//#include<string>
//#include<list>
//#include<algorithm>
//#include<fstream>
//
//using namespace std;
//
//enum categorie{mancare=1,bautura};
//enum material{plastic=1,sticla,hartie};
//
//class Articol {
//
//	unsigned int tip;
//	string denumire;
//	unsigned int pret;
//	unsigned int cantitate;
//
//public:
// 
//	Articol() {}
//	Articol(string denumire,unsigned int pret,unsigned cantitate,unsigned int tip)
//	:denumire(denumire),pret(pret),cantitate(cantitate),tip(tip) {}
//
//	virtual void afisare() {
//
//		cout << "-----------------------------" << endl;
//		cout << "Denumire: " << denumire << endl;
//		cout << "Pret: " << pret << endl;
//		cout << "Cantitate: " << cantitate << endl;
//		cout << "Tip(0-Perisabil,1-Neperisabil): " << tip << endl;
//	}
//
//	friend void cautareDenumire(list<Articol*>li);
//	friend void stergereDenumire(list<Articol*>& li);
//	friend void modificareCantitate(list<Articol*>li);
//	friend ostream& operator<<(ostream& out, Articol*& a);
//};
//
//
//
//class Perisabil :public Articol {
//
//	string dataExpirare;
//	int categorie;
//
//public:
//
//	Perisabil() {}
//	Perisabil(string denumire, unsigned int pret, unsigned cantitate, unsigned int tip,string dataExpirare,int categorie)
//	:Articol(denumire,pret,cantitate,tip),dataExpirare(dataExpirare),categorie(categorie) {}
//
//	void afisare() {
//		
//		Articol::afisare();
//
//		cout << "Data expirare: " << dataExpirare << endl;
//		
//		switch (categorie) {
// 
//		case mancare:cout << "Categoria: Mancare" << endl;
//			break;
//		case bautura: cout << "Categoria: Bautura" << endl;
//			break;
//		default:cout << "Mancare sau bautura!" << endl;
//		
//		}
//		
//		
//
//	}
//
//
//};
//
//
//class Neperisabil :public Articol {
//	string domeniuDeUtilizare;
//	int material;
//
//public:
//
//	Neperisabil() {}
//	Neperisabil(string denumire, unsigned int pret, unsigned cantitate, unsigned int tip,string domeniuDeUtilizare, int categorie)
//		:Articol(denumire, pret, cantitate, tip), domeniuDeUtilizare(domeniuDeUtilizare),material(material) {}
//
//	void afisare() {
//
//		Articol::afisare();
//
//		cout << "Domeniu de utilizare: " << domeniuDeUtilizare << endl;
//		switch (material)
//		{
//
//		case plastic:cout << "Material: Plastic" << endl;
//			break;
//		case sticla:cout << "Material: Sticla" << endl;
//			break;
//		case hartie:cout << "Material: Hartie" << endl;
//			break;
//		default:
//			break;
//
//		}
//
//	}
//};
//
//class Supraincarcare {
//	
//public:
//	string denumire;
//	unsigned int pret;
//	unsigned int cantitate;
//	
//	friend istream& operator>>(istream& in, Supraincarcare& s);
//};
//
//
//
//istream& operator>>(istream& in, Supraincarcare& s) {
//
//	cout << "Denumire: "; cin >> s.denumire;
//	cout << "Pret: "; cin >> s.pret;
//	cout << "Cantitate: "; cin >> s.cantitate;
//	return in;
//
// }
//
//ostream& operator<<(ostream& out, Articol*& a) {
//
//	a->afisare();
//	return out;
//
//}
//
//void adaugare(list<Articol*>& li) {
//
//	string dataExpirare;
//	string domeniuDeUtilizare;
//	int categorie;
//	int material;
//	unsigned int tip;
//	Articol* A;
//	Supraincarcare s;
//
//	cin >> s;
//	do
//	{
//		cout << "Tip(0-Perisabil,1-Neperisabil): "; cin >> tip;
//	}   while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//		
//		cout << "Domeniu de utilizare "; cin >> domeniuDeUtilizare;
//		do
//		{
//			cout << "Categorie(1-mancare,2-bautura): "; cin >> categorie;
//		}   while (categorie != 1 && categorie != 2);
//
//		Perisabil* p = new Perisabil(s.denumire, s.pret, s.cantitate, tip, domeniuDeUtilizare, categorie);
//		A = p;
//		li.push_back(A);
//
//	}
//
//	else if (tip == 1) {
//		
//		cout << "Data expirare: "; cin >> dataExpirare;
//		do
//		{
//			cout << "Material(1-Plastic,2-Sticla,3-Hartie): "; cin >> material;
//		} while (material != 1 && material != 2 && material!=3);
//
//		Neperisabil* n = new Neperisabil(s.denumire, s.pret, s.cantitate, tip, dataExpirare, material);
//		A = n;
//		li.push_back(A);
//
//	}
//
//
//}
//
//
//void citireFisier(list<Articol*>& li) {
//
//	ifstream f("Exemplu.txt");
//	string denumire;
//	unsigned int pret;
//	unsigned int cantitate;
//	string dataExpirare;
//	string domeniuDeUtilizare;
//	int categorie;
//	int material;
//	unsigned int tip;
//	Articol* A;
//
//	while (!f.eof()) {
//		f >> denumire >> pret >> cantitate;
//	
//		do
//		{
//			f >> tip;
//		} while (tip != 0 && tip != 1);
//
//		if (tip == 0) {
//
//			f >> domeniuDeUtilizare;
//			do
//			{
//				f >> categorie;
//			} while (categorie != 1 && categorie != 2);
//
//			Perisabil* p = new Perisabil(denumire, pret, cantitate, tip, domeniuDeUtilizare, categorie);
//			A = p;
//			li.push_back(A);
//
//		}
//
//		else if (tip == 1) {
//
//			f >> dataExpirare;
//			do
//			{
//				f >> material;
//			} while (material != 1 && material != 2 && material != 3);
//
//			Neperisabil* n = new Neperisabil(denumire, pret, cantitate, tip, dataExpirare, material);
//			A = n;
//			li.push_back(A);
//
//		}
//	}
//	f.close();
//	
//}
//
//
//void afisare(list<Articol*>li) {
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Articol* A = *i;
//		cout << A;
//
//	}
//
//}
//void cautareDenumire(list<Articol*>li) {
//
//	bool gasit = false;
//	string denumire;
//	cout << "Denumire: "; cin >> denumire;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Articol* A = *i;
//		if (A->denumire.compare(denumire) == 0) {
//
//			gasit = true;
//			cout << "S-a gasit!" << endl;
//			cout << A;
//
//		}
//
//	}
//
//}
//
//
//void stergereDenumire(list<Articol*>& li) {
//
//	string denumire;
//	cout << "Denumire: "; cin >> denumire;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Articol* A = *i;
//		if (A->denumire.compare(denumire) == 0) {
//
//			li.erase(i);
//			return;
//		}
//
//	}
//}
//
//void modificareCantitate(list<Articol*>li) {
//
//	unsigned int cantitate;
//	cout << "Cantitatea cu care doriti s o inlocuiti: "; cin >> cantitate;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Articol* A = *i;
//		if (A->tip == 0) {
//
//			A->cantitate = cantitate;
//
//		}
//
//	}
//}
//
//int main() {
//
//
//	int opt;
//	list<Articol*>li;
//
//	do {
//		
//		cout << "-----------------------------" << endl;
//		cout << "0.Iesire" << endl;
//		cout << "1.Adaugare" << endl;
//		cout << "2.Citire din fisier" << endl;
//		cout << "3.Afisare" << endl;
//		cout << "4.Cautare" << endl;
//		cout << "5.Stergere" << endl;
//		cout << "6.Modificare" << endl;
//		cout << "Sa se foloseasca supraincarca intrare/iesire" << endl;
//
//		cout << "Optiunea dvs. este: "; cin >> opt;
//		cout << endl;
//
//		switch (opt) {
//		case 0:exit(0);
//			break;
//		case 1:adaugare(li);
//			break;
//		case 2:citireFisier(li);
//			   afisare(li);
//			break;
//		case 3:afisare(li);
//			break;
//		case 4:cautareDenumire(li);
//			break;
//		case 5:stergereDenumire(li);
//			   afisare(li);
//			break;
//		case 6:modificareCantitate(li);
//			break;
//
//		}
//
//
//
//
//
//	} while (1);
//
//	return 0;
//}