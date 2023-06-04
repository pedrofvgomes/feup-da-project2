#include <iomanip>
#include "menu.h"

Menu::Menu() {
    this->state = 0;
}
int Menu::getState() const{
    return this->state;
}
void Menu::setState(int state) {
    this->state = state;
}

void Menu::drawState() {
    switch (state) {
        case 0:
            drawStartMenu();
            break;
        case 1:
            drawToyMenu();
            break;
        case 2:
            drawRealMenu();
            break;
        case 3:
            drawExtraMenu();
            break;
        case 4:
            drawAlgorithmsMenu();
            break;
        default:
            break;
    }
}

void Menu::drawStartMenu() {
    int choice = 0;

    system("cls");
    std::cout << "========= MAIN MENU =========";
    std::cout << "\n\n=== SELECT THE GRAPH TYPE ===";
    std::cout << "\n\n1) Toy Graphs";
    std::cout << "\n\n2) Real World Graphs";
    std::cout << "\n\n3) Extra Medium-Sized Graphs";
    std::cout << "\n\n\n0) Quit";
    std::cout << "\n\n--> ";
    std::cin >> choice;

    while(choice < 0 || choice > 3){
        std::cout << "Please enter a valid option\n--> ";
        std::cin >> choice;
    }

    setState(choice);
    if(!choice) setState(-1);
    drawState();
}

void Menu::drawToyMenu(){

    int choice = 0;

    system("cls");
    std::cout << "========= TOY GRAPHS =========";
    std::cout << "\n\n======= SELECT A GRAPH ========";
    std::cout << "\n\n1) Shipping";
    std::cout << "\n\n2) Stadiums";
    std::cout << "\n\n3) Tourism";
    std::cout << "\n\n\n0) Go back";
    std::cout << "\n\n--> ";
    std::cin >> choice;

    while(choice < 0 || choice > 3){
        std::cout << "Please enter a valid option\n--> ";
        std::cin >> choice;
    }

    switch (choice) {
        case 0:
            setState(0);
            break;
        case 1:
            graphname = "Toy Graphs - Shipping";
            readData("../../data/Toy-Graphs/shipping.csv", true, false, false, true);
            break;
        case 2:
            graphname = "Toy Graphs - Stadiums";
            readData("../../data/Toy-Graphs/stadiums.csv", true, false, false, true);
            break;
        case 3:
            graphname = "Toy Graphs - Tourism";
            readData("../../data/Toy-Graphs/tourism.csv", true, true, false, true);
            break;
        default:
            break;
    }
    setState(!choice? 0 : 4);
}
void Menu::drawRealMenu() {
    int choice = 0;

    system("cls");
    std::cout << "========= REAL WORLD GRAPHS =========";
    std::cout << "\n\n========== SELECT A GRAPH ==========";
    std::cout << "\n\n1) Graph 1";
    std::cout << "\n\n2) Graph 2";
    std::cout << "\n\n\n0) Go back";
    std::cout << "\n\n--> ";
    std::cin >> choice;

    while(choice < 0 || choice > 2){
        std::cout << "Please enter a valid option\n--> ";
        std::cin >> choice;
    }

    switch (choice) {
        case 0:
            setState(0);
            break;
        case 1:
            graphname = "Real-World Graphs - Graph 1";
            readData("../../data/Real-world Graphs/graph1/edges.csv", true, false, false, true);
            readData("../../data/Real-world Graphs/graph1/nodes.csv", true, false, true, false);
            break;
        case 2:
            graphname = "Real-World Graphs - Graph 2";
            readData("../../data/Real-world Graphs/graph2/edges.csv", true, false, false, true);
            readData("../../data/Real-world Graphs/graph2/nodes.csv", true, false, true, false);
            break;
        default:
            break;
    }
    setState(!choice? 0 : 4);
}
void Menu::drawExtraMenu() {
    int choice = 0;

    system("cls");
    std::cout << "========= EXTRA MEDIUM-SIZED GRAPHS =========";
    std::cout << "\n\n======== SELECT THE NUMBER OF NODES ========";
    std::cout << "\n\n1) 25";
    std::cout << "\n\n2) 50";
    std::cout << "\n\n3) 75";
    std::cout << "\n\n4) 100";
    std::cout << "\n\n5) 200";
    std::cout << "\n\n6) 300";
    std::cout << "\n\n7) 400";
    std::cout << "\n\n8) 500";
    std::cout << "\n\n9) 600";
    std::cout << "\n\n10) 700";
    std::cout << "\n\n11) 800";
    std::cout << "\n\n12) 900";
    std::cout << "\n\n\n0) Go back";
    std::cout << "\n\n--> ";
    std::cin >> choice;

    while(choice < 0 || choice > 12){
        std::cout << "Please enter a valid option\n--> ";
        std::cin >> choice;
    }

    switch (choice) {
        case 1:
            graphname = "Extra Graphs - 25 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_25.csv", false, false, false, true);
            break;
        case 2:
            graphname = "Extra Graphs - 50 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_50.csv", false, false, false, true);
            break;
        case 3:
            graphname = "Extra Graphs - 75 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_75.csv", false, false, false, true);
            break;
        case 4:
            graphname = "Extra Graphs - 100 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_100.csv", false, false, false, true);
            break;
        case 5:
            graphname = "Extra Graphs - 200 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_200.csv", false, false, false, true);
            break;
        case 6:
            graphname = "Extra Graphs - 300 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_300.csv", false, false, false, true);
            break;
        case 7:
            graphname = "Extra Graphs - 400 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_400.csv", false, false, false, true);
            break;
        case 8:
            graphname = "Extra Graphs - 500 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_500.csv", false, false, false, true);
            break;
        case 9:
            graphname = "Extra Graphs - 600 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_600.csv", false, false, false, true);
            break;
        case 10:
            graphname = "Extra Graphs - 700 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_700.csv", false, false, false, true);
            break;
        case 11:
            graphname = "Extra Graphs - 800 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_800.csv", false, false, false, true);
            break;
        case 12:
            graphname = "Extra Graphs - 900 nodes";
            readData("../../data/Extra_Fully_Connected_Graphs/edges_900.csv", false, false, false, true);
            break;
        default:
            break;
    }
    setState(!choice? 0 : 4);
}

