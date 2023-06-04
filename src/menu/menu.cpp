#include "menu.h"
#include <filesystem>

using namespace std;

Menu::Menu() {
    this->state = 0;
}

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
        case 1:
            readData("../../data/Toy-Graphs/shipping.csv", true, false, false, true);
            break;
        case 2:
            readData("../../data/Toy-Graphs/stadiums.csv", true, false, false, true);
            break;
        case 3:
            readData("../../data/Toy-Graphs/tourism.csv", true, true, false, true);
            break;
        default:
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
        case 1:
            readData("../../data/Real-world Graphs/graph1/edges.csv", true, false, false, true);
            readData("../../data/Real-world Graphs/graph1/nodes.csv", true, false, true, false);
            break;
        case 2:
            readData("../../data/Real-world Graphs/graph2/edges.csv", true, false, false, true);
            readData("../../data/Real-world Graphs/graph2/nodes.csv", true, false, true, false);
            break;
        default:
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
        case 1:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_25.csv", false, false, false, true);
            break;
        case 2:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_50.csv", false, false, false, true);
            break;
        case 3:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_75.csv", false, false, false, true);
            break;
        case 4:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_100.csv", false, false, false, true);
            break;
        case 5:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_200.csv", false, false, false, true);
            break;
        case 6:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_300.csv", false, false, false, true);
            break;
        case 7:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_400.csv", false, false, false, true);
            break;
        case 8:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_500.csv", false, false, false, true);
            break;
        case 9:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_600.csv", false, false, false, true);
            break;
        case 10:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_700.csv", false, false, false, true);
            break;
        case 11:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_800.csv", false, false, false, true);
            break;
        case 12:
            readData("../../data/Extra_Fully_Connected_Graphs/edges_900.csv", false, false, false, true);
            break;
        default:
            break;
    }
}

void Menu::readData(const std::string& filename, bool header, bool label, bool nodes, bool newgraph) {
    cout << "Loading..." << endl;

    if(newgraph) this->graph = Graph(true);

    std::string a, b, distance, alabel, blabel, line;

    std::ifstream input(filename);

    if(header) getline(input, line);

    while(getline(input, line)){
        std::stringstream ss(line);

        getline(ss, a, ',');
        getline(ss, b, ',');
        getline(ss, distance, ',');
        if(label){
            getline(ss, alabel, ',');
            getline(ss, blabel, ',');
        }

        if(line.back() == '\r' || line.back() == '\n') line.pop_back();

        this->graph.addVertex(std::stoi(a), nodes ? std::stoi(b) : 0, nodes? std::stoi(distance) : 0, label ? alabel : "");
        if(!nodes){
            this->graph.addVertex(std::stoi(b), 0, 0, label ? blabel : "");
            this->graph.addEdge(std::stoi(a), std::stoi(b), std::stoi(distance));
            this->graph.addEdge(std::stoi(b), std::stoi(a), std::stoi(distance));
        }
    }


    cout << "Reading complete\n" << filename << endl << graph.getEdgeCount() << endl;

    int n;
    cin >> n;
}