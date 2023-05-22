#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

template<typename Data>
struct ListNode {
  Data data;
  ListNode *next = nullptr;
};

template<typename Data>
class SinglyLinkedList {
  private:
    ListNode<Data> *head;
    int size;

    void addAtFront(Data newData) {
      ListNode<Data> *newNode = new ListNode<Data>;
      newNode->data = newData;

      newNode->next = head->next;
      head->next = newNode;

      size++;
      return;
    }

    void addAtEnd(Data newData) {
      ListNode<Data> *searchNode = head->next;

      while (searchNode->next != nullptr) {
        searchNode = searchNode->next;
      }

      ListNode<Data> *newNode = new ListNode<Data>;

      newNode->data = newData;
      searchNode->next = newNode;

      size++;
      return;
    }

    void removeAtFront() {
      ListNode<Data> *deleteNode = head->next;

      if (head->next != nullptr) {
        head->next = head->next->next;
        delete deleteNode;
      }

      size--;
      return;
    }

    void removeAtEnd() {
      ListNode<Data> *searchNode = head->next;

      while (searchNode->next != nullptr) {
        searchNode = searchNode->next;
      }

      delete searchNode;

      size--;
      return;
    }

  public:
    SinglyLinkedList() {
      size = 0;
      head = new ListNode<Data>;
    }

    ~SinglyLinkedList() {
      clear();
      delete head;
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
      }
    }

    void add(Data newData, int index) {
      if (index > size) {
        throw;
      }
      else if (index == 0) {
        addAtFront(newData);
        return;
      }
      else if (index == size) {
        addAtEnd(newData);
        return;
      }

      ListNode<Data> *searchNode = head->next;

      for (int i = 0; i < index - 1; i++) {
        searchNode = searchNode->next;
      }

      ListNode<Data> *newNode = new ListNode<Data>;

      newNode->data = newData;
      newNode->next = searchNode->next;
      searchNode->next = newNode;

      size++;
      return;
    }

    Data get(int index) {
      if (index >= size) {
        throw;
      }

      ListNode<Data> *searchNode = head->next;

      for (int i = 0; i < index; i++) {
        searchNode = searchNode->next;
      }

      return searchNode->data;
    }

    void remove(int index) {
      if (index >= size) {
        throw;
      }

      if (index == 0) {
        removeAtFront();
        return;
      }
      else if (index == size - 1) {
        removeAtEnd();
        return;
      }

      ListNode<Data> *searchNode = head->next;

      for (int i = 0; i < index - 1; i++) {
        searchNode = searchNode->next;
      }

      ListNode<Data> *deleteNode = searchNode->next;

      searchNode->next = deleteNode->next;

      delete deleteNode;

      size--;
      return;
    }
};

#endif