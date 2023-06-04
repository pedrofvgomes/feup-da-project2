#include "graph.h"

Graph::Graph(bool directed) {
    this->directed = directed;
    this->edgeCount = 0;
    this->vertexMap = std::unordered_map<int, vertexNode>();
}

int Graph::getEdgeCount() const {
    return this->edgeCount;
}
int Graph::getVertexCount() const {
    return this->vertexMap.size();
}
bool Graph::isDirected() const {
    return this->directed;
}
double Graph::getLatitude(int v) {
    return this->vertexMap[v].latitude;
}
double Graph::getLongitude(int v) {
    return this->vertexMap[v].longitude;
}

std::string Graph::getLabel(int v) {
    return this->vertexMap[v].label;
}
double Graph::getDistance(int v1, int v2) {
    for(auto &e: this->vertexMap[v1].adjacent)
        if(e.destVertex == v2)
            return e.distance;

    return 0;
}


void Graph::setCoordinates(int v, double latitude, double longitude) {
    this->vertexMap[v].latitude = latitude;
    this->vertexMap[v].longitude = longitude;
}


bool Graph::addVertex(int v, double latitude, double longitude, std::string label) {
    if(v < 0 || vertexMap.count(v)) return false;

    this->vertexMap[v] = vertexNode{v, latitude, longitude, label, std::vector<edgeNode>()};

    return true;
}
bool Graph::addEdge(int v1, int v2, double distance) {
    if(v1 < 0 || v2 < 0 || this->vertexMap.count(v1) == 0 || this->vertexMap.count(v2) == 0)
        return false;

    for(auto &e : this->vertexMap[v1].adjacent)
        if(e.destVertex == v2) return false;

    this->vertexMap[v1].adjacent.push_back(edgeNode{v2, distance});

    if(this->directed){
        for(auto &e : this->vertexMap[v2].adjacent)
            if(e.destVertex == v1) return false;

        this->vertexMap[v2].adjacent.push_back(edgeNode{v1, distance});
    }

    this->edgeCount++;
    return true;
}
