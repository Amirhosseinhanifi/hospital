#ifndef _patient
#define _patient

#include <iostream>
#include <string>

using namespace std;

class patient
{
    private:

        string name;
        unsigned int age;
        string gender;
        string patientFor;

    public:

        void set_name(string name) { this->name = name; }
        string get_name() { return this->name; }

        void set_age(unsigned int age) { this->age = age; }
        unsigned int get_age() { return this->age; }

        void set_gender(string gender) { this->gender = gender; }
        string get_gender() { return this->gender; }

        void set_patientFor(string patientFor) { this->patientFor = patientFor; }
        string get_patientFor() { return this->patientFor; }
};

#endif