#ifndef GDODAJ_H
#define GDODAJ_H

#include <exception>
#include <string>

class GDodaj : public std::exception {
public:
	GDodaj() = default;
	GDodaj(std::string e) : ex(e) {}
	const char *what() const override { return ex.c_str(); }
private:
	std::string ex = "Dodavanje nije moguce!";
};

#endif