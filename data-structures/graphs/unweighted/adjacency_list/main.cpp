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

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);  
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    g.add_edge(3, 4);
    g.add_edge(4, 5);

    g.print_list();
    auto paths = g.all_paths_two_vertex(0, 5);
    for (auto path : paths)
    {
        for(auto p : path)
        {
            std::cout << p << " -> ";
        }
        std::cout << "\n";
    }
}