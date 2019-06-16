#ifndef GNEMATEKUCEG_H
#define GNEMATEKUCEG_H

#include <iostream>

class GNemaTekuceg {
	friend std::ostream& operator<<(std::ostream& it, const GNemaTekuceg&) {
		return it << "Nema tekuceg elementa!";
	}
};

#endif