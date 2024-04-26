#ifndef GRAPH_H
#define GRAPH_H 

/*
 Written By: Harshavardan Yuvaraj, Ryan cuff, Casey Sloan, and Anosh Askari
 DS Section: 3 (Tuesday's and Thursday's @ 8AM)
       Date: 20th November, 2023

    Purpose: The Graph class is an implementation of a weighted, undirected graph. It utilizes an unordered map to store vertices 
             and their associated edges in the form of an Adjacency List. This class supports operations for adding and removing vertices and edges, 
             and it includes a function for finding the shortest path between two vertices using Dijkstra's algorithm. 
*/

#include <unordered_map>
#include <list>
#include <queue>
#include <limits>
#include "GraphBase.hpp"

class Graph: public GraphBase {

    public: 
       // Define types for representing edges and Dijkstra's table (will be utilized to hold the shortest path information from a given source to all other vertices)
       typedef std::list<std::pair<std::string, unsigned long>> Edge;
       typedef std::unordered_map<std::string, std::pair<unsigned long, std::string>> DijkstraTable;
      
      // Constructor and Destructor
       Graph();
       ~Graph();

       // Graph operations
       void addVertex(std::string label);
       void removeVertex(std::string label);
       void addEdge(std::string label1, std::string label2, unsigned long weight);
       void removeEdge(std::string label1, std::string label2);

       // Shortest path computation
       unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);

    private:
      // Helper function to trace and construct the shortest path from Dijkstra's Table
      void traceShortestPath(const std::string& startLabel, const std::string& endLabel, std::vector<std::string> &path, DijkstraTable& dijkstra_table);

    private:
     // Main data structure representing the graph as an Adjacency List 
      std::unordered_map<std::string, Edge> graph;
};

#endif // GRAPH_H