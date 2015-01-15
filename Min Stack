class MinStack {
public:
    void push(int x) {
        stk.push(x);
        if(mins.empty() || x<=mins.top())
            mins.push(x);
    }

    void pop() {
        if(stk.top()==mins.top())
            mins.pop();
        stk.pop();
    }

    int top() {
        return stk.top();
    }

    int getMin() {
        return mins.top();
    }
private:
    stack<int> stk;
    stack<int> mins;
};
