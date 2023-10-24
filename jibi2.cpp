#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// 定义一个结构存储活动的开始和结束时间
struct Activity {
    int start;
    int end;
};

// 用于排序的比较函数
bool compare(const Activity &a, const Activity &b) {
    return a.start < b.start;
}

int minPresenters(vector<Activity> &activities) {
    sort(activities.begin(), activities.end(), compare);  // 按开始时间排序

    vector<int> presenters;  // 存储每个主持人的结束时间

    for (auto &activity : activities) {
        bool assigned = false;

        for (auto &presenter_end_time : presenters) {
            if (presenter_end_time <= activity.start) {
                presenter_end_time = activity.end;  // 更新这名主持人的结束时间
                assigned = true;
                break;
            }
        }

        if (!assigned) {
            presenters.push_back(activity.end);
        }
    }

    return presenters.size();
}
vector<Activity> parseInput(const string &input) {
    vector<Activity> result;

    // 删除所有的 '{' 和 '}'
    string modified = input;
    modified.erase(remove(modified.begin(), modified.end(), '{'), modified.end());
    modified.erase(remove(modified.begin(), modified.end(), '}'), modified.end());
    stringstream ss(modified);
    int numArrays, num;
    char ch;
    ss >> numArrays;
    ss >> ch; // 跳过逗号
    while (numArrays--) {
        Activity ac;
        ss >> num;
        ac.start = (num);
        ss >> ch; // 跳过逗号

        ss >> num;
        ac.end = (num);
        ss >> ch; // 跳过逗号
        result.push_back(ac);
    }

    return result;
}
int main() {
    string line;
    vector<int> res;
    while (getline(cin,line))
    {
        vector<Activity> actvs = parseInput(line);
        res.push_back(minPresenters(actvs));
    }
    for(int a : res){
        cout << a << endl;
    }

    return 0;
}
