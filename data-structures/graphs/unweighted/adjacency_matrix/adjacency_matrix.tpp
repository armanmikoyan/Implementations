template<typename T>
graph_matrix<T>::graph_matrix(size_t v)
    : _graph(v, std::vector<int>(v, 0))
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
void graph_matrix<T>::add_edge(size_t u, size_t v)
{
    if (u >= _graph.size() || v >= _graph.size()) throw std::out_of_range("Vertex index out of range");
    _graph[u][v] = 1;
 //   _graph[v][u] = 1;  //  for undirected graph
}

template<typename T>
void graph_matrix<T>::add_vertex()
{
    for (auto& row : _graph)
    {
        row.push_back(0);
    }
    _graph.push_back(std::vector<int>(_graph.size() + 1, 0));
}

template<typename T>
bool graph_matrix<T>::has_cycle_undirected() const
{
    std::vector<bool> visited(_graph.size(), false);

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
bool graph_matrix<T>::has_cycle_undirected_helper(size_t source, size_t parent, std::vector<bool>& visited) const
{
    visited[source] = true;

    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i])
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
    std::vector<bool> visited(_graph.size(), false);
    std::vector<bool> on_rec_stack(_graph.size(), false);

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
bool graph_matrix<T>::has_cycle_directed_helper(size_t source, std::vector<bool>& visited,
                                                               std::vector<bool>& on_rec_stack) const
{
    visited[source]      = true;
    on_rec_stack[source] = true;

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i])
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
void graph_matrix<T>::dfs(size_t vertex, std::function<void(size_t)> callback) const
{
    if (vertex >= _graph.size()) throw std::out_of_range("vertex index is great");

    std::vector<bool> visited(_graph.size(), false);
    dfs_helper_recrusive(vertex, visited, callback);
   // dfs_helper_iterative(vertex, visited, callback);
}

template<typename T>
void graph_matrix<T>::dfs_extra_case(size_t vertex, std::function<void(size_t)> callback) const
{
    std::vector<bool> visited(_graph.size(), false);
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            dfs_helper_recrusive(i, visited, callback);
        }
    }
}

template<typename T>
void graph_matrix<T>::dfs_helper_recrusive(size_t current, std::vector<bool>& visited,
                                                           std::function<void(size_t)> callback) const
{
    visited[current] = true;

    callback(current);

    for (int i = 0; i < _graph.size(); ++i)
    {
       if (_graph[current][i] && !visited[i])
       {
           dfs_helper_recrusive(i, visited, callback);
       }
    }
}

template<typename T>
void graph_matrix<T>::dfs_helper_iterative(size_t vertex, std::vector<bool>& visited,
                                                          std::function<void(size_t)> callback) const
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
            if (_graph[current][i] && !visited[i])
            {
                stack.push(i);
                visited[i] = true;
            }
        }
    }
}

template<typename T>
void graph_matrix<T>::bfs(size_t vertex,  std::function<void(size_t)> callback) const
{
    if (vertex >= _graph.size()) throw std::out_of_range("vertex index is great");

    std::vector<bool> visited(_graph.size(), false);
    bfs_helper(vertex, visited, callback);

}

template<typename T>
void graph_matrix<T>::bfs_extra_case(size_t vertex, std::function<void(size_t)> callback) const
{
    std::vector<bool> visited(_graph.size(), false);
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
void graph_matrix<T>::bfs_helper(size_t vertex, std::vector<bool>& visited, std::function<void(size_t)> callback) const
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
            if (_graph[current][i] && !visited[i])
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
    std::vector<bool> visited(_graph.size(), false);
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
                    if (_graph[current][i] && !visited[i])
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
    std::vector<bool> visited(_graph.size(), false);
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
                if (_graph[curr][i] && !visited[i])
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
size_t graph_matrix<T>::shortest_path_two_vertex(size_t source, size_t destionation) const
{
    if (source == destionation) return 0;
    std::queue<size_t> q;
    std::vector<bool> visited(_graph.size(), false);
    size_t path_length = 0;
    q.push(source);
    visited[source] = true;

    while(!q.empty())
    {
        ++path_length;
        size_t size = q.size();
        while (size--)
        {
            size_t curr = q.front();
            q.pop();
            for (int i = 0; i < _graph.size(); ++i)
            {
                if (_graph[curr][i] && !visited[i])
                {
                    if (i == destionation)
                        return path_length;
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    std::cout << "from " << source  << " " << destionation << " is not reachable\n";
    return INT_MAX;
}

template<typename T>
std::vector<std::vector<int>> graph_matrix<T>::all_paths_two_vertex(size_t source, size_t destination) const
{
    std::vector<std::vector<int>> paths;
    std::vector<int> raw_path(_graph.size(), -1);
    std::vector<bool> visited(_graph.size(), false);
    all_paths_two_vertex_helper(source, destination, visited, raw_path, paths);

    return paths;
}

template<typename T>
void  graph_matrix<T>::all_paths_two_vertex_helper(size_t source,
                                     size_t destination,
                                     std::vector<bool>& visited,
                                     std::vector<int>& raw_path,
                                     std::vector<std::vector<int>>& paths) const
{
    visited[source] = true;
    for (int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i] && !visited[i])
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
std::vector<int> graph_matrix<T>::topological_sort() const     // This is NOT RECOMMENDED algorithm !!!!!!!!!!! instead use Kahn's algorithm
{
    if (has_cycle_directed()) throw std::logic_error("There is cycle in the graph");

    std::vector<int> result;
    std::vector<bool> visited(_graph.size(), false);
    std::vector<size_t> vertex_degree(_graph.size(), 0);

    for (int i = 0; i < _graph.size(); ++i)
    {
        for (int j = 0; j < _graph.size(); ++j)
        {
            if (_graph[i][j])
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
void graph_matrix<T>::topological_sort_helper(size_t source, std::vector<bool>& visited, std::vector<int>& result) const
{
    visited[source] = true;

    for(int i = 0; i < _graph.size(); ++i)
    {
        if (_graph[source][i] && !visited[i])
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
            if (_graph[i][j])
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
            if (_graph[current][i])
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
    const char* reset = "\033[0m";

    std::cout << "    ";
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << i << "   ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << "   ";
        for (size_t j = 0; j < _graph[i].size(); ++j)
        {
            std::cout << "----";
        }
        std::cout << std::endl;

        std::cout << i << " |";
        for (size_t j = 0; j < _graph[i].size(); ++j)
        {
            if (_graph[i][j])
            {
                std::cout << green;
            }
            else
            {
                std::cout << red;
            }
            std::cout << " " << _graph[i][j] << reset << " |";
        }
        std::cout << std::endl;
    }

    std::cout << "   ";
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << "----";
    }
    std::cout << std::endl;
}