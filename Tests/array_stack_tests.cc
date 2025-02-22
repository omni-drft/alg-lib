#include <gtest/gtest.h>

#include "array_stack.h"  


TEST(ArrayStackTest, ConstructorAndIsEmpty) {
  alglib::ArrayStack<int, 5> stack;
  EXPECT_TRUE(stack.IsEmpty());
  EXPECT_EQ(stack.Size(), 0);
  EXPECT_EQ(stack.Capacity(), 5);
}


TEST(ArrayStackTest, PushAndTop) {
  alglib::ArrayStack<int, 5> stack;
  stack.Push(10);
  EXPECT_FALSE(stack.IsEmpty());
  EXPECT_EQ(stack.Top(), 10);
  EXPECT_EQ(stack.Size(), 1);

  stack.Push(20);
  EXPECT_EQ(stack.Top(), 20);
  EXPECT_EQ(stack.Size(), 2);
}


TEST(ArrayStackTest, Pop) {
  alglib::ArrayStack<int, 5> stack;
  stack.Push(10);
  stack.Push(20);

  EXPECT_EQ(stack.Pop(), 20);
  EXPECT_EQ(stack.Size(), 1);
  EXPECT_EQ(stack.Top(), 10);

  EXPECT_EQ(stack.Pop(), 10);
  EXPECT_TRUE(stack.IsEmpty());
  EXPECT_EQ(stack.Size(), 0);

  EXPECT_THROW(stack.Pop(), std::runtime_error);
}

TEST(ArrayStackTest, IsFull) {
  alglib::ArrayStack<int, 2> stack;
  EXPECT_FALSE(stack.IsFull());

  stack.Push(10);
  EXPECT_FALSE(stack.IsFull());

  stack.Push(20);
  EXPECT_TRUE(stack.IsFull());
}

TEST(ArrayStackTest, Overflow) {
  alglib::ArrayStack<int, 2> stack;
  stack.Push(10);
  stack.Push(20);

  EXPECT_THROW(stack.Push(30), std::runtime_error);
}

TEST(ArrayStackTest, Size) {
  alglib::ArrayStack<int, 5> stack;
  EXPECT_EQ(stack.Size(), 0);

  stack.Push(10);
  EXPECT_EQ(stack.Size(), 1);

  stack.Push(20);
  EXPECT_EQ(stack.Size(), 2);

  stack.Pop();
  EXPECT_EQ(stack.Size(), 1);
}

TEST(ArrayStackTest, Capacity) {
  alglib::ArrayStack<int, 5> stack;
  EXPECT_EQ(stack.Capacity(), 5);

  alglib::ArrayStack<int, 10> largerStack;
  EXPECT_EQ(largerStack.Capacity(), 10);
}

TEST(ArrayStackTest, TopOnEmptyStack) {
  alglib::ArrayStack<int, 5> stack;
  EXPECT_THROW(stack.Top(), std::runtime_error);
}