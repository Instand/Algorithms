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
        void insertRoot(const T& key, const Value& value) {
            insertRootImpl(&m_root, key, value);
        }

        void insert(const T& key, const Value& value) {
            Node** node = search(&m_root, key);

            if ((*node) == nullptr) {
                (*node) = new Node();
                (*node)->key = key;
            }

            (*node)->value = value;
        }

        void erase(const T& key) {
            eraseImpl(&m_root, key);
        }

        void join(cs::BinarySearchTree<T, Value, Comparer>& tree) {
            m_root = joinImpl(m_root, tree.m_root);
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

        const T& root() const {
            return m_root->key;
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

        void insertRootImpl(Node** node, const T& key, const Value& value) {
            if ((*node) == nullptr) {
                (*node) = new Node();
                (*node)->key = key;
                (*node)->value = value;

                return;
            }

            if ((*node)->key == key) {
                (*node)->value = value;
                return;
            }

            if ((*node)->key < key) {
                insertRootImpl(&((*node)->left), key, value);
                rotateRight(node);
            }
            else {
                insertRootImpl(&((*node)->right), key, value);
                rotateLeft(node);
            }
        }

        void rotateRight(Node** node) {
            if ((*node)->left == nullptr) {
                return;
            }

            auto x = (*node)->left;
            (*node)->left = x->right;
            x->right = (*node);
            (*node) = x;
        }

        void rotateLeft(Node** node) {
            if ((*node)->right == nullptr) {
                return;
            }

            auto x = (*node)->right;
            (*node)->right = x->left;
            x->left = (*node);
            (*node) = x;
        }

        Node** min(Node** node) {
            if ((*node)->left == nullptr) {
                return node;
            }

            return min(&((*node)->left));
        }

        Node* joinLR(Node* left, Node* right) {
            if (right == nullptr) {
                return left;
            }

            Node** node = min(&right);
            Node* root = (*node);
            (*node) = nullptr;

            root->left = left;
            root->right = right;

            return root;
        }

        void eraseImpl(Node** node, const T& key) {
            if ((*node) == nullptr) {
                return;
            }

            if (key < (*node)->key) {
                eraseImpl(&((*node)->left), key);
            }
            else if (key > (*node)->key) {
                eraseImpl(&((*node)->right), key);
            }
            else {
                Node* n = (*node);
                (*node) = joinLR((*node)->left, (*node)->right);
                delete n;
            }
        }

        Node* joinImpl(Node* left, Node* right) {
            if (right == nullptr) {
                return left;
            }

            if (left == nullptr) {
                return right;
            }

            insertRootImpl(&right, left->key, left->value);

            right->left = joinImpl(left->left, right->left);
            right->right = joinImpl(left->right, right->right);

            delete left;
            return right;
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
