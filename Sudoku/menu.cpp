#include "menu.h"
#include <iostream>

using namespace std;

int Menu::showMainMenu() {
    int choice;
    cout << "\n1. Ucitaj postojecu zagonetku iz datoteke\n"
        << "2. Generisi novu zagonetku\n"
        << "0. Izlaz iz programa\n"
        << "Izaberite opciju: ";
    cin >> choice;
    return choice;
}

int Menu::showGameMenu() {
    int choice;
    cout << "\n1. Samostalno resi zagonetku\n"
        << "2. Kompjuter resava zagonetku\n"
        << "0. Nazad na glavni meni\n"
        << "Izaberite opciju: ";
    cin >> choice;
    return choice;
}

int Menu::playAgainMenu() {
    int choice;
    cout << "\n1. Igraj ponovo\n"
        << "0. Nazad na glavni meni\n"
        << "Izaberite opciju: ";
    cin >> choice;
    return choice;
}
