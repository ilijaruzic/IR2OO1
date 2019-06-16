#include <iostream>
#include "Tacka.h"
#include "Oblak.h"
#include "Komparator.h"

int main() {
	Oblak oblak1(3), oblak2(3);
	Tacka a1(3, 1), b1(3, 2), c1(3, 3), a2(3, 1.5), b2(3, 2.5), c2(3, 3.5);
	Komparator komparator(0.87);
	((oblak1 += a1) += b1) += c1; 
	std::cout << oblak1;
	((oblak2 += a2) += b2) += c2; 
	std::cout << oblak2;
	std::cout << uporedi(komparator, oblak1, oblak2);
	return 0;
}