#include "card.h"
#include "CardReader.h"
#include <iostream>

CardReader::CardReader(const char *port, CardHandler* handler):
    _port (port),
    _serial (NULL),
    _handler (handler),
    _is_broken (false)
{
    _serial = open_connection();
    std::thread* thr = new std::thread (&CardReader::run, this);
    thr->detach();
}


void CardReader::run()
{
    _is_run = true;
    Card* cr = read_card();
    _is_run = false;
    if (cr != nullptr && _handler != nullptr) _handler->handle_card(cr);

}

void CardReader::break_reading()
{
    _is_broken = true;
}



Card* CardReader::read_card ()
    {
    char c = 0;
    DWORD iSize;
    std::string* s = new std::string("");
    while (((int)c == -1 || (int)c == 0) && !_is_broken)
        {
        ReadFile (_serial, &c, 1, &iSize, 0);
        }
    while (true)
        {
        (*s) += c;
        Sleep(10);
        ReadFile (_serial, &c, 1, &iSize, 0);
        if ((int)c == -1 || (int)c == 0 || c == '\n' || _is_broken) break;
        }
    CloseHandle (_serial);

    if (!_is_broken) return new Card(s);
    else return nullptr;
    }

HANDLE CardReader::open_connection()
{
    HANDLE serial = CreateFile(_port, GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    DCB dcbSerialParams = {0};

    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    dcbSerialParams.BaudRate = CBR_9600;
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;

    SetCommState(serial, &dcbSerialParams);

    return serial;
}

bool CardReader::is_run(){return _is_run;}

CardReader::~CardReader()
{
    OutputDebugString ("CardReader deleted");
}
