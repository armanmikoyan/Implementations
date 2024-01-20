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
    g.add_edge(1, 5);
    g.add_edge(5, 4);
    g.add_edge(2, 4);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    g.print_matrix();

    auto list = g.scc_Kosarajus_algorithm();

    for (auto vertice : list)
    {
        for (auto v : vertice)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }
  
  
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

    g.print_matrix();

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

    g.print_matrix();

    auto list = g.topological_sort_Kahns_algorithm();

    for (auto vertice : list)
    {
        std::cout << vertice << " ";
    }

    std::cout << std::endl;





// Test cases for Kosaraju's  algorithm


Test 1

graph_matrix<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(1, 5);
    g.add_edge(5, 4);
    g.add_edge(2, 4);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 0);

    g.print_matrix();

    auto list = g.scc_Kosarajus_algorithm();

    for (auto vertice : list)
    {
        for (auto v : vertice)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }

Test 2

    graph_matrix<int> g{};
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(1, 0);
    g.add_edge(0, 2);
    g.add_edge(2, 0);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 7);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_edge(6, 4);
    g.add_edge(4, 7);
    g.add_edge(7, 8);

    g.print_matrix();

    auto list = g.scc_Kosarajus_algorithm();

    for (auto vertice : list)
    {
        for (auto v : vertice)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }


#endif