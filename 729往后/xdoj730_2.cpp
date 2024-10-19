#include <stack>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class poly
{
public:
    poly(int number, int index)
    {
        this->number = number;
        this->index = index;
    }
    int get_number()
    {
        return this->number;
    }
    int get_index()
    {
        return this->index;
    }
    poly *next;
private:
    int index;
    int number;

};
int main()
{
    stack<poly> first_number, second_number, result;
    string output;
    int temp_number, temp_index, n, m, t;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> temp_number >> temp_index;
        first_number.push(poly(temp_number, temp_index));
    }
    for (int i = 0; i < m; i++)
    {
        cin >> temp_number >> temp_index;
        second_number.push(poly(temp_number, temp_index));
    }
    while (!(first_number.empty() || second_number.empty()))
    {
        if (first_number.top().get_index() > second_number.top().get_index())
        {
            result.push(poly(first_number.top().get_number(), first_number.top().get_index()));
            first_number.pop();
        }
        else if (first_number.top().get_index() < second_number.top().get_index())
        {
            if (t)
                result.push(poly(0 - second_number.top().get_number(), second_number.top().get_index()));
            else
                result.push(poly(second_number.top().get_number(), second_number.top().get_index()));
            second_number.pop();
        }
        else
        {
            if (t)
                result.push(poly(first_number.top().get_number() - second_number.top().get_number(), second_number.top().get_index()));
            else
                result.push(poly(first_number.top().get_number() + second_number.top().get_number(), second_number.top().get_index()));
            first_number.pop();
            second_number.pop();
        }
    }
    while (!first_number.empty())
    {
        result.push(poly(first_number.top().get_number(), first_number.top().get_index()));
        first_number.pop();
    }
    if (t)
        while (!second_number.empty())
        {
            result.push(poly(0 - second_number.top().get_number(), second_number.top().get_index()));
            second_number.pop();
        }
    else
        while (!second_number.empty())
        {
            result.push(poly(second_number.top().get_number(), second_number.top().get_index()));
            second_number.pop();
        }
    while (!result.empty())
    {
        if (!result.top().get_number())
        {
            result.pop();
            continue;
        }
        if (!result.top().get_index())
        {
            output.append(to_string(result.top().get_number()));
            result.pop();
            continue;
        }
        if (abs(result.top().get_number()) != 1)
        {
            if (output.empty() || result.top().get_number() < 0)
                output.append(to_string(result.top().get_number())).append("x");
            else
                output.append("+").append(to_string(result.top().get_number())).append("x");
        }
        else
        {
            if (result.top().get_number() == 1)
            {
                if (output.empty())
                    output.append("x");
                else
                    output.append("+x");
            }
            else
                output.append("-x");
        }
        if (result.top().get_index() > 1 || result.top().get_index() < 0)
            output.append("^").append(to_string(result.top().get_index()));
        result.pop();
    }
    if (output.empty())
        output.append(to_string(0));
    cout << output << endl;
    return 0;
}