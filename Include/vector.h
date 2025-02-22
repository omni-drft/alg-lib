#ifndef ALGLIB_INCLUDE_VECTOR_H_
#define ALGLIB_INCLUDE_VECTOR_H_

#include "constants.h"

namespace alglib {

template <typename T>
class Vector {
 public:
  Vector() noexcept;
  Vector(size_t elements) noexcept;
  Vector(size_t elements, const T& value) noexcept;
  
  void Push(const T& value) noexcept;
  T& Pop();
  const T& Pop() const;

  T& At(size_t index);
  const T& At(size_t index) const;
  
  size_t Size() const noexcept;
  size_t Capacity() const noexcept;
  void Resize(size_t size);
  void ShrinkToFit();
  
  T& Front();
  const T& Front() const;
  T& Back();
  const T& Back() const;

  ~Vector() noexcept;

 private:
  void Reallocate(size_t amount);

  size_t size;
  size_t capacity;

  T* data;
};

template <typename T>
Vector<T>::Vector() noexcept : size(0), capacity(0), data(nullptr) {
  Reallocate(4);
}

template <typename T>
Vector<T>::Vector(size_t elements) noexcept
    : size(0), capacity(0), data(nullptr) {
  Reallocate(elements);
}

template <typename T>
Vector<T>::Vector(size_t elements, const T& value) noexcept
    : size(0), capacity(0), data(nullptr) {
  Reallocate(elements);
  for (size_t i{}; i < capacity; ++i) {
    data[i] = value;
  }
}

template <typename T>
void Vector<T>::Push(const T& value) noexcept {
  if (size >= capacity) {
    Reallocate(capacity * 2);
  }
  data[size++] = value;
}

template <typename T>
T& Vector<T>::Pop() {
  return data[size--];
}

template <typename T>
const T& Vector<T>::Pop() const {
  return data[size--];
}

template <typename T>
T& Vector<T>::At(size_t index) {
  if (index >= size) {
    throw std::runtime_error(errors::kIndexOutOfRange);
  }
  return data[index];
}

template <typename T>
const T& Vector<T>::At(size_t index) const {
  if (index >= size) {
    throw std::runtime_error(errors::kIndexOutOfRange);
  }
  return data[index];
}

template <typename T>
size_t Vector<T>::Size() const noexcept {
  return size;
}

template <typename T>
size_t Vector<T>::Capacity() const noexcept {
  return capacity;
}

template <typename T>
void Vector<T>::Resize(size_t size) {
  Reallocate(size);
}

template <typename T>
void Vector<T>::ShrinkToFit() {
  Reallocate(size);
}

template <typename T>
T& Vector<T>::Front() {
  return data[0];
}

template <typename T>
const T& Vector<T>::Front() const {
  return data[0];
}

template <typename T>
T& Vector<T>::Back() {
  return data[size - 1];
}

template <typename T>
const T& Vector<T>::Back() const {
  return data[size - 1];
}

template <typename T>
Vector<T>::~Vector() noexcept {
  delete[] data;
}

template <typename T>
void Vector<T>::Reallocate(size_t amount) {
  T* new_data{new T[amount]};
  size = (amount < size) ? amount : size;
  for (size_t i{}; i < size; ++i) {
    new_data[i] = data[i];
  }
  delete[] data;
  data = new_data;
  capacity = amount;
}
}  // namespace alglib

#endif  // ALGLIB_INCLUDE_VECTOR_H_
