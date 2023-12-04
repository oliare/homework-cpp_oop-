#include "Passport.h"

namespace PassportNamespace {
    Passport::Passport() = default;

    Passport::Passport(const string& fullName, const Sex& s, const Birth& birth, const Expiry& expiry, const string& nationality, const size_t& docNumber, const size_t& record)
        : fullName{ fullName }, s{ s }, birth{ birth }, nationality{ nationality }, docNumber{ docNumber }, record{ record }, expiry{ expiry }
    {}
    Passport::Passport()
        : fullName(""), s(MALE), birth({ 0, 0, 0 }), expiry({ 0, 0, 0 }), nationality(""), docNumber(0), record(0) {}

    void Passport::printBirth(const Birth& birth) const {
        cout << (birth.day < 10 ? "0" : "") << birth.day << "." << (birth.month < 10 ? "0" : "") << birth.month << "." << birth.year;
    }
    void Passport::printExpiry(const Expiry& expiry) const {
        cout << (expiry.day < 10 ? "0" : "") << expiry.day << "." << (expiry.month < 10 ? "0" : "") << expiry.month << "." << expiry.year;
    }

    void Passport::print() const {
        cout << "\nFull name  : " << fullName << "\nSex        : " << (s == MALE ? "Male" : "Female") << "\nBirthday   : ";
        printBirth(birth);
        cout << "\nNationality: " << nationality << "\nDocument N : " << docNumber << "\nRecord     : " << record << "\nExpiry Date: ";
        printExpiry(expiry);
        cout << endl;
    }
}
