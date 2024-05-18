#include "Teste.h"
#include <assert.h>

void testeazaDomain() {
	// Testam getterele si setterele
	Activitate activitate = Activitate(1, "Sport", "Fotbal", 4, "outdoor");
	assert(activitate.getId() == 1);
	assert(activitate.getTitlu() == "Sport");
	assert(activitate.getDescriere() == "Fotbal");
	assert(activitate.getDurata() == 4);
	assert(activitate.getTip() == "outdoor");

	Activitate activitate2 = Activitate(activitate);
	activitate2.setTitlu("Gatit");
	activitate2.setDescriere("Mancare");
	activitate2.setDurata(2);
	activitate2.setTip("indoor");

	assert(activitate2.getId() == 1);
	assert(activitate2.getTitlu() == "Gatit");
	assert(activitate2.getDescriere() == "Mancare");
	assert(activitate2.getDurata() == 2);
	assert(activitate2.getTip() == "indoor");

	// Testam functiile de comparare
	assert(comparaId(activitate, activitate2) == true);
	assert(comparaTitlu(activitate, activitate2) == false);
	assert(comparaDescriere(activitate, activitate2) == false);
	assert(comparaDurata(activitate, activitate2) == false);
	assert(comparaTip(activitate, activitate2) == false);

	Activitate activitate3 = Activitate(2, "Gatit", "Mancare", 2, "indoor");
	assert(comparaId(activitate3, activitate2) == false);
	assert(comparaTitlu(activitate3, activitate2) == true);
	assert(comparaDescriere(activitate3, activitate2) == true);
	assert(comparaDurata(activitate3, activitate2) == true);
	assert(comparaTip(activitate3, activitate2) == true);

	// Testam operatorul ==
	assert((activitate == activitate2) == true);
}

void testeazaRepository() {
	Repository repository;

	Activitate activitate = Activitate(1, "Sport", "Fotbal", 4, "outdoor");
	Activitate activitate2 = Activitate(1, "Gatit", "Mancare", 2, "indoor");
	Activitate activitate3 = Activitate(2, "Plimbare", "Pe jos", 1, "outdoor");

	repository.adaugaActivitate(activitate);
	assert(repository.getAll()[0].getId() == 1);

	repository.modificaActivitate(activitate2);
	assert(repository.getAll()[0].getTitlu() == "Gatit");

	try {
		repository.stergeActivitate(activitate3);
	}
	catch (const ActivitateRepoException& e) {
		cout << e;
		assert(true);
	}

	repository.stergeActivitate(activitate2);


	assert(repository.getAll().size() == 0);

	repository.adaugaActivitate(activitate);
	repository.adaugaActivitate(activitate3);
	assert(repository.getAll().size() == 2);
}


void testeazaService() {
	Repository repository;
	ActivitateValidator validator;
	Service service{ repository, validator };

	Activitate fake = Activitate(1, "", "", 5, "");
	Activitate activitate = Activitate(1, "Hiking", "La munte", 5, "outdoor");
	Activitate activitate2 = Activitate(2, "Plimbare", "In parc", 4, "indoor");
	Activitate activitate3 = Activitate(1, "Curatenie", "In casa", 4, "indoor");
	Activitate activitate4 = Activitate(4, "Treaba", "In casa", 5, "indoor");

	try {
		service.adaugaActivitateService(fake);
	}
	catch (const ValidateException& ex) {
		cout << ex;
		assert(true);
	}

	service.adaugaActivitateService(activitate);

	service.adaugaActivitateService(activitate);

	service.adaugaActivitateService(activitate2);
	assert(service.getAllService().size() == 2);

	service.modificaActivitateService(activitate4);

	service.modificaActivitateService(activitate3);
	assert(service.getAllService()[0].getId() == 1);

	service.adaugaActivitateService(activitate4);

	service.stergeActivitateService(4);
	service.stergeActivitateService(99);


	assert(service.filtreazaDupaDescriere("In casa").size() == 1);
	assert(service.filtreazaDupaDescriere("Random").size() == 0);

	assert(service.filtreazaDupaTip("indoor").size() == 2);
	assert(service.filtreazaDupaTip("outdoor").size() == 0);

	assert(service.sorteazaDupaTitlu()[0].getTitlu() == "Curatenie");

	assert(service.sorteazaDupaDescriere()[0].getDescriere() == "In casa");

	Activitate activitate5 = Activitate(5, "CuratenieToamna", "Afara", 4, "outdoor");
	service.adaugaActivitateService(activitate5);
	assert(service.sorteazaDupaTipDurata()[0].getDurata() == 4);
	assert(service.sorteazaDupaTipDurata()[2].getDescriere() == "Afara");
}


void Teste::start() {
	testeazaDomain();
	testeazaRepository();
	testeazaService();
}
