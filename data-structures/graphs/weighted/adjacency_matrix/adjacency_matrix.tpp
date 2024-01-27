template<typename T>
graph_matrix<T>::graph_matrix(size_t v)
    : _graph(v, std::vector<std::pair<bool, int>>(v, {false, 0}))
{
}

template<typename T>
graph_matrix<T>::graph_matrix(const graph_matrix<T>& oth)
{
    _graph = oth._graph;
}

template<typename T>
graph_matrix<T>::graph_matrix(graph_matrix<T>&& oth) noexcept
{
    _graph = std::move(oth._graph);
}

template<typename T>
graph_matrix<T>& graph_matrix<T>::operator=(const graph_matrix<T>& rhs)
{
    if (this != &rhs)
    {
        _graph = rhs._graph;
    }
    return *this;
}

template<typename T>
graph_matrix<T>& graph_matrix<T>::operator=(graph_matrix<T>&& rhs) noexcept
{
    if (this != &rhs)
    {
        _graph = std::move(rhs._graph);
    }
    return *this;
}

template<typename T>
void graph_matrix<T>::add_edge(size_t u, size_t v, size_t w)
{
    if (u >= _graph.size() || v >= _graph.size()) throw std::out_of_range("Vertex index out of range");
    _graph[u][v] = {true, w};
    if (!_graph[v][u].first)
    {
       // _graph[v][u] = {true, w};  //  for undirected graph
    }
}

template<typename T>
void graph_matrix<T>::add_vertex()
{
    for (auto& row : _graph)
    {
        row.push_back({false , 0});
    }
    _graph.push_back(std::vector<std::pair<bool, int>>(_graph.size() + 1, {false, 0}));
}

template<typename T>
bool graph_matrix<T>::has_cycle_undirected() const
{
    visited_type visited(_graph.size(), false);

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            if (has_cycle_undirected_helper(i, -1, visited)) return true;
        }
        std::cout << std::endl;
    }

    return false;
}

template<typename T>
bool graph_matrix<T>::has_cycle_undirected_helper(size_t source, size_t parent, visited_type& visited) const
{
    visited[source] = true;

    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first)
        {
             if (!visited[i])
            {
                if (has_cycle_undirected_helper(i, source, visited)) return true;
            }
            else if (i != parent) return true;
        }
    }

    return false;
}

template<typename T>
bool graph_matrix<T>::has_cycle_directed() const
{
    visited_type visited(_graph.size(), false);
    visited_type on_rec_stack(_graph.size(), false);

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            if (has_cycle_directed_helper(i, on_rec_stack, visited)) return true;
        }
    }

    return false;
}

template<typename T>
bool graph_matrix<T>::has_cycle_directed_helper(size_t source, visited_type& visited,
                                                               visited_type& on_rec_stack) const
{
    visited[source]      = true;
    on_rec_stack[source] = true;

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first)
        {
            if (!visited[i])
            {
                if (has_cycle_directed_helper(i, visited, on_rec_stack)) return true;
            }

            else if (on_rec_stack[i]) return true;
        }
    }

    on_rec_stack[source] = false;
    return false;
}

template<typename T>
void graph_matrix<T>::transpose()
{
    graph_matrix<T> tmp = *this;
    for (int i = 0; i < _graph.size(); ++i)
    {
        for (int j = 0; j < _graph.size(); ++j)
        {
            tmp._graph[i][j] = _graph[j][i];
        }
    }
    _graph = std::move(tmp._graph);
}

template<typename T>
void graph_matrix<T>::dfs(size_t vertex, callback_type callback) const
{
    if (vertex >= _graph.size()) throw std::out_of_range("vertex index is great");

    visited_type visited(_graph.size(), false);
  //  dfs_helper_recrusive(vertex, visited, callback);
   dfs_helper_iterative(vertex, visited, callback);
}

template<typename T>
void graph_matrix<T>::dfs_extra_case(size_t vertex, callback_type callback) const
{
    visited_type visited(_graph.size(), false);
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            dfs_helper_recrusive(i, visited, callback);
        }
    }
}

