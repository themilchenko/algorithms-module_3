#ifndef A_PROBLEM_SET_GRAPH_HPP
#define A_PROBLEM_SET_GRAPH_HPP

#include <unordered_set>
#include <vector>

#include "graph.hpp"

class SetGraph : public IGraph {
 public:
  explicit SetGraph(size_t count);
  explicit SetGraph(const IGraph &other);

  ~SetGraph() override = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::unordered_set<int>> vertex_;
};

#endif  // A_PROBLEM_SET_GRAPH_HPP
