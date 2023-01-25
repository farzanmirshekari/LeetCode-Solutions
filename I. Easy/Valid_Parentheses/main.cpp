#include <string>
#include <stack>

class Solution {
    public:
        bool is_valid(std::string s) {
            std::stack<char> character_stack;
            for (auto i : s) {
                if (i == '(' || i == '{' || i == '[') {
                    character_stack.push(i);
                }
                else {
                    if (
                        (character_stack.empty())                  || 
                        (character_stack.top() == '(' && i != ')') ||
                        (character_stack.top() == '{' && i != '}') || 
                        (character_stack.top() == '[' && i != ']')
                    ) {
                        return false;
                    }
                    character_stack.pop();
                }
            }
            return character_stack.empty();
        }
};