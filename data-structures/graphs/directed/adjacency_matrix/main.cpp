#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{5};
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 4);
    g.add_edge(3, 1);
    g.add_edge(4, 3);

    g.print_matrix();
    std::cout << g.vertex_count_in_level(0, 1);
}