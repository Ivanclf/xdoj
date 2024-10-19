#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<string>
using namespace std;
class Solution
{
public:
    string isValid(string s)
    {

        for (auto it = s.begin(); it != s.end(); ++it)
            left.push(*it);
        right.push(left.top());
        left.pop();
        while (!left.empty())
        {
            if ((right.top() == '}' && right.top() - left.top() == 2)||( right.top() == ']' && right.top() - left.top() == 2) || (right.top() == ')' && right.top() - left.top() == 1))
            {
                left.pop();
                right.pop();
                if(right.empty() && !left.empty())
                {
                    right.push(left.top());
                    left.pop();
                }
            }
            else
            {
                right.push(left.top());
                left.pop();
            }
        }
        if (left.empty() && right.empty())
            return "yes";
        else
            return "no";
    }

private:
    stack<char> left;
    stack<char> right;
};
int main()
{
    int n;
    Solution solution;
    cin >> n;
    string s, t;
    vector<string> couple;
    for(int i = 0; i < n; i++){
        cin >> s;
        for(auto it = s.begin(); it != s.end(); ++it)
            if(*it == '(' || *it == ')' || *it == '[' || *it == ']' || *it == '{' || *it == '}')
                t.push_back(*it);
        couple.push_back(s);
        }
    for(int i = 0; i < n; i++)
        cout << solution.isValid(couple[i]) << endl;
    return 0;
    
}