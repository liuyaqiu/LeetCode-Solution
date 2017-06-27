#include <iostream>
#include <vector>

using namespace std;

/*
 * Data Stream as Disjoint Intervals
 *
 * Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
 *
 * For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
 *
 * [1, 1]
 * [1, 1], [3, 3]
 * [1, 1], [3, 3], [7, 7]
 * [1, 3], [7, 7]
 * [1, 3], [6, 7]
 * Follow up:
 * What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
 *
 *
 */

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

struct Node {
    Interval itv;
    Node* left;
    Node* right;
    Node(Interval i): itv(i), left(NULL), right(NULL) {}
};

void insert(Node* root, int val) {
    if(val == root->itv.start - 1) {
        root->itv.start = val;
        Node* lpre = root;
        Node* lnode = root->left;
        if(lnode == NULL)
            return;
        while(lnode->right != NULL) {
            lpre = lnode;
            lnode = lnode->right;
        }
        if(lnode->itv.end + 1 == val) {
        	if(lpre != root)
            	lpre->right = lnode->left;
            else
            	lpre->left = lnode->left;
            root->itv.start = lnode->itv.start;
            delete(lnode);
        }
    }
    else if(val == root->itv.end + 1) {
        root->itv.end = val;
        Node* rpre = root;
        Node* rnode = root->right;
        if(rnode == NULL)
            return;
        while(rnode->left != NULL) {
            rpre = rnode;
            rnode = rnode->left;
        }
        if(rnode->itv.start - 1 == val) {
            if(rpre != root)
                rpre->left = rnode->right;
            else
                rpre->right = rnode->right;
            root->itv.end = rnode->itv.end;
            delete(rnode);
        }
    }
    else if(val < root->itv.start - 1) {
        if(root->left == NULL) {
            Node* cur = new Node(Interval(val, val));
            root->left = cur;
        }
        else
            insert(root->left, val);
    }
    else if(val > root->itv.end + 1) {
        if(root->right == NULL) {
            Node* cur = new Node(Interval(val, val));
            root->right = cur;
        }
        else
            insert(root->right, val);
    }
}

void inOrder(Node* root, vector<Interval>& res) {
    if(root == NULL)
        return;
    if(root->left != NULL)
        inOrder(root->left, res);
    res.push_back(root->itv);
    if(root->right != NULL)
        inOrder(root->right, res);
}
 
class SummaryRanges {
private:
    Node* root;

public:
    SummaryRanges(): root(NULL) {}

    void addNum(int val) {
        if(root == NULL) {
            root = new Node(Interval(val, val));
        }
        else
            insert(root, val);
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        inOrder(root, res);
        return res;
    }
};

void print(vector<Interval>& res) {
    for(auto itv: res)
        cout << itv.start << " " << itv.end << endl;
    cout << endl;
}

int main() {
    SummaryRanges obj = SummaryRanges();
    vector<Interval> res;
    int val;
    cin >> val;
    obj.addNum(val);
    res = obj.getIntervals();
    print(res);
    cin >> val;
    obj.addNum(val);
    res = obj.getIntervals();
    print(res);
    cin >> val;
    obj.addNum(val);
    res = obj.getIntervals();
    print(res);
    cin >> val;
    obj.addNum(val);
    res = obj.getIntervals();
    print(res);
    cin >> val;
    obj.addNum(val);
    res = obj.getIntervals();
    print(res);
    return 0;
}
