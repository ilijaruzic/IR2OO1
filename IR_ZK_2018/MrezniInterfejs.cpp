#include "MrezniInterfejs.h"

void MrezniInterfejs::posaljiOkvirPodataka(const OkvirPodataka& op) const { if (susedni) susedni->primiOkvirPodataka(op); }

void MrezniInterfejs::primiOkvirPodataka(const OkvirPodataka& op) const { uredjaj->obradiOkvirPodataka(op, this); }