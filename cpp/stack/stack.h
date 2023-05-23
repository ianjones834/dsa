#ifndef STACK_H
#define STACK_H

template<typename Data>
struct StackNode {
  Data data;
  StackNode *next = nullptr;
};

template<typename Data>
class Stack {
  private:
    StackNode<Data> *head;
    int size;

  public:

    Stack() {
      head = new StackNode<Data>;
      size = 0;
    }

    ~Stack() {
      clear();
      delete head;
    }

    void clear() {
      while (isEmpty() == false) {
        pop();
      }
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    void push(Data newData) {
      StackNode<Data> *newNode = new StackNode<Data>;
      newNode->data = newData;

      newNode->next = head->next;
      head->next = newNode;


      size++;
      return;
    }

    Data top() {
      if (size == 0) {
        throw;
      }

      return head->next->data;
    }

    void pop() {
      if (size == 0) {
        throw;
      }

      StackNode<Data> *deleteNode = head->next;
      head->next = deleteNode->next;


      size--;
      delete deleteNode;
      return;
    }
};

#endif