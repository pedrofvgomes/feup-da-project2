#ifndef FEUP_DA_PROJECT2_GRAPH_H
#define FEUP_DA_PROJECT2_GRAPH_H

#include <string>
#include <unordered_map>
#include <vector>
#include <stack>
#include <limits>
#include <queue>
#include <iostream>
#include <math.h>

#define EARTH_RADIUS (double) 6371000.0


struct edgeNode{
    int destVertex;
    double distance;
};
struct vertexNode{
    int vertex;
    double latitude;
    double longitude;
    std::string label;

    std::vector<edgeNode> adjacent;
};

class Graph{
public:
    Graph(bool directed);

    // get
    int getEdgeCount() const;
    int getVertexCount() const;
    std::unordered_map<int, vertexNode> getVertices();
    bool isDirected() const;
    double getLatitude(int v);
    double getLongitude(int v);
    double getDistance(int v1, int v2);
    std::string getLabel(int v);

    // set
    void setCoordinates(int v, double latitude, double longitude);

    // add / remove
    bool addVertex(int v, double latitude, double longitude, std::string label);
    bool addEdge(int v1, int v2, double distance);
    bool removeEdge(int v1, int v2);

    // algorithms
    void dijkstra(int source);
    std::vector<std::pair<int,int>> prim_mst(std::vector<int>& parent);
    void backtrack_tsp(std::vector<int>& path, std::vector<bool>& visited, double &min_cost, double current_cost);
    double triangular_approximation();
    void dfs(int current, const std::vector<int> &parent, std::vector<bool> &visited, std::stack<int> &cityStack, std::vector<int> &path);
    bool are_nodes_connected(int a, int b);
    double haversine(double lat1, double lon1, double lat2, double lon2);
    double total_distance(const std::vector<int>& path);
    std::vector<int> nearest_neighbor(int start);

protected:
    bool directed;
    int edgeCount;

    std::unordered_map<int, vertexNode> vertexMap;
};

#endif //FEUP_DA_PROJECT2_GRAPH_H
