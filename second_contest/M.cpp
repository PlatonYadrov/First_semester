#include <iostream>

struct Node {
  Node* left = nullptr;
  Node* right = nullptr;
  Node* parent = nullptr;
  int64_t value = 0;
};

struct BST {
  Node* root = nullptr;
  int64_t all_height = 0;
  void Insert(int64_t);
  void Clear(Node* root);
  void ShowTree(Node*, int64_t*, int64_t*);
};

void BST::Insert(int64_t val) {
  int64_t temp_height = 1;
  auto new_node = new Node;
  new_node->value = val;
  Node* parent = nullptr;
  Node* now = root;
  while (now != nullptr) {
    parent = now;
    if (val == now->value) {
      now = nullptr;
      parent = nullptr;
      delete new_node;
      return;
    }
    if (val > now->value) {
      now = now->right;
    } else {
      now = now->left;
    }
    ++temp_height;
  }
  new_node->parent = parent;
  if (parent == nullptr) {
    root = new_node;
    all_height = 1;
    return;
  }
  if (val > parent->value) {
    parent->right = new_node;
  } else {
    parent->left = new_node;
  }
  if (temp_height > all_height) {
    all_height = temp_height;
  }
}

void BST::ShowTree(Node* root, int64_t* p, int64_t* arr) {
  if (root == nullptr) {
    return;
  }
  ShowTree(root->left, p, arr);
  arr[(*p)] = root->value;
  (*p)++;
  ShowTree(root->right, p, arr);
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

int main() {
  auto* tree = new BST;
  int element;
  std::cin >> element;
  int64_t i = 0;
  for (i = 0; element != 0; ++i) {
    tree->Insert(element);
    std::cin >> element;
  }
  auto* arr = new int64_t[i];
  int64_t p = 0;
  tree->ShowTree(tree->root, &p, arr);
  std::cout << arr[p - 2];
  Node* root = tree->root;
  tree->Clear(root);
  delete tree;
  delete[] arr;
  return 0;
}
