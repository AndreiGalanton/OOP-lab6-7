#include "UI.h"
#include <iomanip>

void UI::printeaza(const std::vector <Activitate>& activitati) const {
	for (unsigned int index = 0; index < activitati.size(); index++) {
		std::cout << "-------------\n";
		std::cout << "Id:" << setw(15) << activitati.at(index).getId() << "\n";
		std::cout << "Titlu: " << setw(12) << activitati.at(index).getTitlu() << "\n";
		std::cout << "Descriere: " << setw(5) << activitati.at(index).getDescriere() << "\n";
		std::cout << "Durata: " << setw(5) << activitati.at(index).getDurata() << "\n";
		std::cout << "Tip: " << setw(2) << activitati.at(index).getTip() << "\n";
		std::cout << "\n";
	}
}

void UI::start() {

	int cmd = 0;

	do {
		std::cout << "-----Aplicatie gestiune activitati-----\n";
		std::cout << "1. Adaugare activitate\n";
		std::cout << "2. Stergere activitate\n";
		std::cout << "3. Modificare activitate\n";
		std::cout << "4. Afisare activitati\n";
		std::cout << "5. Filtrare activitati\n";
		std::cout << "6. Sortare activitati\n";
		std::cout << "9. Populare lista activitati\n";
		std::cout << "0. Exit\n";
		std::cout << '\n';

		std::cout << "Dati comanda: "; std::cin >> cmd; std::cout << '\n';

		if (cmd == 1) {
			int id, durata;
			std::string titlu, descriere, tip;
			std::cout << "Dati id: "; std::cin >> id;
			std::cout << "Dati titlu: "; std::getline(std::cin >> std::ws, titlu);
			std::cout << "Dati descrierea: "; std::getline(std::cin >> std::ws, descriere);
			std::cout << "Dati durata: "; std::cin >> durata;
			std::cout << "Dati tip: "; std::getline(std::cin >> std::ws, tip);
			std::cout << '\n';
			try {
				service.adaugaActivitateService(Activitate(id, titlu, descriere, durata, tip));
			}
			catch (ValidateException&) {
				std::cout << "Nu exista acest activitate!\n";
			}
			
		}

		if (cmd == 2) {
			int id;
			std::cout << "Dati id: "; std::cin >> id;
			service.stergeActivitateService(id);
			//	std::cout << "Nu exista acest activitate!\n";
			std::cout << "Activitatea a fost stearsa!\n";
		}

		if (cmd == 3) {
			int id, durataNou;
			std::string titluNou, descriereNoua, tipNou;
			std::cout << "Dati id-ul: "; std::cin >> id;
			std::cout << "Dati titlul nou: "; std::getline(std::cin >> std::ws, titluNou);
			std::cout << "Dati descrierea noua: "; std::getline(std::cin >> std::ws, descriereNoua);
			std::cout << "Dati durata noua: "; std::cin >> durataNou;
			std::cout << "Dati tipul nou: "; std::getline(std::cin >> std::ws, tipNou);
			std::cout << '\n';
			service.modificaActivitateService(Activitate(id, titluNou, descriereNoua, durataNou, tipNou));
		}

		if (cmd == 4) printeaza(service.getAllService());

		if (cmd == 5) {
			std::cout << "1. Dupa Descriere\n";
			std::cout << "2. Dupa tip\n";
			std::cout << '\n';
			std::cout << "Dati comanda: "; std::cin >> cmd; std::cout << '\n';

			if (cmd == 1) {
				std::string descriere;
				std::cout << "Dati descriere: "; std::getline(std::cin >> std::ws, descriere); std::cout << '\n';
				printeaza(service.filtreazaDupaDescriere(descriere));
			}

			if (cmd == 2) {
				std::string tip;
				std::cout << "Dati tip: "; std::getline(std::cin >> std::ws, tip); std::cout << '\n';
				printeaza(service.filtreazaDupaTip(tip));
			}
		}

		if (cmd == 6) {
			std::cout << "1. Dupa titlu\n";
			std::cout << "2. Dupa descriere\n";
			std::cout << "3. Dupa tip + durata\n";
			std::cout << '\n';
			std::cout << "Dati comanda: "; std::cin >> cmd; std::cout << '\n';

			if (cmd == 1) printeaza(service.sorteazaDupaTitlu());
			if (cmd == 2) printeaza(service.sorteazaDupaDescriere());
			if (cmd == 3) printeaza(service.sorteazaDupaTipDurata());
		}

		if (cmd == 9) {
			service.adaugaActivitateService(Activitate(1, "Hiking", "Iesire in natura", 3, "outdoor"));
			service.adaugaActivitateService(Activitate(2, "Plimbare", "Iesire", 1, "outdoor"));
			service.adaugaActivitateService(Activitate(3, "Iesire", "Meet cu prieteni", 3, "outdoor"));
			service.adaugaActivitateService(Activitate(4, "Curatenie", "Curatenie in casa", 4, "indoor"));
			service.adaugaActivitateService(Activitate(5, "Gatit", "Mancare", 2, "indoor"));
			service.adaugaActivitateService(Activitate(6, "Somn", "Odihna", 7, "indoor"));
		}

		if (cmd == 0) {
			return;
		}
	} while (1);
}
