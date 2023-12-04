#include "AddInfo.h"
#include <iostream>

using namespace std;

namespace AddInfo {
    ForeignPassport::ForeignPassport() :
 Passport(), visitReason(""), visaType(""), insurance(""), numberOfStamps("") {
    }

    void ForeignPassport::print() {
        cout << "Foreign Passport Information:" << endl;
        cout << "Visit reason                : " << visitReason << endl;
        cout << "Visa Type                   : " << visaType << endl;
        cout << "Insurance                   : " << insurance << endl;
        cout << "Number Of Stamps            : " << numberOfStamps << endl;
    }

    void ForeignPassport::input() {
        cout << "Enter reason for visit: "; cin >> visitReason;
        cout << "Enter visa type       : "; cin >> visaType;
        cout << "Enter insurance       : "; cin >> insurance;
        cout << "Enter number of stamps: "; cin >> numberOfStamps;
    }

}
