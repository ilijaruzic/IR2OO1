#ifndef HOST_H
#define HOST_H

#include "MrezniUredjaj.h"

class Host : public MrezniUredjaj {
public:
	using MrezniUredjaj::MrezniUredjaj;
	virtual void obradiOkvirPodataka(const OkvirPodataka& op, const MrezniInterfejs *ui) override {
		std::cout << "Host: " << id << " - " << op;
		if (op.dohvatiOdredisnuAdresu() == ui->dohvatiAdresu()) std::cout << "ALLOW" << std::endl;
		else std::cout << "DENY" << std::endl;
	}
	bool posaljiOkvirPodataka(const OkvirPodataka& op) {
		for (int i = 0; i < brojInterfejsa; i++) 
			if (interfejsi[i]->dohvatiAdresu() == op.dohvatiIzvorisnuAdresu()) {
				interfejsi[i]->posaljiOkvirPodataka(op);
				return true;
			}
		return false;
	}
private:
	static int tekuciId;
	int id = ++tekuciId;
};

#endif