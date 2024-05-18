#include "validator.h"

// Functie de validare pentru o activitate.
void ActivitateValidator::validate(const Activitate& activitate) {
	Vector <string> msgs;
	if (activitate.getTip().size() == 0) msgs.add("Tip vid!!!");
	if (activitate.getTitlu().size() == 0) msgs.add("Titlu vid!!!");
	if (activitate.getDescriere().size() == 0) msgs.add("Descriere vida!!!");
	if (msgs.size() > 0) {
		throw ValidateException(msgs);
	}
}

ostream& operator<<(ostream& out, const ValidateException& ex) {
	for (const auto& mesaj : ex.mesaje) {
		out << mesaj << " ";
	}
	return out;
}