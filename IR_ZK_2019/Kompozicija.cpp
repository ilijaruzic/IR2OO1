#include "Kompozicija.h"
#include "GDodaj.h"

Kompozicija& Kompozicija::dodaj(Takt& t) {
	if (!t.zavrsen()) throw GDodaj("Takt nije zavrsen!");
	if (prvi) {
		prvi = false;
		tr = t.trajanje();
	}
	else {
		if (t.trajanje() > tr || tr > t.trajanje()) throw GDodaj("Nejednaka duzina taktova!");
		if (t.nepotpun()) {
			if (!moguce) throw GDodaj("Nepotpun takt!");
			else moguce = false;
		}
	}
	s.dodaj(&t);
}