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

int Front(Deque* deque) {
  if (deque->size == 0) {
    return -37;
  }
  return deque->first->value;
}

int Back(Deque* deque) {
  if (deque->size == 0) {
    return -37;
  }
  return deque->last->value;
}

int Size(Deque* deque) {
  return deque->size;
}

void Clear(Deque* deque) {
  while (deque->last != nullptr) {
    PopBack(deque);
  }
}

int main() {
  int n;
  auto* command = new char[120];
  auto* deque = new Deque;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (std::strcmp("push_front", command) == 0) {
      int value;
      std::cin >> value;
      PushFront(deque, value);
      std::cout << "ok\n";
    } else if (std::strcmp("push_back", command) == 0) {
      int value;
      std::cin >> value;
      PushBack(deque, value);
      std::cout << "ok\n";
    } else if (std::strcmp("pop_front", command) == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Front(deque) << '\n';
      PopFront(deque);
    } else if (std::strcmp("pop_back", command) == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Back(deque) << '\n';
      PopBack(deque);
    } else if (std::strcmp("front", command) == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Front(deque) << '\n';
    } else if (std::strcmp("back", command) == 0) {
      if (Size(deque) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Back(deque) << '\n';
    } else if (std::strcmp("size", command) == 0) {
      std::cout << Size(deque) << '\n';
    } else if (std::strcmp("clear", command) == 0) {
      Clear(deque);
      std::cout << "ok\n";
    } else if (std::strcmp("exit", command) == 0) {
      std::cout << "bye\n";
      break;
    }
  }
  Clear(deque);
  delete deque;
  delete[] command;
}
