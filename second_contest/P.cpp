#include <iostream>
#include <algorithm>

struct Node {
  int key;
  size_t height = 1;
  Node* left = nullptr;
  Node* right = nullptr;
};

class AVLTree {
 public:
  struct Node {
    int key;
    size_t height = 1;
    Node* left = nullptr;
    Node* right = nullptr;
  };
  AVLTree() : root_(nullptr) {
  }
  Node* root_ = nullptr;

  size_t Height(Node* node) {
    return node == nullptr ? 0 : node->height;
  }

  int Bfactor(Node* node) {
    return Height(node->right) - Height(node->left);
  }

  void FixHeight(Node* node) {
    int h_l = Height(node->left);
    int h_r = Height(node->right);
    node->height = std::max(h_l, h_r) + 1;
  }

  Node* Find(Node* node, int x) {
    if (node != nullptr) {
      if (x > node->key) {
        return Find(node->right, x);
      }
      if (x < node->key) {
        return Find(node->left, x);
      }
    }
    return node;
  }

  void Add(int x) {
    if (Find(root_, x) == nullptr) {
      root_ = Insert(root_, x);
    }
  }

  Node* RotateRight(Node* p) {
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    FixHeight(p);
    FixHeight(q);
    return q;
  }

  Node* RotateLeft(Node* q) {
    Node* p = q->right;
    q->right = p->left;
    p->left = q;
    FixHeight(q);
    FixHeight(p);
    return p;
  }

  Node* Balans(Node* p) {
    FixHeight(p);
    if (Bfactor(p) == 2) {
      if (Bfactor(p->right) == -1) {
        p->right = RotateRight(p->right);
      }
      return RotateLeft(p);
    }
    if (Bfactor(p) == -2) {
      if (Bfactor(p->left) == 1) {
        p->left = RotateLeft(p->left);
      }
      return RotateRight(p);
    }
    return p;
  }

  Node* Insert(Node* r, int k) {
    if (r == nullptr) {
      auto* cur = new Node;
      cur->key = k;
      return cur;
    }
    if (k < r->key) {
      r->left = Insert(r->left, k);
    } else {
      r->right = Insert(r->right, k);
    }
    return Balans(r);
  }

  Node* LowerBound(Node* node, int x) {
    if (node == nullptr) {
      return nullptr;
    }
    if (x > node->key) {
      return LowerBound(node->right, x);
    }
    Node* new_lowerbound = LowerBound(node->left, x);
    if (x < node->key && new_lowerbound != nullptr) {
      return new_lowerbound;
    }
    return node;
  }

  int FindLowerBound(int x) {
    if (LowerBound(root_, x) != nullptr) {
      return LowerBound(root_, x)->key;
    }
    return -1;
  }

  void Clear(Node* root) {
    if (root == nullptr) {
      return;
    }
    if (root->left != nullptr) {
      Clear(root->left);
    }
    if (root->right != nullptr) {
      Clear(root->right);
    }
    delete root;
  }
};

int main() {
  auto* tree = new AVLTree;
  int n;
  char command;
  char command_prev = '-';
  int64_t prev_result;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == '+') {
      int64_t val;
      std::cin >> val;
      if (command_prev == '?') {
        tree->Add((prev_result + val) % 1000000000);
      } else {
        tree->Add(val);
      }
    }
    if (command == '?') {
      int val;
      std::cin >> val;
      int find = tree->FindLowerBound(val);
      prev_result = find;
      std::cout << find << '\n';
    }
    command_prev = command;
  }
  tree->Clear(tree->root_);
  delete tree;
  return 0;
}
