//#include<iostream>
//#include<string>
//#include<algorithm>
//#include<list>
//#include<vector>
//
//using namespace std;
//
//class Persoana {
//
//	string nume;
//	string prenume;
//	string numeLiceu;
//	unsigned int tip;
//
//public:
//
//	Persoana() {}
//	Persoana(string nume, string prenume, string numeLiceu, unsigned int tip)
//		:nume(nume), prenume(prenume), numeLiceu(numeLiceu), tip(tip) {}
//
//	virtual void afisare() {
//
//		cout << "-----------------------" << endl;
//		cout << "Nume: " << nume << endl;
//		cout << "Prenume: " << prenume << endl;
//		cout << "Numele liceului: " << numeLiceu << endl;
//		cout << "Tip(0-Elev,1-Profesor): " << tip << endl;
//
//	}
//
//	friend void cautare(list<Persoana*>li); 
//	friend void stergere(list<Persoana*>&li);
//	friend void afisareOrdonata(list<Persoana*>li);
//	friend void sortare(list<Persoana*>&li);
//	friend ostream &operator<<(ostream &out, Persoana* &p);
//};
//
//
//class Supraincarcare {
//public:
//	string nume;
//	string prenume;
//	string numeLiceu;
//	friend istream &operator>>(istream &in, Supraincarcare &s);
//};
//istream &operator>>(istream &in, Supraincarcare &s) {
//	
//	cout << "Nume: "; cin >> s.nume;
//	cout << "Prenume: "; cin >> s.prenume;
//	cout << "Nume liceu: "; cin >> s.numeLiceu;
//	return in;
//
//}
// ostream &operator<<(ostream &out, Persoana* &p) {
//	p->afisare();
//	return out;
//
//}
//class Elev :public Persoana {
//
//	unsigned int an;
//	unsigned int mediaGenerala;
//	string specializarea;
//
//public:
//
//	Elev() {}
//	Elev(string nume, string prenume, string numeLiceu, unsigned int tip,unsigned int an,unsigned int mediaGenerala,string specializarea)
//	:Persoana(nume,prenume,numeLiceu,tip),an(an),mediaGenerala(mediaGenerala),specializarea(specializarea){}
//
//	void afisare() {
//
//		Persoana::afisare();
//		cout << "Anul: " << an << endl;
//		cout << "Media generala: " << mediaGenerala << endl;
//		cout << "Specializarea: " << specializarea << endl;
//
//	}
//	/*unsigned int returnareMedie(){ return this->mediaGenerala; }*/
//
//	friend void stergere(list<Elev*>&li);
//	friend void sortare(list<Persoana*>&li);
//	friend void afisareOrdonata(list<Persoana*>li);
//};
//
//class Profesor :public Persoana {
//
//	unsigned int vechime;
//	string materie;
//	string gradDidactic;
//	unsigned int salar;
//
//public:
//
//	Profesor(){}
//	Profesor(string nume, string prenume, string numeLiceu, unsigned int tip,unsigned int vechime,string materie,string gradDidactic,unsigned int salar)
//	:Persoana(nume, prenume, numeLiceu, tip),vechime(vechime),materie(materie),gradDidactic(gradDidactic),salar(salar) {}
//
//	void afisare() {
//
//		Persoana::afisare();
//		cout << "Vechime: " << vechime << endl;
//		cout << "Materie: " << materie << endl;
//		cout << "Grad didactic: " << gradDidactic << endl;
//		cout << "Salar: " << salar << endl;
//	}
//	
//	friend void calculareSalar(list<Profesor*>li);
//};
//
//void adaugare(list<Persoana*>&li) {
//	string nume;
//	string prenume;
//	string numeLiceu;
//	unsigned int tip;
//	unsigned int an;
//	unsigned int mediaGenerala;
//	string specializarea;
//	unsigned int vechime;
//	string materie;
//	string gradDidactic;
//	unsigned int salar;
//
//	Supraincarcare s;
//	Persoana*P;
//
//	cin >> s;
//	
//	do
//	{
//		cout << "Tip(0-Elev,1-Profesor): "; cin >> tip;
//
//	} while (tip != 0 && tip != 1);
//
//	if (tip == 0) {
//
//		cout << "An: "; cin >> an;
//		cout << "Media generala: "; cin >> mediaGenerala;
//		cout << "Specializarea: "; cin >> specializarea;
//
//		Elev* e = new Elev(s.nume, s.prenume, s.numeLiceu, tip, an, mediaGenerala, specializarea);
//
//		P = e;
//		li.push_back(P);
//	}
//	else if (tip == 1) {
//
//		cout << "Vechimea: "; cin >> vechime;
//		cout << "Materie: "; cin >> materie;
//		cout << "Grad didactic: "; cin >> gradDidactic;
//		cout << "Salar: "; cin >> salar;
//
//		Profesor *prof = new Profesor(s.nume, s.prenume, s.numeLiceu, tip, vechime, materie, gradDidactic, salar);
//		P = prof;
//		li.push_back(P);
//
//
//
//	}
//
//}
//
//void afisare(list<Persoana*>li) {
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//		Persoana *P = *i;
//		P->afisare();
//
//	}
//
//}
//void afisareOrdonata(list<Persoana*>li) {
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//		Persoana *P = *i;
//		if (P->tip == 0) {
//			P->afisare();
//		}
//
//	}
//
//
//}
//
//void sortare(list<Persoana*>&li) {
//	
//	
//	li.sort([](Persoana *a, Persoana*b) {
//		
//		Elev* e = (Elev*)a;
//		Elev* d = (Elev*)b;
//		return (e->mediaGenerala<d->mediaGenerala);
//
//	});
//}
//
//void cautare(list<Persoana*>li) {
//
//	bool gasit = false;
//	string nume;
//	cout << "Numele pe care l cautati: "; cin >> nume;
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Persoana *P = *i;
//		if (P->nume.compare(nume) == 0) {
//			gasit = true;
//			P->afisare();
//
//		}
//		else cout << "Nu s a gasit !!" << endl;
//	}
//
//}
//
//void stergere(list<Persoana*>&li) {
//
//	
//
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Persoana *E = *i;
//		{
//			if (E->tip==0) {
//
//				li.erase(i);
//				cout<<E;
//				return;
//
//			}
//
//
//		}
//
//	}
//}
//void calculareSalar(list<Profesor*>li) {
//	unsigned int salar = 0;
//	unsigned int count = 0;
//	for (auto i = li.begin(); i != li.end(); i++) {
//
//		Profesor *P = *i;
//		salar += P->salar;
//		count++;
//		}
//	cout << "Salarul mediu: " << salar/count << endl;
//
//}
//
//int main() {
//
//	int opt;
//	list<Persoana*>li;
//
//
//	do
//	{
//		cout << "---------------------------------------" << endl;
//		cout << "1.Adaugare" << endl;
//		cout << "2.Afisare" << endl;
//		cout << "3.Afisare ordonata" << endl;
//		cout << "4.Cautare persoana dupa nume" << endl;
//		cout << "5.Stergere elevi cu media generala<5" << endl;
//		cout << "6.Calcularea salarului mediu" << endl;
//
//		cout << "Optiunea dvs. este: "; cin >> opt;
//
//		switch (opt) {
//		case 0:exit(0);
//			break;
//		case 1:adaugare(li);
//			break;
//		case 2:afisare(li);
//			break;
//		case 3:
//			sortare(li);
//			afisare(li);
//			break;
//		case 4:cautare(li);
//			break;
//		case 5:stergere(li);
//			break;
//		case 6:
//			break;
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
//
//
//
//
//
//
//
//	return 0;
//}