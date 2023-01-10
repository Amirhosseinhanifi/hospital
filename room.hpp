#ifndef _room
#define _room

#include <iostream>
#include <string>

using namespace std;

class room
{
    private:

        unsigned int index = 0;
        unsigned int maxIndex;

        string gender;

        string name;

    public:

        void set_index(unsigned int maxIndex) { this->maxIndex = maxIndex; }
        bool add_index (); 
        unsigned int get_index() const { return index; }

        bool set_gender (const string = "both");
        string get_gender () const { return gender; }

        bool is_available () const;

        void set_name (const string name) { this->name = name; }
        string get_name () const { return name; }

        void get_bigger (unsigned int);
};

#endif