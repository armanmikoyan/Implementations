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