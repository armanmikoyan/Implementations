#include "adjacency_list.hpp"

int main()
{
    graph_list<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 4);
    g.add_edge(1, 4);
    g.add_edge(1, 3);
    g.add_edge(2, 4);
    g.add_edge(4, 3);
    g.add_edge(2, 3);
    g.print_list();

 

    std::cout << std::endl;
}