#ifndef QUEUE_H
#define QUEUE_H

template<typename Data>
struct QueueNode {
  Data data;
  QueueNode *next = nullptr;
};

template<typename Data>
class Queue {
  private:
    QueueNode<Data> *head;
    QueueNode<Data> *tail;
    int size;

  public:

    Queue() {
      head = new QueueNode<Data>;
      tail = head;
      size = 0;
    }

    ~Queue() {
      clear();
      delete head;
      delete tail;
    }

    void clear() {
      while (isEmpty() == false) {
        dequeue();
      }
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    void enqueue(Data newData) {
      QueueNode<Data> *newNode = new QueueNode<Data>;
      newNode->data = newData;

      tail->next = newNode;
      tail = tail->next;

      size++;
      return;
    }

    Data top() {
      if (size == 0) {
        throw;
      }

      return head->next->data;
    }

    void dequeue() {
      if (size == 0) {
        throw;
      }

      QueueNode<Data> *deleteNode = head->next;
      head->next = deleteNode->next;

      delete deleteNode;

      if (deleteNode == tail) {
        tail = head;
      }

      size--;
      return;
    }
};

#endif