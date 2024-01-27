#include "adjacency_matrix.hpp"

int main()
{
    graph_matrix<int> g{9};
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 1);
    g.add_edge(2, 1, 5); 
    g.add_edge(3, 4, 3);
    g.add_edge(4, 5, 3);
    g.add_edge(0, 6, 2);
    g.add_edge(0, 7, 2);
    g.add_edge(0, 8, 2);
  
    g.print_matrix();

    auto list = g.sssp_Bellman_Fords_algorithm();

    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << i << " " << list[i] << "\n";
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



Test 3

    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 1);
    g.add_edge(4, 5);
    g.add_edge(5, 4);
    g.add_edge(6, 5);
    g.add_edge(6, 3);
    g.add_edge(3, 2);
    g.add_edge(2, 0);



// Test cases for Tarjan's  algorithm



Test 1

graph_matrix<int> g{};

    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_vertex();
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 1);
    g.add_edge(4, 5);
    g.add_edge(5, 4);
    g.add_edge(6, 5);
    g.add_edge(6, 3);
    g.add_edge(3, 2);
    g.add_edge(2, 0);
    g.print_matrix();
    auto list = g.scc_Tarjans_algorithm();

    for (auto vertice : list)
    {
        for (auto v : vertice)
        {
            std::cout << v << " ";
        }
        std::cout << std::endl;
    }


////// Test case for  sssp_Armans_algorithm

TEST 1
    graph_matrix<int> g{9};
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



TEST 2
    graph_matrix<int> g{9};
    g.add_edge(0, 4, 15);
    g.add_edge(0, 3, 111);
    g.add_edge(0, 2, 1);
    g.add_edge(0, 1, 3);
    g.add_edge(1, 4, 2);
    g.add_edge(2, 4, 6);
    g.add_edge(3, 4, 2);
    g.add_edge(3, 2, 3);
    g.add_edge(3, 1, 1);
    g.add_edge(3, 4, 2);
    g.add_edge(5, 4, 8);



    // Test cases for sssp_Dijkstras_algorithm algorithm


TEST 1
    graph_matrix<int> g{10};
    g.add_edge(0, 5, 3);
    g.add_edge(5, 1, 111199);
    g.add_edge(1, 2, 2);
    g.add_edge(2, 3, 4);
    g.add_edge(2, 6, 4);
    g.add_edge(3, 6, 9);
    g.add_edge(6, 4, 3);
    g.add_edge(5, 6, 11);
    g.add_edge(5, 3, 111);
    g.add_edge(3, 4, 1211);
    g.add_edge(5, 4, 8);
    g.print_matrix();

    auto path = g.sssp_Dijkstras_algorithm(0, 4);

    for (int i = 0; i < path.size(); ++i)
    {
        std::cout <<  path[i] << "-> ";
    }


TEST 2

    g.add_edge(0, 4, 15);
    g.add_edge(0, 3, 111);
    g.add_edge(0, 2, 1);
    g.add_edge(0, 1, 3);
    g.add_edge(1, 4, 2);
    g.add_edge(2, 4, 6);
    g.add_edge(3, 4, 2);
    g.add_edge(3, 2, 3);
    g.add_edge(3, 1, 1);
    g.add_edge(3, 4, 2);
    g.add_edge(5, 4, 8);


// Test cases for sssp Bellman Fords algorithm 

// if any of distance is INT_MIN there is negative cyle, and from  negative cycle affected vertexes also have INT_MIN

TEST1 1
    graph_matrix<int> g{9};
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 1);
    g.add_edge(2, 1, -5); 
    g.add_edge(3, 4, 3);
    g.add_edge(4, 5, 3);
    g.add_edge(0, 6, 2);
    g.add_edge(0, 7, 2);
    g.add_edge(0, 8, 2);

    g.print_matrix();

    auto list = g.sssp_Bellman_Fords_algorithm();    

   

    for (int i = 0; i < list.size(); ++i)
    {
        std::cout << i << " " << list[i] << "\n";
    }



TEST 2 

    graph_matrix<int> g{9};
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 1);
    g.add_edge(2, 1, 5);
    g.add_edge(3, 4, 3);
    g.add_edge(4, 5, 3);
    g.add_edge(0, 6, 2);
    g.add_edge(0, 7, 2);
    g.add_edge(0, 8, 2);


TEST 3


    graph_matrix<int> g{9};
    g.add_edge(0, 1, 2);
    g.add_edge(0, 2, 2);
    g.add_edge(2, 0, 2);
    g.add_edge(0, 3, 2);
    g.add_edge(1, 3, 3);
    g.add_edge(3, 2, 1);
    g.add_edge(2, 1, -5); 
    g.add_edge(3, 4, 3);
    g.add_edge(4, 5, 3);
    g.add_edge(0, 6, 2);
    g.add_edge(0, 7, 2);
    g.add_edge(0, 8, 2);

#endif