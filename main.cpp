#include "BankovniUcet.h"
#include <iostream>
#include <limits>

int vstup_castky();

int main() {
    BankovniUcet bankovniUcet("Filip Podeszwa", "CZ49 0710 0000 0000 0012 3457", 265000);
    int operace;
    int vybranaCastka = 0;

    cout << "1 - Ulozit castku na ucet" << endl;
    cout << "2 - Vybrat castku z uctu" << endl;
    cout << "3 - Zobrazit stav uctu" << endl;
    cout << "4 - Konec" << endl << endl;

    cout << "Zvolte operaci: ";
    cin >> operace;

    while (cin.get() != '\n');

    while (operace != 4) {
        switch (operace) {
            case 1:
                int vklad;
                cout << "Zadej castku, kterou chces ulozit: ";
                vklad = vstup_castky();
                bankovniUcet.uloz_castku(vklad);
                break;
            case 2: {
                int vyber;
                cout << "Zadej castku, kterou chces vybrat: ";
                vyber = vstup_castky();
                int vysledek = bankovniUcet.vyber_castku(vyber);
                if (vysledek == -1) {
                    cout << "Na uctu neni dostatek penez" << endl;
                } else {
                    vybranaCastka += vysledek;
                    cout << "Mate vybrano celkem " << vybranaCastka << " Kc." << endl;
                }
                break;
            }
            case 3:
                bankovniUcet.zobraz_ucet();
                break;
            default:
                cout << "Neplatna operace." << endl;
        }


        cout << "\n1 - Ulozit castku na ucet" << endl;
        cout << "2 - Vybrat castku z uctu" << endl;
        cout << "3 - Zobrazit stav uctu" << endl;
        cout << "4 - Konec" << endl << endl;

        cout << "Zvolte operaci: ";
        cin >> operace;
    }

    cout << "Nashledanou" << endl;


    return 0;
}

int vstup_castky() {
    int castka;
    while (true) {
        cin >> castka;
        if (cin.good()) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return castka;
        } else {
            cout << "Castka musi obsahovat pouze cisla." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}
