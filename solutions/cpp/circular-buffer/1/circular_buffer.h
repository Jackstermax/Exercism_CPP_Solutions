#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <stdexcept>
#include <vector>
namespace circular_buffer {

template<typename T>
class circular_buffer
{
private:    
    std::size_t m_begin {}; // Head
    std::size_t m_end {};   // Tail
    std::size_t m_length {};
    std::vector<T> m_data {};
public:
    circular_buffer(std::size_t size) : m_begin{0}, m_end{0}, m_length{0}, m_data(size)
    {}
    ~circular_buffer() = default;

    // Getters
    bool is_empty() const noexcept { return m_length == 0; }
    bool is_full()  const noexcept { return m_length == m_data.size(); }
    
    T read();
    void write(const T& data);
    void overwrite(const T& data);
    void clear();
};

// Template class compilation, as functions are in the .cpp, not needed if all are declared in the header
template class circular_buffer<int>;          
template class circular_buffer<std::string>;
}  // namespace circular_buffer
#endif