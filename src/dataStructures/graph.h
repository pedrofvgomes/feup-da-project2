#include <string>
#include <unordered_map>
#include <vector>

#ifndef FEUP_DA_PROJECT2_GRAPH_H
#define FEUP_DA_PROJECT2_GRAPH_H

class Graph{
public:
    Graph(bool directed);

    // get
    int getEdgeCount() const;
    int getVertexCount() const;
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




protected:
    bool directed;
    int edgeCount;

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

    std::unordered_map<int, vertexNode> vertexMap;
};

#endif //FEUP_DA_PROJECT2_GRAPH_H
