//*****************************************************************************
// The MIT License (MIT)
//
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
// File: sll_queue.h
//
// This file contains implementation of SLLQueue class. It uses singly linked
// list as a base for queue data structure. All nodes are allocated on the 
//*****************************************************************************

#ifndef ALGLIB_INCLUDE_SLLQUEUE_H_
#define ALGLIB_INCLUDE_SLLQUEUE_H_

#include <stdexcept>

#include "constants.h"

namespace alglib {

template <typename T>
class SLLQueue {
 public:
  SLLQueue();

  bool IsEmpty() const noexcept;
  T Dequeue();
  void Enqueue(T value) noexcept;

  T PeekFront() const;
  T PeekRear() const;

  ~SLLQueue();

 private:
  struct Node {
    T val;
    Node *next;
    Node(T value);
  };
  Node *front;
  Node *rear;
};

template <typename T>
SLLQueue<T>::Node::Node(T value) : val(value), next(nullptr) {}

template <typename T>
SLLQueue<T>::SLLQueue() : front(nullptr), rear(nullptr) {}

template <typename T>
bool SLLQueue<T>::IsEmpty() const noexcept {
  return front == nullptr;
}

template <typename T>
T SLLQueue<T>::Dequeue() {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kEmptyDeletion);
  }
  T result{front->val};
  Node *tmp{front};
  front = front->next;
  if (front == nullptr) {
    rear = nullptr;
  }
  delete tmp;
  return result;
}

template <typename T>
void SLLQueue<T>::Enqueue(T value) noexcept {
  Node *new_node{new Node(value)};
  if (IsEmpty()) {
    front = rear = new_node;
  }
  rear->next = new_node;
  rear = rear->next;
}

template <typename T>
T SLLQueue<T>::PeekFront() const {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kObjectEmpty);
  }
  return front->val;
}

template <typename T>
T SLLQueue<T>::PeekRear() const {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kObjectEmpty);
  }
  return rear->val;
}

template <typename T>
SLLQueue<T>::~SLLQueue() {
  Node *tmp{front};
  while (tmp != rear) {
    Node *next{tmp->next};
    delete tmp;
    tmp = next;
  }
}

}  // namespace alglib

#endif  // ALGLIB_INCLUDE_SLLQUEUE_H_
