#include "circular_buffer.h"

namespace circular_buffer {
template<typename T>
T circular_buffer<T>::read() {
    if (is_empty()) { throw std::domain_error("Error: Buffer empty, cannot read."); }
    T value = m_data[m_begin];
    m_begin = (m_begin+1) % m_data.size();
    --m_length;
    return value;
}
template<typename T>
void circular_buffer<T>::write(const T& val) {
    if (is_full()) { throw std::domain_error("Error: Buffer full, cannot write."); }
    m_data[m_end] = val;
    m_end = (m_end+1) % m_data.size();        
    ++m_length;
}
template<typename T>
void circular_buffer<T>::overwrite(const T& val) { 
    if (is_full()) {
        m_data[m_end] = val;
        m_end   = (m_end + 1)   % m_data.size();
        m_begin = (m_begin + 1) % m_data.size();
    }
    else { write(val); }
}
template<typename T>  
void circular_buffer<T>::clear() {    
    m_length = 0;
    m_begin  = 0;
    m_end    = 0;
}
}  // namespace circular_buffer