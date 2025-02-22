#include <gtest/gtest.h>

#include "circular_queue.h"

TEST(CircularQueueTest, ConstructorAndIsEmpty) {
  alglib::CircularQueue<int, 5> queue;
  EXPECT_TRUE(queue.IsEmpty());
  EXPECT_FALSE(queue.IsFull());
}

TEST(CircularQueueTest, EnqueueAndPeekFront) {
  alglib::CircularQueue<int, 5> queue;
  queue.Enqueue(10);
  EXPECT_FALSE(queue.IsEmpty());
  EXPECT_EQ(queue.PeekFront(), 10);

  queue.Enqueue(20);
  EXPECT_EQ(queue.PeekFront(), 10);
}

TEST(CircularQueueTest, Dequeue) {
  alglib::CircularQueue<int, 5> queue;
  queue.Enqueue(10);
  queue.Enqueue(20);

  EXPECT_EQ(queue.Dequeue(), 10);
  EXPECT_EQ(queue.PeekFront(), 20);

  EXPECT_EQ(queue.Dequeue(), 20);
  EXPECT_TRUE(queue.IsEmpty());

  EXPECT_THROW(queue.Dequeue(), std::runtime_error);
}

TEST(CircularQueueTest, PeekRear) {
  alglib::CircularQueue<int, 5> queue;
  queue.Enqueue(10);
  EXPECT_EQ(queue.PeekRear(), 10);

  queue.Enqueue(20);
  EXPECT_EQ(queue.PeekRear(), 20);

  queue.Dequeue();
  EXPECT_EQ(queue.PeekRear(), 20);
}

TEST(CircularQueueTest, IsFull) {
  alglib::CircularQueue<int, 2> queue;
  EXPECT_FALSE(queue.IsFull());

  queue.Enqueue(10);
  EXPECT_FALSE(queue.IsFull());

  queue.Enqueue(20);
  EXPECT_TRUE(queue.IsFull());
}

TEST(CircularQueueTest, Overflow) {
  alglib::CircularQueue<int, 2> queue;
  queue.Enqueue(10);
  queue.Enqueue(20);

  EXPECT_THROW(queue.Enqueue(30), std::runtime_error);
}

TEST(CircularQueueTest, PeekFrontOnEmptyQueue) {
  alglib::CircularQueue<int, 5> queue;
  EXPECT_THROW(queue.PeekFront(), std::runtime_error);
}

TEST(CircularQueueTest, PeekRearOnEmptyQueue) {
  alglib::CircularQueue<int, 5> queue;
  EXPECT_THROW(queue.PeekRear(), std::runtime_error);
}

TEST(CircularQueueTest, CircularBehavior) {
  alglib::CircularQueue<int, 3> queue;
  queue.Enqueue(10);
  queue.Enqueue(20);
  queue.Enqueue(30);

  EXPECT_EQ(queue.Dequeue(), 10);
  queue.Enqueue(40);

  EXPECT_EQ(queue.PeekFront(), 20);
  EXPECT_EQ(queue.PeekRear(), 40);

  EXPECT_EQ(queue.Dequeue(), 20);
  EXPECT_EQ(queue.Dequeue(), 30);
  EXPECT_EQ(queue.Dequeue(), 40);
  EXPECT_TRUE(queue.IsEmpty());
}