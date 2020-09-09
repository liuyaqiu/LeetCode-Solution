/*
 * Design your implementation of the linked list. You can choose to use the singly linked list or the doubly linked list. A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node. If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
 *
 * Implement these functions in your linked list class:
 *
 * get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.
 * addAtHead(val) : Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
 * addAtTail(val) : Append a node of value val to the last element of the linked list.
 * addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted.
 * deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 * Example:
 *
 * MyLinkedList linkedList = new MyLinkedList();
 * linkedList.addAtHead(1);
 * linkedList.addAtTail(3);
 * linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
 * linkedList.get(1);            // returns 2
 * linkedList.deleteAtIndex(1);  // now the linked list is 1->3
 * linkedList.get(1);            // returns 3
 * Note:
 *
 * All values will be in the range of [1, 1000].
 * The number of operations will be in the range of [1, 1000].
 * Please do not use the built-in LinkedList library.
 *
 */

#include <vector>
#include <cstdio>

using namespace std;

struct MyListNode {
    int val;
    MyListNode* prev;
    MyListNode* next;
    MyListNode(int x): val(x), prev(NULL), next(NULL) {}
};

class MyLinkedList {
    private:
    MyListNode* head;
    MyListNode* tail;
    
    public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        int i = 0;
        MyListNode* cur = head;
        while(i < index && cur != NULL) {
            cur = cur->next;
            i += 1;
        }
        if(cur != NULL)
            return cur->val;
        else
            return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        MyListNode* cur = new MyListNode(val);
        cur->next = head;
        if(head != NULL)
            head->prev = cur;
        head = cur;
        if(tail == NULL)
            tail = cur;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        MyListNode* cur = new MyListNode(val);
        cur->prev = tail;
        if(tail != NULL)
            tail->next = cur;
        tail = cur;
        if(head == NULL)
            head = cur;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int i = 0;
        MyListNode* p = head;
        while(i < index && p != NULL) {
            i += 1;
            p = p->next;
        }
        if(p == NULL) {
            if(i != index)
                return;
            else
                addAtTail(val);
        }
        else {
            MyListNode* cur = new MyListNode(val);
            p->prev->next = cur;
            cur->prev = p->prev;
            cur->next = p;
            p->prev = cur;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int i = 0;
        MyListNode* p = head;
        while(i < index && p != NULL) {
            i += 1;
            p = p->next;
        }
        if(p != NULL) {
            if(p->prev != NULL)
                p->prev->next = p->next;
            if(p->next != NULL)
                p->next->prev = p->prev;
            if(p == head)
                head = p->next;
            if(p == tail)
                tail = p->prev;
            delete p;
        }
    }
};