template<typename T>
void graph_matrix<T>::dfs_helper_recrusive(size_t current, visited_type& visited, callback_type callback) const
{
    visited[current] = true;

    callback(current);

    for (int i = 0; i < _graph.size(); ++i)
    {
       if (_graph[current][i].first && !visited[i])
       {
           dfs_helper_recrusive(i, visited, callback);
       }
    }
}

template<typename T>
void graph_matrix<T>::dfs_helper_iterative(size_t vertex, visited_type& visited, callback_type callback) const
{
    std::stack<size_t> stack;
    stack.push(vertex);
    visited[vertex] = true;

    while (!stack.empty())
    {
        size_t current = stack.top();
        stack.pop();

        callback(current);

        for (int i = _graph.size() - 1; i >= 0; --i)
        {
            if (_graph[current][i].first && !visited[i])
            {
                stack.push(i);
                visited[i] = true;
            }
        }
    }
}

template<typename T>
void graph_matrix<T>::bfs(size_t vertex,  callback_type callback) const
{
    if (vertex >= _graph.size()) throw std::out_of_range("vertex index is great");

    visited_type visited(_graph.size(), false);
    bfs_helper(vertex, visited, callback);

}

template<typename T>
void graph_matrix<T>::bfs_extra_case(size_t vertex, callback_type callback) const
{
    visited_type visited(_graph.size(), false);
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            bfs_helper(i, visited, callback);
        }
        std::cout << std::endl;
    }
}

template<typename T>
void graph_matrix<T>::bfs_helper(size_t vertex, visited_type& visited, callback_type callback) const
{
    std::queue<size_t> queue;
    queue.push(vertex);
    visited[vertex] = true;

    while (!queue.empty())
    {
        size_t current = queue.front();
        queue.pop();

        callback(current);

        for (int i = 0; i < _graph.size(); ++i)
        {
            if (_graph[current][i].first && !visited[i])
            {
                queue.push(i);
                visited[i] = true;
            }
        }
    }
}

template<typename T>
size_t graph_matrix<T>::component_count() const
{
    size_t count = 0;
    std::stack<size_t> stack;
    visited_type visited(_graph.size(), false);
    for (int i = 0; i < _graph.size(); ++i)
    {
       if (!visited[i])
       {
            ++count;
            stack.push(i);
            visited[i] = true;

            while (!stack.empty())
            {
                size_t current = stack.top();
                stack.pop();

                for (int i = _graph.size() - 1; i >= 0; --i)
                {
                    if (_graph[current][i].first && !visited[i])
                    {
                        stack.push(i);
                        visited[i] = true;
                    }
                }
            }
       }
    }
    return count;
}

