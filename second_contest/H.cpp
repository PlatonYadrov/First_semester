#include <iostream>
#include <cstring>

struct Node {
  Node* prev = nullptr;
  char value;
};

struct Stack {
  Node* last = nullptr;
  size_t size = 0;
};

void Push(Stack* stack, char val) {
  auto new_node = new Node;
  new_node->value = val;
  new_node->prev = stack->last;
  stack->last = new_node;
  ++stack->size;
}

char Pop(Stack* stack) {
  if (stack->size == 0) {
    return 0;
  }
  char temp = stack->last->value;
  Node* last_for_delete = stack->last;
  stack->last = stack->last->prev;
  delete last_for_delete;
  --stack->size;
  return temp;
}

char Back(Stack* stack) {
  if (stack->size == 0) {
    return 0;
  }
  return stack->last->value;
}

int Size(Stack* stack) {
  return stack->size;
}

void Clear(Stack* stack) {
  if (stack->size > 0) {
    Pop(stack);
    Clear(stack);
  }
  delete stack->last;
}

int main() {
  bool right = false;
  auto* str = new char[100003];
  auto* stack = new Stack;
  std::cin >> str;
  for (int i = 0; str[i] != '\0'; ++i) {
    if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
      Push(stack, str[i]);
    }
    if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
      if (Size(stack) == 0) {
        right = true;
      } else {
        if (Back(stack) == '(' && str[i] == ')') {
          Pop(stack);
        } else if (Back(stack) == '[' && str[i] == ']') {
          Pop(stack);
        } else if (Back(stack) == '{' && str[i] == '}') {
          Pop(stack);
        } else {
          right = true;
          break;
        }
      }
    }
  }
  if (Size(stack) == 0 && !right) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  Clear(stack);
  delete stack;
  delete[] str;
}
