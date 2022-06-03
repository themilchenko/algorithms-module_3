#ifndef A_PROBLEM_LIST_GRAPH_HPP_
#define A_PROBLEM_LIST_GRAPH_HPP_

#include <vector>

#include "graph.hpp"

class ListGraph : public IGraph {
 public:
  explicit ListGraph(size_t count);
  explicit ListGraph(const IGraph &other);

  ~ListGraph() override = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::vector<int> > vertex_;
};

#endif  // A_PROBLEM_LIST_GRAPH_HPP_