#ifndef A_PROBLEM_ARC_GRAPH_HPP
#define A_PROBLEM_ARC_GRAPH_HPP

#include <vector>

#include "graph.hpp"

class ArcGraph : public IGraph {
 public:
  ArcGraph(size_t count);
  ArcGraph(const IGraph &other);

  ~ArcGraph() override = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::pair<int, int>> vertex_;
};

#endif  // A_PROBLEM_ARC_GRAPH_HPP
