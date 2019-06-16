#ifndef PESMA_H
#define PESMA_H

#include <string>
#include "Izvodjac.h"

class Pesma {
public:
	Pesma(std::string n, int m, int s, int k) : naziv(n), min(m), sek(s) { izv = new Izvodjac*[kap = k]; }
private:
	std::string naziv;
	int min, sek, br = 0, kap;
	Izvodjac **izv;
};

#endif