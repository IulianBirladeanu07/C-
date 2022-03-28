//#include<iostream>
//#include<list>
//#include<string>
//#include<algorithm>
//
//using namespace std;
//
//
//class magazinHaine {
//	string nume;
//	string codInregistrare;
//	unsigned int pret;
//	string producator;
//	string material;
//	unsigned int tip;
//
//public:
//	magazinHaine(){}
//	magazinHaine(string nume,string codInregistrare,unsigned int pret,string producator,string material,unsigned int tip)
//	:nume(nume),codInregistrare(codInregistrare),pret(pret),producator(producator),material(material),tip(tip){}
//
//	virtual void afisare() {
//		cout << "----------------------" << endl;
//		cout << "Nume: " << nume << endl;
//		cout << "Cod inregistrare: " << codInregistrare << endl;
//		cout << "Pret: " << pret << endl;
//		cout << "Producator: " << producator << endl;
//		cout << "Material: " << material << endl;
//		cout << "Tip(0-Copil,1-Adult): " << tip << endl;
//
//	}
//
//	friend ostream&operator<<(ostream &out, magazinHaine* &m);
//	friend void cautareNume(list<magazinHaine*>li);
//	friend void stergereMarime(list<magazinHaine*>&li);
//	friend void cautarePret(list<magazinHaine*>li);
//	friend void stergereCod(list<magazinHaine*>&li);
//};
//
//
//class Copil :public magazinHaine {
//
//	unsigned int varsta;
//	string asociere;
//
//public:
//	Copil() {}
//	Copil(string nume, string codInregistrare, unsigned int pret, string producator, string material, unsigned int tip,unsigned int varsta,string asociere)
//	:magazinHaine(nume,codInregistrare,pret,producator,material,tip),varsta(varsta),asociere(asociere){}
//
//	void afisare() {
//
//		magazinHaine::afisare();
//		cout << "Varsta: " << varsta << endl;
//		cout << "Animatii asociate: " << asociere << endl;
//
//
//	
//	}
//};
//
//class Adult :public magazinHaine {
//
//	unsigned int marime;
//	string sex;
//	string sportElegant;
//public:
//	Adult() {}
//	Adult(string nume, string codInregistrare, unsigned int pret, string producator, string material, unsigned int tip, unsigned int marime,string sex,string sportElegant)
//	:magazinHaine(nume, codInregistrare, pret, producator, material, tip), marime(marime),sex(sex),sportElegant(sportElegant){}
//
//	void afisare() {
//
//		magazinHaine::afisare();
//		cout << "Marime: " << marime << endl;
//		cout << "Sex(Barbat sau femeie): "<<sex << endl;
//		cout << "Cargoria(Sport sau elegant): " << sportElegant << endl;
//	}
//	
//	friend void stergereMarime(list<magazinHaine*>&li);
//};
//
//class Supraincarcare {
//public: 
//	string nume;
//	string codInregistrare;
//	unsigned int pret;
//	string producator;
//	string material;
//	friend istream &operator<<(istream &in, Supraincarcare &s);
//};
//istream &operator>>(istream &in, Supraincarcare &s) {
//
//	cout << "Nume: "; cin >> s.nume;
//	cout << "Cod Inregistrare: "; cin >> s.codInregistrare;
//	cout << "Pret: "; cin >> s.pret;
//	cout << "Producator: "; cin >> s.producator;
//	cout << "Material: "; cin >> s.material;
//	return in;
//}
//
//ostream&operator<<(ostream &out, magazinHaine* &m) {
//
//	m->afisare();
//	return out;
//}
//
//
//void adaugare(list<magazinHaine*>&li) {
//
//	unsigned int tip;
//	unsigned int varsta;
//	string asociere;
//	unsigned int marime;
//	string sex;
//	string sportElegant;
//
//	magazinHaine *M;
//	Supraincarcare s;
//
//	cin >> s;
//	cout << "Tip(0-Copil,1-Adult): "; cin >> tip;
//
//	if (tip == 0) {
//
//		cout << "Varsta: "; cin >> varsta;
//		cout << "Animatii asociate: "; cin >> asociere;
//
//		Copil*c = new Copil(s.nume, s.codInregistrare, s.pret, s.producator, s.material, tip, varsta, asociere);
//
//		M = c;
//		li.push_back(M);
//	}
//	else if (tip == 1) {
//
//		cout << "Marime: "; cin >> marime;
//		cout << "Introduceti sexul(Barbat sau Femeie): "; cin >> sex;
//		cout << "Introduceti categoria(Sport sau elegant): "; cin >> sportElegant;
//
//		Adult *a = new Adult(s.nume, s.codInregistrare, s.pret, s.producator, s.material, tip, marime, sex, sportElegant);
//
//		M = a;
//		li.push_back(M);
//	}
//}
//
//
//
//void afisare(list<magazinHaine*>li) {
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine *M = *i;
//		cout << M;
//
//	}
//}
//
//void cautareNume(list<magazinHaine*>li) {
//	
//	bool gasit = false;
//	string nume;
//	cout << "Marime: "; cin >> nume;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine *M = *i;
//		
//		if (M->nume.compare(nume) == 0) {
//			gasit = true;
//
//		}
//
//
//	}
//
//}
//
//void stergereMarime(list<magazinHaine*>&li) {
//
//	unsigned int marime;
//	cout << "Marime: "; cin >> marime;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine *M = *i;
//		Adult *a = (Adult*)M;
//
//		if (a->marime == marime) {
//
//			li.erase(i);
//			return;
//		}
//	
//
//	}
//}
//
//void cautarePret(list<magazinHaine*>li) {
//
//	bool gasit = false;
//	unsigned int pret;
//	cout << "Pret: "; cin >> pret;
//
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine *M = *i;
//		
//		if (M->pret == pret) {
//			gasit = true;
//		}
//
//	}
//}
//
//
//void stergereCod(list<magazinHaine*>&li) {
//
//	string codInregistrare;
//	cout << "Cod Inregistrare: "; cin >> codInregistrare;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		magazinHaine *M = *i;
//
//		if (M->codInregistrare == codInregistrare) {
//
//			li.erase(i);
//			return;
//		}
//
//
//	}
//}
//int main() {
//
//	list<magazinHaine*>li;
//
//	int opt;
//
//	do {
//
//		cout << "----------------------" << endl;
//		cout << "0.Iesire" << endl;
//		cout << "1.Adaugare" << endl;
//		cout << "2.Afisarea intregului stoc" << endl;
//		cout << "3.Cautare haine dupa nume" << endl;
//		cout << "4.Stergere dupa marime" << endl;
//		cout << "5.Afisarea hainelor cu un anumit pret" << endl;
//		cout << "6.Vanzarea unei haine dupa un cod de inregistrare" << endl;
//
//		cout << "Optiunea dvs. este: "; cin >> opt;
//		cout << endl;
//
//		switch (opt)
//		{
//		case 0:exit(0);
//			break;
//		case 1:adaugare(li);
//			break;
//		case 2:afisare(li);
//			break;
//		case 3:cautareNume(li);
//			afisare(li);
//			break;
//		case 4:stergereMarime(li);
//			afisare(li);
//			break;
//		case 5:cautarePret(li);
//			afisare(li);
//			break;
//		case 6:stergereCod(li);
//			afisare(li);
//			break;
//
//		default:cout << "Optiunea este gresita!" << endl;
//			break;
//		}
//
//
//
//
//	} while (1);
//
//
//	return 0;
//}