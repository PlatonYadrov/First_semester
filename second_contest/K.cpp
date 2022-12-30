#include <iostream>

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
  int len;
  int window;
  auto* queue = new Queue;
  auto* deque = new Queue;
  std::cin >> len >> window;
  for (int i = 0; i < window; ++i) {
    int value;
    std::cin >> value;
    Enqueue(queue, value);
    while (Size(deque) > 0 && Back(deque) > value) {
      PopBack(deque);
    }
    Enqueue(deque, value);
  }
  std::cout << Front(deque) << '\n';
  int del = Front(queue);
  Dequeue(queue);
  if (Front(deque) == del) {
    Dequeue(deque);
  }
  for (int i = 0; i < len - window; ++i) {
    int value;
    std::cin >> value;
    Enqueue(queue, value);
    while (Size(deque) > 0 && Back(deque) > value) {
      PopBack(deque);
    }
    Enqueue(deque, value);
    std::cout << Front(deque) << '\n';
    int del = Front(queue);
    Dequeue(queue);
    if (Front(deque) == del) {
      Dequeue(deque);
    }
  }
  Clear(queue);
  delete queue;
  Clear(deque);
  delete deque;
}