void Menu::readData(const std::string& filename, bool header, bool label, bool nodes, bool newgraph) {
    if(!nodes) std::cout << "\n\nLoading..." << std::endl;

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
            this->graph.addEdge(std::stoi(a), std::stoi(b), std::stod(distance));
            this->graph.addEdge(std::stoi(b), std::stoi(a), std::stod(distance));
        }
    }

    if(!nodes) {
        std::cout << "\nReading complete!\n\n0) Continue\n";
        int n = 1;
        while (n != 0) {
            std::cout << "--> ";
            std::cin >> n;
        }
    }
}

void Menu::drawAlgorithmsMenu() {
    int choice = 0;

    system("cls");
    std::cout << "========= ALGORITHMS =========";
    std::cout << "\n\nSELECTED GRAPH: " << graphname;
    std::cout << "\n\n===== CHOOSE AN ALGORITHM =====";
    std::cout << "\n\n1) Triangular Approximation";
    std::cout << "\n\n2) Nearest Neighbor";
    std::cout << "\n\n3) Backtracking";
    std::cout << "\n\n\n0) Go back";
    std::cout << "\n\n--> ";
    std::cin >> choice;
    while(choice < 0 || choice > 3){
        std::cout << "Please enter a valid option\n--> ";
        std::cin >> choice;
    }

    executeAlgorithm(choice);
    if(choice){
        std::cout << "0) Continue\n";
        int n = 1;
        while(n!=0){
            std::cout << "--> ";
            std::cin >> n;
        }
        if(!n){
            setState(0);
            drawState();
        }
    }
}

void Menu::executeAlgorithm(int choice) {
    std::cout << "\nLoading... \n\n";
    clock_t start_time = clock(), end_time;
    double val, min_cost;
    std::vector<int> path;

    switch (choice) {
        case 1:
            val = this->graph.triangular_approximation();
            end_time = clock();
            break;
        case 2: {
            std::unordered_map<int, vertexNode> vertices = this->graph.getVertices();
            min_cost = std::numeric_limits<double>::max();
            std::vector<int> min_path;

            for(int i=0; i<vertices.size(); i++) {
                std::vector<int> current_path = this->graph.nearest_neighbor(i);
                val = this->graph.total_distance(current_path);

                if(val < min_cost){
                    min_cost = val;
                    min_path = current_path;
                }
            }

            end_time = clock();
            val = this->graph.total_distance(min_path);
            break;
        }
        case 3: {
            min_cost = std::numeric_limits<double>::max();
            path = {0};
            std::vector<bool> visited(this->graph.getVertexCount(), false);
            visited[0] = true;

            this->graph.backtrack_tsp(path, visited, min_cost, 0.0);

            end_time = clock();
            val = min_cost;
            break;
        }
        case 0:
            setState(0);
            drawState();
            return;
    }

    std::cout << std::fixed << std::setprecision(2) << "Minimum Distance: " << val << std::endl;
    std::cout << "Execution Time: " << double(end_time-start_time) / CLOCKS_PER_SEC << " seconds\n\n";
}
