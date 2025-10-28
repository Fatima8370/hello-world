#include "pch.h"
#include "../24i0875_D_Lab5/Header.h"

// ---------- INSERTION TESTS ----------
TEST(LinkedListTest, InsertAtHeadEmpty) {
	LinkedList<int> list;
	list.insertAtHead(10);
	list.displayForward();
	EXPECT_FALSE(list.isEmpty());
	EXPECT_EQ(list.search(10)->data, 10);
}
TEST(LinkedListTest, InsertAtHeadNonEmpty) {
	LinkedList<int> list;
	list.insertAtHead(10);
	list.insertAtHead(5);
	list.displayForward();

	EXPECT_EQ(list.search(5)->data, 5);
}
TEST(LinkedListTest, InsertAtTailEmpty) {
	LinkedList<int> list;
	list.insertAtTail(20);
	list.displayForward();
	EXPECT_EQ(list.search(20)->data, 20);
}
TEST(LinkedListTest, InsertAtTailNonEmpty) {
	LinkedList<int> list;
	list.insertAtHead(10);
	list.insertAtTail(30);
	list.displayForward();
	EXPECT_EQ(list.search(30)->data, 30);
}
TEST(LinkedListTest, InsertAfterMiddle) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.insertAtTail(10);
	list.insertAtTail(30);
	list.insertAfter(25, 10);
	list.displayForward();
	EXPECT_NE(list.search(25), nullptr);
}
TEST(LinkedListTest, InsertAfterNonExistent) {
	LinkedList<int> list;

	list.insertAtTail(5);
	list.insertAfter(100, 50); // should not insert
	list.displayForward();
	EXPECT_EQ(list.search(100), nullptr);
}
TEST(LinkedListTest, InsertBeforeHead) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.insertBefore(1, 5);
	list.displayForward();
	EXPECT_NE(list.search(1), nullptr);
}
TEST(LinkedListTest, InsertBeforeNonExistent) {
	LinkedList<int> list;
	list.insertAtTail(10);
	list.insertBefore(99, 50);
	list.displayForward();
	EXPECT_EQ(list.search(99), nullptr);
}
// ---------- REMOVAL TESTS ----------
TEST(LinkedListTest, RemoveMiddle) {
	LinkedList<int> list;
	list.insertAtTail(1);
	list.insertAtTail(5);
	list.insertAtTail(10);
	list.remove(5);
	list.displayForward();
	EXPECT_EQ(list.search(5), nullptr);
}
TEST(LinkedListTest, RemoveHead) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.insertAtTail(10);
	list.remove(5);
	list.displayForward();
	EXPECT_EQ(list.search(5), nullptr);
}
TEST(LinkedListTest, RemoveTail) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.insertAtTail(10);
	list.remove(10);
	list.displayForward();
	EXPECT_EQ(list.search(10), nullptr);
}

TEST(LinkedListTest, RemoveNonExistent) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.remove(99);
	list.displayForward();
	EXPECT_NE(list.search(5), nullptr); // unchanged
}
TEST(LinkedListTest, RemoveBeforeMiddle) {
	LinkedList<int> list;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.removeBefore(3); // removes 2
	list.displayForward();
	EXPECT_EQ(list.search(2), nullptr);
}
TEST(LinkedListTest, RemoveBeforeHeadNoChange) {
	LinkedList<int> list;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.removeBefore(1); // nothing happens
	list.displayForward();
	EXPECT_NE(list.search(1), nullptr);
}
TEST(LinkedListTest, RemoveAfterMiddle) {
	LinkedList<int> list;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.insertAtTail(3);
	list.insertAtTail(4);
	list.removeAfter(2); // removes 3
	list.displayForward();
	EXPECT_EQ(list.search(3), nullptr);
}
TEST(LinkedListTest, RemoveAfterTailNoChange) {
	LinkedList<int> list;
	list.insertAtTail(1);
	list.insertAtTail(2);
	list.removeAfter(2); // nothing happens
	list.displayForward();
	EXPECT_NE(list.search(2), nullptr);
}
// ---------- UTILITY TESTS ----------
TEST(LinkedListTest, IsEmpty) {

	LinkedList<int> list;
	list.displayForward();
	EXPECT_TRUE(list.isEmpty());
	list.insertAtHead(10);
	list.displayForward();
	EXPECT_FALSE(list.isEmpty());
}
TEST(LinkedListTest, SearchFound) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.displayForward();
	EXPECT_NE(list.search(5), nullptr);
}
TEST(LinkedListTest, SearchNotFound) {
	LinkedList<int> list;
	list.insertAtTail(5);
	list.displayForward();
	EXPECT_EQ(list.search(50), nullptr);
}
TEST(LinkedListTest, ReverseList) {
	LinkedList<int> list;
	list.displayForward();
	for (int i = 1; i <= 4; i++) list.insertAtTail(i);
	list.reverse(); // should be 4 → 3 → 2 → 1
	list.displayForward();
	EXPECT_NE(list.search(4), nullptr);
	EXPECT_NE(list.search(1), nullptr);
}
TEST(LinkedListTest, ReverseEmpty) {
	LinkedList<int> list;
	list.reverse(); // should not crash
	list.displayForward();
	EXPECT_TRUE(list.isEmpty());
}
TEST(LinkedListTest, ReverseSingle) {
	LinkedList<int> list;
	list.insertAtTail(10);
	list.reverse();
	list.displayForward();
	EXPECT_NE(list.search(10), nullptr);
}
// ---------- EDGE & STRESS TEST ----------
TEST(LinkedListTest, LargeInsertAndRemove) {
	LinkedList<int> list;
	for (int i = 0; i < 1000; i++) list.insertAtTail(i);
	//list.displayForward();
	EXPECT_EQ(list.search(500)->data, 500);
	list.remove(500);

	//list.displayForward();
	EXPECT_EQ(list.search(500), nullptr);
}

