#include <iostream>
#include <queue>

#include "arc_graph.hpp"
#include "list_graph.hpp"
#include "matrix_graph.hpp"
#include "set_graph.hpp"

void bfs(const IGraph &graph, int vertex, void (*visit)(int)) {
  std::vector<bool> visited_vec(graph.VerticesCount());

  std::queue<int> bfs_queue;
  bfs_queue.push(vertex);

  visited_vec[vertex] = true;

  while (!bfs_queue.empty()) {
    int current = bfs_queue.front();
    bfs_queue.pop();
    visit(current);
    std::vector<int> list = graph.GetNextVertices(current);
    for (int vrtx : list) {
      if (!visited_vec[vrtx]) {
        bfs_queue.push(vrtx);
        visited_vec[vrtx] = true;
      }
    }
  }
}

int main() {
  IGraph *graph = new ListGraph(6);
  graph->AddEdge(1, 3);
  graph->AddEdge(2, 1);
  graph->AddEdge(2, 3);
  graph->AddEdge(2, 4);
  graph->AddEdge(3, 4);
  graph->AddEdge(4, 5);
  graph->AddEdge(5, 3);
  graph->AddEdge(5, 4);

  std::cout << "-=List Graph=-\n";
  bfs(*graph, 1, [](int v) { std::cout << v << ' '; });

  std::cout << "\n\n";

  auto *m_graph = new MatrixGraph(*graph);
  delete graph;
  std::cout << "-=Matrix Graph=-\n";
  bfs(*m_graph, 1, [](int v) { std::cout << v << ' '; });

  std::cout << "\n\n";

  auto *s_graph = new SetGraph(*m_graph);
  delete m_graph;
  std::cout << "-=Set Graph=-\n";
  bfs(*s_graph, 1, [](int v) { std::cout << v << ' '; });

  std::cout << "\n\n";

  auto *a_graph = new SetGraph(*s_graph);
  delete s_graph;
  std::cout << "-=Arc Graph=-\n";
  bfs(*a_graph, 1, [](int v) { std::cout << v << ' '; });

  return EXIT_SUCCESS;
}