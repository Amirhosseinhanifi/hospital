#include "room.hpp"

bool room::set_gender (const string gender)
{
    if (gender == "male")
    {
        this->gender = "male";

        return true;
    }
    else if (gender == "female")
    {
        this->gender = "female";

        return true;
    }
    else if (gender == "both")
    {
        this->gender = "both";

        return true;
    }
    else
        return false;
}

bool room::is_available () const
{
    if (this->index < this->maxIndex)
        return true;
    else
        return false;
}

bool room::add_index ()
{
    if (this->index < this->maxIndex)
    {
        this->index++;

        return true;
    }
    else
    {
        return false;
    }
}

void room::get_bigger (unsigned int extra)
{
    this->maxIndex += extra;
}