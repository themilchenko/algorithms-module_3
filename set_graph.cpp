#include "set_graph.hpp"

SetGraph::SetGraph(size_t count) {
  vertex_.resize(count);
}

SetGraph::SetGraph(const IGraph& other) {
  vertex_.resize(other.VerticesCount());
  for (size_t i = 0; i < other.VerticesCount(); ++i) {
    for (auto &el : other.GetNextVertices(i)) {
      vertex_[i].insert(el);
    }
  }
}

void SetGraph::AddEdge(int from, int to) {
  assert(from > 0 && from <= vertex_.size());
  assert(to > 0 && from <= vertex_.size());

  vertex_[from].insert(to);
}

int SetGraph::VerticesCount() const { return vertex_.size(); }

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
  std::vector<int> result;
  for (int i : vertex_[vertex]) {
    result.push_back(i);
  }
  return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
  return GetNextVertices(vertex);
}