// ---------- MERGE SORTED LIST TESTS ----------
TEST(MergeSortedTest, MergeTwoNonEmptyLists) {
	LinkedList<int> L1, L2;
	L1.insertAtTail(1);
	L1.insertAtTail(3);
	L1.insertAtTail(5);
	L2.insertAtTail(2);
	L2.insertAtTail(4);
	L2.insertAtTail(6);

	LinkedList<int> merged = L1.mergeSorted(L2);
	// Check sorted order
	std::vector<int> expected = { 1,2,3,4,5,6 };
	node<int>* curr = merged.head;
	for (int val : expected) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, val);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
	// Original lists must remain unchanged
	EXPECT_NE(L1.search(1), nullptr);
	EXPECT_NE(L2.search(2), nullptr);
}
TEST(MergeSortedTest, MergeWithEmptyList1) {
	LinkedList<int> L1, L2;
	L1.insertAtTail(10);
	L1.insertAtTail(20);
	L1.insertAtTail(30);
	LinkedList<int> merged = L1.mergeSorted(L2);
	std::vector<int> expected = { 10,20,30 };
	node<int>* curr = merged.head;
	for (int val : expected) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, val);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
}
TEST(MergeSortedTest, MergeWithEmptyList2) {
	LinkedList<int> L1, L2;
	L2.insertAtTail(5);
	L2.insertAtTail(15);
	L2.insertAtTail(25);
	LinkedList<int> merged = L1.mergeSorted(L2);
	std::vector<int> expected = { 5,15,25 };
	node<int>* curr = merged.head;

	for (int val : expected) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, val);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
}
TEST(MergeSortedTest, MergeBothEmptyLists) {
	LinkedList<int> L1, L2;
	LinkedList<int> merged = L1.mergeSorted(L2);
	EXPECT_TRUE(merged.isEmpty());
}
TEST(MergeSortedTest, MergeWithDuplicates) {
	LinkedList<int> L1, L2;
	L1.insertAtTail(1);
	L1.insertAtTail(3);
	L1.insertAtTail(5);
	L2.insertAtTail(1);	
	L2.insertAtTail(3);
	L2.insertAtTail(7);
	LinkedList<int> merged = L1.mergeSorted(L2);
	std::vector<int> expected = { 1,1,3,3,5,7 };
	node<int>* curr = merged.head;
	for (int val : expected) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, val);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
}
TEST(MergeSortedTest, MergeWithInterleavingValues) {
	LinkedList<int> L1, L2;
	L1.insertAtTail(1);
	L1.insertAtTail(4);
	L1.insertAtTail(8);
	L2.insertAtTail(2);
	L2.insertAtTail(3);
	L2.insertAtTail(9);

	LinkedList<int> merged = L1.mergeSorted(L2);
	std::vector<int> expected = { 1,2,3,4,8,9 };
	node<int>* curr = merged.head;
	for (int val : expected) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, val);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
}
TEST(MergeSortedTest, LargeLists) {
	LinkedList<int> L1, L2;
	for (int i = 0; i < 1000; i += 2) L1.insertAtTail(i); // even numbers
	for (int i = 1; i < 1000; i += 2) L2.insertAtTail(i); // odd numbers
	LinkedList<int> merged = L1.mergeSorted(L2);
	node<int>* curr = merged.head;
	for (int i = 0; i < 1000; i++) {
		ASSERT_NE(curr, nullptr);
		EXPECT_EQ(curr->data, i);
		curr = curr->next;
	}
	EXPECT_EQ(curr, nullptr);
}