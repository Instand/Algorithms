#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <vector>
#include <structures/heap.hpp>

namespace cs {
    template <typename T, typename Container = std::vector<T>>
    class PriorityQueue {
    public:
        using iterator = typename Container::iterator;
        using const_iterator = typename Container::const_iterator;
        using value_type = typename Container::value_type;

        iterator begin() {
            return m_data.begin();
        }

        iterator end() {
            return m_data.end();
        }

        const_iterator begin() const {
            return m_data.begin();
        }

        const_iterator end() const {
            return m_data.end();
        }

        bool isEmpty() const {
            return std::empty(m_data);
        }

        size_t size() const {
            return std::size(m_data);
        }

        void push(const T& value) {
            m_data.push_back(value);
            Heap::fixUp(m_data.begin(), m_data.end());
        }

        T top() const {
            return m_data.front();
        }

        void pop() {
            if (!m_data.empty()) {
                std::iter_swap(begin(), std::prev(end()));
            }

            m_data.pop_back();

            Heap::fixDown(m_data.begin(), m_data.end());
        }

    private:
        Container m_data;
    };
}

#endif // PRIORITYQUEUE_HPP
