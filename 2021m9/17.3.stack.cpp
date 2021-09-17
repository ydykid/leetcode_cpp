class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        this->q1 = queue<int>();
        this->q2 = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        this->q2.push(x);
        while (!this->q1.empty()){
            int v = this->q1.front();
            this->q2.push(v);
            this->q1.pop();
        }
        swap(this->q1, this->q2);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int v = this->q1.front();
        this->q1.pop();
        return v;
    }
    
    /** Get the top element. */
    int top() {
        return this->q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return this->q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */