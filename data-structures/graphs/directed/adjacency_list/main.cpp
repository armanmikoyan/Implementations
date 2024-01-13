#include "adjacency_list.hpp"


int main()
{
    graph_list<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    g.add_edge(3, 6);
    g.add_edge(3, 2);
    g.add_edge(4, 5);
    g.add_edge(3, 5);
    g.add_edge(2, 5);
    g.add_edge(1, 3);
    g.add_edge(5, 6);


    g.add_edge(4, 7);
    g.add_edge(5, 7);
    g.add_edge(6, 7);
    g.print_list();
    g.dfs(1);
}