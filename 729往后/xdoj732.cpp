#include <iostream>
#include <stack>
#include <string>
enum direction
{
    failed,
    right,
    down,
    left,
    up
};
enum surroundings
{
    uncover,
    blocked,
    covered
};
surroundings map[105][105] = {uncover};
int m, n;
typedef struct Axis
{
    int x;
    int y;
    surroundings is_right;
    surroundings is_left;
    surroundings is_up;
    surroundings is_down;
    direction dir;
} axis;

axis judge(axis target)
{

    if (target.y == n - 1)
        target.is_right = blocked;
    else
        target.is_right = map[target.x][target.y + 1];

    if (!target.y)
        target.is_left = blocked;
    else
        target.is_left = map[target.x][target.y - 1];

    if (!target.x)
        target.is_up = blocked;
    else
        target.is_up = map[target.x - 1][target.y];

    if (target.x == m - 1)
        target.is_down = blocked;
    else
        target.is_down = map[target.x + 1][target.y];

    return target;
}
axis direction_confirmed(axis target, bool is_forward)
{
    surroundings status;
    if (is_forward)
        status = uncover;
    else
        status = covered;

    if (target.is_right == status)
        target.dir = right;
    else if (target.is_down == status)
        target.dir = down;
    else if (target.is_left == status)
        target.dir = left;
    else if (target.is_up == status)
        target.dir = up;
    else
        target.dir = failed;
    return target;
}
axis step_forwards(axis target)
{
    if (target.dir == right)
    {
        map[target.x][target.y] = covered;
        target.y++;
    }
    else if (target.dir == down)
    {
        map[target.x][target.y] = covered;
        target.x++;
    }
    else if (target.dir == left)
    {
        map[target.x][target.y] = covered;
        target.y--;
    }
    else if (target.dir == up)
    {
        map[target.x][target.y] = covered;
        target.x--;
    }
    return target;
}
int main()
{
    axis begin, end, temp;
    int num;
    std::stack<axis> track;

    std::cin >> m >> n >> begin.x >> begin.y >> end.x >> end.y;
    begin.x--, begin.y--, end.x--, end.y--;

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            std::cin >> num;
            switch (num)
            {
            case 0:
                map[i][j] = uncover;
                break;
            case 1:
                map[i][j] = blocked;
            }
        }
    temp = begin;
    while (true)
    {
        temp.dir = right;
        if (temp.x == end.x && temp.y == end.y)
        {
            track.push(temp);
            break;
        }
        temp = judge(temp);
        temp = direction_confirmed(temp, true);
        if (temp.dir)
        {
            track.push(temp);
            temp = step_forwards(temp);
        }
        else
        {
            if (temp.x == begin.x && temp.y == begin.y)
                break;
            else
            {
                map[temp.x][temp.y] = blocked;
                temp = track.top();
                temp = direction_confirmed(temp, false);
                track.pop();
            }
        }
    }

    if (!track.empty() && track.top().x == end.x && track.top().y == end.y)
    {
        std::stack<axis> temp;
        std::string s;
        while (!track.empty())
        {
            temp.push(track.top());
            track.pop();
        }
        while (!temp.empty())
        {
            s.append("(").append(std::to_string(temp.top().x + 1)).append(",").append(std::to_string(temp.top().y + 1)).append(",").append(std::to_string(temp.top().dir)).append("),");
            temp.pop();
        }
        s.pop_back();
        std::cout << s << std::endl;
    }
    else
        std::cout << "no" << std::endl;
    return 0;
}