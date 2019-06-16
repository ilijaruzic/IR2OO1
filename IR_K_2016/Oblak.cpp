#include "Oblak.h"

Oblak::~Oblak() {
	while (prvi != nullptr) {
		Elem *stari = prvi;
		prvi = prvi->sled; 
		delete stari;
	}
	brojTacaka = 0; 
	posl = nullptr;
}

Oblak& Oblak::operator+=(const Tacka& t) {
	posl = (!prvi ? prvi : posl->sled) = new Elem(t);
	++brojTacaka; 
	return *this;
}

Tacka Oblak::centroid() const {
	double *centroid = new double[dim];
	for (int i = 0; i < dim; i++)
		centroid[i] = 0;
	Elem *tren = prvi;
	while (tren != nullptr) {
		for (int i = 0; i < dim; i++)
			centroid[i] += tren->tacka[i];
		tren = tren->sled;
	}
	for (int i = 0; i < dim; i++)
		centroid[i] /= brojTacaka;
	return Tacka(centroid, dim);
}

std::ostream& operator<<(std::ostream& it, const Oblak& o) {
	it << "[" << o.centroid() << "]" << std::endl;
	Oblak::Elem *tren = o.prvi;
	while (tren != nullptr) {
		it << tren->tacka << std::endl;
		tren = tren->sled;
	}
	return it;
}