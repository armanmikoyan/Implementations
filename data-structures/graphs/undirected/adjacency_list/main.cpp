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

    g.add_edge(4, 0);
    g.add_edge(2, 0);
    g.add_edge(4, 3);  
    g.add_edge(0, 1);
    g.add_edge(5, 0);
    g.add_edge(1, 2);
    g.add_edge(3, 5);
    g.print_list();

    auto paths = g.all_paths_two_vertex(1, 3);
    for(auto path : paths)
    {
        for(auto p : path)
        {
            std::cout << p << " -> ";
        }
        n
    }

    n
}