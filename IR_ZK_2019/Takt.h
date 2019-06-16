#ifndef TAKT_H
#define TAKT_H

#include <iostream>
#include "Sekvenca.h"
#include "Razlomak.h"
#include "Znak.h"

class Takt {
public:
	Takt(Razlomak mt) : max(mt), tek(0) {}
	Takt(const Takt& t) = delete;
	void operator=(const Takt& t) = delete;
	Razlomak trajanje() const { return max; }
	Takt& dodaj(Znak& z);
	Takt& zavrsi() {
		kraj = true;
		return *this;
	}
	bool zavrsen() const { return kraj; }
	bool nepotpun() const { return max > tek; }
	friend std::ostream& operator<<(std::ostream& it, const Takt& t) {
		for (int i = 0; i < t.s.duzina(); i++)
			it << *t.s[i] << " ";
		return it << "|";
	}
private:
	Sekvenca<Znak*> s;
	Razlomak max, tek;
	bool kraj = false;
};

#endif