template<typename T>
size_t graph_matrix<T>::vertex_count_in_level(size_t vertex, size_t level)  const
{
    std::queue<size_t> q;
    visited_type visited(_graph.size(), false);
    q.push(vertex);
    visited[vertex] = true;

    while (!q.empty())
    {
        int size = q.size();

        if (!level) return size;

        while (size--)
        {
            size_t curr = q.front();
            q.pop();
            for (int i = 0; i < _graph.size(); ++i)
            {
                if (_graph[curr][i].first && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        --level;
    }

    return 0;
}

template<typename T>
typename graph_matrix<T>::matrix_type graph_matrix<T>::all_paths_two_vertex(size_t source, size_t destination) const
{
    matrix_type paths;
    std::vector<int> raw_path(_graph.size(), -1);
    visited_type visited(_graph.size(), false);
    all_paths_two_vertex_helper(source, destination, visited, raw_path, paths);

    return paths;
}

template<typename T>
void  graph_matrix<T>::all_paths_two_vertex_helper(size_t source,
                                                   size_t destination,
                                                   visited_type& visited,
                                                   std::vector<int>& raw_path,
                                                   matrix_type& paths) const
{
    visited[source] = true;
    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first && !visited[i])
        {
            raw_path[i] = source;
            if (i == destination)
            {
                paths.push_back(reconstruct(source, destination, raw_path));
            }
            else
            {
                all_paths_two_vertex_helper(i, destination, visited, raw_path, paths);
            }
        }
    }

    visited[source] = false;
}

template<typename T>
std::vector<int> graph_matrix<T>::reconstruct(size_t source, size_t destination, std::vector<int>& raw_path) const
{
    std::vector<int> path;

    while (destination != -1)
    {
        path.insert(path.begin(), destination);
        destination = raw_path[destination];
    }
    return path;
}

template<typename T>
std::vector<int> graph_matrix<T>::topological_sort() const // This is NOT RECOMMENDED algorithm !!!!!!!!!!! instead use Kahn's algorithm
{
    if (has_cycle_directed()) throw std::logic_error("There is cycle in the graph");

    std::vector<int> result;
    visited_type visited(_graph.size(), false);
    std::vector<size_t> vertex_degree(_graph.size(), 0);

    for (int i = 0; i < _graph.size(); ++i)
    {
        for (int j = 0; j < _graph.size(); ++j)
        {
            if (_graph[i][j].first)
            {
                ++vertex_degree[j];
            }
        }
    }

    for (int i = 0; i < vertex_degree.size(); ++i)
    {
        if (!visited[i] && vertex_degree[i] == 0)
        {
            topological_sort_helper(i, visited, result);
        }
    }

    return result;
}

template<typename T>
void graph_matrix<T>::topological_sort_helper(size_t source, visited_type& visited, std::vector<int>& result) const
{
    visited[source] = true;

    for(int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first && !visited[i])
        {
            topological_sort_helper(i, visited, result);
        }
    }
    result.insert(result.begin(), source);
}


template<typename T>
std::vector<int> graph_matrix<T>::topological_sort_Kahns_algorithm() const     // Use this algorithm !!!
{
    std::vector<int> result;
    std::queue<size_t> queue;
    std::vector<size_t> vertice_degree(_graph.size(), 0);


    for (int i = 0; i < _graph.size(); ++i)
    {
        for (int j = 0; j < _graph.size(); ++j)
        {
            if (_graph[i][j].first)
            {
                ++vertice_degree[j];
            }
        }
    }

    for (size_t i = 0; i < vertice_degree.size(); ++i)
    {
        if (vertice_degree[i] == 0) // if there is not vertice with degree 0, the graph is cyclic
        {
            queue.push(i);
        }
    }

    while (!queue.empty())
    {
        size_t current = queue.front();
        result.push_back(current);
        queue.pop();

        for (int i = 0; i < _graph.size(); ++i)
        {
            if (_graph[current][i].first)
            {
                --vertice_degree[i];
                if (vertice_degree[i] == 0)
                {
                    queue.push(i);
                }
            }
        }
    }

   if (result.size() != _graph.size()) throw std::logic_error("There is cycle in the graph");

   return result;
}



//-------------------SCC-------------------//

template<typename T>
typename graph_matrix<T>::matrix_type graph_matrix<T>::scc_Kosarajus_algorithm() const
{
    visited_type visited(_graph.size(), false);
    matrix_type result;
    std::stack<size_t> finish_time;

    // 1. first pass, fill the stack with finishing time of vertices
    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            scc_Kosarajus_algorithm_helper_first_pass(i, visited, finish_time);
        }
    }

    // 2. second pass, strongly connected component detecting
    visited.assign(visited.size(), false);
    auto tmp = *this;
    tmp.transpose();

    while (!finish_time.empty())
    {
        size_t curr = finish_time.top();
        finish_time.pop();

        if (!visited[curr])
        {
            std::vector<int> scc;
            scc_Kosarajus_algorithm_helper_second_pass(curr, visited, scc, tmp._graph);
            result.push_back(std::move(scc));
        }
    }
    return result;
}

