class MinStack {
public:
    void push(int val) {
        auto top{ m_min_stack.empty() ? val : m_min_stack.top() };
        m_stack.push(val);
        m_min_stack.push(std::min(val, top));
    }
    
    void pop() {
        m_stack.pop();
        m_min_stack.pop();
    }
    
    int top() {
        return m_stack.top();
    }
    
    int getMin() {
        return m_min_stack.top();
    }

private:
    std::stack<int> m_stack;
    std::stack<int> m_min_stack;
};
