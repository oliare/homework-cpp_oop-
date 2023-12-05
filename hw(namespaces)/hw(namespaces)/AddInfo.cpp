#include "AddInfo.h"
#include <iostream>

namespace AddInfo {
    ForeignPassport::ForeignPassport() : PassportNamespace::Passport() {}

    void ForeignPassport::print() {
        cout << "Foreign Passport Information:" << endl;
        cout << "Visit reason                : " << visitReason << endl;
        cout << "Visa Type                   : " << visaType << endl;
        cout << "Insurance                   : " << insurance << endl;
        cout << "Number Of Stamps            : " << numberOfStamps << endl;
    }
}
