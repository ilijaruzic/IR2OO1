#ifndef IZVODJAC_H
#define IZVODJAC_H

#include <string>

enum Zanr { POP, REP, ROK };

class Izvodjac {
public:
	Izvodjac(std::string i, Zanr z) : ime(i), zanr(z) {}
	Zanr dohvatiZanr() const { return zanr; }
	void pisi() const;
private:
	std::string ime;
	Zanr zanr;
	static std::string str_zanr[];
};

#endif