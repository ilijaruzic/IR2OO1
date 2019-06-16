#pragma once

#include <iostream>
#include "Tacka.h"

class Oblak {
public:
	Oblak(int ddim = 2) : brojTacaka(0), prvi(nullptr), dim(ddim) {}
	Oblak(const Oblak&) = delete;
	Oblak& operator=(const Oblak&) = delete;
	~Oblak();
	Oblak& operator+=(const Tacka& t);
	int dohvBrojTacaka() const { return brojTacaka; }
	Tacka centroid() const;
	friend std::ostream& operator<<(std::ostream& it, const Oblak& o);
private:
	int dim, brojTacaka;
	struct Elem {
		Tacka tacka; 
		Elem *sled;
		Elem(const Tacka& t, Elem *s = nullptr) : tacka(t), sled(s) {}
	};
	Elem *prvi, *posl;
};