/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {

    }
    
    void push(int x) 
    {
        stack_.push(x);
        if (minstack_.empty() || minstack_.top() >= x)
            minstack_.push(x);
    }
    
    void pop() 
    {
        if (!stack_.empty())
        {
            if (!minstack_.empty() && stack_.top() == minstack_.top())
                minstack_.pop();
            stack_.pop();
        }
    }
    
    int top() 
    {
        return stack_.top();
    }
    
    int getMin() 
    {
        return minstack_.top();
    }

private:
    std::stack<int> stack_;
    std::stack<int> minstack_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

