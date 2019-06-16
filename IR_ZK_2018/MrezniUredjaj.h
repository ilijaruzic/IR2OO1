#ifndef MREZNIUREDJAJ_H
#define MREZNIUREDJAJ_H

#include "MrezniInterfejs.h"

class MrezniUredjaj {
public:
	MrezniUredjaj(int bi): brojInterfejsa(bi) {
		interfejsi = new MrezniInterfejs *[brojInterfejsa];
		for (int i = 0; i < brojInterfejsa; i++)
			interfejsi[i] = new MrezniInterfejs(this);
	}
	MrezniUredjaj(const MrezniUredjaj&) = delete;
	MrezniUredjaj(MrezniUredjaj&&) = delete;
	virtual ~MrezniUredjaj() {
		for (int i = 0; i < brojInterfejsa; i++)
			delete interfejsi[i];
		delete[] this;
	}
	MrezniInterfejs *dohvatiSlobodan() const {
		for (int i = 0; i < brojInterfejsa; i++)
			if (interfejsi[i]->dohvatiSusedni() == nullptr)
				return interfejsi[i];
		return nullptr;
	}
	virtual void obradiOkvirPodataka(const OkvirPodataka&, const MrezniInterfejs*) = 0;
protected:
	MrezniInterfejs **interfejsi;
	int brojInterfejsa;
};

#endif