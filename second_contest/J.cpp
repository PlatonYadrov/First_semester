#include <iostream>
#include <cstring>

struct Node {
  Node* prev = nullptr;
  Node* next = nullptr;
  int value;
};

struct Queue {
  Node* first = nullptr;
  Node* last = nullptr;
  size_t size = 0;
};

void Enqueue(Queue* queue, int val) {
  auto new_node = new Node;
  new_node->value = val;
  if (queue->size == 0) {
    queue->last = new_node;
    queue->first = new_node;
    ++queue->size;
    return;
  }
  if (queue->size == 1) {
    new_node->prev = queue->first;
    queue->last = new_node;
    queue->first->next = queue->last;
    ++queue->size;
    return;
  }
  new_node->prev = queue->last;
  queue->last->next = new_node;
  queue->last = new_node;
  ++queue->size;
}

void Dequeue(Queue* queue) {
  if (queue->size == 0) {
    return;
  }
  Node* first_for_delete = queue->first;
  if (queue->size == 1) {
    delete first_for_delete;
    queue->last = nullptr;
    queue->first = nullptr;
  } else {
    queue->first->prev = nullptr;
    queue->first = queue->first->next;
    delete first_for_delete;
  }
  --queue->size;
}

void PopBack(Queue* queue) {
  if (queue->size == 0) {
    return;
  }
  Node* last_for_delete = queue->last;
  if (queue->size == 1) {
    delete last_for_delete;
    queue->last = nullptr;
    queue->first = nullptr;
  } else {
    queue->last = queue->last->prev;
    queue->last->next = nullptr;
    delete last_for_delete;
  }
  --queue->size;
}

int Front(Queue* queue) {
  if (queue->size == 0) {
    return -37;
  }
  return queue->first->value;
}

int Back(Queue* queue) {
  if (queue->size == 0) {
    return -37;
  }
  return queue->last->value;
}

int Size(Queue* queue) {
  return queue->size;
}

void Clear(Queue* queue) {
  while (queue->first != nullptr) {
    Dequeue(queue);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n;
  auto* command = new char[120];
  auto* queue = new Queue;
  auto* deque = new Queue;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (std::strcmp("enqueue", command) == 0) {
      int value;
      std::cin >> value;
      Enqueue(queue, value);
      while (Size(deque) > 0 && Back(deque) > value) {
        PopBack(deque);
      }
      Enqueue(deque, value);
      std::cout << "ok\n";
    } else if (std::strcmp("dequeue", command) == 0) {
      if (Size(queue) == 0) {
        std::cout << "error\n";
        continue;
      }
      int del = Front(queue);
      std::cout << del << '\n';
      Dequeue(queue);
      if (Front(deque) == del) {
        Dequeue(deque);
      }
    } else if (std::strcmp("front", command) == 0) {
      if (Size(queue) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Front(queue) << '\n';
    } else if (std::strcmp("size", command) == 0) {
      std::cout << Size(queue) << '\n';
    } else if (std::strcmp("clear", command) == 0) {
      Clear(queue);
      std::cout << "ok\n";
      Clear(deque);
    }
    if (std::strcmp("min", command) == 0) {
      if (Size(queue) == 0) {
        std::cout << "error\n";
        continue;
      }
      std::cout << Front(deque) << '\n';
    }
  }
  Clear(queue);
  delete queue;
  Clear(deque);
  delete deque;
  delete[] command;
}
