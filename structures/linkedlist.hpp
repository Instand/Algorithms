#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <cstdlib>
#include <iterator>
#include <memory>

namespace cs {
    // classic linked list with fictive head and tail links
    template<typename T>
    class LinkedList {
    private:
        struct Node {
            Node* next = nullptr;
            Node* previous = nullptr;
            T data;
        };

        using Type = std::remove_cv<T>;
        using IteratorBase = std::iterator<std::bidirectional_iterator_tag, Type>;  // deprecated in C++17

        class Iterator : public IteratorBase {
        public:
            Iterator() = default;
            explicit Iterator(Node* node):m_node(node) {}

            T& operator*() {
                return m_node->data;
            }

            bool operator==(const Iterator& iterator) {
                return iterator.m_node == m_node;
            }

            bool operator!=(const Iterator& iterator) {
                return !((*this) == iterator);
            }

            auto& operator++() {
                if (m_node) {
                    m_node = m_node->next;
                }

                return *this;
            }

            auto& operator --() {
                if (m_node) {
                    m_node = m_node->previous;
                }

                return *this;
            }

        private:
            mutable Node* m_node = nullptr;

            template<typename K>
            friend class LinkedList;
        };

    public:
        using iterator = Iterator;
        using const_iterator = const Iterator;
        using value_type = T;

        iterator begin() {
            return Iterator(m_head->next);
        }

        iterator end() {
            return Iterator(m_tail);
        }

        const_iterator begin() const {
            return (const_cast<LinkedList*>(this))->begin();
        }

        const_iterator end() const {
            return (const_cast<LinkedList*>(this))->end();
        }

        size_t size() const {
            return m_size;
        }

        LinkedList() {
            defaultState();
        }

        ~LinkedList() {
            clear();

            delete m_head;
            delete m_tail;
        }

        void clear() {
            auto head = m_head->next;
            while (head->next && head != m_tail) {
                auto next = head->next;
                delete head;
                head = next;
            }

            defaultState();
            m_size = 0;
        }

        void pushBack(const T& element) {
            Node* node = new Node();
            node->data = element;

            pushBack(node);
        }

        void pushFront(const T& element) {
            Node* node = new Node();
            node->data = element;

            pushFront(node);
        }

        void insert(iterator iterator, const T& value) {
            Node* node = new Node();
            node->data = value;

            if (m_size != 0) {
                if (iterator == begin()) {
                    pushFront(node);
                    return;
                }
                else if (iterator == end()) {
                    pushBack(node);
                    return;
                }

                Node* currentNode = iterator.m_node;

                if (m_head->next == currentNode) {
                    m_head->next = currentNode;
                }
                else if (m_tail->previous == currentNode) {
                    m_tail->previous = currentNode;
                }

                node->next = currentNode;
                node->previous = currentNode->previous;

                currentNode->previous = node;
            }
            else {
                firstAdd(node);
            }

            m_size++;
        }

        void popFront() {
            if (size() == 0 ) {
                return;
            }
            else if (size() == 1) {
                delete m_head->next;
                defaultState();
            }
            else {
                auto next = m_head->next->next;
                delete m_head->next;

                m_head->next = next;
                next->previous = m_head;
            }

            m_size--;
        }

        void popBack() {
            if (size() == 0) {
                return;
            }
            else if (size() == 1) {
                delete m_tail->previous;
                defaultState();
            }
            else {
               auto previous = m_tail->previous->previous;
               delete m_tail->previous;
               m_tail->previous = previous;
               previous->next = m_tail;
            }

            m_size--;
        }

        void erase(iterator iterator) {
            if (m_size == 0) {
                return;
            }

            if (iterator == begin()) {
                popFront();
                return;
            }

            if (iterator == (--end())) {
                popBack();
                return;
            }

            Node* node = iterator.m_node;

            if (m_head->next == m_tail->previous) {
                defaultState();
            }
            else {
                auto next = node->next;
                auto previous = node->previous;

                previous->next = next;
                next->previous = previous;
            }

            delete node;
            --m_size;
        }

        void reverse() {
            if (size() < 2) {
                return;
            }

            auto next = m_tail->previous;
            while (next != m_head) {
                std::swap(next->previous, next->next);
                next = next->next;
            }

            std::swap(m_head, m_tail);

            m_head->next = m_head->previous;
            m_head->previous = nullptr;

            m_tail->previous = m_tail->next;
            m_tail->next = nullptr;
        }

    private:
        Node* m_head = new Node();
        Node* m_tail = new Node();
        size_t m_size = 0;

        void pushFront(Node* node) {
            if (m_size != 0) {
                node->next = m_head->next;
                node->previous = m_head;

                m_head->next->previous = node;
                m_head->next = node;
            }
            else {
                firstAdd(node);
            }

            m_size++;
        }

        void pushBack(Node* node) {
            if (m_size != 0) {
                node->next = m_tail;
                node->previous = m_tail->previous;

                m_tail->previous->next = node;
                m_tail->previous = node;
            }
            else {
                firstAdd(node);
            }

            m_size++;
        }

        void firstAdd(Node* node) {
            node->next = m_tail;
            node->previous = m_tail->previous;

            m_tail->previous->next = node;
            m_tail->previous = node;
        }

        void defaultState() {
            m_head->next = m_tail;
            m_tail->previous = m_head;
        }
    };
}

#endif // LINKEDLIST_HPP
