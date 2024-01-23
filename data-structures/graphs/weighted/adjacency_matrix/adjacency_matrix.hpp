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
    using visited_type  =                               std::vector<bool>;
    using callback_type =                    std::function <void(size_t)>;
    using matrix_type   =                   std::vector<std::vector<int>>;
    using list_type     =  std::vector<std::vector<std::pair<bool, int>>>;

public:
    graph_matrix                        () = default;
    graph_matrix                            (size_t);
    graph_matrix               (const graph_matrix&);
    graph_matrix           (graph_matrix&&) noexcept;
    graph_matrix&     operator=(const graph_matrix&);
    graph_matrix& operator=(graph_matrix&&) noexcept;

public:
    void                                                         add_vertex();
    void                                  add_edge(size_t, size_t,size_t = 0);
    void                                                          transpose();
    void                                                 print_matrix() const;
    bool                                         has_cycle_undirected() const;
    bool                                           has_cycle_directed() const;
    void            dfs(size_t = 0,  callback_type = default_operation) const;
    void dfs_extra_case(size_t = 0,  callback_type = default_operation) const;
    void            bfs(size_t = 0,  callback_type = default_operation) const;
    void bfs_extra_case(size_t = 0,  callback_type = default_operation) const;
    size_t                                            component_count() const;
    size_t                        vertex_count_in_level(size_t, size_t) const;
    matrix_type                    all_paths_two_vertex(size_t, size_t) const;
    std::vector<int>                                 topological_sort() const;
    std::vector<int>                 topological_sort_Kahns_algorithm() const;

    //SCC
    matrix_type scc_Kosarajus_algorithm() const;
    matrix_type   scc_Tarjans_algorithm() const;

private: // helpers
    void                                         dfs_helper_recrusive(size_t, visited_type&, callback_type) const;
    void                                         dfs_helper_iterative(size_t, visited_type&, callback_type) const;
    void                                                  bfs_helper(size_t,  visited_type&, callback_type) const;
    bool                                         has_cycle_undirected_helper(size_t, size_t, visited_type&) const;
    bool                                    has_cycle_directed_helper(size_t, visited_type&, visited_type&) const;
    void                                  topological_sort_helper(size_t, visited_type&, std::vector<int>&) const;
    std::vector<int>                                         reconstruct(size_t, size_t, std::vector<int>&) const;
    void              scc_Kosarajus_algorithm_helper_first_pass(size_t, visited_type&, std::stack<size_t>&) const;
    void   scc_Kosarajus_algorithm_helper_second_pass(size_t, visited_type&, std::vector<int>&, list_type&) const;
    void        all_paths_two_vertex_helper(size_t, size_t, visited_type&, std::vector<int>&, matrix_type&) const;

    void scc_Tarjans_algorithm_helper(size_t, visited_type&,
                                      std::stack<size_t>&,
                                      std::vector<int>&,
                                      std::vector<int>&,
                                      matrix_type&) const;

private:
    static void default_operation(size_t = 0);

private:
    list_type _graph;
};

#include "adjacency_matrix.tpp"

#endif // AJ_MATRIX

