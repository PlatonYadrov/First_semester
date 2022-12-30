#include <iostream>
#include <cstring>

struct Node {
  Node* prev = nullptr;
  Node* next = nullptr;
  int value;
};

struct Deque {
  Node* first = nullptr;
  Node* last = nullptr;
  size_t size = 0;
};

void PushFront(Deque* deque, int val) {
  auto new_node = new Node;
  new_node->value = val;
  if (deque->size == 0) {
    deque->first = new_node;
    deque->last = new_node;
    ++deque->size;
    return;
  }
  if (deque->size == 1) {
    new_node->next = deque->last;
    deque->first = new_node;
    deque->last->prev = deque->first;
    ++deque->size;
    return;
  }
  new_node->next = deque->first;
  deque->first->prev = new_node;
  deque->first = new_node;
  ++deque->size;
}

void PushBack(Deque* deque, int val) {
  auto new_node = new Node;
  new_node->value = val;
  if (deque->size == 0) {
    deque->last = new_node;
    deque->first = new_node;
    ++deque->size;
    return;
  }
  if (deque->size == 1) {
    new_node->prev = deque->first;
    deque->last = new_node;
    deque->first->next = deque->last;
    ++deque->size;
    return;
  }
  new_node->prev = deque->last;
  deque->last->next = new_node;
  deque->last = new_node;
  ++deque->size;
}

void PopFront(Deque* deque) {
  if (deque->size == 0) {
    return;
  }
  Node* first_for_delete = deque->first;
  if (deque->size == 1) {
    delete first_for_delete;
    deque->last = nullptr;
    deque->first = nullptr;
  } else {
    deque->first->prev = nullptr;
    deque->first = deque->first->next;
    delete first_for_delete;
  }
  --deque->size;
}

void PopBack(Deque* deque) {
  if (deque->size == 0) {
    return;
  }
  Node* last_for_delete = deque->last;
  if (deque->size == 1) {
    delete last_for_delete;
    deque->last = nullptr;
    deque->first = nullptr;
  } else {
    deque->last = deque->last->prev;
    deque->last->next = nullptr;
    delete last_for_delete;
  }
  --deque->size;
}

int Front(const Deque* deque) {
  if (deque->size == 0) {
    return -37;
  }
  return deque->first->value;
}

int Back(const Deque* deque) {
  if (deque->size == 0) {
    return -37;
  }
  return deque->last->value;
}

int Size(const Deque* deque) {
  return deque->size;
}

void Clear(Deque* deque) {
  while (deque->last != nullptr) {
    PopBack(deque);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  int all_person = 0;
  auto* command = new char[2];
  auto* deque_left = new Deque;
  auto* deque_right = new Deque;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (std::strcmp("+", command) == 0) {
      ++all_person;
      int val;
      std::cin >> val;
      PushBack(deque_right, val);
      if (Size(deque_left) < (all_person + 1) / 2) {
        int temp = deque_right->first->value;
        PopFront(deque_right);
        PushBack(deque_left, temp);
      }
    }
    if (std::strcmp("-", command) == 0) {
      --all_person;
      std::cout << Front(deque_left) << '\n';
      PopFront(deque_left);
      if (Size(deque_left) < (all_person + 1) / 2) {
        int temp = deque_right->first->value;
        PopFront(deque_right);
        PushBack(deque_left, temp);
      }
    }
    if (std::strcmp("*", command) == 0) {
      ++all_person;
      int val;
      std::cin >> val;
      PushFront(deque_right, val);
      if (Size(deque_left) < (all_person + 1) / 2) {
        int temp = deque_right->first->value;
        PopFront(deque_right);
        PushBack(deque_left, temp);
      }
    }
  }
  Clear(deque_left);
  delete deque_left;
  Clear(deque_right);
  delete deque_right;
  delete[] command;
}
