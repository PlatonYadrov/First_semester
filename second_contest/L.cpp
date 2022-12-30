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
  void Insert(int64_t val) {
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

  void Clear(Node* root) {
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
};

int main() {
  auto* tree = new BST;
  int element;
  std::cin >> element;
  while (element != 0) {
    tree->Insert(element);
    std::cin >> element;
  }
  std::cout << tree->all_height;
  Node* root = tree->root;
  tree->Clear(root);
  delete tree;
  return 0;
}
