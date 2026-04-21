Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

 

Example 1:

Input: s = "3+2*2"
Output: 7
Example 2:

Input: s = " 3/2 "
Output: 1
Example 3:

Input: s = " 3+5 / 2 "
Output: 5
 

int calculate(char* s) {
     int len = strlen(s);
    int stack[len];
    int top = -1;
    int num = 0;
    char sign = '+';

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }

        if ((!isdigit(c) && !isspace(c)) || i == len - 1) {
            if (sign == '+') {
                stack[++top] = num;
            } else if (sign == '-') {
                stack[++top] = -num;
            } else if (sign == '*') {
                int val = stack[top--];
                stack[++top] = val * num;
            } else if (sign == '/') {
                int val = stack[top--];
                stack[++top] = val / num;
            }
            sign = c;
            num = 0;
        }
    }

    int result = 0;
    for (int i = 0; i <= top; i++) {
        result += stack[i];
    }
    return result;

}