#include "adjacency_list.hpp"

#define n  std::cout << std::endl;

int main()
{
graph_list<int> g{};
g.add_vertex();
g.add_vertex();
g.add_vertex();
g.add_vertex();
g.add_vertex();

g.add_edge(0, 1);
g.add_edge(1, 2);
g.add_edge(2, 3);
g.add_edge(3, 4);
g.add_edge(1, 4);


g.print_list();

std::cout << g.has_cycle_directed();
}