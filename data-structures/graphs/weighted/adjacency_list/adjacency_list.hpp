#ifndef  AJ_LIST
#define  AJ_LIST

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>

template<typename T>
class graph_list
{
public:
    graph_list                      () = default;
    graph_list                          (size_t);
    graph_list               (const graph_list&);
    graph_list           (graph_list&&) noexcept;
    graph_list&     operator=(const graph_list&);
    graph_list& operator=(graph_list&&) noexcept;



private:
    std::vector<std::vector<int>> _graph;
};

#include "adjacency_list.tpp"

#endif // AJ_LIST

