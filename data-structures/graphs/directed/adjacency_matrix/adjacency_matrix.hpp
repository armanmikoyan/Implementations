#ifndef  AJ_MATRIX
#define  AJ_MATRIX

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

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

public:
    void                                                        add_vertex();
    void                                                         transpose();
    void                                            add_edge(size_t, size_t);
    void                                                print_matrix() const;
    void                                               dfs(size_t = 0) const;  
    void                                               bfs(size_t = 0) const;
    size_t                       vertex_count_in_level(size_t, size_t) const;
    size_t                    shortest_path_two_vertex(size_t, size_t) const;
    std::vector<std::vector<int>> all_paths_two_vertex(size_t, size_t) const;  

// helpers
private: 
    void     dfs_helper_recrusive(size_t, std::vector<bool>&) const;
    void     dfs_helper_iterative(size_t, std::vector<bool>&) const;
    void               bfs_helper(size_t, std::vector<bool>&) const;
    std::vector<int>   reconstruct(size_t, std::vector<int>&) const;

    void all_paths_two_vertex_helper(size_t, 
                                     size_t, 
                                     std::vector<bool>&, 
                                     std::vector<int>, 
                                     std::vector<std::vector<int>>&) const;

private:
    std::vector<std::vector<int>> _graph;
};

#include "adjacency_matrix.tpp"

#endif // AJ_MATRIX



