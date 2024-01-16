#include "adjacency_list.hpp"
#include <map>


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
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();

    g.add_edge(1, 0);
    g.add_edge(1, 3);
    g.add_edge(0, 2);
    g.add_edge(3, 2);
    g.add_edge(2, 4);
    g.add_edge(2, 7);
    g.add_edge(4, 5);
    g.add_edge(7, 5);
    g.add_edge(7, 8);
    g.add_edge(5, 6);
    g.add_edge(8, 9);
    g.add_edge(10, 8);
    g.add_edge(11, 8);
    g.add_edge(11, 10);
    g.add_edge(12, 0);
    g.add_edge(12, 11);
    g.add_edge(12, 2);
    g.print_list();

    auto list = g.topological_sort_Kahns_algorithm();

    for (auto vertice : list)
    {
        std::cout << vertice << " ";
    }

    std::cout << std::endl;
}





/*
TESTS  ------------
                  |
                  |
                  |
                  |
                  |
                  V
*/


#if 0

////// Test case for topological sort dfs (postorder travsersal)
graph_list<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();

    g.add_edge(1, 0);
    g.add_edge(1, 3);
    g.add_edge(0, 2);
    g.add_edge(3, 2);
    g.add_edge(2, 4);
    g.add_edge(2, 7);
    g.add_edge(4, 5);
    g.add_edge(7, 5);
    g.add_edge(7, 8);
    g.add_edge(5, 6);
    g.add_edge(8, 9);
    g.add_edge(10, 8);
    g.add_edge(11, 8);
    g.add_edge(11, 10);
    g.add_edge(12, 0);
    g.add_edge(12, 11);
    g.add_edge(12, 2);

    g.print_list();

    auto list = g.topological_sort();

    for (auto vertice : list)
    {
        std::cout << vertice << " ";
    }



////// Test case for Kahn's topological sort algorithm
 graph_list<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();

    g.add_edge(1, 0);
    g.add_edge(1, 3);
    g.add_edge(0, 2);
    g.add_edge(3, 2);
    g.add_edge(2, 4);
    g.add_edge(2, 7);
    g.add_edge(4, 5);
    g.add_edge(7, 5);
    g.add_edge(7, 8);
    g.add_edge(5, 6);
    g.add_edge(8, 9);
    g.add_edge(10, 8);
    g.add_edge(11, 8);
    g.add_edge(11, 10);
    g.add_edge(12, 0);
    g.add_edge(12, 11);
    g.add_edge(12, 2);

    g.print_list();

    auto list = g.topological_sort_Kahns_algorithm();

    for (auto vertice : list)
    {
        std::cout << vertice << " ";
    }

    std::cout << std::endl;





#endif