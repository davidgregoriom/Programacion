#ifndef GRAPH_H
#define GRAPH_H
#include <array>
#include<iostream>
#include <vector>
#include "queue.h"
#include <memory>
#include <iostream>
#include <functional>
#include <set>
//en el txt del metro tengo las paradas linea por linea y los trasbordos en cada parada luego del |.

using namespace std;

template <typename TipoNode, typename TipoEdge, int N>
class Graph {
public:
    Graph(){for(int n{0}; n < N; n++){
            for(int j{0}; j < N; j++){
                edges[n][j] = std::make_shared<TipoEdge>();
            }
        }}

    void add_edge(int origin, int target, TipoEdge distance) {
        edges[origin][target] = distance;
    }
    void remove_node(int node) {
        nodes[node] = nullptr;
        // Remove all the edges that use this node!
        for (int i=0; i<N; i++) {
            this->remove_edge(node, i); // It is undirected, no need to remove (i, node) as well.
        }
    }
    void remove_edge(int origin, int target) {
        edges[origin][target] = nullptr;
    }
    std::array<std::array<std::shared_ptr<TipoEdge>, N>, N> getEdges() const;
    bool are_connected(TipoNode city1, TipoNode city2) const;
    std::array<std::shared_ptr<TipoNode>,N> getStations() const;
    void add_node(int node, const TipoNode& dato_node);

    int num_components() const;//hay que recorrer el grafo e ir sacando los subgrafos hasta llegar a contar 23 nodos
    int dfs(std::function<void (std::string node)> action) {
        std::array<bool, N> visited;
        int k{0};
        for (int i=0; i<N; i++) {
            visited[i] = false;
        }
        for (int i=0; i<N; i++) {
            _dfs(i, visited, action, k);
        }
        return k;
    }
    void bfs() {
        std::array<bool, N> visited;
        for (int i=0; i<N; i++) { visited[i] = false; }
        queue queue;
        for (int  i=0; i<N; i++) {
            queue.push(nodes[i]);
            while (!queue.empty()) {
                TipoDato node = queue.front();
                queue.pop();
                if (!visited[node]) {
                    visited[node] = true;
                    //action(node);
                    for (auto i: adj_lists[node]) {
                        queue.push(i);  // may exclude those already visited
                    }
                }
            }
        }
    }
    int bfs_paths(string entrada, string final){
        queue a;
        a.push(entrada);
        vector<string > camino;
        camino.push_back(entrada);
        while (a.size() != 0){
            a.pop();
            for (auto elem:nodes){
                if (nodes[elem] == final){
                    return camino + nodes[elem];
                }else{
                    a.push((nodes[elem], camino + nodes[elem]));
                    camino.push_back(nodes[elem]);
                }
            }
        }
    }

private:
    std::array<std::shared_ptr<std::string>, N> nodes;
    std::array<std::array<std::shared_ptr<TipoEdge>, N>, N> edges;
    std::array<std::shared_ptr<TipoNode>,N> stations;
    std::array<std::set<int>, N> adj_lists;
    void _dfs(int node, std::array<bool, N>& visited, std::function<void (std::string node)> action, int & c) {
        if (!visited[node]) {
            action(*stations[node]);
            visited[node] = true;
            for (int i=0; i<N; i++) {
                if (*edges[node][i] != 0){
                    _dfs(i, visited, action, c);
                }
            }
        }
    }
};

template <typename TipoNode, typename TipoEdge, int N>
std::ostream &operator<<(std::ostream &os, const Graph<TipoNode, TipoEdge,N> &g)
{
    for(int j{0}; j < N; j++){
        for(int k{0}; k < N; k++){
           os << *(g.getEdges()[j][k]) << ' ';
        }
        os << '\n';
    }
    return os;
}


template <typename TipoNode, typename TipoEdge, int N>
std::array<std::array<std::shared_ptr<TipoEdge>, N>, N> Graph<TipoNode, TipoEdge, N>::getEdges() const
{
return edges;
}

template <typename TipoNode, typename TipoEdge, int N>
bool Graph<TipoNode, TipoEdge, N>::are_connected(TipoNode city1, TipoNode city2) const
{
    int pos1{0};
    int pos2{0};
    for(int j{0}; j < stations.size(); j++){
        if(*stations[j] == city1){pos1 = j;}
        else if(*stations[j] == city2){pos2 = j;}
    }
        if(*edges[pos1][pos2] != 0){
            std::cout <<"distance between them: " << *edges[pos1][pos2] << '\n';
            return true;}else return false;
}
template <typename TipoNode, typename TipoEdge, int N>
std::array<std::shared_ptr<TipoNode>,N> Graph<TipoNode, TipoEdge,N>::getStations() const
{
    return stations;
}

template<typename TipoNode, typename TipoEdge, int N>
void Graph<TipoNode, TipoEdge, N>::add_node(int node, const TipoNode &dato_node)
{
    auto dato = std::make_shared<TipoNode>(dato_node);
    stations[node] = dato;
}

#endif // GRAPH_H
