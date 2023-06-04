//
// Created by pedro on 01/06/2023.
//

#ifndef FEUP_DA_PROJECT2_MENU_H
#define FEUP_DA_PROJECT2_MENU_H

#include "../dataStructures/graph.cpp"
#include <iostream>
#include <fstream>
#include <sstream>


class Menu{
public:
    Menu();

    void start();
    void setState(int state);
    void drawState();
    void drawToyMenu();
    void drawRealMenu();
    void drawExtraMenu();
    void readData(const std::string& filename, bool header, bool label, bool nodes, bool newgraph);
private:
    int state;
    Graph graph = Graph(true);
};

#endif //FEUP_DA_PROJECT2_MENU_H
