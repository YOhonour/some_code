/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
#include "../stdc++.h"
using namespace std;

class Solution
{
public:
    int findMinStep(string board, string hand)
    {
        unordered_set<string> visited;
        queue<State> q;
        sort(hand.begin(), hand.end());
        q.emplace(board, hand);

        int level = 0;
        while (!q.empty())
        {
            int n = q.size();
            level++;
            for (int t = 0; t < n; t++)
            {
                // 对每一个此时的状态的进行操作
                State cur_state = q.front();
                q.pop();
                for (int j = 0; j < cur_state.board.size(); j++)
                { // 遍历 球队列 j 为插入的位置
                    // 跳过相同的字符 新字符插入最左端的
                    // if (j != 0 && cur_state.board[j - 1] == cur_state.board[j])
                    //     continue;
                    bool a2 = false;
                    for (int i = 0; i < cur_state.hand.size(); i++)
                    {                                                            // 遍历 手中的球 i 为插入的球
                        if (i > 0 && cur_state.hand[i - 1] == cur_state.hand[i]) // 跳过重复球
                                                                                 // 第 1 个剪枝条件：手中颜色相同的球每次选择时只需要考虑其中一个即可
                            continue;

                        // 如果插入球的颜色与插入位置上一个球相同 那么应该跳过哦
                        // 第 2 个剪枝条件：只在连续相同颜色的球的开头位置或者结尾位置插入新的颜色相同的球
                        if (j > 0 && cur_state.board[j - 1] == cur_state.hand[i])
                            continue;
                        bool flag = false;
                        if (j - 1 >= 0 && cur_state.board[j] == cur_state.board[j - 1] && cur_state.board[j] != cur_state.hand[i])
                        {
                            // 第 2 种情况 : 当前后颜色相同且与当前颜色不同时候放置球
                            flag = true;
                        }
                        if (cur_state.board[j] == cur_state.hand[i])
                        {
                            //  第 1 种情况 : 当前球颜色与后面的球的颜色相同
                            flag = true;
                        }
                        if (flag == false)
                            continue;
                        string newBoard = (cur_state.board.substr(0, j) + cur_state.hand[i] + cur_state.board.substr(j));
                        string newHand = (cur_state.hand.substr(0, i) + cur_state.hand.substr(i + 1));
                        // newBoard.insert(j, 1, cur_state.hand.at(i));
                        // newHand.erase(newHand.begin() + i);
                        newBoard = clean(newBoard);
                        if (newBoard.empty())
                            return level;
                        if (!newBoard.empty() && newHand.empty())
                            continue;
                        if (!visited.count(newBoard + ' ' + hand))
                        {
                            visited.insert(newBoard + ' ' + hand);
                            q.emplace(newBoard, newHand);
                        }
                    }
                }
            }
        }
        return -1;
    }

    string clean(string &board)
    {
        vector<pair<char, int>> visited_ball;
        char cur_color = board.front();
        for (int i = 0; i < board.size(); i++)
        {
            cur_color = board[i];
            while (!visited_ball.empty() && cur_color != visited_ball.back().first && visited_ball.back().second >= 3)
            {
                visited_ball.pop_back();
            }
            if (visited_ball.empty() || cur_color != visited_ball.back().first)
            {
                visited_ball.push_back({cur_color, 1});
            }
            else
            {
                visited_ball.back().second++;
            }
        }
        if (visited_ball.back().second >= 3)
        {
            visited_ball.pop_back();
        }
        string s;
        for (auto &it : visited_ball)
        {
            s.append(it.second, it.first);
        }
        return s;
    }

private:
    class State
    {
    public:
        string board;
        string hand;
        State(string board_, string hand_) : board(board_), hand(hand_)
        {
        }
    };
};
int main()
{
    Solution s;
    string str = "wwwbbwwaaaebbbbb";
    string board = "RRGGBBYYWWRRGGBB";
    string hand = "RGBYW";
    auto nums = s.findMinStep(board, hand);
    // auto a = s.clean(str);
    // cout << a << endl;
    return 0;
}
// @lc code=end
