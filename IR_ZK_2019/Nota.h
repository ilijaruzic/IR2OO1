#ifndef NOTA_H
#define NOTA_H

#include <string>
#include "Znak.h"

class Nota : public Znak {
public:
	enum Visina { DO, RE, MI, FA, SOL, LA, SI };
	Nota(int o, Visina v, Razlomak t) : Znak(t), okt(o), vis(v) {}
	Nota& operator<<=(int p) {
		okt -= p;
		return *this;
	}
	Nota& operator>>=(int p) {
		okt += p;
		return *this;
	}
	std::string opis() const override {
		std::string s[]{ "DO", "RE", "MI", "FA", "SOL", "LA", "SI" };
		return s[vis];
	}
private:
	int okt;
	Visina vis;
};

#endif