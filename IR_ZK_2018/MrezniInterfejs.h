#ifndef MREZNIINTERFEJS_H
#define MREZNIINTERFEJS_H

#include "Adresa.h"
#include "MrezniUredjaj.h"

class MrezniInterfejs {
public:
	MrezniInterfejs(MrezniUredjaj *u): uredjaj(u) {}
	MrezniInterfejs(const MrezniInterfejs&) = delete;
	MrezniInterfejs(MrezniInterfejs&&) = delete;
	Adresa dohvatiAdresu() const { return adresa; }
	void postaviAdresu(const Adresa& a) { adresa = a; }
	MrezniInterfejs *dohvatiSusedni() const { return susedni; }
	void postaviSusedni(MrezniInterfejs *s) { susedni = s; }
	void posaljiOkvirPodataka(const OkvirPodataka&) const;
	void primiOkvirPodataka(const OkvirPodataka&) const;
protected:
	Adresa adresa;
	MrezniInterfejs *susedni = nullptr;
	MrezniUredjaj *uredjaj = nullptr;
};

#endif