class MyCircularQueue {
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        vals_ = vector<int>(k);
        start_ = 0;
        size_ = 0;
    }

    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        vals_[(start_ + size_) % vals_.size()] = value;
        size_ += 1;
        return true;
    }

    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        start_ = (start_ + 1) % vals_.size();
        size_ -= 1;
        return true;
    }

    /** Get the front item from the queue. */
    int Front() {
        if (size_ <= 0) {
            return -1;
        }
        return vals_[start_];
    }

    /** Get the last item from the queue. */
    int Rear() {
        if (size_ == 0) {
            return -1;
        }
        return vals_[(start_ + size_ - 1) % vals_.size()];
    }

    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size_ == 0;
    }

    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size_ == vals_.size();
    }

private:
    vector<int> vals_;
    int start_ = -1;
    int size_ = -1;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */