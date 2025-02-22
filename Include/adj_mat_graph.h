#ifndef ALGLIB_INCLUDE_ADJMATGRAPH_H_
#define ALGLIB_INCLUDE_ADJMATGRAPH_H_

#include <array>
#include <functional>
#include <vector>

#include "sll_queue.h"

namespace alglib {

template <typename T>
class AdjMatGraph {
 public:
  AdjMatGraph(size_t vertices, bool is_directed);
  AdjMatGraph(size_t vertices, bool is_directed,
              const std::vector<std::array<unsigned, 3>>& edges);

  void BFS(size_t start, const std::function<void(int)>& visit_callback);
  void DFS(size_t start, const std::function<void(int)>& visit_callback);

 private:
  std::vector<std::vector<int>> adjacency_matrix;
  bool directed;
};

template <typename T>
AdjMatGraph<T>::AdjMatGraph(size_t vertices, bool is_directed)
    : directed(is_directed) {
  adjacency_matrix.resize(vertices);
  for (auto in_vec : adjacency_matrix) {
    in_vec.resize(vertices);
  }
}

template <typename T>
AdjMatGraph<T>::AdjMatGraph(size_t vertices, bool is_directed,
                            const std::vector<std::array<unsigned, 3>>& edges)
    : directed(is_directed) {
  adjacency_matrix.resize(vertices);
  for (std::vector<int> in_vec : adjacency_matrix) {
    in_vec.resize(vertices);
  }
  for (auto pair : edges) {
    if (directed) {
      adjacency_matrix.at(pair.at(0)).at(pair.at(1)) = pair.at(2);
    } else {
      adjacency_matrix.at(pair.at(0)).at(pair.at(1)) = pair.at(2);
      adjacency_matrix.at(pair.at(1)).at(pair.at(0)) = pair.at(2);
    }
  }
}

template <typename T>
void AdjMatGraph<T>::BFS(size_t start,
                         const std::function<void(int)>& visit_callback) {
  SLLQueue<int> q;
  std::vector<bool> visited(adjacency_matrix.size(), false);
  visited.at(start) = true;
  q.Enqueue(start);
  while (!q.IsEmpty()) {
    int current{q.Dequeue()};
    visit_callback(current);
    for (auto i : adjacency_matrix.at(current)) {
      if (!visited.at(i)) {
        visited.at(i) = true;
        q.Enqueue(i);
      }
    }
  }
}

template <typename T>
void AdjMatGraph<T>::DFS(size_t start,
                         const std::function<void(int)>& visit_callback) {

}

}  // namespace alglib

#endif  // ALGLIB_INCLUDE_ADJMATGRAPH_H_
