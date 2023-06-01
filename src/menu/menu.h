//
// Created by pedro on 01/06/2023.
//

#ifndef FEUP_DA_PROJECT2_MENU_H
#define FEUP_DA_PROJECT2_MENU_H

class Menu{
public:
    void start();
    void setState(int state);
    void drawState();
    void drawToyMenu();
    void drawRealMenu();
    void drawExtraMenu();
private:
    int state;
};

#endif //FEUP_DA_PROJECT2_MENU_H
