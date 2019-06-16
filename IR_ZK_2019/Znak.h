#ifndef ZNAK_H
#define ZNAK_H

#include <iostream>
#include <string>
#include "Razlomak.h"

class Znak {
public:
	explicit Znak(Razlomak t) : tr(t) {}
	Razlomak trajanje() const { return tr; }
	friend Razlomak operator+(const Znak& z1, const Znak& z2) { return z1.tr + z2.tr; }
	operator Razlomak() const { return tr; }
	virtual std::string opis() const = 0;
	friend std::ostream& operator<<(std::ostream& it, const Znak& z) { return it << z.opis() << "(" << z.tr << ")"; }
private:
	Razlomak tr;
};

#endif