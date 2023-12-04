#include "ForeignPassport.h"
#include "Passport.h"
#include "AddInfo.h"

using namespace AddInfo;

namespace ForeignPassportNamespace {
    ForeignPassport::ForeignPassport() : Passport() {
        visa.country = "some country";
        visa.type = "some type";
        visa.number = 12345;
        visa.expiry = { 1, 1, 2040 };
        foreignNum = 134679;
    }

    ForeignPassport::ForeignPassport(const string& fullName, const PassportNamespace::Sex& s, const PassportNamespace::Birth& birth, const PassportNamespace::Expiry& expiry, const string& nationality,
        const size_t& docNumber, const size_t& record, const string& visaCountry, const string& type, const size_t& number, const PassportNamespace::Expiry& visaExpiry, const size_t& foreignNum)
        : Passport(fullName, s, birth, expiry, nationality, docNumber, record), visa{ visaCountry, type, number, visaExpiry }, foreignNum{ foreignNum } {}

    void ForeignPassport::print() const {
        std::cout << "\n\n\t*  Foreign Passport Date   *" << std::endl;
        Passport::print();
        std::cout << "VISA (...) : \n\tCountry: " << visa.country << "\n\tType   : " << visa.type << "\n\tNumber : " << visa.number
            << "\n\tExpiry Date: " << (visa.expiry.day < 10 ? "0" : "") << visa.expiry.day << "." << (visa.expiry.month < 10 ? "0" : "") << visa.expiry.month << "." << visa.expiry.year << "\nDocument N : " << foreignNum << std::endl;
    }
 
}
