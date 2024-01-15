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
    g.add_vertex();
    g.add_edge(1, 0);
    g.print_list();

    g.dfs_extra_case();
}