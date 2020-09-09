/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) {
            return head;
        }
        Node* the_next = flatten(head->next);
        Node* the_child = flatten(head->child);
        if (the_child != nullptr) {
            head->child = nullptr;
            head->next = the_child;
            the_child->prev = head;
            Node* tail = the_child;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = the_next;
            if (the_next != nullptr) {
                the_next->prev = tail;
            }
        }
        return head;
    }
};