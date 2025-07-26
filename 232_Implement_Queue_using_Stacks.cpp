class MyQueue {
public:
    stack<int> inStack, outStack;

    MyQueue() {
    }

    void push(int x) {
        inStack.push(x);
    }

    int pop() {
        shiftStacks();
        int front = outStack.top();
        outStack.pop();
        return front;
    }

    int peek() {
        shiftStacks();
        return outStack.top();
    }

    bool empty() {
        return inStack.empty() && outStack.empty();
    }

private:
    void shiftStacks() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
};
