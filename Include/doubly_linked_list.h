// Copyright © 2024 Piotr Walczak
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//*****************************************************************************

//*****************************************************************************
// File: SinglyLinkedList.h
//
// TODO: Add description
//*****************************************************************************

#ifndef ALGLIB_INCLUDE_DOUBLYLINKEDLIST_H_
#define ALGLIB_INCLUDE_DOUBLYLINKEDLIST_H_

#include <cstdlib>

namespace alglib {
template <typename T>
class DoublyLinkedList {
 public:
  DoublyLinkedList();

  void Traverse() const;
  size_t Size() const;
  size_t Find(const T value) const;

  std::vector<T> GetAsVector() const;

  void InsertAtBeginning(const T data);
  void InsertAtEnd(const T data);
  void InsertAtPosition(const uint32_t pos, const T data);

  void DeleteAtBeginning();
  void DeleteAtEnd();
  void DeleteAtPosition(uint32_t pos);

  ~DoublyLinkedList();

 private:
  struct Node {
    Node(T data);
    ~Node() = default;
    Node *next;
    Node *previous;
    T data;
  };

  bool IsEmpty() const;

  Node *head_;
  Node *tail_;
};

template <typename T>
DoublyLinkedList<T>::Node::Node(const T data)
    : next(nullptr), previous(nullptr), data(data) {}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head_(nullptr), tail_(nullptr) {}

template <typename T>
void DoublyLinkedList<T>::Traverse() const {
  Node *tmp{head_};
  while (tmp) {
    // Do something with tmp->data
    std::cout << tmp->data << " ";
    tmp = tmp->next;
  }
}

template <typename T>
size_t DoublyLinkedList<T>::Size() const {
  Node *tmp{head_};
  size_t count{};
  while (tmp) {
    ++count;
    tmp = tmp->next;
  }
  return count;
}

template <typename T>
size_t DoublyLinkedList<T>::Find(const T value) const {
  Node *tmp{head_};
  size_t count{};
  while (tmp && tmp->data != value) {
    ++count;
    tmp = tmp->next;
  }
  if (tmp == nullptr) {
    throw std::runtime_error(errors::kItemNotFound);
  } else {
    return count;
  }
}

template <typename T>
std::vector<T> DoublyLinkedList<T>::GetAsVector() const {
  std::vector<T> vec{};
  vec.reserve(Size());
  Node *tmp{head_};
  while (tmp) {
    vec.emplace_back(tmp->data);
    tmp = tmp->next;
  }
  return vec;
}

template <typename T>
void DoublyLinkedList<T>::InsertAtBeginning(const T data) {
  Node *new_node{new Node(data)};
  if (IsEmpty()) {
    head_ = new_node;
  } else {
    new_node->next = head_;
    new_node->previous = nullptr;
    head_->previous = new_node;
    head_ = new_node;
  }
}

template <typename T>
void DoublyLinkedList<T>::InsertAtEnd(const T data) {
  Node *new_node{new Node(data)};
  if (IsEmpty()) {
    head_ = new_node;
  } else {
    Node *tmp{head_};
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = new_node;
    new_node->previous = tmp;
  }
}

template <typename T>
void DoublyLinkedList<T>::InsertAtPosition(const uint32_t pos, const T data) {
  if (pos > Size()) {
    throw std::runtime_error(errors::kIndexOutOfRange);
  }
  if (pos == 0) {
    InsertAtBeginning(data);
    return;
  } else if (pos == Size()) {
    InsertAtEnd(data);
    return;
  }
  Node *new_node = new Node(data);
  Node *prev_node = head_;
  uint32_t count = 0;
  while (count < pos - 1) {
    prev_node = prev_node->next;
    ++count;
  }
  new_node->next = prev_node->next;
  new_node->previous = prev_node;
  prev_node->next = new_node;
  if (new_node->next != nullptr) {
    new_node->next->previous = new_node;
  }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtBeginning() {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kEmptyDeletion);
  } else if (head_->next == nullptr) {
    delete head_;
    head_ = nullptr;
  } else {
    Node *tmp{head_};
    head_ = head_->next;
    head_->previous = nullptr;
    delete tmp;
  }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtEnd() {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kEmptyDeletion);
  } else if (head_->next == nullptr) {
    delete head_;
    head_ = nullptr;
  } else {
    Node *tmp{head_};
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->previous->next = nullptr;
    delete tmp;
  }
}

template <typename T>
void DoublyLinkedList<T>::DeleteAtPosition(uint32_t pos) {
  if (head_ == nullptr) {
    throw std::runtime_error(errors::kEmptyDeletion);
  }
  Node *curr = head_;
  uint32_t index = 0;
  while (curr != nullptr && index < pos) {
    curr = curr->next;
    ++index;
  }
  if (curr == nullptr) {
    throw std::runtime_error(errors::kIndexOutOfRange);
  }
  if (curr->previous == nullptr) {
    head_ = curr->next;
    if (head_ != nullptr) {
      head_->previous = nullptr;
    }
  } else {
    curr->previous->next = curr->next;
  }
  if (curr->next != nullptr) {
    curr->next->previous = curr->previous;
  }
  delete curr;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
  Node *tmp{head_};
  while (tmp) {
    Node *next{tmp->next};
    delete tmp;
    tmp = next;
  }
  delete tail_;
}

template <typename T>
bool DoublyLinkedList<T>::IsEmpty() const {
  return head_ == nullptr;
}

}  // namespace alglib

#endif  // ALGLIB_INCLUDE_DOUBLYLINKEDLIST_H_