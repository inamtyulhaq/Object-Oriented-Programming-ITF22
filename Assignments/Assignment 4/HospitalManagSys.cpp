#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class Patient
{
private:
    int id;
    string name;
    string cnic;
    string phoneNumber;
    string disease;
    bool isAdmitted;

public:
    Patient(int id, const string &name, const string &cnic, const string &phoneNumber, const string &disease, bool isAdmitted)
        : id(id), name(name), cnic(cnic), phoneNumber(phoneNumber), disease(disease), isAdmitted(isAdmitted) {}

    int getId() const { return id; }
    string getName() const { return name; }
    string getCnic() const { return cnic; }
    string getPhoneNumber() const { return phoneNumber; }
    string getDisease() const { return disease; }
    bool getIsAdmitted() const { return isAdmitted; }

    void setId(int id) { this->id = id; }
    void setName(const string &name) { this->name = name; }
    void setCnic(const string &cnic) { this->cnic = cnic; }
    void setPhoneNumber(const string &phoneNumber) { this->phoneNumber = phoneNumber; }
    void setDisease(const string &disease) { this->disease = disease; }
    void setIsAdmitted(bool isAdmitted) { this->isAdmitted = isAdmitted; }

    void displayInfo() const
    {
        cout << "ID: " << id << "\n"
             << "Name: " << name << "\n"
             << "CNIC: " << cnic << "\n"
             << "Phone Number: " << phoneNumber << "\n"
             << "Disease: " << disease << "\n"
             << "Is Admitted: " << (isAdmitted ? "Yes" : "No") << "\n";
    }

    void saveToFile(ofstream &outFile) const
    {
        outFile << id << "\n"
                << name << "\n"
                << cnic << "\n"
                << phoneNumber << "\n"
                << disease << "\n"
                << isAdmitted << "\n";
    }

    static Patient loadFromFile(ifstream &inFile)
    {
        int id;
        string name, cnic, phoneNumber, disease;
        bool isAdmitted;

        inFile >> id;
        inFile.ignore();
        getline(inFile, name);
        getline(inFile, cnic);
        getline(inFile, phoneNumber);
        getline(inFile, disease);
        inFile >> isAdmitted;
        inFile.ignore();

        return Patient(id, name, cnic, phoneNumber, disease, isAdmitted);
    }
};

void addPatient(vector<Patient> &patients)
{
}

void deletePatientById(int id, vector<Patient> &patients)
{
}

void updatePatientInfo(Patient &patient)
{
}

void updatePatient(vector<Patient> &patients);
void searchPatientById();
