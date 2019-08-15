#ifndef FORWARDLIST_HPP
#define FORWARDLIST_HPP

#include <iterator>

namespace cs {
    // similar to std::forward_list
    template <typename T>
    class ForwardList {
        struct Node;

        using Pointer = ForwardList*;

        class Iterator : public std::iterator<std::forward_iterator_tag, std::remove_cv_t<T>> {
        public:
            Iterator() = default;
            Iterator(Node* node):m_node(node) {}

            T& operator*() {
                return m_node->data;
            }

            const T& operator*() const {
                return m_node->data;
            }

            Iterator& operator++() {
                if (m_node) {
                    m_node = m_node->next;
                }

                return *this;
            }

            bool operator==(const Iterator& iter) {
                return iter.m_node == m_node;
            }

            bool operator!=(const Iterator& iter) {
                return !((*this) == iter);
            }

        private:
            Node* m_node = nullptr;
        };

    public:
        using value_type = T;
        using iterator = Iterator;
        using const_iterator = const iterator;

        ~ForwardList() {
            clear();
        }

        void clear() {
            Node* current = m_head;

            while (current != nullptr) {
                Node* next = current->next;
                delete current;

                current = next;
            }

            defaultState();
        }

        void pushFront(const T& value) {
            Node* node = new Node { m_head, value };

            m_head = node;
            ++m_size;
        }

        iterator begin() {
            return iterator(m_head);
        }

        const_iterator begin() const {
            return (const_cast<Pointer>(this))->begin();
        }

        iterator end() {
            return iterator(nullptr);
        }

        const_iterator end() const {
            return (const_cast<Pointer>(this))->end();
        }

        size_t size() const {
            return m_size;
        }

        bool isEmpty() const {
            return size() == 0;
        }

    private:
        void defaultState() {
            m_head = nullptr;
            m_size = 0;
        }

        struct Node {
            Node* next = nullptr;
            T data;
        };

        Node* m_head = nullptr;
        size_t m_size = 0;
    };
}

#endif // FORWARDLIST_HPP
