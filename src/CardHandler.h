#ifndef CARD_HANDLER_H
#define CARD_HANDLER_H

#include "card.h"

class CardHandler
{
public:
    /**
    @brief This function will be call after CardReader will read the card
    */
    virtual void handle_card(Card* card) = 0;
    CardHandler();
};

#endif // CARD_ACCEPTOR_H
