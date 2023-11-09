

#include <memory>
#include <array>
#include <set>
#include <string>
#include <functional>
#include "tipodato.h"
#include "queue.h"
#include <vector>
#include <iomanip>
using namespace std;

template <int N>
class Grafo_de_las_estaciones
{

public:
    Grafo_de_las_estaciones() {
        for (int i=0; i<N; i++) {
            nodes[i] = nullptr;
            for (int j=0; j<N; j++) {
                edges[i][j] = nullptr;
            }
        }
    }

    void add_node(int node, const std::string& city) {
        nodes[node] = std::make_shared<std::string>(city);
    }

    bool add_edge(int origin, int target, int distance) {
        if (nodes[origin] == nullptr || nodes[target] == nullptr) {
            return false;
        }
        edges[origin][target] = std::make_shared<int>(distance);
        edges[target][origin] = std::make_shared<int>(distance);
        return true;
    }
    void remove_node(int node) {
        nodes[node] = nullptr;
        // Remove all the edges that use this node!
        for (int i=0; i<N; i++) {
            this->remove_edge(node, i); // It is undirected, no need to remove (i, node) as well.
        }
    }

   bool remove_edge(int origin, int target) {
        edges[origin][target] = nullptr;
        edges[target][origin] = nullptr;
    }
//   void bfs(std::function<void (string node)> action) {
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

   void bfs_paths(string entrada, string final){
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
   template <int SIZE>
   friend std::ostream& operator<<(std::ostream& os, const Grafo_de_las_estaciones<SIZE>& graph);
protected:
    std::array<std::shared_ptr<std::string>, N> nodes;
    std::array<std::array<std::shared_ptr<int>, N>, N> edges;
    std::array<std::set<int>, N> adj_lists;
};


template <int N>
std::ostream& operator<<(std::ostream& os, const Grafo_de_las_estaciones<N>& graph) {
    os << "      ";
    for (int i = 0; i < N; i++) {
        os << " " << right << std::setw(4) << i;
    }
    os << std::endl;

    for (int i = 0; i < N; i++) {
        os << std::right << std::setw(4) << i << " |";
        for (int j = 0; j < N; j++) {
            if (graph.edges[i][j] != nullptr) {
                os << " " << std::right << std::setw(4) << *graph.edges[i][j];
            }
            else {
                os << "     ";
            }
        }
        os << std::endl;
    }
    return os;
}


