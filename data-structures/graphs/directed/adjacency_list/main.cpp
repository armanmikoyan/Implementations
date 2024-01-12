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
    g.add_edge(1, 2);
    g.add_edge(2, 4);
    g.add_edge(4, 3);
    g.add_edge(3, 1);
    g.add_edge(4, 5);
    g.add_edge(3, 5);
    g.add_edge(2, 5);
    g.add_edge(5, 1);
    g.add_edge(1, 3);
    g.print_list();
    auto paths = g.all_paths_two_vertex(2, 3);
    for(auto path : paths)
    {
        for(auto p : path)
        {
            std::cout << p << " -> ";
        }
        std::cout << std::endl;
    }
}