Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

bool isValid(char* s) {
      int len = strlen(s);
    char *stack = (char*)malloc(len * sizeof(char));  // dynamic allocation
    int top = -1;
    
    for (int i = 0; i < len; i++) {
        char c = s[i];
        
        if (c == '(' || c == '[' || c == '{') {
            stack[++top] = c;  // push
        } else {
            if (top == -1) { free(stack); return false; }
            
            char last = stack[top--];  // pop
            if ((c == ')' && last != '(') ||
                (c == ']' && last != '[') ||
                (c == '}' && last != '{')) {
                free(stack);
                return false;
            }
        }
    }
    
    bool result = (top == -1);
    free(stack);
    return result;

}