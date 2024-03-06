class Solution {
public:
    bool isValid(string s) {
        if (s.size() & 1) return false;
        stack<char> a;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[') a.push(c);
            else
            {
                if (a.empty()) return false;
                else if (a.top()+1 == c || a.top()+2 == c) a.pop();
                else return false;    
            }
        }
        return a.empty();
    }
};