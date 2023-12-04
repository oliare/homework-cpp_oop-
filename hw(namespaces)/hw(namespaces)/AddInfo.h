#pragma once
#include "Passport.h" 

namespace AddInfo {
    class ForeignPassport : public PassportNamespace::Passport { 
    public:
        ForeignPassport();
        void print();
        void input();

    protected:
        string visitReason;
        string visaType;
        string insurance;
        string numberOfStamps;
    };
}

