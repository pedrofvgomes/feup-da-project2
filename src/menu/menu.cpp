#include "menu.h"
#include <iostream>
using namespace std;

void Menu::start() {
    int choice = 0;

    system("cls");
    cout << "========= MAIN MENU =========";
    cout << "\n\n=== SELECT THE GRAPH TYPE ===";
    cout << "\n\n1) Toy Graphs";
    cout << "\n\n2) Real World Graphs";
    cout << "\n\n3) Extra Medium-Sized Graphs";
    cout << "\n\n\n0) Quit";
    cout << "\n\n--> ";
    cin >> choice;

    while(choice < 0 || choice > 3){
        cout << "Please enter a valid option\n--> ";
        cin >> choice;
    }

    setState(choice);
    drawState();
}

void Menu::setState(int state) {
    this->state = state;
}

void Menu::drawState() {
    switch (state) {
        case 1:
            drawToyMenu();
            break;
        case 2:
            drawRealMenu();
            break;
        case 3:
            drawExtraMenu();
            break;
        default:
            break;
    }
}

void Menu::drawToyMenu(){
    int choice = 0;

    system("cls");
    cout << "========= TOY GRAPHS =========";
    cout << "\n\n=== SELECT A GRAPH ===";
    cout << "\n\n1) Shipping";
    cout << "\n\n2) Stadiums";
    cout << "\n\n3) Tourism";
    cout << "\n\n\n0) Go back";
    cout << "\n\n--> ";
    cin >> choice;

    while(choice < 0 || choice > 3){
        cout << "Please enter a valid option\n--> ";
        cin >> choice;
    }

    switch (choice) {
        case 0:
            start();
            break;
        default:
            // readGraph({1, choice});
            break;
    }
}
void Menu::drawRealMenu() {
    int choice = 0;

    system("cls");
    cout << "========= REAL WORLD GRAPHS =========";
    cout << "\n\n=== SELECT A GRAPH ===";
    cout << "\n\n1) Graph 1";
    cout << "\n\n2) Graph 2";
    cout << "\n\n3) Graph 3";
    cout << "\n\n\n0) Go back";
    cout << "\n\n--> ";
    cin >> choice;

    while(choice < 0 || choice > 3){
        cout << "Please enter a valid option\n--> ";
        cin >> choice;
    }

    switch (choice) {
        case 0:
            start();
            break;
        default:
            // readGraph({2, choice});
            break;
    }
}
void Menu::drawExtraMenu() {
    int choice = 0;

    system("cls");
    cout << "========= EXTRA MEDIUM-SIZED GRAPHS =========";
    cout << "\n\n=== SELECT THE NUMBER OF NODES ===";
    cout << "\n\n1) 25";
    cout << "\n\n2) 50";
    cout << "\n\n3) 75";
    cout << "\n\n4) 100";
    cout << "\n\n5) 200";
    cout << "\n\n6) 300";
    cout << "\n\n7) 400";
    cout << "\n\n8) 500";
    cout << "\n\n9) 600";
    cout << "\n\n10) 700";
    cout << "\n\n11) 800";
    cout << "\n\n12) 900";
    cout << "\n\n\n0) Go back";
    cout << "\n\n--> ";
    cin >> choice;

    while(choice < 0 || choice > 12){
        cout << "Please enter a valid option\n--> ";
        cin >> choice;
    }

    switch (choice) {
        case 0:
            start();
            break;
        default:
            // readGraph({3, choice});
            break;
    }
}