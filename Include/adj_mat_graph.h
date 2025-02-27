#ifndef ALGLIB_INCLUDE_ADJMATGRAPH_H_
#define ALGLIB_INCLUDE_ADJMATGRAPH_H_

#include <array>
#include <functional>

#include "sll_queue.h"
#include "vector.h"

namespace alglib {

template <typename T>
class AdjMatGraph {
 public:
  AdjMatGraph(size_t vertices, bool is_directed);
  AdjMatGraph(size_t vertices, bool is_directed,
              const Vector<int>& edges);

  void BFS(size_t start, const std::function<void(int)>& visit_callback);
  void DFS(size_t start, const std::function<void(int)>& visit_callback);

 private:
  Vector<Vector<T>> adjacency_matrix;
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
                            const Vector<int>& edges)
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
  Vector<int> visited;
  SLLStack<int> stack;
  stack.Push(start);
  visited.At(i) = true;
  while (!stack.IsEmpty()) {
    int cur_node{stack.Pop()};
    visit_callback(curr_node);
    for (size_t i{adjacency_matrix.Size() - 1}; i >= 0; i--) {
      if (adjacency_matrix.At(cur_node).At(i) == 1 && !visited.At(i)) {
        stack.Push(i);
        visited.At(i) = true;
      }
    }
  }
}
    
}  // namespace alglib

#endif  // ALGLIB_INCLUDE_ADJMATGRAPH_H_
