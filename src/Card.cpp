#include <iostream>
#include <stdio.h>
#include <windows.h>

#include "Card.h"

Card::Card ():
    _type (nullptr),
    _subtype (nullptr),
    _UID (nullptr),
    _ATQA (nullptr),
    _SAK (nullptr)
    {}

Card::Card (std::string* card_data):
    _type (nullptr),
    _subtype (nullptr),
    _UID (nullptr),
    _ATQA (nullptr),
    _SAK (nullptr)
    {

    int l_sq_br = card_data->find_first_of('[');
    int r_sq_br = card_data->find_first_of(']');
    int l_br    = card_data->find_first_of('(');
    int r_br    = card_data->find_first_of(')');

    _type = new std::string(card_data->substr(0, l_sq_br));
    _UID  = new std::string (card_data->substr(l_sq_br+1, r_sq_br-l_sq_br-1));
    _subtype = new std::string (card_data->substr(r_sq_br+2, l_br-r_sq_br-3));
    _ATQA = new std::string (card_data->substr (l_br+1, 4));
    _SAK = new std::string (card_data->substr (l_br+6, 2));
    }

void Card::setUID (std::string* UID)
{
    _UID = UID;
}

const std::string* Card::getUID()
{
    return _UID;
}

Card::~Card()
{
    OutputDebugString("Card destructed!");

}











