#include <stack>

class MinStack {
    private:
        std::stack<int> main_st; // Holds all the normal values
        std::stack<int> min_st; // The "shadow" stack that only holds minimums
public:
    MinStack() {
        
    }
    
    void push(int val) {
        // push stack
        main_st.push(val);
        if (min_st.empty()) {
            min_st.push(val);
        } else {
            if (val <= min_st.top()) {
                // min_st.pop();
                min_st.push(val);
            }
        }
    }
    
    void pop() {
        // pop stack
        if (!min_st.empty()){
            if (main_st.top() == min_st.top()) {
                min_st.pop();
            }
        }
        main_st.pop();
    }
    
    int top() {
        // top stack
        return main_st.top();
    }
    
    int getMin() {
        // top min stack
        return min_st.top();
    }
};
