#include <iostream>
#include <algorithm>
using namespace std;

struct student {
    int no, grade1, grade2, grade3;
    double average;
    string name;
};

bool cmp(student a, student b) {
    if (a.average > b.average)
        return 1;
    else if (a.average == b.average && a.no < b.no)
        return 1;
    
    return 0;
}

int main() {
    struct student stu[110];
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> stu[i].no >> stu[i].name >> stu[i].grade1 >> stu[i].grade2 >> stu[i].grade3;
    
    for (int i = 0; i < n; i++)
        stu[i].average = (stu[i].grade1 + stu[i].grade2 + stu[i].grade3) / 3.0;

    sort(stu, stu + n, cmp);

    for (int i = 0; i < n; i++)
        printf("%d %s %.1lf\n", stu[i].no, stu[i].name.c_str(), stu[i].average);

    return 0;
}