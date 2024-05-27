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

    cout << "Enter Phone Number: ";
    getline(cin, phoneNumber);

    cout << "Enter Disease: ";
    getline(cin, disease);

    cout << "Is Admitted (1 for Yes, 0 for No): ";
    cin >> isAdmitted;

    Patient newPatient(id, name, cnic, phoneNumber, disease, isAdmitted);
    patients.push_back(newPatient);

    ofstream outFile("patient_record.txt", ios::app);
    if (outFile.is_open())
    {
        newPatient.saveToFile(outFile);
        outFile.close();
        cout << "Patient added and saved to file successfully.\n";
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
            for (const auto &patient : patients)
            {
                patient.saveToFile(outFile);
            }
            outFile.close();
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
    cout << "Enter Patient ID to delete: ";
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

    cout << "Enter new Phone Number: ";
    getline(cin, phoneNumber);
    patient.setPhoneNumber(phoneNumber);

    cout << "Enter new Disease: ";
    getline(cin, disease);
    patient.setDisease(disease);

    cout << "Is Admitted (1 for Yes, 0 for No): ";
    cin >> isAdmitted;
    patient.setIsAdmitted(isAdmitted);
}

void searchPatient()
{
    int id;
    cout << "Enter Patient ID to search: ";
    cin >> id;

    ifstream inFile("patient_record.txt");
    if (!inFile.is_open())
    {
        cerr << "Unable to open file.\n";
        return;
    }

    bool found = false;
    while (inFile.peek() != EOF)
    {
        Patient patient = Patient::loadFromFile(inFile);
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
            else
            {
                cerr << "Unable to open file.\n";
            }
            break;
        }
    }
    if (!found)
    {
        cout << "No record found with ID " << id << ".\n";
    }
}

int main()
{
    vector<Patient> patients;
    int choice;

    do
    {
        cout << "\nPatient Management System\n";
        cout << "1. Add Patient\n";
        cout << "2. Delete Patient\n";
        cout << "3. Update Patient\n";
        cout << "4. Search Patient\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
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
    } while (choice != 5);
    return 0;
}
