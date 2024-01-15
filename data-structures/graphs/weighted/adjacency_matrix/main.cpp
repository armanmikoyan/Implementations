#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
       g.add_vertex();
      
  g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 5);
    g.add_edge(1, 3);
 g.add_edge(4, 2);
    g.add_edge(3, 4);
    g.print_matrix();



   

    auto res = g.all_paths_two_vertex(0, 3);
    for (auto path : res)
    {
        for(auto p : path)
        {
            std::cout << p << " -> ";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
}