template<typename T>
graph_list<T>::graph_list(size_t vertex_count)
    : _graph(vertex_count, std::vector<int>{})
{
}

template<typename T>
graph_list<T>::graph_list(const graph_list<T>& oth)
{
    _graph = oth._graph;
}

template<typename T>
graph_list<T>::graph_list(graph_list<T>&& oth) noexcept
{
    _graph = std::move(oth._graph);
}

template<typename T>
graph_list<T>& graph_list<T>::operator=(const graph_list<T>& rhs)
{
    if (this != &rhs)
    {
        _graph = rhs._graph;
    }
    return *this;
}

template<typename T>
graph_list<T>& graph_list<T>::operator=(graph_list<T>&& rhs) noexcept
{
    if (this != &rhs)
    {   
        _graph = std::move(rhs._graph);
    }
    return *this;
}

template<typename T>
void graph_list<T>::add_vertex() 
{
    _graph.push_back({});
}

template<typename T>
void graph_list<T>::add_edge(size_t u, size_t v) 
{
    if (u >= _graph.size() || v >= _graph.size()) throw std::out_of_range("Vertex index out of range");
    for (auto curr : _graph[u])
    {
        if (curr == v) return;
    }
    _graph[u].push_back(v);
   // _graph[v].push_back(u);  //  for undirected graph

}

template<typename T>
bool graph_list<T>::has_cycle_undirected() const
{
    std::vector<bool> visited(_graph.size(), false);
    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            if (has_cycle_undirected_helper(i, -1, visited)) return true;
        }
    }
    return false;
}

template<typename T>
bool graph_list<T>::has_cycle_undirected_helper(size_t source, size_t parent, std::vector<bool>& visited) const
{
    visited[source] = true;

    for (auto next : _graph[source])
    {
        if (!visited[next])
        {
            if (has_cycle_undirected_helper(next, source, visited)) return true;
        }

        else if (next != parent) return true;
    }
    return false;
}

template<typename T>
bool graph_list<T>::has_cycle_directed() const
{
    std::vector<bool>       visited(_graph.size(), false);
    std::vector<bool> on_rec_stack(_graph.size(), false);

    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            if (has_cycle_directed_helper(i, visited, on_rec_stack)) return true;
        }
    }
    return false;
}

template<typename T>
bool graph_list<T>::has_cycle_directed_helper(size_t source, std::vector<bool>& visited, 
                                                             std::vector<bool>& on_rec_stack) const
{
    visited[source]      = true;
    on_rec_stack[source] = true;

    for (auto next : _graph[source])
    {
        if (!visited[next])
        {
            if (has_cycle_directed_helper(next, visited, on_rec_stack)) return true;
        }

        else if (on_rec_stack[next]) return true;
    }

    on_rec_stack[source] = false;
    return false;
}

template<typename T>
void graph_list<T>::transpose() 
{
    graph_list<T> tmp(this->_graph.size());

    for (int i = 0; i < _graph.size(); ++i)
    {
        for (int j = 0; j < _graph[i].size(); ++j)
        {
            tmp._graph[_graph[i][j]].push_back(i);
        }
    }
    _graph = std::move(tmp._graph);
}

template<typename T>  
size_t graph_list<T>::component_count() const
{
    size_t count = 0;
    std::vector<bool> visited(_graph.size(), false);
    std::stack<size_t> stack;
    
    for (int i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            ++count;
            stack.push(i);
            while (!stack.empty())
            {
                size_t curr = stack.top();
                stack.pop();
                visited[curr] = true;
                for (auto next : _graph[curr])
                {
                    if (!visited[next])
                    {
                        stack.push(next);
                        visited[next];
                    }
                }
            }
        }
    }
    return count;
}

template<typename T>
void graph_list<T>::dfs(size_t start, std::function<void(size_t)> callback) const
{
    if (start >= _graph.size()) throw std::out_of_range("vertex index is great");

    std::vector<bool> visited(_graph.size(), false);
    dfs_helper_recrusive(start, visited, callback);
    // dfs_helper_iterative(start, visited, callback);
}

template<typename T>
void graph_list<T>::dfs_extra_case(size_t start, std::function<void(size_t)> callback) const
{
    std::vector<bool> visited(_graph.size(), false);
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        if (!visited[i])
        {
            dfs_helper_recrusive(i, visited, callback);
        }
       std::cout << std::endl;
    }
}

template<typename T>
void graph_list<T>::dfs_helper_recrusive(size_t current, std::vector<bool>& visited, 
                                                         std::function<void(size_t)> callback) const
{
    visited[current] = true;

    callback(current);

    for (auto next : _graph[current])
    {
        if (!visited[next])
        {
            dfs_helper_recrusive(next, visited, callback);
        }
    }
}

template<typename T>
void graph_list<T>::dfs_helper_iterative(size_t start, std::vector<bool>& visited, 
                                                       std::function<void(size_t)> callback) const
{
    std::stack<size_t> stack;
    stack.push(start);
    visited[start] = true;

    while (!stack.empty())
    {
        size_t current = stack.top();
        callback(current);
        stack.pop();
        for (auto next : _graph[current])
        {
            if (!visited[next])
            {
                stack.push(next);
                visited[next] = true;
            }
        }
    }
}

