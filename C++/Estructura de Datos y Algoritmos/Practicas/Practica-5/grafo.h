#ifndef GRAFO_H
#define GRAFO_H
#pragma once
#include <array>
#include <ostream>
#include <functional>
#include <queue>
#include <array>
using namespace std;
template <int N>
class Graph {
public:
    Graph() {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                edges[i][j] = false;
            }
        }
    }
    void add_edge(int origin, int target) {
        edges[origin][target] = true;
    }

    void remove_edge(int origin, int target) {
        edges[origin][target] = false;
    }

    void dfs(std::function<void (int node)> action) {
        array<bool, N> visited;
        for (int i=0; i<N; i++) { visited[i] = false; }
        for (int i=0; i<N; i++) {
            _dfs(i, visited, action);
        }
    }
    void bfs(std::function<void (int node)> action) {
        array<bool, N> visited;
        for (int i=0; i<N; i++) { visited[i] = false; }
        queue<int> queue;
        for (int i=0; i<N; i++) {
            queue.push(i);
            while (!queue.empty()) {
                int node = queue.front(); queue.pop();
                if (!visited[node]) {
                    action(node);
                    visited[node] = true;
                    for (int i=0; i<N; i++) {
                        if (edges[node][i]) {
                            queue.push(i);
                        }
                    }
                }
            }
            //}
        }
    }

    bool are_connected(string city1, string city2) const{
        if(city1==city2){
            return true;
        }else{
            return false;
        }
    }
    int num_components() const{

    }
    Graph<N> telephone() const{

    }
    int sum_kilometers() const{

    }

    template <int Size>
    friend ostream& operator<<(ostream& os, const Graph<Size>& graph);

private:
    void _dfs(int node, array<bool, N>& visited, function<void (int node)> action) {
        if (!visited[node]) {
            action(node);
            visited[node] = true;
            for (int i=0; i<N; i++) {
                if (edges[node][i]) {
                    _dfs(i, visited, action);
                }
            }
        }
    }

private:
    array<array<bool, N>, N> edges;
};

template <int N>
ostream& operator<<(ostream& os, const Graph<N>& graph) {

    os << "  |";
    for (int i=0; i<N; i++) {
        os << " " << i;
    }
    os << endl;
    for (int i=0; i<N; i++) {
        os << i << " | ";
        for (int j=0; j<N; j++) {
            os << graph.edges[i][j] << " ";
        }
        os << endl;
    }
    return os;
}



#endif // GRAFO_H
