#include <gtest/gtest.h>

#include "doubly_linked_list.h"

TEST(DoublyLinkedListTest, ConstructorAndIsEmpty) {
  alglib::DoublyLinkedList<int> list;
  EXPECT_TRUE(list.IsEmpty());
  EXPECT_EQ(list.Size(), 0);
}

TEST(DoublyLinkedListTest, InsertAtBeginning) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtBeginning(10);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtBeginning(20);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({20, 10}));
}

TEST(DoublyLinkedListTest, InsertAtEnd) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  EXPECT_FALSE(list.IsEmpty());
  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtEnd(20);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20}));
}

TEST(DoublyLinkedListTest, InsertAtPosition) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtPosition(0, 10);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtPosition(1, 30); 
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 30}));

  list.InsertAtPosition(1, 20);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20, 30}));

  EXPECT_THROW(list.InsertAtPosition(10, 40), std::runtime_error);
}

TEST(DoublyLinkedListTest, DeleteAtBeginning) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtBeginning();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({20, 30}));

  list.DeleteAtBeginning();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({30}));

  list.DeleteAtBeginning();
  EXPECT_TRUE(list.IsEmpty());

  EXPECT_THROW(list.DeleteAtBeginning(), std::runtime_error);
}

TEST(DoublyLinkedListTest, DeleteAtEnd) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtEnd();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20}));

  list.DeleteAtEnd();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.DeleteAtEnd();
  EXPECT_TRUE(list.IsEmpty());

  EXPECT_THROW(list.DeleteAtEnd(), std::runtime_error);
}

TEST(DoublyLinkedListTest, DeleteAtPosition) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtPosition(1);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 30}));

  list.DeleteAtPosition(0); 
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({30}));

  list.DeleteAtPosition(0);  
  EXPECT_TRUE(list.IsEmpty());

  EXPECT_THROW(list.DeleteAtPosition(10), std::runtime_error);
}

TEST(DoublyLinkedListTest, Find) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  EXPECT_EQ(list.Find(10), 0);
  EXPECT_EQ(list.Find(20), 1);
  EXPECT_EQ(list.Find(30), 2);
  EXPECT_THROW(list.Find(40), std::runtime_error); 
}

TEST(DoublyLinkedListTest, GetAsVector) {
  alglib::DoublyLinkedList<int> list;
  EXPECT_EQ(list.GetAsVector(), std::vector<int>());

  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20, 30}));
}

TEST(DoublyLinkedListTest, Traverse) {
  alglib::DoublyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  EXPECT_NO_THROW(list.Traverse());
}

TEST(DoublyLinkedListTest, Destructor) {
  auto list = new alglib::DoublyLinkedList<int>();
  list->InsertAtEnd(10);
  list->InsertAtEnd(20);
  list->InsertAtEnd(30);

  delete list; 
  EXPECT_TRUE(true); 
}