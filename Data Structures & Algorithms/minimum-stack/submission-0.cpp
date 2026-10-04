class MinStack {
public:
    void push(int val) {
        m_stack.push(val);
        m_ms.insert(val);
    }
    
    void pop() {
        const auto top{ m_stack.top() };
        m_ms.erase(m_ms.find(top));
        m_stack.pop();
    }
    
    int top() {
        return m_stack.top(); 
    }
    
    int getMin() {
        return *m_ms.cbegin(); 
    }

private:
    std::stack<int> m_stack;
    std::multiset<int> m_ms;
};
