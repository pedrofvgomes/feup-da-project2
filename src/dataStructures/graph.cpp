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
std::unordered_map<int, vertexNode> Graph::getVertices() {
    return this->vertexMap;
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

std::vector<std::pair<int,int>> Graph::prim_mst(std::vector<int>& parent){
    std::vector<double> key(vertexMap.size(), std::numeric_limits<double>::max());
    std::vector<bool> in_mst(vertexMap.size(), false);
    int start = 0;
    key[start] = 0.0;

    std::priority_queue<std::pair<double,int>, std::vector<std::pair<double,int>>, std::greater<std::pair<double,int>>> pq;
    pq.push(std::make_pair(0.0, start));

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        if(in_mst[u]) continue;
        in_mst[u] = true;

        for(const edgeNode &edge : vertexMap[u].adjacent){
            if(!in_mst[edge.destVertex] && edge.distance < key[edge.destVertex]){
                parent[edge.destVertex] = u;
                key[edge.destVertex] = edge.distance;
                pq.push(std::make_pair(edge.distance, edge.destVertex));
            }
        }
    }

    std::vector<std::pair<int,int>> mst;
    std::cout << "Minimum-Cost Spanning Tree: " << std::endl;
    for(int i=1; i<vertexMap.size(); ++i){
        mst.push_back(std::make_pair(parent[i], i));

        std::cout << parent[i] << " - " << i << std::endl;
    }

    return mst;
}


void Graph::backtrack_tsp(std::vector<int>& path, std::vector<bool>& visited, double &min_cost, double current_cost){
    if(path.size() == vertexMap.size()){
        int start = path.front();
        int end = path.back();

        for(auto &edge : vertexMap[end].adjacent){
            if(edge.destVertex == start){
                double cycle_cost = current_cost + edge.distance;
                if(cycle_cost < min_cost) min_cost = cycle_cost;
                // Don't break here to explore other potential paths
            }
        }

        return;
    }

    int end = path.back();
    for(auto &edge: vertexMap[end].adjacent){
        if(!visited[edge.destVertex]){
            path.push_back(edge.destVertex);
            visited[edge.destVertex] = true;
            backtrack_tsp(path, visited, min_cost, current_cost + edge.distance);
            path.pop_back();
            visited[edge.destVertex] = false;
        }
    }
}


void Graph::dfs(int current, const std::vector<int> &parent, std::vector<bool> &visited, std::stack<int> &cityStack, std::vector<int> &path) {
    visited[current] = true;
    cityStack.push(current);

    while (!cityStack.empty()) {
        int city = cityStack.top();
        cityStack.pop();

        // Process the city or print its order
        path.push_back(city);

        for (int neighbor = 0; neighbor < parent.size(); ++neighbor) {
            if (parent[neighbor] == city && !visited[neighbor]) {
                visited[neighbor] = true;
                cityStack.push(neighbor);
            }
        }
    }
}

double Graph::total_distance(const std::vector<int>& path){
    double total = 0.0;

    for(int i=0; i<path.size()-1; ++i){
        int a = path[i], b = path[i+1];

        if(!are_nodes_connected(a, b)){
            total += haversine(vertexMap[a].latitude, vertexMap[a].longitude, vertexMap[b].latitude, vertexMap[b].longitude);
            continue;
        }

        for(const edgeNode& edge : vertexMap[a].adjacent){
            if(edge.destVertex == b){
                total += edge.distance;
                break;
            }
        }
    }

    int final_city = path.back();
    if(!are_nodes_connected(final_city, path[0])){
        total += haversine(vertexMap[final_city].latitude, vertexMap[final_city].longitude, vertexMap[path[0]].latitude, vertexMap[path[0]].longitude);
    }
    else for(const edgeNode& edge : vertexMap[final_city].adjacent){
        if(edge.destVertex == path[0]){
            total += edge.distance;
            break;
        }
    }

    return total;
}

bool Graph::are_nodes_connected(int a, int b){
    int a_index;

    for(auto it = vertexMap.begin(); it != vertexMap.end(); it++){
        if(it->second.vertex == a){
            a_index = it->first;
            break;
        }
    }

    for(const edgeNode& edge : vertexMap[a_index].adjacent){
        if(edge.destVertex == b) return true;
    }

    return false;
}

double Graph::haversine(double lat1, double lon1, double lat2, double lon2) {
    if (lat1 == 0 && lon1 == 0 && lat2 == 0 && lon2 == 0) {
        return 0.0;
    }

    double lat1Rad = lat1 * M_PI / 180.0;
    double lon1Rad = lon1 * M_PI / 180.0;
    double lat2Rad = lat2 * M_PI / 180.0;
    double lon2Rad = lon2 * M_PI / 180.0;

    double dLat = lat2Rad - lat1Rad;
    double dLon = lon2Rad - lon1Rad;

    double a = std::sin(dLat / 2.0) * std::sin(dLat / 2.0) +
               std::cos(lat1Rad) * std::cos(lat2Rad) *
               std::sin(dLon / 2.0) * std::sin(dLon / 2.0);
    double c = 2.0 * std::atan2(std::sqrt(a), std::sqrt(1.0 - a));
    double distance = EARTH_RADIUS * c;

    return distance;
}

double Graph::triangular_approximation(){
    std::vector<int> parent(vertexMap.size(), -1);
    prim_mst(parent);

    std::vector<bool> visited(vertexMap.size(), false);
    std::vector<int> path;
    std::stack<int> cityStack;
    dfs(0, parent, visited, cityStack, path);

    return total_distance(path);
}

std::vector<int> Graph::nearest_neighbor(int start) {
    std::vector<int> path;
    std::vector<bool> visited(vertexMap.size(), false);

    int current = start;
    path.push_back(current);
    visited[current] = true;

    while(path.size() < vertexMap.size()){
        int next = -1;
        double minimumDistance = std::numeric_limits<double>::max();

        for(const auto &edge : vertexMap[current].adjacent)
            if(!visited[edge.destVertex] && edge.distance < minimumDistance){
                next = edge.destVertex;
                minimumDistance = edge.distance;
            }

        if(next == -1) break;

        path.push_back(next);
        visited[next] = true;
        current = next;
    }

    return path;
}
