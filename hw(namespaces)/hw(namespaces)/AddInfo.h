#pragma once
#include "Passport.h"
#include <iostream>

namespace AddInfo {
    class ForeignPassport : public PassportNamespace::Passport {
    public:
        ForeignPassport();
        void print();

    protected:
        string visitReason;
        string visaType;
        string insurance;
        string numberOfStamps;
    };
}