template<typename T>
void graph_list<T>::bfs(size_t start, std::function<void(size_t)> callback) const
{
    if (start >= _graph.size()) throw std::out_of_range("vertex index is great");

    std::vector<bool> visited(_graph.size(), false);
    bfs_helper(start, visited, callback);
}

template<typename T>
void graph_list<T>::bfs_extra_case(size_t start, std::function<void(size_t)> callback) const
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
void graph_list<T>::bfs_helper(size_t start, std::vector<bool>& visited, std::function<void(size_t)> callback) const
{
    std::queue<size_t> queue;
    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        size_t current = queue.front();
        queue.pop();
        callback(current);

        for(auto next : _graph[current])
        {
            if (!visited[next])
            {
                queue.push(next);
                visited[next] = true;
            }
        }
    }
}

template<typename T>
size_t  graph_list<T>::vertex_count_in_level(size_t vertex, size_t level) const
{
    if (vertex >= _graph.size() || level >= _graph.size()) throw std::invalid_argument("args is not valid");
    std::vector<bool> visited(_graph.size(), false);
    std::queue<size_t> queue;
    queue.push(vertex);
    visited[vertex] = true;

    while (!queue.empty())
    {
        int size = queue.size();
        if (!level) return size;
        while (size--)
        {
            size_t current = queue.front();
            queue.pop();
            for(auto next : _graph[current])
            {
                if (!visited[next])
                {
                    queue.push(next);
                    visited[next] = true;
                }
            }       
        }
        --level;
    }
    return 0;   
}

template<typename T>
size_t graph_list<T>::shortest_path_two_vertex(size_t source, size_t destination) const
{
    if (source >= _graph.size() || destination >= _graph.size()) throw std::invalid_argument("args is not valid");

    std::vector<bool> visited(_graph.size(), false);
    std::queue<size_t> queue;
    size_t count = 0;
    queue.push(source);
    visited[source] = true;

    while (!queue.empty())
    {
        int size = queue.size();
        ++count;  
        while (size--)
        {
            size_t current = queue.front();
            queue.pop();

            for (auto next : _graph[current])
            {
                if (next == destination) return count;

                if (!visited[next])
                {
                    queue.push(next);
                    visited[next] = true;
                }
            }
        }
    }

    std::cout << "There is no path " << "from " << source << " to " << destination << "\n";
    return INT_MAX;
}

template<typename T>
std::vector<std::vector<int>> graph_list<T>::all_paths_two_vertex(size_t source, size_t destination) const
{
    if (source >= _graph.size() || destination >= _graph.size()) throw std::invalid_argument("args is not valid");
    std::vector<std::vector<int>> paths;
    std::vector<int> raw_path(_graph.size(), -1);
    std::vector<bool> visited(_graph.size(), false);
    all_paths_two_vertex_helper(source, destination, visited, raw_path, paths);
    
    return paths;
}

template<typename T>
void graph_list<T>::all_paths_two_vertex_helper(size_t source, 
                                                size_t destination, 
                                                std::vector<bool>& visited, 
                                                std::vector<int>& raw_path,
                                                std::vector<std::vector<int>>& paths) const
{
    visited[source] = true;     
    for (auto next : _graph[source])
    {
        if (!visited[next])
        {
            raw_path[next] = source;
            if (next == destination) 
            {
                paths.push_back(reconstruct(source, destination, raw_path));
            }
            else
            {
                all_paths_two_vertex_helper(next, destination, visited, raw_path, paths);
            }
        }
    }
    visited[source] = false;
}

template<typename T>
std::vector<int> graph_list<T>::reconstruct(size_t source, size_t destination, std::vector<int>& raw_path) const
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
std::vector<int> graph_list<T>::topological_sort() const
{
    if (has_cycle_directed()) throw std::logic_error("There is cycle in the graph");

    std::vector<bool> visited(_graph.size(), false);
    std::vector<int> result;

    //for (int i = 0; i < _graph.size(); ++i)
    //{
        //if (!visited[i] && _graph[i].size() == 0)
        //{
            topological_sort_helper(4, visited, result);
        //}
   // }
        
    return result;
}

template<typename T>
void graph_list<T>::topological_sort_helper(size_t source, std::vector<bool>& visited, std::vector<int>& result) const
{
    visited[source] = true;

    for (auto next : _graph[source])
    {
        if (!visited[next])
        {
            topological_sort_helper(next, visited, result);
        }
    }
    result.insert(result.begin(), source);
}

template<typename T>
std::vector<int> graph_list<T>::topological_sort_Kahns_algorithm() const
{

}

template<typename T>
void graph_list<T>::default_operation(size_t vertex) 
{
    std::cout << vertex << " ";
}

template<typename T>
void graph_list<T>::print_list() const
{
    for (size_t i = 0; i < _graph.size(); ++i)
    {
        std::cout << i << " ->";
        for (size_t j = 0; j < _graph[i].size(); ++j)
        {
            std::cout <<  "\033[1;32m" << " " << _graph[i][j] <<  "\033[0m" << " |"; 
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}