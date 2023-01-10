#include "game.hpp"

void game::initMaleBathroom ()
{
    maleBathroom.set_name ("MaleBathroom");
    maleBathroom.set_index (6);
    maleBathroom.set_gender ("male");
}
void game::initFemaleBathroom ()
{
    femaleBathroom.set_name ("FemaleBathroom");
    femaleBathroom.set_index (6);
    femaleBathroom.set_gender ("female");
}

void game::initHospitalMorgue ()
{
    hospitalMorgueO.set_name ("hospitalMorgue");
    hospitalMorgueO.set_index (16);
    hospitalMorgueO.set_gender ("both");
}

void game::initICU ()
{
    ICUO.set_name ("ICU");
    ICUO.set_index (16);
    ICUO.set_gender ("both");
}

void game::initOperatingRoom ()
{
    operatingRoomO.set_name ("operatingRoom");
    operatingRoomO.set_index (16);
    operatingRoomO.set_gender ("both");
}

void game::initExtraSlots ()
{
    extraSlots.set_name ("ExtraSlot1");
    extraSlots.set_index (32);
    extraSlots.set_gender ("both");
}

void game::initReception ()
{
    receptionO.set_name ("Reception");
    receptionO.set_index (16);
    receptionO.set_gender ("both");
}

void game::initRestSlot ()
{
    restSlotO.set_name ("RestSlot");
    restSlotO.set_index (16);
    restSlotO.set_gender ("both");
}

void game::initFile()
{
    file.open ("../patientInf.txt", ios::out);
}

void game::update ()
{
    string name;
    unsigned int age;
    string gender;
    string patientFor;

    cout << "Enter patient name: ";
    getline (cin, name, '\n');

    this->set_name (name);

    age = -1;

    while (this->set_age (age) != true)
    {
        cout << "Enter patient age: ";
        cin >> age;
        cin.ignore ();
    }

    while (this->set_gender (gender) != true)
    {
        cout << "Enter patient gender (M: Male, F: Female): ";
        cin >> gender;
        cin.ignore ();
    }

    while (this->set_patientFor (patientFor) != true)
    {
        cout << "Enter patient for (NeedBathroom, NeedSurgery, BadPos, Dead, NeedHelp, NeedRest): ";
        cin >> patientFor;
        cin.ignore ();
    }

    patients[patientIndex].set_name (this->get_name ());
    patients[patientIndex].set_age (this->get_age ());
    patients[patientIndex].set_gender (this->get_gender ());
    patients[patientIndex].set_patientFor (this->get_patientFor ());

    file << "name: " << this->get_name () << " age: " << this->get_age () << " gender: " << this->get_gender () << " patientFor: " << this->get_patientFor () << endl;
}
void game::Render ()
{
    if (patients[patientIndex].get_patientFor () == "needbathroom")
    {
        if (patients[patientIndex].get_gender () == "male")
        {
            if (maleBathroom.add_index () == false)
            {
                maleBathroom.get_bigger (extraSlots.devideIntoTwo ());
                if (maleBathroom.add_index () == false)
                {
                    cout << "hospital is full" << endl;

                    isFull = true;
                }
            }
        }
        else if (patients[patientIndex].get_gender () == "female")
        {
            if (femaleBathroom.add_index () == false)
            {
                femaleBathroom.get_bigger (extraSlots.devideIntoTwo ());
                if (femaleBathroom.add_index () == false)
                {
                    cout << "hospital is full" << endl;

                    isFull = true;
                }
            }
        }
    }
    else if (patients[patientIndex].get_patientFor () == "needsurgery")
    {
        if (operatingRoomO.add_index () == false)
        {
            operatingRoomO.get_bigger (extraSlots.devideIntoTwo ());
            if (operatingRoomO.add_index () == false)
            {
                cout << "hospital is full" << endl;

                isFull = true;
            }
        }
    }
    else if (patients[patientIndex].get_patientFor () == "badpos")
    {
        if (ICUO.add_index () == false)
        {
            ICUO.get_bigger (extraSlots.devideIntoTwo ());
            if (ICUO.add_index () == false)
            {
                cout << "hospital is full" << endl;

                isFull = true;
            }
        }
    }
    else if (patients[patientIndex].get_patientFor () == "dead")
    {
        if (hospitalMorgueO.add_index () == false)
        {
            hospitalMorgueO.get_bigger (extraSlots.devideIntoTwo ());
            if (hospitalMorgueO.add_index () == false)
            {
                cout << "hospital is full" << endl;

                isFull = true;
            }
        }
    }
    else if (patients[patientIndex].get_patientFor () == "needhelp")
    {
        if (receptionO.add_index () == false)
        {
            receptionO.get_bigger (extraSlots.devideIntoTwo ());
            if (receptionO.add_index () == false)
            {
                cout << "hospital is full" << endl;

                isFull = true;
            }
        }
    }
    else if (patients[patientIndex].get_patientFor () == "needrest")
    {
        if (restSlotO.add_index () == false)
        {
            restSlotO.get_bigger (extraSlots.devideIntoTwo ());
            if (restSlotO.add_index () == false)
            {
                cout << "hospital is full" << endl;

                isFull = true;
            }
        }
    }

    patientIndex++;

    cout << "-----------------------" << endl;

    cout << "Male_Bathroom:\t numberOfIn: " << maleBathroom.get_index () << endl;
    cout << "Female_Bathroom:\t numberOfIn: " << femaleBathroom.get_index () << endl << endl;
    cout << "OperatingRoom:\t numberOfIn: " << operatingRoomO.get_index () << endl << endl;
    cout << "ICU:\t numberOfIn:\t " << ICUO.get_index () << endl << endl;
    cout << "hospitalMorgue:\t numberOfIn: " << hospitalMorgueO.get_index () << endl << endl;
    cout << "reception:\t numberOfIn: " << receptionO.get_index () << endl << endl;
    cout << "restRoom:\t numberOfIn: " << restSlotO.get_index () << endl;

    cout << "-----------------------" << endl;

    this->print ();

    cout << "-----------------------" << endl;
}

