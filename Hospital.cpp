#include "Hospital.h"

Hospital::Hospital(std::vector<std::string>& listDisease):_list_diseeases(listDisease),_id_patient(1),_score_procedures(0){}

void Hospital::registration_patient(Patient& patient){
	_patients.emplace(_id_patient, patient);
	std::cout << "Пациент " << patient.GetName() << " зарегистрирован.\tId: " << _id_patient << std::endl;
	_id_patient++;
}

void Hospital::Show_patients(){
	_it = _patients.begin();
	for (int i = 0; _it != _patients.end(); _it++) { 
		std::cout<<"Id: " << _it->first << ", имя: " << _it->second.GetName() << std::endl;
	}
}

void Hospital::redirect(int id_patient){
	_patients.erase(id_patient);
	std::cout << "Пациент переведен в другой госпиталь\n";
}

void Hospital::Procedures(int id_patient){
	int treatment = 0;
	_it = _patients.find(id_patient);
	for (size_t i = 0; i < _list_diseeases.size(); i++)	{
		if (_it->second.GetDisease() == _list_diseeases[i]) {
			std::cout << "Пациент " <<_it->second.GetName() << " вылечен от " <<_it->second.GetDisease() << '\n';
			treatment++;
		}
	}
	if (treatment == 0) {
		std::cout << "В больнице "<<_it->second.GetDisease()<<" не вылечить. Перенаправление пациента "<<_it->second.GetName()<<" в другой госпиталь\n";
		redirect(_it->first);
	}
	else
		Discharge(_it->first);
}

void Hospital::Discharge(int id_patient){
	//std::string name = _patients[id_patient].GetName(); // почему не получается извлечь имя пациента?
	std::cout << "Пациент выписан.\tId: " << id_patient << std::endl;
	_patients.erase(id_patient);
}
