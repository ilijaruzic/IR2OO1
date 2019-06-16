#ifndef HAB_H
#define HAB_H

#include "MrezniUredjaj.h"

class Hab : public MrezniUredjaj {
public:
	using MrezniUredjaj::MrezniUredjaj;
	virtual void obradiOkvirPodataka(const OkvirPodataka& op, const MrezniInterfejs *ui) override {
		for (int i = 0; i < brojInterfejsa; i++)
			if (interfejsi[i] != ui) interfejsi[i]->posaljiOkvirPodataka(op);
	}
};

#endif