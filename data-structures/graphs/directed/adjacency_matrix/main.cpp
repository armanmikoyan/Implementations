#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{5};
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(1, 0);
    g.add_edge(3, 1);
    g.add_edge(4, 0);

    g.print_matrix();
    g.dfs(2);
}