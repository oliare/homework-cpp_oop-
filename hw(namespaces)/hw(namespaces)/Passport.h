#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace PassportNamespace 
{
    enum Sex {
        MALE = 1, FEMALE = 2
    };

    struct Birth {
        int day, month, year;
    };

    struct Expiry {
        int day, month, year;
    };

    class Passport {    
    private:
        string fullName;
        Sex s;
        Birth birth;
        Expiry expiry;
        string nationality;
        size_t docNumber;
        size_t record;

    public:
        Passport();
        Passport(const string& fullName, const Sex& s, const Birth& birth, const Expiry& expiry, const string& nationality, const size_t& docNumber, const size_t& record);
        void printBirth(const Birth& birth) const;
        void printExpiry(const Expiry& expiry) const;
        void print() const;
    };
}
