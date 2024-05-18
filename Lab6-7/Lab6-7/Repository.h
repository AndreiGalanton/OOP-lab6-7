#pragma once
#include "Activitate.h"
#include <vector>

class Repository {
private:
	vector<Activitate> repositoryList;
public:
	Repository() = default;
	Repository(const Repository& repository) = delete;

	void adaugaActivitate(const Activitate& activitate);

	void modificaActivitate(const Activitate& activitate);

	const vector<Activitate>& getAll() const noexcept;

	void stergeActivitate(const Activitate& activitate);

	const Activitate find(const Activitate& activitate) const;

	bool exist(const Activitate& activitate);
};

class ActivitateRepoException {
	string msg;
public:
	ActivitateRepoException(string m) :msg{ m } {}
	friend ostream& operator<<(ostream& out, const ActivitateRepoException& ex);
	string getMsg() {
		return msg;
	}
};

ostream& operator<<(ostream& out, const ActivitateRepoException& ex);

