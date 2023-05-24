// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <algorithm>

template <typename T>
class BST {
 private:
  struct Node {
    T key;
    int count;
    Node* left, *right;
    explicit Node(T k): key(k), count(1), left(nullptr), right(nullptr) {}
  };
  Node* root;
  Node* addNode(Node*, const T&);
  int heightTree(Node*);
  int searchTree(Node*, const T&);
 public:
  BST(): root(nullptr) {}
  void add(const T&);
  int height();
  int search(const T&);
};

template <typename T>
typename BST<T>::Node* BST<T>::addNode(Node* root, const T& val) {
  if (root == nullptr) {
    p = new Node(val);
  } else if (root->key > val) {
    root->left = addNode(root->left, val);
  } else if (root->key < val) {
    root->right = addNode(root->right, val);
  } else {
    root->count++;
  }
  return root;
}

template <typename T>
void BST<T>::add(const T& val) {
  root = addNode(root, val);
}

template <typename T>
int BST<T>::heightTree(Node* root) {
  if (root == nullptr) {
    return 0;
  }
  return 1 + std::max(heightTree(root->left), heightTree(root->right));
}

template <typename T>
int BST<T>::height() {
  return heightTree(root) - 1;
}

template <typename T>
int BST<T>::searchTree(Node* root, const T& val) {
  if (root == nullptr) {
    return 0;
  } else if (root->key == val) {
    return root->count;
  } else if (root->key < val) {
    return searchTree(root->right, val);
  }
  return searchTree(root->left, val);
}

template <typename T>
int BST<T>::search(const T& val) {
  return searchTree(root, val);
}

#endif  // INCLUDE_BST_H_
