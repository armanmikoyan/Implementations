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
void graph_matrix<T>::bfs(int v) const
{
    std::vector<bool> visited(_graph.size(), false);
    bfs_h(v, visited);
}

template<typename T>
void graph_matrix<T>::bfs_h(int v, std::vector<bool>& visited) const
{
    std::queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int front = q.front();
        std::cout << front << " ";
        q.pop();
        visited[front] = true;
        for (int curr = 0; curr < _graph.size(); ++curr)
        {
            if (_graph[front][curr])
            {
                if (!visited[curr])
                {
                    q.push(curr);
                    visited[curr] = true;
                }
            }
        }
    }
    std::cout << std::endl;
}

template<typename T>
void graph_matrix<T>::dfs(int v) const
{
    std::vector<bool> visited(_graph.size(), false);
    dfs_helper_recrusive(v, visited);
  //  dfs_helper_iterative(v, visited);
}

template<typename T>
void graph_matrix<T>::dfs_helper_recrusive(int v, std::vector<bool>& visited) const
{
    visited[v] = true;
    std::cout << v << "\n";
    for (int curr = 0; curr < _graph[v].size(); ++curr)
    {
        if (_graph[v][curr])
        {
            if (!visited[curr])
            {
                dfs_helper_recrusive(curr, visited);
            }
        }
    }
}

template<typename T>
void graph_matrix<T>::dfs_helper_iterative(int v, std::vector<bool>& visited) const
{
    std::stack<int> stack;
 
    visited[v] = true;
    stack.push(v);

    while (!stack.empty())
    {
        int top = stack.top();
        stack.pop();
        std::cout << top << "\n";

        for (int curr = 0; curr < _graph.size(); ++curr)
        {
            if (_graph[top][curr] && !visited[curr])
            {
                stack.push(curr);
                visited[curr] = true;
            }
        }
    }
}

template<typename T>
void graph_matrix<T>::add_edge(size_t u, size_t v)
{
    if (u >= _graph.size() || v >= _graph.size()) throw std::out_of_range("Vertex index out of range");

    _graph[u][v] = 1;
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
