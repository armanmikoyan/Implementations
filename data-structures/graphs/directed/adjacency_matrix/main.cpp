#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{3};
    g.add_vertex();
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(3, 0);
    g.print_matrix();
    g.dfs(0);
}