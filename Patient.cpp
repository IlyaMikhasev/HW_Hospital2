#include "Patient.h"
Patient::Patient(int age, const std::string& name, const std::string& disease): _age(age), _name(name), _disease(disease) {}
const std::string& Patient::GetDisease() const{
    return _disease;
}

const std::string& Patient::GetName() const{
    return _name;
}
