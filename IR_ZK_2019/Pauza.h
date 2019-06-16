#ifndef PAUZA_H
#define PAUZA_H

#include <string>
#include "Znak.h"

class Pauza : public Znak {
public:
	Pauza(Razlomak t) : Znak(t) {}
	std::string opis() const override { return "_"; }
};

#endif