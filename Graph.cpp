/*
 Written By: Harshavardan Yuvaraj, Ryan cuff, Casey Sloan, and Anosh Askari
 DS Section: 3 (Tuesday's and Thursday's @ 8AM)
       Date: 20th November, 2023

    Purpose: The Graph class is an implementation of a weighted, undirected graph. It utilizes an unordered map to store vertices 
             and their associated edges in the form of an Adjacency List. This class supports operations for adding and removing vertices and edges, 
             and it includes a function for finding the shortest path between two vertices using Dijkstra's algorithm. 
*/

#include "Graph.hpp"

// Adds a vertex to the graph if it doesn't exist
void Graph::addVertex(std::string label) {
    if(graph.count(label) == 0)
       graph[label];
}

// Removes a vertex from the graph, including all edges connected to it
void Graph::removeVertex(std::string label) {
    // Check to see if the vertex exists in the graph
    if(graph.count(label) == 0)
       return;

    // Remove the vertex from the graph
    graph.erase(label);

    // Remove edges pointing to the deleted vertex in other vertices' adjacency lists
    for(auto &vertexAdjList : graph) {
        for(auto edge = vertexAdjList.second.begin(); edge != vertexAdjList.second.end(); edge++) {
             if(edge->first == label) {
                vertexAdjList.second.erase(edge);
                break;
             }
        }
    }
}

// Adds an edge between two vertices with a specified weight
void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    if(graph.count(label1) == 0 || graph.count(label2) == 0 || label1 == label2)
      return;

    bool edge1 = false, edge2 = false;

   // Check if the edge already exists in the adjacency lists
   for(auto edge = graph[label1].begin(); edge != graph[label1].end(); edge++) {
        if(edge->first == label2) {
           edge1 = true;
           break;
        }
    }

    for(auto edge = graph[label2].begin(); edge != graph[label2].end(); edge++) {
        if(edge->first == label1) {
           edge2 = true;
           break;
        }
    }

    // Add the edge if it doesn't already exist
    if(!edge1)
       graph[label1].push_back(std::make_pair(label2, weight));

    if(!edge2)
       graph[label2].push_back(std::make_pair(label1, weight));
}

// Removes the edge between two vertices
void Graph::removeEdge(std::string label1, std::string label2) {
    if(graph.count(label1) == 0 || graph.count(label2) == 0)
      return;

    // Remove the edge from the adjacency lists
    for(auto edge = graph[label1].begin(); edge != graph[label1].end(); edge++) {
        if(edge->first == label2) {
           graph[label1].erase(edge);
           break;
        }
    }

    for(auto edge = graph[label2].begin(); edge != graph[label2].end(); edge++) {
        if(edge->first == label1) {
          graph[label2].erase(edge);
          break;
        }
    }

}

// Finds the shortest path between two vertices using Dijkstra's algorithm
unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    
    // Priority queue for efficient node selection
    std::priority_queue <std::pair<unsigned long, std::string>, 
                        std::vector<std::pair<unsigned long, std::string>>, 
                        std::greater<std::pair<unsigned long, std::string>>> pq; 
    
    // Dijkstra's table for tracking shortest distances
    DijkstraTable dijkstra_table;

    // Initialize distances in the Dijkstra table
    for(auto &vertex : graph) { dijkstra_table[vertex.first] = std::make_pair(std::numeric_limits<unsigned long>::max(), vertex.first); }
    
    // Set the distance of the start vertex to 0
    dijkstra_table[startLabel] = std::make_pair(0,startLabel);
    pq.push(dijkstra_table[startLabel]);

    // Dijkstra's algorithm
    while(!pq.empty()) {
        unsigned long dist = pq.top().first; 
        std::string vertex = pq.top().second;
        pq.pop();
     
        // Explore neighbors
        for(auto adjNode = graph[vertex].begin(); adjNode != graph[vertex].end(); adjNode++) {
            unsigned long edgeCost = adjNode->second;
            std::string adjVertex = adjNode->first;

            // Update distances in the Dijkstra table
            if(dist + edgeCost < dijkstra_table[adjVertex].first) {
                dijkstra_table[adjVertex] = std::make_pair((dist + edgeCost), vertex);
                pq.push({(dist + edgeCost), adjVertex});
            }
        }
    }
    
    // Trace and construct the shortest path
    traceShortestPath(startLabel, endLabel, path, dijkstra_table);
   
   // Return the length of the shortest path
   return dijkstra_table[endLabel].first;
}

// Helper function to construct the actual shortest path given the Dijkstra table
void Graph::traceShortestPath(const std::string& startLabel, const std::string& endLabel, std::vector<std::string> &path, DijkstraTable& dijkstra_table) {
    
    std::vector<std::string> shortestPath;

    // Backtrack from the end vertex to the start vertex
    shortestPath.push_back(endLabel);
    std::string back_vertex = endLabel;

    while(true) {
      shortestPath.push_back(dijkstra_table[back_vertex].second);
      
      // Break if the start vertex is reached
      if(dijkstra_table[back_vertex].second == startLabel)
        break;
      else 
        back_vertex = dijkstra_table[back_vertex].second;
    } 
   
    // Reverse the path to get it from start to end
    for(int index = shortestPath.size()-1; index >= 0; index--)
       path.push_back(shortestPath[index]);
    
}

// Constructor initializes the graph
Graph::Graph() : graph() { }

// Destructor is empty as there is no dynamic memory allocation
Graph::~Graph() { }