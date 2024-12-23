#include <iostream>
#include <vector>

#include "alg_lib.h"

int main() {
  // ======================== SLL TESTS =======================================
  std::cout << "Singly Linked List Tests" << std::endl;
  
  // ID: 1
  // Test the insertion of elements in the singly linked list.
  alglib::SinglyLinkedList<int> insertionSLLTest{};
  insertionSLLTest.InsertAtEnd(1);
  insertionSLLTest.InsertAtEnd(2);
  insertionSLLTest.InsertAtBeginning(3);
  insertionSLLTest.InsertAtPosition(1, 4);
  std::vector<int> insertionSLLTestVector{insertionSLLTest.GetAsVector()};
  std::vector<int> insertionSLLTestVectorExpected{3, 4, 1, 2};
  if (insertionSLLTestVector != insertionSLLTestVectorExpected) {
    std::cout << "  Test 1 - Failed" << std::endl;
  } else {
    std::cout << "  Test 1 - OK" << std::endl;
  }

  // ID: 2
  // Test the deletion of elements in the singly linked list.
  alglib::SinglyLinkedList<int> deletionSLLTest{};
  deletionSLLTest.InsertAtEnd(1);
  deletionSLLTest.InsertAtEnd(2);
  deletionSLLTest.InsertAtBeginning(3);
  deletionSLLTest.InsertAtPosition(1, 4);
  deletionSLLTest.InsertAtBeginning(5);
  deletionSLLTest.DeleteAtEnd();
  deletionSLLTest.DeleteAtPosition(1);
  deletionSLLTest.DeleteAtBeggining();
  std::vector<int> deletionSLLTestVector{deletionSLLTest.GetAsVector()};
  std::vector<int> deletionSLLTestVectorExpected{4, 1};
  if (deletionSLLTestVector != deletionSLLTestVectorExpected) {
    std::cout << "  Test 2 - Failed" << std::endl;
  } else {
    std::cout << "  Test 2 - OK" << std::endl;
  }

  // ID: 3
  // Test the size of the singly linked list.
  alglib::SinglyLinkedList<int> sizeSLLTest{};
  sizeSLLTest.InsertAtEnd(1);
  sizeSLLTest.InsertAtEnd(2);
  sizeSLLTest.InsertAtBeginning(3);
  sizeSLLTest.InsertAtPosition(1, 4);
  size_t sizeSLLTestSize{sizeSLLTest.Size()};
  size_t sizeSLLTestSizeExpected{4};
  if (sizeSLLTestSize != sizeSLLTestSizeExpected) {
    std::cout << "  Test 3 - Failed" << std::endl;
  } else {
    std::cout << "  Test 3 - OK" << std::endl;
  }

  // ID: 4
  // Test the search of an element in the singly linked list.
  alglib::SinglyLinkedList<int> searchSLLTest{};
  searchSLLTest.InsertAtEnd(1);
  searchSLLTest.InsertAtEnd(2);
  searchSLLTest.InsertAtBeginning(3);
  searchSLLTest.InsertAtPosition(1, 4);
  size_t searchSLLTestFind{searchSLLTest.Find(2)};
  size_t searchSLLTestFindExpected{3};
  if (searchSLLTestFind != searchSLLTestFindExpected) {
    std::cout << "  Test 4 - Failed" << std::endl;
  } else {
    std::cout << "  Test 4 - OK" << std::endl;
  }

  // ======================== DLL TESTS =======================================
  std::cout << "Doubly Linked List Tests" << std::endl;
  
  // ID: 5
  // Test the insertion of elements in the doubly linked list.
  alglib::DoublyLinkedList<int> insertionDLLTest{};
  insertionDLLTest.InsertAtEnd(1);
  insertionDLLTest.InsertAtEnd(2);
  insertionDLLTest.InsertAtBeginning(3);
  insertionDLLTest.InsertAtPosition(1, 4);
  std::vector<int> insertionDLLTestVector{insertionDLLTest.GetAsVector()};
  std::vector<int> insertionDLLTestVectorExpected{3, 4, 1, 2};
  if (insertionDLLTestVector != insertionDLLTestVectorExpected) {
    std::cout << "  Test 5 - Failed" << std::endl;
  } else {
    std::cout << "  Test 5 - OK" << std::endl;
  }

  // ID: 6
  // Test the deletion of elements in the doubly linked list.
  alglib::DoublyLinkedList<int> deletionDLLTest{};
  deletionDLLTest.InsertAtEnd(1);
  deletionDLLTest.InsertAtEnd(2);
  deletionDLLTest.InsertAtBeginning(3);
  deletionDLLTest.InsertAtPosition(1, 4);
  deletionDLLTest.InsertAtBeginning(5);
  deletionDLLTest.DeleteAtEnd();
  deletionDLLTest.DeleteAtPosition(1);
  deletionDLLTest.DeleteAtBeginning();
  std::vector<int> deletionDLLTestVector{deletionDLLTest.GetAsVector()};
  std::vector<int> deletionDLLTestVectorExpected{4, 1};
  if (deletionDLLTestVector != deletionDLLTestVectorExpected) {
    std::cout << "  Test 6 - Failed" << std::endl;
  } else {
    std::cout << "  Test 6 - OK" << std::endl;
  }
  
  // ID: 7
  // Test the size of the doubly linked list.
  alglib::DoublyLinkedList<int> sizeDLLTest{};
  sizeDLLTest.InsertAtEnd(1);
  sizeDLLTest.InsertAtEnd(2);
  sizeDLLTest.InsertAtBeginning(3);
  sizeDLLTest.InsertAtPosition(1, 4);
  size_t sizeDLLTestSize{sizeDLLTest.Size()};
  size_t sizeDLLTestSizeExpected{4};
  if (sizeDLLTestSize != sizeDLLTestSizeExpected) {
    std::cout << "  Test 7 - Failed" << std::endl;
  } else {
    std::cout << "  Test 7 - OK" << std::endl;
  }

  // ID: 8
  // Test the search of an element in the doubly linked list.
  alglib::DoublyLinkedList<int> searchDLLTest{};
  searchDLLTest.InsertAtEnd(1);
  searchDLLTest.InsertAtEnd(2);
  searchDLLTest.InsertAtBeginning(3);
  searchDLLTest.InsertAtPosition(1, 4);
  size_t searchDLLTestFind{searchDLLTest.Find(2)};
  size_t searchDLLTestFindExpected{3};
  if (searchDLLTestFind != searchDLLTestFindExpected) {
    std::cout << "  Test 8 - Failed" << std::endl;
  } else {
    std::cout << "  Test 8 - OK" << std::endl;
  }

  int arr[] = {1, 4, 2, 5, 7, 9, 3, 2, 11};
  alglib::SelectionSort(arr, arr + 9);
  for (int i = 0; i < 9; ++i) {
    std::cout << arr[i] << " ";
  }

  return 0;
}