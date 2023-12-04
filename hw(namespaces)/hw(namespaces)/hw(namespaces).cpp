#include <iostream>
#include "Passport.h"
#include "ForeignPassport.h"
#include "AddInfo.h"

using namespace PassportNamespace;
using namespace AddInfo;

int main() {
    Passport myPassport("Jony Jonas", MALE, { 10, 8, 1990 }, { 10, 8, 2025 }, "USA", 123456789, 987654);

    cout << "Passport Information:" << std::endl;
    myPassport.print();

    ForeignPassport myForeignPassport("Jony Jonas", MALE, { 10, 8, 1990 }, { 10, 8, 2025 }, "USA", 123456789, 987654, "some country", "work visa", 987654321, { 10, 10, 2023 }, 123);

    cout << "\nForeign Passport Information:" << std::endl;
    myForeignPassport.print();

}
