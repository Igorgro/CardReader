
#ifndef CardReader_H
#define CardReader_H

#include <thread>
#include "card.h"
#include "CardHandler.h"
#include "windows.h"



class CardReader
{
    const char* _port;

    HANDLE _serial;

    CardHandler* _handler;

    bool _is_broken;

    bool _is_run;

    void run();

    Card* read_card();

    HANDLE open_connection();


public:
    /**
    @brief Creates new card reader and starts card waiting thread
    @param port Port, to which the reader is connected
    @param handler A class? which can handle smart card, read by card reader

    */
    CardReader (const char* port, CardHandler* handler);

    /**
    @brief Breaks card reading thread
    After calling this function, the card reading thread calls handle_card function with nullptr as parameter
    */
    void break_reading();

    bool is_run();

    ~CardReader();
};

#endif // CardReader_H
