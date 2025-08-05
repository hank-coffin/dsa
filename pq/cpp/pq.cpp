#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdint>
#include <climits>

using namespace std;

template<typename T>
struct EL {
    enum class Some { Some, None };
    Some    some;
    T       val;
    
    // Helper function to check if element has a value
    bool hasValue() const { return some == Some::Some; }
    bool isEmpty() const { return some == Some::None; }
};

template<typename T>
class PQ { 
public:
    PQ() : m_pq(32, {EL<T>::Some::None, T()}), num_elements(0) {
        
    }

    void insert(T value) {
        cout << "Inserting " << value << "\n";
    }

    T getMax() {
        if ( num_elements > 0 ) {
            return m_pq[0].val;
        }
        return T(); 
    }

    bool isEmpty() const {
        return num_elements == 0;
    }

private:
    size_t find_pos( T value )
    {
        size_t pos = 0;
        bool searching = true;

        while ( searching ) {
            if ( m_pq[pos].isEmpty() ) {
                return pos;  
            }
            pos++;
            if (pos >= m_pq.size()) {
                searching = false;
            }
        }
        return SIZE_MAX;  // No position found
    }
    
    size_t get_parent( size_t pos ) {
        return pos == 0 ? SIZE_MAX : pos / 2;
    }

    size_t get_left_child( size_t pos ) {
        const size_t child_pos = pos * 2;
        return (child_pos > m_pq.size()-1) ? SIZE_MAX : child_pos;
    }
    
    size_t get_right_child( size_t pos ) {
        const size_t child_pos = pos * 2 + 1;
        return (child_pos > m_pq.size()-1) ? SIZE_MAX : child_pos;
    }

    vector<EL<T>> m_pq;
    size_t num_elements;
};

int main() {

    std::cout << "Priority Queue Exercise" << std::endl;

    PQ<int32_t> pq;

    pq.insert(100);
    pq.insert(50);
    pq.insert(40);
    pq.insert(30);

    return 0;
}