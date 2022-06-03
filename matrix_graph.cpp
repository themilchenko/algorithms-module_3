#include "matrix_graph.hpp"

#include <cassert>

MatrixGraph::MatrixGraph(size_t count) {
  vertex_.resize(count);
  for (auto &el : vertex_) {
    el.resize(count);
  }
}

MatrixGraph::MatrixGraph(const IGraph &other) {
  vertex_.resize(other.VerticesCount());
  for (size_t i = 0; i < other.VerticesCount(); ++i) {
    vertex_[i].resize(vertex_.size());
    for (auto &el : other.GetNextVertices(i)) {
      vertex_[i][el] = true;
    }
  }
}

void MatrixGraph::AddEdge(int from, int to) {
  assert(from > 0 && from <= vertex_.size());
  assert(to > 0 && from <= vertex_.size());

  vertex_[from][to] = true;
}

int MatrixGraph::VerticesCount() const { return vertex_.size(); }

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());

  std::vector<int> result;
  for (size_t i = 0; i < vertex_.size(); ++i) {
    if (vertex_[vertex][i]) {
      result.push_back(i);
    }
  }
  return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());

  std::vector<int> result;
  for (size_t i = 0; i < vertex_.size(); ++i) {
    if (vertex_[i][vertex]) {
      result.push_back(i);
    }
  }
  return result;
}
