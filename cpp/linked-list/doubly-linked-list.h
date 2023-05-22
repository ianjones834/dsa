#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template<typename Data>
struct ListNode {
  Data data;
  ListNode *next = nullptr;
  ListNode *previous = nullptr;
};

template<typename Data>
class DoublyLinkedList {
  private:
    ListNode<Data> *head;
    ListNode<Data> *tail;
    int size;

    void addAtFront(Data newData) {
      ListNode<Data> *newNode = new ListNode<Data>;
      newNode->data = newData;

      newNode->previous = head;
      newNode->next = head->next;
      newNode->next->previous = newNode;
      head->next = newNode;

      size++;
      return;
    }

    void addAtEnd(Data newData) {
      ListNode<Data> *newNode = new ListNode<Data>;
      newNode->data = newData;

      newNode->next = tail;
      newNode->previous = tail->previous;
      newNode->previous->next = newNode;
      tail->previous = newNode;

      size++;
      return;
    }

    void removeFromFront() {
      ListNode<Data> *deleteNode = head->next;

      head->next = deleteNode->next;
      head->next->previous = head;

      size--;
      delete deleteNode;
    }

    void removeFromEnd() {
      ListNode<Data> *deleteNode = tail->previous;

      tail->previous = deleteNode->previous;
      tail->previous->next = tail;

      size--;
      delete deleteNode;
    }

  public:

    DoublyLinkedList() {
      head = new ListNode<Data>;
      tail = new ListNode<Data>;

      head->next = tail;
      tail->previous = head;

      size = 0;
    }

    ~DoublyLinkedList() {
      clear();
      delete head;
      delete tail;
    }

    int getSize() {
      return size;
    }

    bool isEmpty() {
      return size == 0;
    }

    void clear() {
      while (isEmpty() == false) {
        remove(0);
        size--;
      }
    }

    void add(Data newData, int index) {
      if (index > size) {
        throw;
      }

      if (index == 0) {
        addAtFront(newData);
        return;
      }
      else if (index == size) {
        addAtEnd(newData);
        return;
      }

      ListNode<Data> *newNode = new ListNode<Data>;
      newNode->data = newData;

      if (index <= size / 2) {
        ListNode<Data> *searchNode = head->next;

        for (int i = 0; i < index - 1; i++) {
          searchNode = searchNode->next;
        }

        newNode->previous = searchNode;
        newNode->next = searchNode->next;
        newNode->next->previous = newNode;
        searchNode->next = newNode;
      }
      else {
        ListNode<Data> *searchNode = tail->previous;

        for (int i = 0; i < size - index - 1; i++) {
          searchNode = searchNode->previous;
        }

        newNode->next = searchNode;
        newNode->previous = searchNode->previous;
        newNode->previous->next = newNode;
        searchNode->previous = newNode;
      }

      size++;
      return;
    }

    Data get(int index) {
      if (index >= size) {
        throw;
      }

      ListNode<Data> *searchNode;

      if (index <= size / 2) {
        searchNode = head->next;

        for (int i = 0; i < index; i++) {
          searchNode = searchNode->next;
        }
      }
      else {
        searchNode = tail->previous;

        for (int i = 0; i < size - index - 1; i++) {
          searchNode = searchNode->previous;
        }
      }

      return searchNode->data;
    }

    void remove(int index) {
      if (index >= size) {
        throw;
      }

      if (index == 0) {
        removeFromFront();
        return;
      }
      else if (index == size - 1) {
        removeFromEnd();
        return;
      }

      ListNode<Data> *deleteNode = new ListNode<Data>;

      if (index <= size / 2) {
        ListNode<Data> *searchNode = head->next;

        for (int i = 0; i < index - 1; i++) {
          searchNode = searchNode->next;
        }

        deleteNode = searchNode->next;

        searchNode->next = deleteNode->next;
        deleteNode->next->previous = searchNode;
      }
      else {
        ListNode<Data> *searchNode = tail->previous;

        for (int i = 0; i < size - index - 1; i++) {
          searchNode = searchNode->previous;
        }

        deleteNode = searchNode->previous;

        searchNode->previous = deleteNode->previous;
        deleteNode->previous->next = searchNode;
      }

      delete deleteNode;
      size--;

      return;
    }
};

#endif