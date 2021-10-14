/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <queue>

using namespace std;

template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    // your code here
    Node * temp_right = t->right;
    Node * temp = temp_right->left;
    t->right = temp;
    temp_right->left = t;
    t->height = 1 + max(heightOrNeg1(t->left),heightOrNeg1(t->right));
    t = temp_right;
    t->height = 1 + max(heightOrNeg1(t->left),heightOrNeg1(t->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    Node * temp_left = t->left;
    Node * temp = temp_left->right;
    t->left = temp;
    temp_left->right = t;
    t->height = 1 + max(heightOrNeg1(t->left),heightOrNeg1(t->right));
    t = temp_left;
    t->height = 1 + max(heightOrNeg1(t->left),heightOrNeg1(t->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // your code here
    rotateRight(t->right);
    rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    if (subtree == NULL) {
      return;
    }

    int b = (heightOrNeg1(subtree->left)-heightOrNeg1(subtree->right));
    if (b == -2) {
      int b_left = (heightOrNeg1(subtree->right->left)-heightOrNeg1(subtree->right->right));
      if (b_left < 0) {
        rotateLeft(subtree);
      } else {
        rotateRightLeft(subtree);
      }
    }
    if (b == 2) {
      int b_right = (heightOrNeg1(subtree->left->left)-heightOrNeg1(subtree->left->right));
      if (b_right > 0) {
        rotateRight(subtree);
      } else {
        rotateLeftRight(subtree);
      }
    }
    subtree->height = 1 + std::max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right));

}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
    if (subtree == NULL) {
        Node * temp = new Node(key, value);
        subtree = temp;
    }

    else if (key < subtree->key) {
      insert(subtree->left, key, value);
    }

    else if (key >= subtree->key) {
      insert(subtree->right, key, value);
    }

    rebalance(subtree);
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        remove(subtree->left, key);
    } else if (key > subtree->key) {
        remove(subtree->right, key);
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            delete subtree;
            subtree = NULL;
        } else if (subtree->left != NULL && subtree->right != NULL) {

            Node * temp = subtree->left;
            while (temp->right != NULL) {
              temp = temp->right;
            }
            swap(subtree, temp);
            remove(subtree->left, key);
        } else {
            Node * right = subtree->right;
            Node * left = subtree->left;
            if (left != NULL) {
              delete subtree;
              subtree = left;
            }
            else if (right != NULL) {
              delete subtree;
              subtree = right;
            } else {
              delete subtree;
              subtree = NULL;
            }
        }
    }
    rebalance(subtree);
}
