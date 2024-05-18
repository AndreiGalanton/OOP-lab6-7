#pragma once
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Activitate {
private:
	int id;
	std::string titlu;
	std::string descriere;
	int durata;
	std::string tip;

public:
	//Activitate() = default;

	Activitate(const int id,
		const std::string titlu,
		const std::string descriere,
		const int durata,
		const std::string tip) :
		id{ id },
		titlu{ titlu },
		descriere{ descriere },
		durata{ durata },
		tip{ tip }
	{};

	Activitate(const Activitate& activitate) {
		ofstream output;
		output.open("out.txt", std::ios::app);
		output << "-------Copy Constructor------------\n";
		id = activitate.id;
		titlu = activitate.titlu;
		descriere = activitate.descriere;
		durata = activitate.durata;
		tip = activitate.tip;
	}

	int getId() const noexcept {
		return id;
	}

	string getTitlu() const {
		return titlu;
	}

	string getDescriere() const {
		return descriere;
	}

	int getDurata() const noexcept {
		return durata;
	}

	string getTip() const {
		return tip;
	}

	string setTitlu(string t) {
		this->titlu = t;
		return this->titlu;
	}

	string setDescriere(string desc) {
		this->descriere = desc;
		return this->descriere;
	}

	int setDurata(const int dur) {
		this->durata = dur;
		return this->durata;
	}

	string setTip(string t) {
		this->tip = t;
		return this->tip;
	}
};

bool comparaId(const Activitate& activitate1, const Activitate& activitate2);

bool comparaTitlu(const Activitate& activitate1, const Activitate& activitate2);

bool comparaDescriere(const Activitate& activitate1, const Activitate& activitate2);

bool comparaTip(const Activitate& activitate1, const Activitate& activitate2);

bool comparaDurata(const Activitate& activitate1, const Activitate& activitate2);

inline bool operator==(const Activitate& lhs, const Activitate& rhs) { return comparaId(lhs, rhs); }

