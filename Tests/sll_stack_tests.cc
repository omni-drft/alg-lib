#include <gtest/gtest.h>

#include "sll_stack.h"

TEST(SLLStackTest, ConstructorAndIsEmpty) {
  alglib::SLLStack<int> stack;
  EXPECT_TRUE(stack.IsEmpty());
  EXPECT_EQ(stack.Size(), 0);
}

TEST(SLLStackTest, PushAndTop) {
  alglib::SLLStack<int> stack;
  stack.Push(10);
  EXPECT_FALSE(stack.IsEmpty());
  EXPECT_EQ(stack.Top(), 10);
  EXPECT_EQ(stack.Size(), 1);

  stack.Push(20);
  EXPECT_EQ(stack.Top(), 20);
  EXPECT_EQ(stack.Size(), 2);
}

TEST(SLLStackTest, Pop) {
  alglib::SLLStack<int> stack;
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

TEST(SLLStackTest, TopOnEmptyStack) {
  alglib::SLLStack<int> stack;
  EXPECT_THROW(stack.Top(), std::runtime_error);
}

TEST(SLLStackTest, Size) {
  alglib::SLLStack<int> stack;
  EXPECT_EQ(stack.Size(), 0);

  stack.Push(10);
  EXPECT_EQ(stack.Size(), 1);

  stack.Push(20);
  EXPECT_EQ(stack.Size(), 2);

  stack.Pop();
  EXPECT_EQ(stack.Size(), 1);
}

TEST(SLLStackTest, StackBehavior) {
  alglib::SLLStack<int> stack;
  stack.Push(10);
  stack.Push(20);
  stack.Push(30);

  EXPECT_EQ(stack.Pop(), 30);
  EXPECT_EQ(stack.Top(), 20);

  stack.Push(40);
  EXPECT_EQ(stack.Top(), 40);

  EXPECT_EQ(stack.Pop(), 40);
  EXPECT_EQ(stack.Pop(), 20);
  EXPECT_EQ(stack.Pop(), 10);
  EXPECT_TRUE(stack.IsEmpty());
}

TEST(SLLStackTest, Destructor) {
  auto stack = new alglib::SLLStack<int>();
  stack->Push(10);
  stack->Push(20);
  stack->Push(30);

  delete stack;       
  EXPECT_TRUE(true); 
}