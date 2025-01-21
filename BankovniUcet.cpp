#include "BankovniUcet.h"

#include <iostream>
#include <cctype>

using namespace std;

void BankovniUcet::zobraz_ucet() {
    cout << "Jmeno vkladatele: " << this->jmeno << endl;
    cout << "Cislo uctu: " << this->cisloUctu << endl;
    cout << "Zustatek na uctu: " << this->zustatek << " Kc" << endl;
}

BankovniUcet::BankovniUcet() {
    this->jmeno = "no name";
    this->cisloUctu = "0000 0000 0000 0000 0000 0000";
    this->zustatek = 0;
}

BankovniUcet::BankovniUcet(const string &jmeno, const string &cisloUctu, int zustatek) {
    this->jmeno = jmeno;
    this->cisloUctu = cisloUctu;
    this->zustatek = zustatek;
}

BankovniUcet::~BankovniUcet() = default;

void BankovniUcet::uloz_castku(int castka) {
    this->zustatek += castka;
}

int BankovniUcet::vyber_castku(int castka) {
    if (this->zustatek < castka) {
        return -1;
    } else {
        this->zustatek -= castka;
    }
    return castka;
}
