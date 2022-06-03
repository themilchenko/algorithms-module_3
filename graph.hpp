#ifndef A_PROBLEM_GRAPH_HPP_
#define A_PROBLEM_GRAPH_HPP_

#include <vector>

struct IGraph {
  virtual ~IGraph() {}

  virtual void AddEdge(int from, int to) = 0;

  virtual int VerticesCount() const = 0;

  virtual std::vector<int> GetNextVertices(int vertex) const = 0;
  virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif  // A_PROBLEM_GRAPH_HPP_