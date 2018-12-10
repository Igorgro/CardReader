#if !defined (CARD_H)
#define CARD_H

#include <string>

#define NO_CARD std::string("No Card ")
class Card
    {
    private:
    std::string* _type;
    std::string* _subtype;

    std::string* _UID;
    std::string* _ATQA;
    std::string* _SAK;

    public:
    Card ();
    Card (std::string* card_data);

    void setUID (std::string* UID);

    const std::string* getUID();

    ~Card();
    };
#endif
