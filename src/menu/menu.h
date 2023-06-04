#ifndef FEUP_DA_PROJECT2_MENU_H
#define FEUP_DA_PROJECT2_MENU_H

#include "../dataStructures/graph.cpp"
#include <iostream>
#include <fstream>
#include <sstream>

/**
 * @brief The Menu class represents a menu for interacting with the graph algorithms.
 */
class Menu {
public:
    /**
     * @brief Constructs a new Menu object.
     * @details Time Complexity: O(1)
     */
    Menu();

    /**
     * @brief Gets the current state of the menu.
     * @details Time Complexity: O(1)
     * @return The current state of the menu.
     */
    int getState() const;

    /**
     * @brief Sets the state of the menu.
     * @details Time Complexity: O(1)
     * @param state The new state.
     */
    void setState(int state);

    /**
     * @brief Draws the current state of the menu.
     * @details Time Complexity: O(1)
     */
    void drawState();

    /**
     * @brief Draws the starting menu.
     * @details Time Complexity: O(1)
     */
    void drawStartMenu();

    /**
     * @brief Draws the Toy Graphs menu.
     * @details Time Complexity: O(1)
     */
    void drawToyMenu();

    /**
     * @brief Draws the Real-World Graphs menu.
     * @details Time Complexity: O(1)
     */
    void drawRealMenu();

    /**
     * @brief Draws the Extra Graphs menu.
     * @details Time Complexity: O(1)
     */
    void drawExtraMenu();

    /**
     * @brief Draws the algorithms menu.
     * @details Time Complexity: O(1)
     */
    void drawAlgorithmsMenu();

    /**
     * @brief Reads data from a file and initializes the graph.
     * @details Time Complexity: O(n), n = number of lines in the file
     * @param filename The name of the file to read data from.
     * @param header Flag indicating whether the file has a header.
     * @param label Flag indicating whether the file has labels.
     * @param nodes Flag indicating whether the file represents nodes or edges.
     * @param newgraph Flag indicating whether to create a new graph or update an existing one.
     *
     *
     * @details This function reads data from a CSV file and initializes the graph based on the file contents.
     *          It supports reading both node and edge information. The file format must follow the specified
     *          structure, and the data is loaded into the `graph` object.
     *
     * @note If `newgraph` is set to true, a new graph will be created. Otherwise, the data will be added to an existing graph.
     *
     * @note This function assumes that the CSV file is properly formatted and accessible.
     */
    void readData(const std::string& filename, bool header, bool label, bool nodes, bool newgraph);

    /**
     * @brief Executes the selected algorithm.
     * @details Time Complexity: O(V), V = number of vertices
     * @param choice The user's choice of algorithm.
     */
    void executeAlgorithm(int choice);

private:
    int state;  /**< The current state of the menu. */
    Graph graph = Graph(true);  /**< The graph object to perform algorithms on */
    std::string graphname; /**< The name of the selected graph */
};

#endif //FEUP_DA_PROJECT2_MENU_H
