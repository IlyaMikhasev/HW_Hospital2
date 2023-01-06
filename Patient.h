#pragma once
#include <string>
#include <vector>
class Patient
{
public:
	Patient(int age, const std::string& name,const std::string& disease);
	const std::string& GetDisease()const;
	const std::string& GetName()const;
private:
	int _age;
	std::string _name;
	std::string _disease;
	std::vector<std::string> _history_diseases;

};

