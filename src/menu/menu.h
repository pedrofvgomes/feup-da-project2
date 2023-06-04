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

    int getState() const;
    void setState(int state);
    void drawState();
    void drawStartMenu();
    void drawToyMenu();
    void drawRealMenu();
    void drawExtraMenu();
    void drawAlgorithmsMenu();
    void readData(const std::string& filename, bool header, bool label, bool nodes, bool newgraph);
    void executeAlgorithm(int choice);
private:
    int state;
    Graph graph = Graph(true);
};

#endif //FEUP_DA_PROJECT2_MENU_H
