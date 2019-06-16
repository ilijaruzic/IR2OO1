#ifndef GTRAJANJE_H
#define GTRAJANJE_H

#include <exception>

class GTrajanje : public std::exception {
public:
	const char *what() const override { return "Prekoracenje maksimalnog trajanja takta!"; }
};

#endif