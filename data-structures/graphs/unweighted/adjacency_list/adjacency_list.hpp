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

public:
    void                                                                       add_vertex();
    void                                                                        transpose();
    void                                                                 print_list() const;
    void                                                           add_edge(size_t, size_t);
    bool                                                       has_cycle_undirected() const;
    bool                                                         has_cycle_directed() const;
    void             dfs(size_t = 0, std::function<void(size_t)> = default_operation) const;
    void  dfs_extra_case(size_t = 0, std::function<void(size_t)> = default_operation) const;   
    void             bfs(size_t = 0, std::function<void(size_t)> = default_operation) const;
    void  bfs_extra_case(size_t = 0, std::function<void(size_t)> = default_operation) const;
    size_t                                                          component_count() const;
    size_t                                      vertex_count_in_level(size_t, size_t) const;
    size_t                                   shortest_path_two_vertex(size_t, size_t) const;
    std::vector<std::vector<int>>                all_paths_two_vertex(size_t, size_t) const;
    std::vector<int>                                               topological_sort() const;
    std::vector<int>                               topological_sort_Kahns_algorithm() const;

    //SCC
    std::vector<std::vector<int>>                           scc_Kosarajus_algorithm() const;

private: // helpers
    void  dfs_helper_recrusive(size_t, std::vector<bool>&, std::function<void(size_t)>) const;
    void  dfs_helper_iterative(size_t, std::vector<bool>&, std::function<void(size_t)>) const;
    void            bfs_helper(size_t, std::vector<bool>&, std::function<void(size_t)>) const;
    bool      has_cycle_directed_helper(size_t, std::vector<bool>&, std::vector<bool>&) const;
    bool                has_cycle_undirected_helper(size_t, size_t, std::vector<bool>&) const;
    std::vector<int>                     reconstruct(size_t, size_t, std::vector<int>&) const;
    void         topological_sort_helper(size_t, std::vector<bool>&, std::vector<int>&) const;

    void scc_Kosarajus_algorithm_helper_first_pass(size_t, 
                                                   std::vector<bool>&, 
                                                   std::stack<size_t>&) const;

    void scc_Kosarajus_algorithm_helper_second_pass(size_t,
                                                    std::vector<bool>&,
                                                    std::vector<int>&,
                                                    std::vector<std::vector<int>>&) const;

    void all_paths_two_vertex_helper(size_t,
                                     size_t,
                                     std::vector<bool>&,
                                     std::vector<int>&,
                                     std::vector<std::vector<int>>&) const;

private:
    static void default_operation(size_t = 0);

private:
    std::vector<std::vector<int>> _graph;
};

#include "adjacency_list.tpp"

#endif // AJ_LIST

