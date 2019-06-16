#ifndef GINDEKS_H
#define GINDEKS_H

#include <exception>

class GIndeks : public std::exception {
public:
	const char *what() const override { return "Nedozvoljen indeks!"; }
};

#endif