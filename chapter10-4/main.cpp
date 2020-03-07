/*
	제휴관계
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor; //forward declaration

class Patient
{
private:
	string m_name;
	vector<Doctor*> m_doctors;

public:
	Patient(const string& name_in) :m_name(name_in) {}

	void addDoctor(Doctor* const new_doctor)
	{
		m_doctors.push_back(new_doctor);
	}

	void meetDoctors(); //doctor안에 m_name이 있는지 없는지 모르기에 정의를 분리해서 doctor밑에 옮김

	friend class Doctor;
};

class Doctor
{
private:
	string m_name;
	vector<Patient*> m_patient;

public:
	Doctor(const string& name_in) :m_name(name_in) {}

	void addPatient(Patient* const new_patient)
	{
		m_patient.push_back(new_patient);
	}

	void meetPatient()
	{
		for (const auto& e : m_patient)
		{
			cout << "Meet Patient: " << e->m_name << endl;
		}
	}
	friend class Patient;
};

void Patient::meetDoctors()
{
	for (const auto& e : m_doctors)
	{
		cout << "Meet doctor: " << e->m_name << endl;
	}
}

int main()
{
	Patient* p1 = new Patient("Jack Jack");
	Patient* p2 = new Patient("Dash");
	Patient* p3 = new Patient("violet");

	Doctor* d1 = new Doctor("Doctor K");
	Doctor* d2 = new Doctor("Doctor L");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	//patients meet doctors
	p1->meetDoctors();
	p2->meetDoctors();
	p3->meetDoctors();

	//doctors meet patients
	d1->meetPatient();
	d2->meetPatient();

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;
}