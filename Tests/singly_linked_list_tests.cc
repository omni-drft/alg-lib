#include <gtest/gtest.h>

#include "singly_linked_list.h"  

TEST(SinglyLinkedListTest, ConstructorAndIsEmpty) {
  alglib::SinglyLinkedList<int> list;
  EXPECT_EQ(list.Size(), 0);
  EXPECT_TRUE(list.GetAsVector().empty());
}

TEST(SinglyLinkedListTest, InsertAtBeginning) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtBeginning(10);
  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtBeginning(20);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({20, 10}));
}

TEST(SinglyLinkedListTest, InsertAtEnd) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  EXPECT_EQ(list.Size(), 1);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtEnd(20);
  EXPECT_EQ(list.Size(), 2);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20}));
}

TEST(SinglyLinkedListTest, InsertAtPosition) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtPosition(0, 10);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.InsertAtPosition(1, 30);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 30}));

  list.InsertAtPosition(1, 20);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20, 30}));

  EXPECT_THROW(list.InsertAtPosition(10, 40), std::runtime_error);
}

TEST(SinglyLinkedListTest, DeleteAtBeginning) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtBeggining();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({20, 30}));

  list.DeleteAtBeggining();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({30}));

  list.DeleteAtBeggining();
  EXPECT_TRUE(list.GetAsVector().empty());

  EXPECT_THROW(list.DeleteAtBeggining(), std::runtime_error);
}

TEST(SinglyLinkedListTest, DeleteAtEnd) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtEnd();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20}));

  list.DeleteAtEnd();
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10}));

  list.DeleteAtEnd();
  EXPECT_TRUE(list.GetAsVector().empty());

  EXPECT_THROW(list.DeleteAtEnd(), std::runtime_error);
}

TEST(SinglyLinkedListTest, DeleteAtPosition) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  list.DeleteAtPosition(1); 
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 30}));

  list.DeleteAtPosition(0);  
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({30}));

  list.DeleteAtPosition(0); 
  EXPECT_TRUE(list.GetAsVector().empty());

  EXPECT_THROW(list.DeleteAtPosition(10), std::runtime_error);
}

TEST(SinglyLinkedListTest, Find) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  EXPECT_EQ(list.Find(10), 0);
  EXPECT_EQ(list.Find(20), 1);
  EXPECT_EQ(list.Find(30), 2);
  EXPECT_THROW(list.Find(40), std::runtime_error); 
}

TEST(SinglyLinkedListTest, GetAsVector) {
  alglib::SinglyLinkedList<int> list;
  EXPECT_TRUE(list.GetAsVector().empty());

  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);
  EXPECT_EQ(list.GetAsVector(), std::vector<int>({10, 20, 30}));
}

TEST(SinglyLinkedListTest, Traverse) {
  alglib::SinglyLinkedList<int> list;
  list.InsertAtEnd(10);
  list.InsertAtEnd(20);
  list.InsertAtEnd(30);

  EXPECT_NO_THROW(list.Traverse([](int value) {}));
}

TEST(SinglyLinkedListTest, Destructor) {
  auto list = new alglib::SinglyLinkedList<int>();
  list->InsertAtEnd(10);
  list->InsertAtEnd(20);
  list->InsertAtEnd(30);

  delete list;
  EXPECT_TRUE(true);
}