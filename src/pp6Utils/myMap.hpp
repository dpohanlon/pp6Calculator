#ifndef MYMAP_H
#define MYMAP_H

namespace MyMap {

template<typename K, typename V>
struct Node
{
    Node(K iKey, V iVal) : key(iKey), value(iVal) { }

    K key;
    V value;

    Node * left = nullptr;
    Node * right = nullptr;
};

template<typename K, typename V>
struct Map
{ 
    Node<K, V> * root = new Node<K, V>(K(), V());

    ~Map(void) { removeChildren(root); }
};

template<typename K, typename V>
void removeChildren(Node<K, V> * node)
{
    if (node->left != nullptr) removeChildren(node->left);
    if (node->right != nullptr) removeChildren(node->right);
    delete node;
    node = nullptr;
}

template<typename K, typename V>
void insert(Node<K, V> * node, K key, V value)
{
    if (key < node->key) {
        if (node->left == nullptr){
            node->left = new Node<K, V>(key, value);
        }
        else insert(node->left, key, value);
    }
    else {
        if (node->right == nullptr) { 
            node->right = new Node<K, V>(key, value);
        }
        else insert(node->right, key, value);
    }
}

template<typename K, typename V>
void insert(Map<K, V> * m, K key, V value)
{
    insert(m->root, key, value);
}

template<typename K, typename V>
Node<K, V> * find(Node<K, V> * node, K key)
{
    if (node == nullptr) return nullptr;
    if (key > node->key) return find(node->right, key);
    else if (key < node->key) return find(node->left, key);
    else return node; 
}

template<typename K, typename V>
V get(Map<K, V> * m, K key)
{
    // Returns nullptr if not found

    Node<K, V> * node = find(m->root, key);
    return (node != nullptr) ? node->value : nullptr;
}

} // namespace MyMap

#endif
