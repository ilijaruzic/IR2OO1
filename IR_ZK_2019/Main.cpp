#include <iostream>
#include <exception>
#include "Razlomak.h"
#include "Nota.h"
#include "Pauza.h"
#include "Takt.h"
#include "Kompozicija.h"

int main() {
	try {
		Razlomak osmina(1, 8), cetvrtina(1, 4), polovina(1, 2);
		Nota mi_2(2, Nota::MI, polovina), re_4(2, Nota::RE, cetvrtina), do_8(2, Nota::DO, osmina), la_8(2, Nota::LA, osmina), sol_4(2, Nota::SOL, cetvrtina), si_2(2, Nota::SI, polovina);
		Pauza pauza_2(polovina), pauza_4(cetvrtina), pauza_8(osmina);
		Takt takt1(polovina), takt2(polovina), takt3(polovina);
		takt1.dodaj(re_4).zavrsi();
		takt2.dodaj(mi_2).zavrsi();
		takt3.dodaj(la_8).dodaj(pauza_8).dodaj(sol_4).zavrsi();
		Kompozicija kompozicija;
		std::cout << kompozicija.dodaj(takt1).dodaj(takt2).dodaj(takt3);
	} 
	catch (std::exception& e) {
		std::cout << std::endl << e.what();
	}
}