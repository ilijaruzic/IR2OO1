#ifndef LISTA_H
#define LISTA_H

template <typename T>
class Lista {
public:
	Lista() { prvi = poslednji = tekuci = nullptr; }
	Lista(const Lista&) = delete;
	Lista& operator=(const Lista&) = delete;
	~Lista() { obrisiListu(); }
	Lista& dodajNaPocetak(const T& t) {
		prvi = !prvi ? poslednji : prvi->prethodni = new Element(t, nullptr, prvi);
		return *this;
	}
	Lista& dodajNaKraj(const T& t) {
		poslednji = !prvi ? prvi : poslednji->sledeci = new Element(t, poslednji, nullptr);
		return *this;
	}
	void postaviNaPrvi() const { tekuci = prvi; }
	void postaviNaPoslednji() const { tekuci = poslednji; }
	void postaviNaPrethodni() const { if (tekuci) tekuci = tekuci->prethodni; }
	void postaviNaSledeci() const { if (tekuci) tekuci = tekuci->sledeci; }
	bool imaTekuci() const { return tekuci != nullptr; }
	T& dohvatiTekuci() const {
		if (!tekuci) throw GNemaTekuceg();
		return tek->podatak;
	}
	Lista& obrisiTekuci();
private:
	struct Element {
		T podatak;
		Element *prethodni, *sledeci;
		Element(const T& t, Elem *p, Elem *s): podatak(t), prethodni(p), sledeci(s) {}
	};
	Element *prvi, *poslednji;
	mutable Element *tekuci;
	void obrisiListu();
};

#endif