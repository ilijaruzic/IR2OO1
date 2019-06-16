#ifndef RAZLOMAK_H
#define RAZLOMAK_H

#include <iostream>

class Razlomak {
public:
	Razlomak(int b, int i = 1) : br(b), im(i) {}
	friend Razlomak operator+(const Razlomak& r1, const Razlomak& r2) { return Razlomak(r1.br*r2.im+r2.br*r1.im, r1.im*r2.im); }
	friend bool operator>(const Razlomak& r1, const Razlomak& r2) { return r1.br*r2.im > r2.br*r1.im; }
	friend std::ostream& operator<<(std::ostream& it, const Razlomak& r) { return it << r.br << "/" << r.im; }
private:
	int br, im;
};

#endif