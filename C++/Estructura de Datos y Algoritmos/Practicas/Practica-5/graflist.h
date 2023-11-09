#ifndef GRAFLIST_H
#define GRAFLIST_H
#pragma once

#include <array>
#include <set>
#include <ostream>
#include "grafo.h"

template <int N>
class GraphLists {
  public:
    GraphLists() {}

    void add_edge(int origin, int target) {
      adj_lists[origin].insert(target);
    }

    void remove_edge(int origin, int target) {
      adj_lists[origin].remove(target);
    }

    void dfs(std::function<void (int node)> action) {
      std::array<bool, N> visited;
      for (int i=0; i<N; i++) { visited[i] = false; }
      for (int i=0; i<N; i++) {
        _dfs(i, visited, action);
      }
    }

    void bfs(std::function<void (int node)> action) {
      std::array<bool, N> visited;
      for (int i=0; i<N; i++) { visited[i] = false; }

      std::queue<int> queue;
      for (int i=0; i<N; i++) {
        //if (!visited[i]) {
          queue.push(i);
          while (!queue.empty()) {
            int node = queue.front(); queue.pop();
            if (!visited[node]) {
              action(node);
              visited[node] = true;
              for (auto i: adj_lists[node]) {
                queue.push(i);  // may exclude those already visited
              }
            }
          }
        //}
      }
    }

    template <int Size>
    friend std::ostream& operator<<(std::ostream& os, const GraphLists<Size>& graph);

  private:
    void _dfs(int node, std::array<bool, N>& visited, std::function<void (int node)> action) {
      if (!visited[node]) {
        action(node);
        visited[node] = true;
        for (auto i: adj_lists[node]) {
          _dfs(i, visited, action);
        }
      }
    }

  private:
    std::array<std::set<int>, N> adj_lists;
};

template <int N>
std::ostream& operator<<(std::ostream& os, const GraphLists<N>& graph) {
  for (int i = 0; i<N; i++) {
    os << i << ": ";
    for (auto v: graph.adj_lists[i]) {
      os << " " << v;
    }
    os << std::endl;
  }
  return os;
}
#endif // GRAFLIST_H
