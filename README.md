# Djikstra
Implementation of weighted, undirected graph, including unit testing with Catch2 framework

# Graph Manipulation and Shortest Path Algorithm

## Overview

Project Proposal: Dr. Valentina Korzhova (Instructor at the University of South Florida)

This C++ project presents a powerful `Graph` class designed for manipulating weighted, undirected graphs. The class includes essential functionalities for adding and removing vertices and edges, with the added capability of employing Dijkstra's algorithm to find the shortest path between two vertices. The project embraces a modular design, ensuring a clean separation between the public interface and the private implementation.

## Table of Contents

1. [Introduction](#introduction)
2. [Graph Class Design](#graph-class-design)
3. [Usage Examples](#usage-examples)
4. [Compile and Run (Linux)](#how-to-compile-and-run)
5. [Authors](#authors)



## Introduction

Graphs serve as fundamental data structures with diverse applications across various computational domains. This project focuses on a C++ implementation of a versatile `Graph` class, specifically tailored for efficient manipulation of weighted, undirected graphs. The incorporation of Dijkstra's algorithm further enhances its utility, making it a valuable tool for scenarios such as network analysis, transportation optimization, and route planning.

## Graph Class Design

The `Graph` class is meticulously designed to provide a clear and accessible interface for managing vertices and edges. Utilizing an unordered map for graph representation ensures efficient access and modification operations. The implementation follows a modular design, fostering code maintainability and extensibility. Dijkstra's algorithm is seamlessly integrated, adopting a Greedy approach for optimal pathfinding within the graph.

The following public methods are offered by class `Graph`: 
  1. `addVertex(std::string label)`
         - Adds a vertex with the given label to the graph.

  2. `removeVertex(std::string label)`
         - Removes the vertex with the given label from the graph.

  3. `addEdge(std::string label1, std::string label2, unsigned long weight)`
         - Adds an edge between vertices with labels `label1` and `label2` with the specified weight.
  
  4. `removeEdge(std::string label1, std::string label2)`
         - Removes the edge between vertices with labels `label1` and `label2`.

  5. `shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)` 
         - Finds the shortest path from the vertex with label `startLabel` to the vertex with label `endLabel`.

## Usage Examples

<pre>
```cpp

std::vector<std::string> vertices1 = { "1", "2", "3", "4", "5", "6" }; 
std::vector<std::tuple<std::string, std::string, unsigned long>> 
edges1 = { {"1", "2", 7}, {"1", "3", 9}, {"1", "6", 14}, {"2", "3", 10}, {"2", "4", 15}, {"3", "4", 11}, {"3", "6", 2}, {"4", "5", 6}, {"5", "6", 9} };

for (const auto label : vertices1) g.addVertex(label);
for (const auto &tuple : edges1) g.addEdge(std::get<0>(tuple), std::get<1>(tuple), std::get<2>(tuple));

g.shortestPath("1", "5", path); // == 20 
g.shortestPath("1", "5", path); // = { "1", "3", "6", "5" }      

```
</pre>

## Compile and Run (Linux)

If Catch2 and source files are in this directory and at directory level, then to compile: g++ -std=c++17 -Wall *.cpp

To see what tests were successful and failed as defined in PP4Test.cpp, run your executable with the -s flag: ./a.out -s

A successful test should output: All tests passed (18 assertions in 1 test case)

## Authors

- Harshavardan Yuvaraj
- Casey Sloan
- Ryan Cuff
- Anosh Askari


