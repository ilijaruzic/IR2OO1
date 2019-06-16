#ifndef KOMPOZICIJA_H
#define KOMPOZICIJA_H

#include <iostream>
#include "Sekvenca.h"
#include "Takt.h"

class Kompozicija {
public:
	Kompozicija() = default;
	Kompozicija(const Kompozicija& k) = delete;
	void operator=(const Kompozicija& k) = delete;
	Kompozicija& dodaj(Takt& t);
	friend std::ostream& operator<<(std::ostream &it, const Kompozicija& k) {
		for (int i = 0; i < k.s.duzina(); i++)
			it << *k.s[i] << std::endl;
		return it; 
	}
private:
	Sekvenca<Takt*> s;
	bool moguce = true, prvi = true;
	Razlomak tr = Razlomak(0);
};

#endif