bool game::set_age (int age)
{
    if (age > 0)
    {
        this->age = age;

        return true;
    }
    else
        return false;
}
int game::get_age ()
{
    return this->age;
}

bool game::set_gender (string gender)
{
    if (gender == "M")
    {
        this->gender = "male";

        return true;
    }
    else if (gender == "F")
    {
        this->gender = "female";

        return true;
    }
    else
        return false;
}

bool game::set_patientFor (string patientForO)
{
    if (patientForO == "NeedBathroom")
    {
        this->patientFor = NEEDBATHROOM;
        return true;
    }
    else if (patientForO == "NeedSurgery")
    {
        this->patientFor = NEEDSURGERY;
        return true;
    }
    else if (patientForO == "BadPos")
    {
        this->patientFor = BADPOS;
        return true;
    }
    else if (patientForO == "Dead")
    {
        this->patientFor = DEAD;
        return true;
    }
    else if (patientForO == "NeedHelp")
    {
        this->patientFor = NEEDHELP;
        return true;
    }
    else if (patientForO == "NeedRest")
    {
        this->patientFor = NEEDREST;
        return true;
    }
    else
        return false;
}
string game::get_patientFor ()
{
    switch (this->patientFor)
    {
        case 0:
            return "needbathroom";
            break;
        case 1:
            return "needsurgery";
            break;
        case 2:
            return "badpos";
            break;
        case 3:
            return "dead";
            break;
        case 4:
            return "needhelp";
            break;
        case 5:
            return "needrest";
            break;
    }
}

void game::print () const
{
    cout << "          __________________________" << endl;
    cout << "          |    |    |  |  |        |" << endl;
    cout << "          |    |    |  |  |        |" << endl;
    cout << "          |    |    |  |  |        |" << endl;
    cout << "          |    |    |  |  |        |" << endl;
    cout << "          |                        |" << endl;
    cout << "          |                        |" << endl;
    cout << "                                   |" << endl;
    cout << "                                   |" << endl;
    cout << "          |                        |" << endl;
    cout << "          |                        |" << endl;
    cout << "          |    |    |    |_________|" << endl;
    cout << "          |    |    |    |          " << endl;
    cout << "          |    |    |    |          " << endl;
    cout << "          |____|____|____|          " << endl;
}

game::game ()
{
    this->initMaleBathroom ();
    this->initFemaleBathroom ();
    this->initHospitalMorgue ();
    this->initICU ();
    this->initOperatingRoom ();
    this->initExtraSlots ();
    this->initReception ();
    this->initRestSlot ();
    
    this->initFile ();
}
game::~game ()
{

}