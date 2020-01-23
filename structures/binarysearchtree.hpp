#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <stack>
#include <functional>

// does not allow multiple keys
// size realizaed as recursive version

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
            return sizeImpl(m_root);
        }

        size_t height() const {
            auto h = heightImpl(m_root);
            return h == -1 ? 0 : static_cast<size_t>(h);
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

            return (m_comparer(key, (*node)->key) ? search(&((*node)->left), key) : search(&((*node)->right), key));
        }

        size_t sizeImpl(Node* node) const {
            if (node == nullptr) {
                return 0;
            }

            return sizeImpl(node->left) + sizeImpl(node->right) + 1;
        }

        int heightImpl(Node* node) const {
            if (node == nullptr) {
                return -1;
            }

            auto left = heightImpl(node->left);
            auto right = heightImpl(node->right);

            return (left > right) ? left + 1 : right + 1;
        }

        Node* m_root = nullptr;
        Comparer m_comparer = Comparer();
    };
}

#endif // BINARYSEARCHTREE_HPP
