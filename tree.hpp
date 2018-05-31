
#include "iterator.hpp"
#include <initializer_list>

namespace BSTree {

template <typename T>
class Tree {
public:
    //using iterator = pre_order::iterator;
    //using reverse_iterator = post_order::iterator;

    Tree(std::initializer_list<T>);
    auto begin() -> pre_iterator<T>;
    auto end() -> pre_iterator<T>;

    auto rbegin() -> post_iterator<T>;
    auto rend() -> post_iterator<T>;
    auto push_back(const T&) -> void;
    //auto print_(Node<T>* curr, int level, T root_data) -> void;
    auto print_tree() -> void; 
private:
    Node<T>* root;
};

template <typename T>
auto Tree<T>:: begin() -> pre_iterator <T> {
    Node <T>* curr=root;
    while (curr->left!=nullptr)
    curr=curr->left;
    pre_iterator<T> beg (curr);
    return beg;
}

template <typename T>
auto Tree<T>:: rbegin() -> post_iterator <T> {
    Node<T> * curr = root;
    while(curr->right!=nullptr) 
curr= curr->right;
 post_iterator<T> rbegin (curr);
return rbegin;
}

template <typename T>
auto Tree<T>:: rend() -> post_iterator <T> {
    post_iterator<T> rend (nullptr);
    return rend;
}


template <typename T>
auto Tree<T>:: end() -> pre_iterator <T> {
    pre_iterator<T> end (nullptr);
    return end;
}


template <typename T>
auto print_(Node<T>* curr, int level, T root_data) -> void {
    if (curr != nullptr) {
        if (curr->right != nullptr) {
            print_(curr->right, level + 1, root_data);
        }
        for (unsigned i = 0; i < level; ++i) std::cout << "   ";
        if (curr->data != root_data) {
            std::cout << "--";
        }
        std::cout << curr->data << std::endl;
        if (curr->left != nullptr) {
            print_(curr->left, level + 1, root_data);
        }
    }
}

template <typename T>
auto Tree<T>::print_tree() -> void {
    print_(root, 0, root->data);
}


template <typename T>
auto Tree<T>:: push_back (const T& value) -> void {
    if (root == nullptr) {
        root = new Node<T> {value,nullptr,nullptr,nullptr};
        return ;
    }
    Node<T> * parent= root;
    Node<T> * curr= root;
    while ( curr != nullptr) {
        if (curr->data < value) curr= curr->right;
        else curr= curr->left;
        if (curr!=nullptr) parent= curr;
    }
    if (parent->data< value) {parent->right = new Node <T> {value, 
nullptr, nullptr, parent};}
    else {parent->left = new Node<T> {value, nullptr, nullptr, parent};}
}

template <typename T>
Tree<T>:: Tree (std::initializer_list<T> list) {
    root=nullptr;
    for (auto value:list) {
        push_back(value);
    }
}

}

