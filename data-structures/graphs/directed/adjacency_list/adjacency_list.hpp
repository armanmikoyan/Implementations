#ifndef  AJ_LIST
#define  AJ_LIST

#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <utility>

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

public:
    void                                                        add_vertex();
    void                                                         transpose();
    void                                            add_edge(size_t, size_t);
    void                                                print_matrix() const;
    void                                                  dfs(int = 0) const;  
    void                                                  bfs(int = 0) const;
    size_t                       vertex_count_in_level(size_t, size_t) const;
    size_t                    shortest_path_two_vertex(size_t, size_t) const;
    std::vector<std::vector<int>> all_paths_two_vertex(size_t, size_t) const;  

// helpers
private: 

public:
    std::vector<std::vector<int>> _graph;
};

#include "adjacency_list.tpp"

#endif // AJ_LIST



