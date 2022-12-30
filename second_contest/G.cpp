#include <iostream>

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

int Front(Deque* deque) {
  if (deque->size == 0) {
    return -37;
  }
  return deque->first->value;
}

int Size(Deque* deque) {
  return deque->size;
}

void Clear(Deque* deque) {
  while (deque->first != nullptr) {
    PopFront(deque);
  }
}

int main() {
  int count = 0;
  int is_first_win = 0;
  int is_second_win = 0;
  auto* deck_first = new Deque;
  auto* deck_second = new Deque;
  for (int i = 0; i < 5; ++i) {
    int n;
    std::cin >> n;
    PushBack(deck_first, n);
  }
  for (int i = 0; i < 5; ++i) {
    int n;
    std::cin >> n;
    PushBack(deck_second, n);
  }
  while (true) {
    ++count;
    int var_first = Front(deck_first);
    int var_second = Front(deck_second);
    PopFront(deck_first);
    PopFront(deck_second);
    if (var_first == 0 && var_second == 9) {
      PushBack(deck_first, var_first);
      PushBack(deck_first, var_second);
    } else if (var_first == 9 && var_second == 0) {
      PushBack(deck_second, var_first);
      PushBack(deck_second, var_second);
    } else if (var_first > var_second) {
      PushBack(deck_first, var_first);
      PushBack(deck_first, var_second);
    } else {
      PushBack(deck_second, var_first);
      PushBack(deck_second, var_second);
    }
    if (Size(deck_first) == 0) {
      std::cout << "second";
      ++is_first_win;
      break;
    }
    if (Size(deck_second) == 0) {
      std::cout << "first";
      ++is_second_win;
      break;
    }
    if (count == 200000) {
      std::cout << "botva";
      break;
    }
  }
  if (is_first_win == 1 || is_second_win == 1) {
    std::cout << " " << count;
  }
  Clear(deck_first);
  delete deck_first;
  Clear(deck_second);
  delete deck_second;
  return 0;
}
