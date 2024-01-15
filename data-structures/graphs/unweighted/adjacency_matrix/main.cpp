#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();

    g.add_edge(0, 1);

    g.print_matrix();
    g.bfs_extra_case();
    std::cout << std::endl;
}