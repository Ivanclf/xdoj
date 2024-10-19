#include <stack>
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;

int main()
{
    int n, m, t;
    int temp_num, temp_index, temp;
    string output;
    stack<int> first_number, second_number, result;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_num >> temp_index;
        while (temp_index != first_number.size())
            first_number.push(0);
        first_number.push(temp_num);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp_num >> temp_index;
        while (temp_index != second_number.size())
            second_number.push(0);
        second_number.push(temp_num);
    }
    temp = first_number.size() - second_number.size();
    if (temp < 0)
        temp = 0 - temp;
    if (first_number.size() > second_number.size())
        for (int i = 0; i < temp; i++)
            second_number.push(0);
    else
        for (int i = 0; i < temp; ++i)
            first_number.push(0);
    while (!(first_number.empty() || second_number.empty()))
    {
        if (t)
        {
            result.push(first_number.top() - second_number.top());
            first_number.pop();
            second_number.pop();
        }
        else
        {
            result.push(first_number.top() + second_number.top());
            first_number.pop();
            second_number.pop();
        }
    }
    for (int i = 0; !result.empty(); i++)
    {
        if (!result.top())
        {
            result.pop();
            continue;
        }
        if(!i)
        {
            output.append(to_string(result.top()));
            result.pop();
            continue;
        }
        if(abs(result.top()) != 1)
        {
            if(output.empty() || result.top() < 0)
                output.append(to_string(result.top())).append("x");
            else
                output.append("+").append(to_string(result.top())).append("x");
        }
        else
        {
            if(result.top() == 1)
            {
                if(output.empty())
                    output.append("x");
                else
                    output.append("+x");
            }
            else
                output.append("-x");
        }
        if(i > 1)
            output.append("^").append(to_string(i));
        result.pop();
    }
    if(output.empty())
        output.append(to_string(0));
    cout << output << endl;
    return 0;
}