#include <iostream>

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int64_t value = 0;
};

class BST {
 public:
  Node* root = nullptr;
  int64_t all_height = 0;
  Node* Insert(int64_t, Node*);
  void Clear(Node*);
  void ShowTree(const Node*);
};

Node* BST::Insert(int64_t val, Node* prev_node) {
  auto new_node = new Node;
  new_node->value = val;
  Node* parent = nullptr;
  Node* now = root;
  if (prev_node == nullptr) {
    while (now != nullptr) {
      parent = now;
      if (val > now->value) {
        now = now->right;
      } else {
        now = now->left;
      }
    }
    new_node->parent = parent;
    if (parent == nullptr) {
      root = new_node;
      return new_node;
    }
    if (val > parent->value) {
      parent->right = new_node;
    } else {
      parent->left = new_node;
    }
    return new_node;
  }
  prev_node->left = new_node;
  return new_node;
}

void BST::Clear(Node* root) {
  if (root == nullptr) {
    return;
  }
  if (root->right != nullptr) {
    BST::Clear(root->right);
  }
  if (root->left != nullptr) {
    BST::Clear(root->left);
  }
  delete root;
}

void BST::ShowTree(const Node* root) {
  if (root == nullptr) {
    return;
  }
  ShowTree(root->left);
  ShowTree(root->right);
  std::cout << root->value << " ";
}

int main() {
  auto* tree = new BST;
  int all;
  int element = -1000000014;
  int prev_element;
  Node* ptr = nullptr;
  std::cin >> all;
  for (int64_t i = 0; i < all; ++i) {
    prev_element = element;
    std::cin >> element;
    if (prev_element > element) {
      ptr = tree->Insert(element, ptr);
    } else {
      ptr = nullptr;
      tree->Insert(element, ptr);
    }
  }
  tree->ShowTree(tree->root);
  Node* root = tree->root;
  tree->Clear(root);
  delete tree;
  return 0;
}
