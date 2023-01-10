#ifndef _game
#define _game

#include "bathroom.hpp"
#include "extraSlot.hpp"
#include "hospitalMorgue.hpp"
#include "ICU.hpp"
#include "operatingRoom.hpp"
#include "patient.hpp"
#include "reception.hpp"
#include "restSlot.hpp"
#include "others.hpp"

#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

class game
{
    private:

        bathroom maleBathroom;
        bathroom femaleBathroom;
        hospitalMorgue hospitalMorgueO;
        ICU ICUO;
        operatingRoom operatingRoomO;
        extraSlot extraSlots;
        reception receptionO;
        restSlot restSlotO;

        patient patients[120];
        unsigned int patientIndex = 0;
        unsigned int maxPatientIndex = 119;

        bool isFull = false;

        unsigned int randomNum;

        ofstream file;

        string name;
        int age;
        string gender;
        enum patientForO patientFor;

    public:

        void initMaleBathroom ();
        void initFemaleBathroom ();
        void initHospitalMorgue ();
        void initICU ();
        void initOperatingRoom ();
        void initExtraSlots ();
        void initReception ();
        void initRestSlot ();

        void initFile();

        game ();
        ~game ();

        void generate_randomNum ();
        unsigned int get_randomNum ();

        void update ();
        void Render ();

        void set_name (string name) { this->name = name; }
        string get_name () { return this->name;}

        bool set_age (int);
        int get_age ();

        bool set_gender (string);
        string get_gender () { return this->gender; }

        bool set_patientFor (string);
        string get_patientFor ();

        bool is_full () { return this->isFull; }

        void print () const;
};

#endif