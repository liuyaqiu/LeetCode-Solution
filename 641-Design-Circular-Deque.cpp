class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        vals_ = vector<int>(k);
        start_ = 0;
        size_ = 0;
    }

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        vals_[(start_ - 1 + vals_.size()) % vals_.size()] = value;
        start_ = (start_ - 1 + vals_.size()) % vals_.size();
        size_ += 1;
        return true;
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        vals_[(start_ + size_) % vals_.size()] = value;
        size_ += 1;
        return true;
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        start_ = (start_ + 1) % vals_.size();
        size_ -= 1;
        return true;
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        size_ -= 1;
        return true;
    }

    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return vals_[start_];
    }

    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return vals_[(start_ + size_ - 1) % vals_.size()];
    }

    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return size_ == vals_.size();
    }

private:
    vector<int> vals_;
    int start_ = 0;
    int size_ = 0;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */