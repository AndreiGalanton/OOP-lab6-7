#include "Service.h"
#include <cctype>

// Gestionare adagare activitate
void Service::adaugaActivitateService(const Activitate& activitate) {
	validator.validate(activitate);
	try {
		repository.adaugaActivitate(activitate);
	}
	catch (const ActivitateRepoException& e) {
		cout << e;
	}
}

// Gestionare obtinere lista de activitati
const std::vector <Activitate>& Service::getAllService() const noexcept {
	return repository.getAll();
}

// Gestionare stergere activitate
void Service::stergeActivitateService(const int& id) {
	Activitate fake = { id, "fake", "fake", 0, "fake" };
	try {
		repository.stergeActivitate(fake);
	}
	catch (const ActivitateRepoException& e) {
		cout << e;
	}
}

// Gestionare update activitate
void Service::modificaActivitateService(const Activitate& activitate) {
	validator.validate(activitate);
	try {
		repository.modificaActivitate(activitate);
	}
	catch (const ActivitateRepoException& e) {
		cout << e;
	}
}

// Gestionare filtrare activitati
std::vector <Activitate> Service::filtreaza(std::function <bool(const Activitate&)> functie) const {
	std::vector <Activitate> rezultat;
	for (unsigned int index{ 0 }; index < repository.getAll().size(); index++)
		if (functie(repository.getAll().at(index)))
			rezultat.push_back(repository.getAll().at(index));
	return rezultat;
}

// Gestionare filtrare activitati dupa tip
std::vector<Activitate> Service::filtreazaDupaTip(const std::string tip) const {
	return filtreaza([tip](const Activitate& activitate) noexcept {
		return activitate.getTip().find(tip) != std::string::npos or tip.find(activitate.getTip()) != std::string::npos;
		});
}

// Gestionare filtrare activitati dupa Descriere
std::vector<Activitate> Service::filtreazaDupaDescriere(const std::string descriere) const {
	return filtreaza([descriere](const Activitate& activitate) noexcept {
		return activitate.getDescriere().find(descriere) != std::string::npos or descriere.find(activitate.getDescriere()) != std::string::npos;
		});
}

// Functie pentr sortare
std::vector <Activitate> Service::sorteaza(functie functie) const {
	std::vector <Activitate> rezultat{ repository.getAll()};
	if (*functie != nullptr) {
		for(unsigned int index = 0; index<rezultat.size() - 1; index++)
			for(unsigned int index2 = index + 1; index2 < rezultat.size(); index2++)
				if (!functie(rezultat.at(index), rezultat[index2]))
					std::swap(rezultat.at(index), rezultat[index2]);
	}
	return rezultat;
}

// Functie pentr sortare in functie de titlu
std::vector <Activitate> Service::sorteazaDupaTitlu() const {
	return sorteaza([](const Activitate& activitate1, const Activitate& activitate2) {
		return activitate1.getTitlu() < activitate2.getTitlu();
		});
}

// Functie pentr sortare in functie de descriere
std::vector <Activitate> Service::sorteazaDupaDescriere() const {
	return sorteaza([](const Activitate& activitate1, const Activitate& activitate2) {
		return activitate1.getDescriere() < activitate2.getDescriere();
		});
}

// Functie pentr sortare in functie de tip si durata
std::vector <Activitate> Service::sorteazaDupaTipDurata() const {
	return sorteaza([](const Activitate& activitate1, const Activitate& activitate2) {
		if (activitate1.getTip() == activitate2.getTip())
			return activitate1.getDurata() < activitate2.getDurata();
		return activitate1.getTip() < activitate2.getTip();
		});
}

