#include "Tacka.h"

Tacka::Tacka(int ddim, double kkoord) {
	koord = new double[dim = ddim];
	for (int i = 0; i < ddim; i++)
		koord[i] = kkoord;
}

Tacka::Tacka(double *niz, int duz) {
	koord = new double[dim = duz];
	for (int i = 0; i < duz; i++)
		koord[i] = niz[i];
}

double operator-(const Tacka& t1, const Tacka& t2) {
	if (t1.dim == t2.dim) {
		double suma = 0;
		for (int i = 0; i < t1.dim; i++)
			suma += pow((t1.koord[i] - t2.koord[i]), 2);
		return sqrt(suma);
	}
	else return 0;
}

std::ostream& operator<<(std::ostream& it, const Tacka& t) {
	it << "(" << t.koord[0];
	for (int i = 1; i < t.dim; i++)
		it << ", " << t.koord[i];
	return it << ")";
}