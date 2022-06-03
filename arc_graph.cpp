#include "arc_graph.hpp"

ArcGraph::ArcGraph(size_t count) {
  vertex_.resize(count);
}

ArcGraph::ArcGraph(const IGraph& other) {
  vertex_.resize(other.VerticesCount());

  for (size_t i = 0; i < vertex_.size(); ++i) {
    for (int el : other.GetNextVertices(i)) {
      vertex_.emplace_back(i, el);
    }
  }
}

void ArcGraph::AddEdge(int from, int to) {
  assert(from >= 0 && from < vertex_.size());
  assert(to >= 0 && to < vertex_.size());

  vertex_.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
  return vertex_.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());

  std::vector<int> result;
  for (const auto &el : vertex_) {
    if (el.first == vertex) {
      result.push_back(el.second);
    }
  }

  return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
  assert(vertex >= 0 && vertex < vertex_.size());

  std::vector<int> result;

  for (const auto &el : vertex_) {
    if (el.second == vertex) {
      result.push_back(el.first);
    }
  }

  return result;
}
