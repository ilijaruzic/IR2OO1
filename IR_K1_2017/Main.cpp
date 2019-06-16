int main() {
	Izvodjac iz1("Micko", Zanr::POP), iz2("Uki", Zanr::ROK), iz3("Jocke", Zanr::REP);
	Pesma p1(2, 55, "Pesma", 2);
	Pesma p2(3, 23, "Pesma2", 1);
	Pesma p3(2, 49, "Pesma3", 1);
	Plejlista pl;
	p1.dodaj(&iz2); p1.dodaj(&iz3);
	p2.dodaj(&iz1); p3.dodaj(&iz2);
	pl.dodaj(&p1); pl.dodaj(&p2); pl.dodaj(&p3);
	Plejlista p = pl;
	p.uredi();
	pl.pisi();
	cout << "-------------------------" << endl;
	p.pisi();
}