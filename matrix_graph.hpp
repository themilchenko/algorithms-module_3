#ifndef A_PROBLEM_MATRIX_GRAPH_HPP_
#define A_PROBLEM_MATRIX_GRAPH_HPP_

#include <vector>

#include "graph.hpp"

class MatrixGraph : public IGraph {
 public:
  explicit MatrixGraph(size_t count);
  explicit MatrixGraph(const IGraph &other);

  ~MatrixGraph() override = default;

  void AddEdge(int from, int to) override;

  int VerticesCount() const override;

  std::vector<int> GetNextVertices(int vertex) const override;
  std::vector<int> GetPrevVertices(int vertex) const override;

 private:
  std::vector<std::vector<bool> > vertex_;
};

#endif  // A_PROBLEM_MATRIX_GRAPH_HPP_