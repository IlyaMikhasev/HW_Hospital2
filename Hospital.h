#pragma once
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Patient.h"
class Hospital
{
public:
	Hospital(std::vector<std::string>& listDisease);
	void registration_patient(Patient& patient);
	void Show_patients();
	void redirect(int id_patient);
	void Procedures(int id_patient);
	void Discharge(int id_patient);
private:
	std::map<int, Patient> _patients;
	std::vector<std::string> _list_diseeases;
	int _score_procedures;
	int _id_patient;
	std::map<int, Patient> ::iterator _it;
};

