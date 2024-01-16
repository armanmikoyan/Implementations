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

    g.add_edge(4, 3);
    g.add_edge(3, 2);
    g.add_edge(3, 0);
    g.add_edge(2, 0);
    g.add_edge(1, 0);

    std::map<int, std::string> map;
    map[0] = "math";
    map[1] = "discrete";
    map[2] = "calculus";
    map[3] = "linear_algebra";
    map[4] = "num_theory";

    g.print_list();

    auto list = g.topological_sort();

    for (auto l : list)
    {
        std::cout << map[l] << " ";
    }
}