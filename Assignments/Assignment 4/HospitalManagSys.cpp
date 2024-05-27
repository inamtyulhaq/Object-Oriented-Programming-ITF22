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
        : id(id), name(name), cnic(cnic), phoneNumber(phoneNumber), disease(disease), isAdmitted(isAdmitted)
    {
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getCnic() const { return cnic; }
    string getPhoneNumber() const { return phoneNumber; }
    string getDisease() { return disease; }
    bool getIsAdmitted() { return isAdmitted; }

    void setId(int id) { this->id = id; }
    void setName(const string &name) { this->name = name; }
    void setCnic(const string &cnic) { this->nic = cnic; }
    void setPhoneNumber(const string &phoneNumber) { this->phoneNumber = phoneNumber; }
    void setDisease(const string &disease) { this->disease = disease; }
    void setIsAdmitted(bool isAdmitted) { this->isAdmitted = isAdmitted; }

    void displayInfo() const
    {
        cout << "id: " << id << "\n"
             << "name: " << name << "\n"
             << "CNIC: " << cnic << "\n"
             << "Phone Number: " << phoneNcmber << "\n"
             << "Disease: " << disease << "\n"
             << "Is Admitted: " << (isAdmitted ? "Yes" : "No") << "\n";
    }

    void saveToFile(ofstream &outFile)
    {
        outFile << id << "\n"
                << name << "\n"
                << cnic << "\n"
                << phoneNumber << "\n"
                << disease << "\n"
                << isAdmitted << "\n";
    }

    static Patient loadFromFile(ifstream inFile)
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
    int id;
    string name, cnic, phoneNumber, disease;
    bool isAdmitted;

    cout << "Enter ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name);

    cout << "Enter CNIC: ";
    getline(cin, cnic);

    cout << "enter phone number: ";
    getline(cin, phoneNumber);

    cout << "enter disease: ";
    getline(cin, disease);

    cout << "is admitted: ";
    cin >> isAdmitted;

    Patient newPatient(id, name, cnic, phoneNumber, disease, isAdmitted);
    patients.push_back(newPatient);

    ofstream outFile("patient_record.txt", ios::app);
    if (outFile.is_open())
    {
        newPatient.saveToFile(outFile);
        outFile.close();
        cout << "patient added and saved to file successfully.\n";
    }
    else
    {
        cerr << "Unable to open file.\n";
    }
}

void deletePatientById(int id, vector<Patient> &patients)
{
    bool found = false;
    vector<Patient> updatedPatients;

    for (const auto &patient : patients)
    {
        if (patient.getId() == id)
        {
            found = true;
        }
        else
        {
            updatedPatients.push_back(patient);
        }
    }

    if (found)
    {
        patients = updatedPatients;
        ofstream outFile("patient_record.txt");
        if (outFile.is_open())
        {
            for (auto &patient : patients)
            {
                patient.saveoFile(outFile);
            }
            outFile.close;
            cout << "Patient deleted and file updated successfully.\n";
        }
        else
        {
            cerr << "Unable to open file.\n";
        }
    }
    else
    {
        cout << "No record found with ID " << id << ".\n";
    }
}

void deletePatient(vector<Patient> &patients)
{
    int id;
    cout << "enter patient id to delete: ";
    cin >> id;

    deletePatientById(id, patients);
}

void updatePatientInfo(Patient &patient)
{
    string name, cnic, phoneNumber, disease;
    bool isAdmitted;

    cin.ignore();

    cout << "Enter new Name: ";
    getline(cin, name);
    patient.setName(name);

    cout << "Enter new CNIC: ";
    getline(cin, cnic);
    patient.setCnic(cnic);

    cout << "Enter new phone nmber: ";
    getline(cin, phoneNumber);
    patient.setPhoneNumber(phoneNumber);

    cout << "enter new dsease: ";
    getline(cin, disease);
    patient.setDisease(disease);

    cout << "Is admitted (1 for yes, 0 for no): ";
    cin >> isAdmitted;
    patient.setIsAdmitted(isAdmitted);
}

void searchPatient()
{
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    if (!inFile.is_open())
    {
        cerr << "Unable to open file.\n";
        return;
    }

    bool found = false;
    while (inFile.peek() != EOF)
    {
        if (patient.getId() == id)
        {
            patient.displayInfo();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "No record found with ID " << id << ".\n";
    }

    inFile.close();
}

void updatePatient(vector<Patient> &patients)
{
    int id;
    cout << "Enter Patient ID to update: ";
    cin >> id;

    bool found = false;
    for (auto &patient : patients)
    {
        if (patient.getId() == id)
        {
            found = true;
            updatePatientInfo(patient);
            cout << "Patient updated successfully.\n";

            ofstream outFile("patient_record.txt");
            if (outFile.is_open())
            {
                for (const auto &p : patients)
                {
                    p.saveToFile(outFile);
                }
                outFile.close();
            }
            {
                cout << "Unable to open file.";
            }
            break;
        }
    }
    if (!found)
    {
        cout << "No record found with ID " << id << ".\n";
    }

int main()
{
    vector<Patient> patients;
    int choice;
    do {
        cout << "\nPatient Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Search Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin>>choice;
    switch (choice) {
        case 1:
            addPatient(patients);
            break;
        case 2:
            deletePatient(patients);
            break;
        case 3:
            updatePatient(patients);
            break;
        case 4:
            searchPatient();
            break;
        case 5:
            cout << "BYE BYE\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
}

void updatePatient(vector<Patient> &patients);
void searchPatientById();
