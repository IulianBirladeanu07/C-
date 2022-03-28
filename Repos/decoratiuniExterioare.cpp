//#include<iostream>
//#include<string>
//#include<list>
//#include<algorithm>
//#include<fstream>
//
//using namespace std;
//
//
//enum material{lemn=0,bronz,lut};
//enum tip{tufa=0,copaci};
//
//class Decoratiuni {
//	
//	string serieUnica;
//	unsigned int pret;
//	unsigned int inaltime;
//	unsigned int tip;
//
//public:
//	
//	Decoratiuni(){}
//	Decoratiuni(string serieUnica,unsigned int pret,unsigned int inaltime,unsigned int tip)
//	:serieUnica(serieUnica),pret(pret),inaltime(inaltime),tip(tip){}
//
//	virtual void afisare() {
//
//		cout << "------------------------------" << endl;
//		cout << "Serie unica: " << serieUnica << endl;
//		cout << "Pret: " << pret << endl;
//		cout << "Inaltime: " << inaltime << endl;
//		cout << "Tip(0-Statuete,1-Arbusti): "<<tip << endl;
//
//	}
//	friend ostream &operator<<(ostream &out, Decoratiuni * &d);
//	friend void cautare(list<Decoratiuni*>li);
//	friend void modificare(list<Decoratiuni*>li);
//	friend void stergere(list<Decoratiuni*>& li);
//};
//
//class Statuete :public Decoratiuni {
//
//	unsigned int material;
//	string autor;
//	
//public:
//
//	Statuete(){}
//	Statuete(string serieUnica, unsigned int pret, unsigned int inaltime, unsigned int tip,unsigned int material,string autor)
//	:Decoratiuni(serieUnica,pret,inaltime,tip),material(material),autor(autor){}
//
//	void afisare() {
//
//		Decoratiuni::afisare();
//		cout << "Autor: " << autor << endl;
//
//		switch (material) {
//
//		case lemn:cout << "Material: lemn" << endl;
//			break;
//		case bronz:cout << "Material: bronz" << endl;
//			break;
//		case lut:cout << "Material: lut" << endl;
//			break;
//		default:cout << "Gresit!" << endl;
//
//		}
//		
//	}
//
//};
//
//
//class Arbusti :public Decoratiuni {
//	
//	string denumire;
//	unsigned int tipArbust;
//
//public:
//
//	Arbusti() {}
//	Arbusti(string serieUnica, unsigned int pret, unsigned int inaltime, unsigned int tip,string denumire,unsigned int tipArbust ) 
//		:Decoratiuni(serieUnica, pret, inaltime, tip), denumire(denumire),tipArbust(tipArbust) {}
//
//	void afisare() {
//
//		Decoratiuni::afisare();
//		cout << "Denumire: " << denumire << endl;
//
//		switch (tipArbust) {
//
//		case tufa:cout << "Tip arbust: Tufa" << endl;
//			break;
//		case copaci:cout << "Tip arbust: Copac" << endl;
//			break;
//		default:cout << "Gresit!" << endl;
//			break;
//
//		}
//
//	}
//};
//
//class SupraIncarcare {
//	
//public:
//	string serieUnica;
//	unsigned int pret;
//	unsigned int inalitime;
//	friend istream&operator>>(istream& in, SupraIncarcare &s);
//
//};
//
//istream&operator>>(istream& in, SupraIncarcare &s) {
//
//	cout << "Serie unica: "; cin >> s.serieUnica;
//	cout << "Pret: "; cin >> s.pret;
//	cout << "Inaltime: "; cin >> s.inalitime;
//	return in;
//}
//
//ostream &operator<<(ostream&out, Decoratiuni* &d) {
//	
//	d->afisare();
//	return out;
//
//}
//
//
//void adaugare(list<Decoratiuni*>&li) {
//
//	unsigned int material;
//	string autor;
//	string denumire;
//	unsigned int tipArbust;
//	unsigned int tip;
//	SupraIncarcare s;
//	Decoratiuni *D;
//
//	cin >> s;
//	do
//	{
//		cout << "Tip(0-Statuete,1-Arbusti): "; cin >> tip;
//	} while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//
//		cout << "Autor: "; cin >> autor;
//		do
//		{
//			cout << "Material(0-Lemn,1-Bronz,2-Lut): "; cin >> material;
//		} while (material != 0 && material != 1 && material != 2);
//
//		Statuete *st = new Statuete(s.serieUnica, s.pret, s.inalitime,tip, material,autor);
//		D = st;
//		li.push_back(D);
//	}
//
//	else if (tip == 1) {
//
//		cout << "Denumire: "; cin >> denumire;
//		do
//		{
//			cout << "Tip arbust(0-Tufa,1-Copac): "; cin >> tipArbust;
//		} while (tipArbust != 0 && tipArbust != 1);
//
//		Arbusti *a = new Arbusti(s.serieUnica, s.pret, s.inalitime, tip, denumire, tipArbust);
//		D = a;
//		li.push_back(D);
//
//	}
//}
//
//void citireFisier(list<Decoratiuni*>&li) {
//
//	ifstream f("DATE.txt");
//
//	unsigned int material;
//	string autor;
//	string serieUnica;
//	string denumire;
//	unsigned int pret;
//	unsigned int inaltime;
//	unsigned int tipArbust;
//	unsigned int tip;
//	Decoratiuni *D;
//
//	f >> serieUnica; 
//	f >> pret;
//	f >> inaltime;
//
//	do
//	{
//		f >> tip;
//	} while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//
//		f >> autor;
//		do
//		{
//			f >> material;
//		} while (material != 0 && material != 1 && material != 2);
//
//		Statuete *st = new Statuete(serieUnica, pret, inaltime, tip, material, autor);
//		D = st;
//		li.push_back(D);
//	}
//
//	else if (tip == 1) {
//
//		f >> denumire;
//		do
//		{
//			f >> tipArbust;
//		} while (tipArbust != 0 && tipArbust != 1);
//
//		Arbusti *a = new Arbusti(serieUnica, pret, inaltime, tip, denumire, tipArbust);
//		D = a;
//		li.push_back(D);
//
//	}
//}
//
//
//void afisare(list<Decoratiuni*>li) {
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Decoratiuni* D = *i;
//		cout << D;
//
//	}
//}
//
//void cautare(list<Decoratiuni*>li) {
//	
//	bool gasit = false;
//	string serieUnica;
//	cout << "Serie unica: "; cin >> serieUnica;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//	Decoratiuni* D = *i;
//	if (D->serieUnica.compare(serieUnica) == 0)
//		gasit = true;
//	cout << D;
//	}
//
//}
//
//
//void stergere(list<Decoratiuni*>& li) {
//
//	string serieUnica;
//	cout << "Serie unica: "; cin >> serieUnica;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Decoratiuni* D = *i;
//		if (D->serieUnica.compare(serieUnica) == 0)
//
//			li.erase(i);
//		return;
//	}
//
//}
//
//
//void modificare(list<Decoratiuni*>li) {
//
//	string serieUnica;
//	unsigned int pret;
//	cout << "Serie unica: "; cin >> serieUnica;
//	cout << "Dati pretul cu care doriti sa l modificati: "; cin >> pret;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Decoratiuni* D = *i;
//		if (D->serieUnica.compare(serieUnica) == 0)
//
//			D->pret = pret;
//	}
//
//}
//
//
//int main() {
//
//
//	int opt;
//	list<Decoratiuni*>li;
//
//	do
//	{
//		cout << "------------------------------" << endl;
//		cout << "0.Iesire" << endl;
//		cout << "1.Adaugare" << endl;
//		cout << "2.Citire din fisier" << endl;
//		cout << "3.Afisare" << endl;
//		cout << "4.Cautare dupa serie" << endl;
//		cout << "5.Stergere dupa serie" << endl;
//		cout << "6.Modificare dupa pretului dupa serie" << endl;
//		cout << "Supra incarcarea operatorilor intrare/iesire" << endl;
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
//		case 4:cautare(li);
//			break;
//		case 5:stergere(li);
//			break;
//		case 6:modificare(li);
//			break;
//
//		}
//
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
//