template<typename T>
void graph_matrix<T>::scc_Kosarajus_algorithm_helper_first_pass(size_t source,
                                                                visited_type& visited,
                                                                std::stack<size_t>& finish_time) const
{
    visited[source] = true;

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first && !visited[i])
        {
            scc_Kosarajus_algorithm_helper_first_pass(i, visited, finish_time);
        }
    }

    finish_time.push(source);
}

template<typename T>
void graph_matrix<T>::scc_Kosarajus_algorithm_helper_second_pass(size_t source,
                                                                 visited_type& visited,
                                                                 std::vector<int>& scc,
                                                                 list_type& transposed_list) const
{
    visited[source] = true;
    scc.push_back(source);

    for (int i = 0; i < transposed_list.size(); ++i)
    {
        if (transposed_list[source][i].first && !visited[i])
        {
            scc_Kosarajus_algorithm_helper_second_pass(i, visited, scc, transposed_list);
        }
    }
}

template<typename T>
typename graph_matrix<T>::matrix_type graph_matrix<T>::scc_Tarjans_algorithm() const
{
    matrix_type result;
    visited_type on_stack(_graph.size(), false);
    std::stack<size_t> stack;
    std::vector<int> ids(_graph.size(), -1);
    std::vector<int> low_links(_graph.size(), -1);

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (ids[i] == -1)
        {
            scc_Tarjans_algorithm_helper(i, on_stack, stack, ids, low_links, result);
        }
    }
    return result;
}

template <typename T>
void graph_matrix<T>::scc_Tarjans_algorithm_helper(size_t source,
                                                 visited_type& on_stack,
                                                 std::stack<size_t>& stack,
                                                 std::vector<int>& ids,
                                                 std::vector<int>& low_links,
                                                 matrix_type& result) const
{
    static int time = 0;
    ids[source] = low_links[source] = time++;
    on_stack[source] = true;
    stack.push(source);

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i].first)
        {
            if (ids[i] == -1)
            {
                scc_Tarjans_algorithm_helper(i, on_stack, stack, ids, low_links, result);
            }
            if (on_stack[i])
            {
                low_links[source] = std::min(low_links[source], low_links[i]);
            }
        }
    }

    if (low_links[source] == ids[source])
    {
        std::vector<int> scc;
        for (size_t vertex = stack.top();; vertex = stack.top())
        {
            stack.pop();
            on_stack[vertex] = false;
            scc.push_back(vertex);
            if (source == vertex) break;
        }
        result.push_back(std::move(scc));
    }
}

//-------------------SSSP-------------------//

template<typename T>
std::vector<int> graph_matrix<T>::sssp_Armans_algorithm(size_t source, size_t destination) const
{
    std::vector<int> raw_path(_graph.size(), -1);
    std::vector<int> top_sort_arr = topological_sort_Kahns_algorithm();
    std::vector<long long> distance(_graph.size(), INT_MAX);
    size_t source_id = 0;
    distance[source] = 0;

    for (size_t i = 0; i < top_sort_arr.size(); ++i)     // find source id in topologicaly sorted array
    {
        if (top_sort_arr[i] == source)
        {
            source_id = i;
            break;
        }
    }

    for (size_t i = source_id; i < top_sort_arr.size(); ++i)
    {
        size_t vertex = top_sort_arr[i];

        for (int j = 0; j < _graph[i].size(); ++j)
        {
            if (_graph[vertex][j].first)
            {
                if (distance[j] > distance[vertex] + _graph[vertex][j].second)
                {
                    distance[j] = distance[vertex] + _graph[vertex][j].second; // relaxing
                    raw_path[j] = vertex;                                     // parenting for construct path
                }
            }
        }
    }
    return reconstruct(source, destination, raw_path);
}

