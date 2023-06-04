#ifndef FEUP_DA_PROJECT2_GRAPH_H
#define FEUP_DA_PROJECT2_GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits>
#include <queue>
#include <iostream>
#include <cmath>

#define EARTH_RADIUS (double) 6371000.0

/**
 * @brief Structure representing an edge in the graph.
 */
struct edgeNode{
    int destVertex; /**< The destination vertex of the edge. */
    double distance; /**< The distance or weight of the edge. */
};

/**
 * @brief Structure representing a vertex in the graph.
 */
struct vertexNode{
    int vertex; /**< The vertex identifier. */
    double latitude; /**< The latitude coordinate of the vertex. */
    double longitude; /**< The longitude coordinate of the vertex. */
    std::string label; /**< The label or name of the vertex. */
    std::vector<edgeNode> adjacent; /**< List of adjacent edges. */
};

/**
 * @brief The Graph class represents a graph data structure.
 */
class Graph{
public:
    /**
     * @brief Constructs a new Graph object.
     * @details Time Complexity: O(1)
     * @param directed Flag indicating whether the graph is directed.
     */
    Graph(bool directed);

    /**
     * @brief Gets the number of vertices in the graph.
     * @details Time Complexity: O(1)
     * @return The number of vertices.
     */
    int getVertexCount() const;

    /**
     * @brief Gets a map of all the vertices in the graph.
     * @details Time Complexity: O(1)
     * @return The map of vertices.
     */
    std::unordered_map<int, vertexNode> getVertices();

    /**
     * @brief Adds a new vertex to the graph.
     * @details Time Complexity: O(1)
     * @param v The vertex identifier.
     * @param latitude The latitude coordinate of the vertex.
     * @param longitude The longitude coordinate of the vertex.
     * @param label The label or name of the vertex.
     * @return True if the vertex was added successfully, false otherwise.
     */
    bool addVertex(int v, double latitude, double longitude, std::string label);

    /**
     * @brief Adds a new edge to the graph.
     * @details Time Complexity: O(n)
     * @param v1 The identifier of the first vertex.
     * @param v2 The identifier of the second vertex.
     * @param distance The distance or weight of the edge.
     * @return True if the edge was added successfully, false otherwise.
     */
    bool addEdge(int v1, int v2, double distance);

    /**
     * @brief Applies Prim's algorithm to find a minimum spanning tree of the graph.
     * @details Time Complexity: O((V+E) * log(V)), E = number of edges, V = number of vertices
     * @param parent The output vector to store the parent vertices of the minimum spanning tree.
     * @return The list of edges in the minimum spanning tree.
     */
    std::vector<std::pair<int,int>> prim_mst(std::vector<int>& parent);

    /**
     * @brief Applies the backtracking algorithm to solve the Traveling Salesman Problem (TSP).
     * @details Time Complexity: O((V-1)!), V = number of vertices
     * @param path The output vector to store the optimal path.
     * @param visited The state of visited vertices during the backtracking process.
     * @param min_cost The minimum cost of the TSP solution.
     * @param current_cost The current cost of the path being constructed.
     */
    void backtrack_tsp(std::vector<int>& path, std::vector<bool>& visited, double &min_cost, double current_cost);

    /**
     * @brief Applies the Triangular Approximation algorithm to find an approximate solution for the TSP.
     * @details Time Complexity: O((V+E) * log(V)), E = number of edges, V = number of vertices
     * @return The total distance of the approximate TSP solution.
     */
    double triangular_approximation();

    /**
     * @brief Performs a Depth-First Search (DFS) traversal of the graph.
     * @details Time Complexity: O(E + V), E = number of edges, V = number of vertices
     * @param current The current vertex being visited.
     * @param parent The parent vertices during the traversal.
     * @param visited The state of visited vertices during the traversal.
     * @param stack The stack to store the visited vertices in the order of traversal.
     * @param path The output vector to store the path of the DFS traversal.
     */
    void dfs(int current, const std::vector<int> &parent, std::vector<bool> &visited, std::stack<int> &stack, std::vector<int> &path);

    /**
     * @brief Checks if two vertices in the graph are connected by an edge.
     * @details Time Complexity: O(V + E), V = number of vertices, E = number of edges adjacent to the vertex a
     * @param a The identifier of the first vertex.
     * @param b The identifier of the second vertex.
     * @return True if the vertices are connected, false otherwise.
     */
    bool are_nodes_connected(int a, int b);

    /**
     * @brief Calculates the Haversine distance between two coordinates.
     * @details Time Complexity: O(1)
     * @param lat1 The latitude of the first coordinate.
     * @param lon1 The longitude of the first coordinate.
     * @param lat2 The latitude of the second coordinate.
     * @param lon2 The longitude of the second coordinate.
     * @return The Haversine distance between the coordinates.
     */
    double haversine(double lat1, double lon1, double lat2, double lon2);

    /**
     * @brief Calculates the total distance of a given path in the graph.
     * @details Time Complexity: O(n * (V + E)), n = number of vertices in the input path, V = number of vertices in the whole graph, E = number of edges in the whole graph
     * @param path The path represented as a vector of vertex identifiers.
     * @return The total distance of the path.
     */
    double total_distance(const std::vector<int>& path);

    /**
     * @brief Applies the Nearest Neighbor heuristic to find an approximate solution for the TSP starting from a given vertex.
     * @details Time Complexity: O(V^2), V = number of vertices
     * @param start The identifier of the starting vertex.
     * @return The approximate TSP path.
     */
    std::vector<int> nearest_neighbor(int start);

protected:
    bool directed; /**< Flag indicating whether the graph is directed. */
    int edgeCount; /**< The number of edges in the graph. */
    std::unordered_map<int, vertexNode> vertexMap; /**< Unordered map of vertices in the graph. */
};

#endif //FEUP_DA_PROJECT2_GRAPH_H
