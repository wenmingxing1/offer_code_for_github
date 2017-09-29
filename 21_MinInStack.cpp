class Solution {
public:
    std::stack<int> stack_data, min_data;
    void push(int value) {
        stack_data.push(value);
        if (min_data.empty())
            min_data.push(value);

        if (value < min_data.top()){
            min_data.push(value);
        }
        else {
            min_data.push(min_data.top());
        }
    }
    void pop() {
        stack_data.pop();
        min_data.pop();
    }
    int top() {
        return stack_data.top();
    }
    int min() {
		return min_data.top();
    }
};
