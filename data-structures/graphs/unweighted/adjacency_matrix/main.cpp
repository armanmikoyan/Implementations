#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
 

    
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 1);

    g.print_matrix();

    std::cout << g.has_cycle_directed();
    
    std::cout << std::endl;
}