template<typename T>
std::vector<int> graph_matrix<T>::sssp_Dijkstras_algorithm(size_t source, size_t destination) const   // don't allowed negative edge!!!
{
    auto comparator = [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second > b.second;
    };

    std::vector<long long> distance(_graph.size(), INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(comparator)> priority;   // min heap, compatator with pair's second value (cost)
    std::vector<int> raw_path(_graph.size(), -1);

    distance[source] = 0;
    priority.push({source, 0});

    while (!priority.empty())
    {
        auto [vertex, cost] = priority.top();
        priority.pop();

        if (vertex == destination) break;     // raw_path is ready.  If vertex is poped from pq, then vertex won't be updated anymore

        if (cost > distance[vertex]) continue;  // optimization  if extracted vertex cost is not actual, and distanse to vertex  is already updated

        for (int i = 0; i < _graph.size(); ++i)
        {
            if (_graph[vertex][i].first)
            {
                long long new_distanse_from_vertex_to_next = distance[vertex] + _graph[vertex][i].second;

                if (distance[i] > new_distanse_from_vertex_to_next)
                {
                    distance[i] = new_distanse_from_vertex_to_next;
                    priority.push({i, distance[i]});
                    raw_path[i] = vertex;
                }
            }
        }
    }

    return reconstruct(source, destination, raw_path);
    // return  distance   
    // for all shorest path from source to all passible vertexes, 
    //comment this line  --> if (vertex == destination) break; 
}

template<typename T>
std::vector<long long> graph_matrix<T>::sssp_Bellman_Fords_algorithm(size_t source) const
{
    std::vector<long long> distance(_graph.size(), INT_MAX);
    distance[source] = 0;
    
    // 1. first pass relaxing V-1 times

    for (int i = 0; i < _graph.size() - 1; ++i)
    {
        for (int vertex = 0; vertex < _graph.size(); ++vertex)
        {
            for (int next_vertex = 0; next_vertex < _graph.size(); ++next_vertex)
            {
                if (_graph[vertex][next_vertex].first)
                {
                    long long new_distanse_from_vertex_to_next = distance[vertex] + _graph[vertex][next_vertex].second;
                    if (distance[next_vertex] > distance[vertex] + _graph[vertex][next_vertex].second)
                    {
                        distance[next_vertex] = distance[vertex] + _graph[vertex][next_vertex].second;
                    }
                }
            }
        }
    }

    // 2. second pass if distance array have INT_MIN value then, there is negative cycle in the graph 
    // INT_MIN values have all vertexes in cycle and also affected from that cycle

    for (int i = 0; i < _graph.size() - 1; ++i)
    {
        for (int vertex = 0; vertex < _graph.size(); ++vertex)
        {
            for (int next_vertex = 0; next_vertex < _graph.size(); ++next_vertex)
            {
                if (_graph[vertex][next_vertex].first)
                {
                    long long new_distanse_from_vertex_to_next = distance[vertex] + _graph[vertex][next_vertex].second;
                    if (distance[next_vertex] > distance[vertex] + _graph[vertex][next_vertex].second)
                    {
                        distance[next_vertex] = INT_MIN;
                    }
                }
            }
        }
    }
    
    return distance;
}

template<typename T>
void graph_matrix<T>::default_operation(size_t vertex)
{
    std::cout << vertex << " ";
}

template<typename T>
void graph_matrix<T>::print_matrix() const
{
    const char* green = "\033[1;32m";
    const char* red   = "\033[1;31m";
    const char* blue  =  "\033[0;34m ";
    const char* reset = "\033[0m";

    std::cout << "    ";
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << i << "     ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << "   ";
        for (size_t j = 0; j < _graph[i].size(); ++j)
        {
            std::cout << "------";
        }
        std::cout << std::endl;

        std::cout << i << " |";
        for (size_t j = 0; j < _graph[i].size(); ++j)
        {
            std::cout << blue <<  _graph[i][j].second << " "
                      <<  (_graph[i][j].first ?  green :  red)
                      << _graph[i][j].first << reset << " |";
        }
        std::cout << std::endl;
    }

    std::cout << "   ";
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << "-----";
    }
    std::cout << "---";
    std::cout << std::endl;
}