#ifndef  AJ_MATRIX
#define  AJ_MATRIX

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>

template<typename T>
class graph_matrix 
{
public:
    graph_matrix                        () = default;
    graph_matrix                            (size_t);
    graph_matrix               (const graph_matrix&);
    graph_matrix           (graph_matrix&&) noexcept;
    graph_matrix&     operator=(const graph_matrix&);
    graph_matrix& operator=(graph_matrix&&) noexcept;




private:
    std::vector<std::vector<int>> _graph;
};

#include "adjacency_matrix.tpp"

#endif // AJ_MATRIX

