#include <iostream>
#include <vector>
#include <string>
#include "Hospital.h"
#include "Patient.h"
int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::string> listDisease = {"����","����","�����","�����","����������"};
	Patient patient1( 22,"Alex","����" );
	Patient patient2(18, "Larry", "����");
	Patient patient3(45, "Homer", "���");
	Hospital hospital(listDisease);
	hospital.registration_patient(patient1);
	hospital.registration_patient(patient2);
	hospital.registration_patient(patient3);
	hospital.Show_patients();
	std::cout << '\n';
	hospital.Procedures(1);
	std::cout << '\n';
	hospital.Procedures(3);
	std::cout << '\n';
	hospital.Show_patients();
	hospital.Discharge(2);
	std::cout << '\n';
	hospital.Show_patients();
	return 0;
}