#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct Card {
    int type, x, y;
};
bool compare(const Card& a, const Card& b) {return a.x+a.y > a.x+b.y;}
struct Compare_X {
    bool operator() (const Card& a, const Card& b) const {
        return a.x < b.x;
    }
};
int maxDamage(int n, int m, vector<Card>& cards) {
    sort(cards.begin(), cards.end(), compare);
    queue<Card> odd_cards, even_cards;
    for (Card c : cards) {
        if (c.type == 1) {
            odd_cards.push(c);
        } else {
            even_cards.push(c);
        }
    }
    int total_damage = 0;
    int odd_gap = 0;
    int even_gap = 0;
    for (int i = 1; i <= m; ++i) {
        if (i % 2 == 1 && !odd_cards.empty()) {
            Card c = odd_cards.front();
            odd_cards.pop();
            total_damage += (c.x + c.y);
        } else if (i % 2 == 0 && !even_cards.empty()) {
            Card c = even_cards.front();
            even_cards.pop();
            total_damage += (c.x + c.y);
        } else if (!odd_cards.empty()) {
            odd_gap++;
        } else if (!even_cards.empty()) {
            even_gap++;
        }
    }
    if(odd_gap!=0 ||even_gap!=0){
        priority_queue<Card,vector<Card>, Compare_X> last;
        //剩余卡加入
        while (!odd_cards.empty())
        {
            Card c = odd_cards.front();
            odd_cards.pop();
            last.push(c);
        }
        //剩余卡加入
        while (!even_cards.empty())
        {
            Card c = even_cards.front();
            even_cards.pop();
            last.push(c);
        }
        while (odd_gap!=0)
        {
            Card c = last.top();
            last.pop();
            total_damage += (c.x);
            odd_gap--;
        }
        while (even_gap!=0)
        {
            Card c = last.top();
            last.pop();
            total_damage += (c.x);
            even_gap--;
        }
        

    }
    return total_damage;
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<Card> cards(n);
    for(int i = 0; i < n; i++) {
        cin >> cards[i].type >> cards[i].x >> cards[i].y;
    }
    cout << maxDamage(n,m,cards);
    return 0;
}