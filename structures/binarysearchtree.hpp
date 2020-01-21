#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <stack>
#include <functional>

// does not allow multiple keys

namespace cs {
    template<typename T, typename Value, typename Comparer = std::less<T>>
    class BinarySearchTree {
        struct Node {
            Node* left;
            Node* right;
            T key;
            Value value;
        };

    public:
        void insert(const T& key, const Value& value) {
            Node** node = search(&m_root, key);

            if ((*node) == nullptr) {
                (*node) = new Node();
                (*node)->key = key;

                ++m_size;
            }

            (*node)->value = value;
        }

        bool contains(const T& key) const {
            Node** node = search(&m_root, key);
            return (*node) != nullptr;
        }

        template<typename Func>
        void visit(const Func& func) const {
            visitImpl(func, m_root);
        }

        template<typename Func>
        void nonRecursiveVisit(const Func& func) const {
            nonRecursiveVisitImpl(func, m_root);
        }

        size_t size() const {
            return m_size;
        }

    private:
        template<typename Func>
        void visitImpl(const Func& func, Node* node) const {
            if (node == nullptr) {
                return;
            }

            func(node->key, node->value);

            visitImpl(func, node->left);
            visitImpl(func, node->right);
        }

        template<typename Func>
        void nonRecursiveVisitImpl(const Func& func, Node* node) const {
            std::stack<Node*> stack;    // change to std::queue and rotate left right node pushing to implement level visit
            stack.push(node);

            while (!stack.empty()) {
                node = stack.top();
                stack.pop();

                func(node->key, node->value);

                if (node->right != nullptr) {
                    stack.push(node->right);
                }

                if (node->left != nullptr) {
                    stack.push(node->left);
                }
            }
        }

        Node** search(Node** node, const T& key) const {
            if (*node == nullptr || (*node)->key == key) {
                return node;
            }

            return (m_comparer((*node)->key, key) ? search(&((*node)->right), key) : search(&((*node)->left), key));
        }

        size_t m_size = 0;
        Node* m_root = nullptr;
        Comparer m_comparer = Comparer();
    };
}

#endif // BINARYSEARCHTREE_HPP
