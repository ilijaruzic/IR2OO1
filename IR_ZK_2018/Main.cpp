#include <iostream>
#include "Adresa.h"
#include "OkvirPodataka.h"
#include "MrezniInterfejs.h"
#include "Hab.h"
#include "Host.h"
#include "GNemaTekuceg.h"

int main() {
	try {
		unsigned char adresaA[6] = { 1, 1, 1, 1, 1, 1 }, adresaB[6] = { 2, 2, 2, 2, 2, 2 };
		Adresa adresaA(adresaA), adresaB(adresaB);
		Host *hostA = new Host(1), *hostB = new Host(1);
		Hab *hab = new Hab(2);
		MrezniInterfejs *habInterfejs1 = hab->dohvatiSlobodan();
		MrezniInterfejs *hostAInterfejs = hostA->dohvatiSlobodan();
		hostAInterfejs->postaviAdresu(adresaA);
		hostAInterfejs->postaviSusedni(habInterfejs1);
		habInterfejs1->postaviSusedni(hostAInterfejs);
		MrezniInterfejs *habInterfejs2 = hab->dohvatiSlobodan();
		MrezniInterfejs *hostBInterfejs = hostB->dohvatiSlobodan();
		hostBInterfejs->postaviAdresu(adresaB);
		hostBInterfejs->postaviSusedni(habInterfejs2);
		habInterfejs2->postaviSusedni(hostBInterfejs);
		unsigned char sadrzaj[3] = { 'm', 's', 'g' };
		OkvirPodataka okvir(adresaA, adresaB, sadrzaj, 3);
		hostA->posaljiOkvirPodataka(okvir);
		delete hostA;
		delete hostB;
		delete hab;
	} catch (GNemaTekuceg g) {
		std::cout << g;
	}
}