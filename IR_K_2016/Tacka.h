#pragma once

#include <iostream>
#include <cstdlib>
#include <cmath>

class Tacka {
public:
	Tacka(int ddim = 2, double kkoord = 0);
	Tacka(const Tacka& t) { kopiraj(t); }
	Tacka(Tacka&& t) { premesti(t); }
	Tacka(double* niz, int duz);
	~Tacka() { brisi(); }
	Tacka& operator = (const Tacka& t) {
		if (this != &t) { 
			brisi(); 
			kopiraj(t); 
		}
		return *this;
	}
	Tacka& operator=(Tacka&& t) {
		if (this != &t) { 
			brisi(); 
			premesti(t); 
		}
		return *this;
	}
	friend double operator-(const Tacka& t1, const Tacka& t2);
	friend std::ostream& operator<<(std::ostream& it, const Tacka& t);
	int dohvDim() const { return dim; }
	const double& operator[](int i) const {
		if (i < 0 || i >= dim) exit(1);
		return koord[i];
	}
	double& operator[](int i) {
		if (i < 0 || i >= dim) exit(1);
		return koord[i];
	}
private:
	int dim; 
	double* koord;
	void kopiraj(const Tacka& t) {
		koord = new double[dim = t.dim];
		for (int i = 0; i < dim; i++)
			koord[i] = t.koord[i];
	}
	void premesti(Tacka& t) {
		dim = t.dim; koord = t.koord;
		t.koord = nullptr;
	}
	void brisi() {
		dim = 0; 
		delete[] koord; 
		koord = nullptr;
	}
};