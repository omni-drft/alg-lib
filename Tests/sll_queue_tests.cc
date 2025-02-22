#include <gtest/gtest.h>

#include "sll_queue.h"

TEST(SLLQueueTest, ConstructorAndIsEmpty) {
  alglib::SLLQueue<int> queue;
  EXPECT_TRUE(queue.IsEmpty());
}

TEST(SLLQueueTest, EnqueueAndPeekFront) {
  alglib::SLLQueue<int> queue;
  queue.Enqueue(10);
  EXPECT_FALSE(queue.IsEmpty());
  EXPECT_EQ(queue.PeekFront(), 10);

  queue.Enqueue(20);
  EXPECT_EQ(queue.PeekFront(), 10);  
}

TEST(SLLQueueTest, Dequeue) {
  alglib::SLLQueue<int> queue;
  queue.Enqueue(10);
  queue.Enqueue(20);

  EXPECT_EQ(queue.Dequeue(), 10);
  EXPECT_EQ(queue.PeekFront(), 20);

  EXPECT_EQ(queue.Dequeue(), 20);
  EXPECT_TRUE(queue.IsEmpty());

  EXPECT_THROW(queue.Dequeue(), std::runtime_error);
}

TEST(SLLQueueTest, PeekRear) {
  alglib::SLLQueue<int> queue;
  queue.Enqueue(10);
  EXPECT_EQ(queue.PeekRear(), 10);

  queue.Enqueue(20);
  EXPECT_EQ(queue.PeekRear(), 20);

  queue.Dequeue();
  EXPECT_EQ(queue.PeekRear(), 20);  
}

TEST(SLLQueueTest, PeekFrontOnEmptyQueue) {
  alglib::SLLQueue<int> queue;
  EXPECT_THROW(queue.PeekFront(), std::runtime_error);
}

TEST(SLLQueueTest, PeekRearOnEmptyQueue) {
  alglib::SLLQueue<int> queue;
  EXPECT_THROW(queue.PeekRear(), std::runtime_error);
}

TEST(SLLQueueTest, QueueBehavior) {
  alglib::SLLQueue<int> queue;
  queue.Enqueue(10);
  queue.Enqueue(20);
  queue.Enqueue(30);

  EXPECT_EQ(queue.Dequeue(), 10);
  EXPECT_EQ(queue.PeekFront(), 20);
  EXPECT_EQ(queue.PeekRear(), 30);

  queue.Enqueue(40);
  EXPECT_EQ(queue.PeekRear(), 40);

  EXPECT_EQ(queue.Dequeue(), 20);
  EXPECT_EQ(queue.Dequeue(), 30);
  EXPECT_EQ(queue.Dequeue(), 40);
  EXPECT_TRUE(queue.IsEmpty());
}

TEST(SLLQueueTest, Destructor) {
  auto queue = new alglib::SLLQueue<int>();
  queue->Enqueue(10);
  queue->Enqueue(20);
  queue->Enqueue(30);

  delete queue; 
  EXPECT_TRUE(true);
}