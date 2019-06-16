#include <iostream>
#include "Izvodjac.h"

void Izvodjac::pisi() const {
	std::cout << ime << " (" << zanr << ")\n";
}

std::string Izvodjac::str_zanr[] = { "pop", "rep", "rok" };