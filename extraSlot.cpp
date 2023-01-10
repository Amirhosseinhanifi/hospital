#include "extraSlot.hpp"

unsigned int extraSlot::devideIntoTwo ()
{
    this->set_index (this->get_index () / 2);

    return this->get_index () / 2;
}