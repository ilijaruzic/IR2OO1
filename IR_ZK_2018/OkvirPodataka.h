#ifndef OKVIRPODATAKA_H
#define OKVIRPODATAKA_H

#include <iostream>

class OkvirPodataka {
public:
	OkvirPodataka(const Adresa& ia, const Adresa& oa, unsigned char *s, int k): izvorisnaAdresa(ia), odredisnaAdresa(oa), sadrzaj(s), kapacitet(k) {}
	OkvirPodataka(const OkvirPodataka&) = delete;
	OkvirPodataka& operator=(const OkvirPodataka&) = delete;
	Adresa dohvatiIzvorisnuAdresu() const { return izvorisnaAdresa; }
	Adresa dohvatiOdredisnuAdresu() const { return odredisnaAdresa; }
	unsigned char *dohvatiSadrzaj() const { return sadrzaj; }
	int dohvatiKapacitet() const { return kapacitet; }
	friend std::ostream& operator<<(std::ostream& it, const OkvirPodataka& op) {
		it << "Frame[src:" << op.izvorisnaAdresa << ", dst:" << op.odredisnaAdresa << ", content:";
		for (int i = 0; i < op.kapacitet; i++)
			it << op.sadrzaj[i];
		return it << "]";
	}
private:
	Adresa izvorisnaAdresa, odredisnaAdresa;
	unsigned char *sadrzaj;
	int kapacitet;
};

#endif