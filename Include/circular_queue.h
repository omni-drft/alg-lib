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
// File: circular_queue.h
//
// This file contains the implementation of the CircularQueue class.
// Implementation is based on templates, so the class can be used with any type.
// CircularQueue is a queue implementation that uses an array as a base
// structure. It doesn't allocate memory on the heap, but it has a fixed
// capacity.
//*****************************************************************************

#ifndef ALGLIB_INCLUDE_CIRCULARQUEUE_H_
#define ALGLIB_INCLUDE_CIRCULARQUEUE_H_

#include <array>
#include <stdexcept>

#include "constants.h"

namespace alglib {

template <typename T, size_t capacity>
class CircularQueue {
 public:
  CircularQueue();

  bool IsEmpty() const noexcept;
  bool IsFull() const noexcept;
  T Dequeue();
  void Enqueue(T value);

  T PeekFront() const noexcept;
  T PeekRear() const noexcept;

 private:
  std::array<T, capacity> queue;
  size_t front;
  size_t size;
};

template <typename T, size_t capacity>
CircularQueue<T, capacity>::CircularQueue() : front(0), size(0) {}

template <typename T, size_t capacity>
bool CircularQueue<T, capacity>::IsEmpty() const noexcept {
  return size == 0;
}

template <typename T, size_t capacity>
bool CircularQueue<T, capacity>::IsFull() const noexcept {
  return size == capacity;
}

template <typename T, size_t capacity>
T CircularQueue<T, capacity>::Dequeue() {
  if (IsEmpty()) {
    throw std::runtime_error(errors::kEmptyDeletion);
  }
  T result{queue.at(front)};
  front = (front + 1) % capacity;
  --size;
  return result;
}

template <typename T, size_t capacity>
void CircularQueue<T, capacity>::Enqueue(T value) {
  if (IsFull()) {
    throw std::runtime_error(errors::kObjectFull);
  }
  size_t rear{(front + size) % capacity};
  queue.at(rear) = value;
  ++size;
}

template <typename T, size_t capacity>
T CircularQueue<T, capacity>::PeekFront() const noexcept {
  return queue.at(front);
}

template <typename T, size_t capacity>
T CircularQueue<T, capacity>::PeekRear() const noexcept {
  size_t rear{(front + size - 1) % capacity};
  return queue.at(rear);
}

}  // namespace alglib

#endif  // ALGLIB_INCLUDE_CIRCULARQUEUE_H_