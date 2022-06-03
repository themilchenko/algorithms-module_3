#include "list_graph.hpp"

#include <cassert>

ListGraph::ListGraph(size_t count) { vertex_.resize(count); }

ListGraph::ListGraph(const IGraph &other) {
  vertex_.resize(other.VerticesCount());

  for (size_t i = 0; i < other.VerticesCount(); ++i) {
    vertex_[i] = other.GetNextVertices(i);
  }
}

void ListGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < vertex_.size());
  assert(to >= 0 && to < vertex_.size());

  vertex_[from].push_back(to);
}

int ListGraph::VerticesCount() const { return vertex_.size(); }

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());
  return vertex_[vertex];
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());
  std::vector<int> prev_verticies;

  for (size_t i = 0; i < vertex_.size(); ++i) {
    for (size_t j = 0; j < vertex_[i].size(); ++j) {
      if (vertex_[i][j] == vertex) {
        prev_verticies.push_back(i);
      }
    }
  }

  return prev_verticies;
}
