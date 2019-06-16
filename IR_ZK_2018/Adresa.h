#ifndef ADRESA_H
#define ADRESA_H

#include <iostream>

class Adresa {
public:
	Adresa() = default;
	Adresa(const unsigned char *a) {
		for (int i = 0; i < 6; i++)
			adresa[i] = a[i];
	}
	friend bool operator==(const Adresa& a1, const Adresa& a2) {
		for (int i = 0; i < 6; i++)
			if (a1.adresa[i] != a2.adresa[i]) return false;
		return true;
	}
	friend std::ostream& operator<<(std::ostream& it, const Adresa& a) {
		for (int i = 0; i < 5; i++)
			it << std::hex << (int)a.adresa[i] << ":";
		return it << std::hex << (int)a.adresa[5];
	}
private:
	unsigned char adresa[6] = { 0, 0, 0, 0, 0, 0 };
};

#endif