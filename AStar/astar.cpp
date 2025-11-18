#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Element in map example: "A" : { HeuristicValue, { {"B", costToB}, {"C", costToC} } }

void Astar(map<string, vector<pair<int, vector<pair<string, int>>>>> graph, string startNode, string goalNode) {
    int currentCost = 0;
    vector<string> path; // To keep track of the path taken
    vector<string> allNodes; // To keep track of all nodes visited
    string next;
    int h = graph[startNode][0].first; // Heuristic value of start node

    // Just add key of map to path
    path.push_back(startNode);
    string nodoActual = startNode;

    while(nodoActual != goalNode){
        auto best = selectBestConnection(graph, nodoActual, currentCost);
        string next = best.first;
        int cost = best.second;

        if (next.empty()) {
            break; 
        }
        currentCost += cost;
        nodoActual = next;
        path.push_back(nodoActual);
        allNodes.push_back(nodoActual);
    }
    
}

// returns {bestNeighborName, edgeCost} or {"",0} if none
pair<string,int> selectBestConnection(const map<string, vector<pair<int, vector<pair<string,int>>>>>& graph, const string& nodo, int currentCost){
    
    int min = INT32_MAX;
    string next = "";
    int cost = 0;

    const auto &adj = graph.at(nodo)[1].second; // Get adjacency list
    for (const auto &edge : adj) { // Iterate with nodes connected with current node {"B", costToB}
        string connectedNode = edge.first;
        int costToConnection = edge.second;

        int c = currentCost + costToConnection;
        int h = graph.at(connectedNode)[0].first; // Heuristic value of connected node
        int f = c + h; // f(n) = c(n) + h(n)
        if (f < min) {
            min = f;
            next = edge.first;
            cost = edge.second;
        }
    }
    return {next, cost};
}

int main() {
    // Example usage
    map<string, vector<pair<int, vector<pair<string, int>>>>> graph = {
        {"A", { {10, { {"B", 1}, {"C", 2} }} }},
        {"B", { {8, { {"A", 1}, {"D", 4}, {"E", 2} }} }},
        {"C", { {6, { {"A", 2}, {"D", 2} }} }},
        {"D", { {7, { {"B", 4}, {"C", 6}, {"F", 1} }} }},
        {"E", { {4, { {"B", 2}, {"F", 3} }} }},
        {"F", { {2, { {"", 0}} }} },
        {"G", { {1, { {"A", 2}, {"H", 1} }} }},
        {"H", { {0, { {"G", 1} }} }}
    };

    Astar(graph, "A", "F");

    return 0;
}
