#pragma once

#include "Oblak.h"

class Komparator {
public:
	Komparator(double oodst) : odst(oodst) {}
	friend bool uporedi(const Komparator& k, const Oblak& o1, const Oblak& o2) { return (o1.centroid() - o2.centroid()) <= k.odst; }
private:
	double odst;
};