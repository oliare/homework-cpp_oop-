#pragma once
#include "Passport.h"

namespace ForeignPassportNamespace {
    struct Visa {
        string country;
        string type;
        size_t number;
        PassportNamespace::Expiry expiry;
    };

    class ForeignPassport : public PassportNamespace::Passport {
    private:
        Visa visa;
        size_t foreignNum;

    public:
        ForeignPassport();
        ForeignPassport(const string& fullName, const PassportNamespace::Sex& s, const PassportNamespace::Birth& birth, const PassportNamespace::Expiry& expiry, const string& nationality,
            const size_t& docNumber, const size_t& record, const string& visaCountry, const string& type, const size_t& number, const PassportNamespace::Expiry& visaExpiry, const size_t& foreignNum);

        void print() const;
    };
};
