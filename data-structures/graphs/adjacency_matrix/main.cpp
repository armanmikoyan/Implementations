#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g1{3};
    g1.add_vertex();
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 0);
    g1.add_edge(3, 0);
    g1.print_matrix();
    g1.transpose();
    g1.print_matrix();
}