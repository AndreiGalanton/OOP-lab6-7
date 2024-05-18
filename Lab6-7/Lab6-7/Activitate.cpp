#include "Activitate.h"
using namespace std;

// Compara id-urile a doua activitati
bool comparaId(const Activitate& activitate1, const Activitate& activitate2) {
	if (activitate1.getId() == activitate2.getId())
		return true;
	return false;
}

// Compara titlurile a doua activitati
bool comparaTitlu(const Activitate& activitate1, const Activitate& activitate2) {
	if (activitate1.getTitlu() == activitate2.getTitlu())
		return true;
	return false;
}

//compara descrierea a doua activitati
bool comparaDescriere(const Activitate& activitate1, const Activitate& activitate2) {
	if (activitate1.getDescriere() == activitate2.getDescriere())
		return true;
	return false;
}

//compara durata a doua activitati
bool comparaDurata(const Activitate& activitate1, const Activitate& activitate2) {
	if (activitate1.getDurata() == activitate2.getDurata())
		return true;
	return false;
}

//compara tipul a doua activitati
bool comparaTip(const Activitate& activitate1, const Activitate& activitate2) {
	if (activitate1.getTip() == activitate2.getTip())
		return true;
	return false;
}

