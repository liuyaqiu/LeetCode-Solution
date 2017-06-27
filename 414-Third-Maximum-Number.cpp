#include <iostream>
#include <vector>

using namespace std;

/*
 * Third Maximum Number
 *
 * Given a non-empty array of integers, return the third maximum number in this array. If it does not exist, return the maximum number. The time complexity must be in O(n).
 *
 * Example 1:
 * Input: [3, 2, 1]
 *
 * Output: 1
 *
 * Explanation: The third maximum is 1.
 * Example 2:
 * Input: [1, 2]
 *
 * Output: 2
 *
 * Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
 * Example 3:
 * Input: [2, 2, 3, 1]
 *
 * Output: 1
 *
 * Explanation: Note that the third maximum here means the third maximum distinct number.
 * Both numbers with value 2 are both considered as second maximum.
 *
 *
 */

struct Node {
    int val;
    Node* next;
    Node(int x): val(x), next(NULL) {}
};

class ThridNumber {
private:
    Node* head;
    int n;

public:
    ThridNumber(): head(new Node(0)), n(0) {}
    void insert(int v) {
        Node* pre = head;
        Node* cur = head->next;
        while(cur != NULL && cur->val < v) {
            pre = cur;
            cur = cur->next;
        }
        if(cur != NULL && cur->val == v)
            return;
        Node* tmp = new Node(v);
        pre->next = tmp;
        tmp->next = cur;
        n++;
        if(n > 3) {
            Node* p = head->next;
            head->next = p->next;
            delete(p);
            n--;
        }
    }

    int getRes() {
        if(n == 0)
            return -1;
        else if(n == 2)
            return head->next->next->val;
        else
            return head->next->val;
    }
};

int thirdMax(vector<int>& nums) {
    ThridNumber tn = ThridNumber();
    for(auto n: nums)
        tn.insert(n);
    return tn.getRes();
}

int main() {
    int val;
    vector<int> nums;
    while(cin >> val)
        nums.push_back(val);
    int res = thirdMax(nums);
    cout << res << endl;
    return 0;
}
