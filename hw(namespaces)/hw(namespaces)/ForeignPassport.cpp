#include "ForeignPassport.h"
#include <iostream>

namespace ForeignPassportNamespace {
    ForeignPassport::ForeignPassport()
        : PassportNamespace::Passport(), foreignNum(0) {}

    ForeignPassport::ForeignPassport(const string& fullName, const PassportNamespace::Sex& s, const PassportNamespace::Birth& birth, const PassportNamespace::Expiry& expiry, const string& nationality,
        const size_t& docNumber, const size_t& record, const string& visaCountry, const string& type, const size_t& number, const PassportNamespace::Expiry& visaExpiry, const size_t& foreignNum)
        : PassportNamespace::Passport(fullName, s, birth, expiry, nationality, docNumber, record), visa{ visaCountry, type, number, visaExpiry }, foreignNum{ foreignNum } {}

    void ForeignPassport::print() const {
        cout << "\n\n\t*  Foreign Passport Data   *" << endl;
        PassportNamespace::Passport::print();
        cout << "VISA (...) : \n\tCountry: " << visa.country << "\n\tType   : " << visa.type << "\n\tNumber : " << visa.number;
        cout << "\n\tExpiry Date: " << (visa.expiry.day < 10 ? "0" : "") << visa.expiry.day << "." << (visa.expiry.month < 10 ? "0" : "") << visa.expiry.month << "." << visa.expiry.year << "\nDocument N : " << foreignNum << endl;
    }
}

