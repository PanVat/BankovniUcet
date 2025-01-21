#ifndef BANKOVNI_UCET_H_
#define BANKOVNI_UCET_H_

#include <iostream>

using namespace std;

class BankovniUcet {
private:
    string jmeno;
    string cisloUctu;
    int zustatek;

public:
    void zobraz_ucet();

    void uloz_castku(int castka);

    int vyber_castku(int castka);

    BankovniUcet();

    BankovniUcet(const string &jmeno, const string &cisloUctu, int zustatek);

    ~BankovniUcet();
};

#endif