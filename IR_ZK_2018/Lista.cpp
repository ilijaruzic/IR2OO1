#include "Lista.h"

template <typename T>
void Lista<T>::obrisiListu() {
	while (prvi) {
		Elem *stari = prvi;
		prvi = prvi->sledeci;
		delete stari;
	}
	poslednji = tekuci = nullptr;
}

template <typename T>
Lista<T>& Lista<T>::obrisiTekuci() {
	if (!tekuci) throw GNemaTekuceg();
	if (tekuci->prethodni) tekuci->prethodni->sledeci = tekuci->sledeci;
	if (tekuci->sledeci) tekuci->sledeci->prethodni = tekuci->prethodni;
	if (tekuci == prvi) prvi = prvi->sledeci;
	if (tekuci == poslednji) poslednji = poslednji->prethodni;
	Element *stari = tek;
	tekuci = tekuci->prethodni;
	delete stari;
	return *this;
}