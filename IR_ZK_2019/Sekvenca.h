#ifndef SEKVENCA_H
#define SEKVENCA_H

#include "GDodaj.h"
#include "GIndeks.h"

template<typename T>
class Sekvenca {
public:
	Sekvenca() = default;
	Sekvenca(const Sekvenca& s) { kopiraj(s); }
	Sekvenca(Sekvenca&& s) { premesti(s); }
	Sekvenca& operator=(const Sekvenca& s) {
		if (this != &s) {
			brisi();
			kopiraj(s);
		}
		return *this;
	}
	Sekvenca& operator=(Sekvenca&& s) {
		if (this != &s) {
			brisi();
			premesti(s);
		}
		return *this;
	}
	~Sekvenca() { brisi(); }
	Sekvenca& dodaj(T e);
	T uzmi();
	int duzina() const { return duz; }
	T& operator[](int i);
	const T& operator[](int i) const { return const_cast<Sekvenca&>(*this)[i]; }
private:
	struct Elem {
		T t;
		Elem *sled;
		Elem(T e) : t(e), sled(nullptr) {}
	};
	Elem *prvi = nullptr, *posl = nullptr;
	int duz = 0;
	bool moguce = true;
	void kopiraj(const Sekvenca& s);
	void premesti(Sekvenca& s);
	void brisi();
};

template<typename T>
Sekvenca<T>& Sekvenca<T>::dodaj(T t) {
	if (!moguce) throw GDodaj();
	posl = (prvi ? posl->sled : prvi) = new Elem(t);
	duz++;
	return *this;
}

template<typename T>
T Sekvenca<T>::uzmi() {
	T t = prvi->t;
	Elem *pom = prvi;
	prvi = prvi->sled;
	if (!prvi) posl = prvi;
	delete pom;
	duz--;
	moguce = false;
	return t;
}

template<typename T>
T& Sekvenca<T>::operator[](int i) {
	if (i < 0 || i >= duz) throw GIndeks();
	Elem *e = prvi;
	for (; i > 0; i--, e = e->sled);
	return e->t;
}

template<typename T>
void Sekvenca<T>::kopiraj(const Sekvenca<T>& s) {
	duz = 0;
	moguce = true;
	for (Elem *e = s.prvi; e; e = e->sled)
		dodaj(e->t);
}

template<typename T>
void Sekvenca<T>::premesti(Sekvenca<T>& s) {
	duz = s.duz;
	moguce = s.moguce;
	prvi = s.prvi;
	posl = s.posl;
	s.prvi = nullptr;
}

template<typename T>
void Sekvenca<T>::brisi() {
	while (prvi) {
		Elem *pom = prvi;
		prvi = prvi->sled;
		delete pom;
	}
}

#endif