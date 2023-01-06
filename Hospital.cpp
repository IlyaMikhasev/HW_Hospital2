#include "Hospital.h"

Hospital::Hospital(std::vector<std::string>& listDisease):_list_diseeases(listDisease),_id_patient(1),_score_procedures(0){}

void Hospital::registration_patient(Patient& patient){
	_patients.emplace(_id_patient, patient);
	std::cout << "������� " << patient.GetName() << " ���������������.\tId: " << _id_patient << std::endl;
	_id_patient++;
}

void Hospital::Show_patients(){
	_it = _patients.begin();
	for (int i = 0; _it != _patients.end(); _it++) { 
		std::cout<<"Id: " << _it->first << ", ���: " << _it->second.GetName() << std::endl;
	}
}

void Hospital::redirect(int id_patient){
	_patients.erase(id_patient);
	std::cout << "������� ��������� � ������ ���������\n";
}

void Hospital::Procedures(int id_patient){
	int treatment = 0;
	_it = _patients.find(id_patient);
	for (size_t i = 0; i < _list_diseeases.size(); i++)	{
		if (_it->second.GetDisease() == _list_diseeases[i]) {
			std::cout << "������� " <<_it->second.GetName() << " ������� �� " <<_it->second.GetDisease() << '\n';
			treatment++;
		}
	}
	if (treatment == 0) {
		std::cout << "� �������� "<<_it->second.GetDisease()<<" �� ��������. ��������������� �������� "<<_it->second.GetName()<<" � ������ ���������\n";
		redirect(_it->first);
	}
	else
		Discharge(_it->first);
}

void Hospital::Discharge(int id_patient){
	//std::string name = _patients[id_patient].GetName(); // ������ �� ���������� ������� ��� ��������?
	std::cout << "������� �������.\tId: " << id_patient << std::endl;
	_patients.erase(id_patient);
}
