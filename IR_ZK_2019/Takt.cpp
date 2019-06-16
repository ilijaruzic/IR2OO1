#include "Takt.h"
#include "GDodaj.h"
#include "GTrajanje.h"

Takt& Takt::dodaj(Znak& z) {
	if (kraj) throw GDodaj("Takt je zavrsen!");
	if (tek + z.trajanje() > max) throw GTrajanje();
	s.dodaj(&z);
	tek = tek + z;
	return *this;
}