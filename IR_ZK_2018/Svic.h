#ifndef SVIC_H
#define SVIC_H

#include "Lista.h"
#include "Adresa.h"
#include "OkvirPodataka.h"
#include "MrezniInterfejs.h"
#include "MrezniUredjaj.h"

class Svic : public MrezniUredjaj {
public:
	using MrezniUredjaj::MrezniUredjaj;
	~Svic() override {
		for (tabela.postaviNaPrvi(); tabela.imaTekuci(); tabela.postaviNaSledeci()) {
			delete tabela.dohvatiTekuci();
			tabela.dohvatiTekuci = nullptr;
		}
	}
	virtual void obradiOkvirPodataka(const OkvirPodataka& op, const MrezniInterfejs *ui) override {
		bool novi = true;
		const MrezniInterfejs *pomocni = nullptr;
		for (tabela.postaviNaPrvi(); tabela.imaTekuci(); tabela.postaviNaSledeci())
			if (tabela.dohvatiTekuci()->adresa == op.dohvatiIzvorisnuAdresu()) {
				if (tabela.dohvatiTekuci()->interfejs == ui) {
					novi = false;
					break;
				}
				else tabela.obrisiTekuci();
			}
		if (novi == true) {
			tabela.dodajNaKraj(new Par(op.dohvatiIzvorisnuAdresu, ui));
		for (tabela.postaviNaPrvi(); tabela.imaTekuci(); tabela.postaviNaSledeci())
			if (tabela.dohvatiTekuci()->adresa == op.dohvatiOdredisnuAdresu) {
				tabela.dohvatiTekuci()->interfejs->posaljiOkvirPodataka(op);
				break;
			}
		}
	}
private:
	struct Par {
		const Adresa adresa;
		const MrezniInterfejs *interfejs;
		Par(Adresa a, const MrezniInterfejs *i): adresa(a), interfejs(i) {}
	};
	Lista<Par*> tabela;
};

#endif