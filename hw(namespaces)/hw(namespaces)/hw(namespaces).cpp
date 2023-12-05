#include <iostream>
#include "Passport.h"
#include "AddInfo.h"
#include "ForeignPassport.h"

using namespace PassportNamespace;
using namespace ForeignPassportNamespace;

int main() {
    Passport passport("Jony Jonas", MALE, { 10, 8, 1990 }, { 10, 8, 2025 }, "USA", 123456789, 987654);

    cout << "\n\t    *  Passport Data   *" << endl;
    passport.print();

    ForeignPassport fpassport("Jony Jonas", MALE, { 10, 8, 1990 }, { 10, 8, 2025 }, "USA", 123456789, 987654, "some country", "work visa", 987654321, { 10, 10, 2023 }, 123);

    fpassport.print();
}
