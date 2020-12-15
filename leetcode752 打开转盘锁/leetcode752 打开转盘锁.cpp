#include<iostream>
#include<queue>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;
/*
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。
输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
*/
class Solution {
    string plusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '9' ? '0' : s[pos] + 1;
        return res;
    }
    string minusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '0' ? '9' : s[pos] - 1;
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        //BFS,将每个数字视为拥有8个邻接点,每次加一或者减一
        //将一位数字相邻遍历完后,遍历下一位数字
        unordered_set<string> deadstring;
        unordered_set<string> visited;
        for (auto s : deadends) deadstring.insert(s);
        string begin = "0000";
        int step = 0;
        visited.insert(begin);
        queue<string> qu;
        qu.push(begin);
        //这里是从主节点单向扩散，改为双向扩散虽然时间复杂度未降低，但是访问的节点数将减少
        while (!qu.empty()) {
            size_t size = qu.size();
            while (size--) {
                string cur = qu.front();
                qu.pop();
                if (cur == target) return step;
                if (deadstring.count(cur)) continue;
                //visited.insert(cur);
                for (int i = 0; i < 4; ++i) {
                    string curUp = plusOne(cur, i);
                    if (!visited.count(curUp)) {
                        qu.push(curUp);
                        visited.insert(curUp);
                    }
                    string curDown = minusOne(cur, i);
                    if (!visited.count(curDown)) {
                        qu.push(curDown);
                        visited.insert(curDown);
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};

//双向扩散
class Solution1 {
    string plusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '9' ? '0' : s[pos] + 1;
        return res;
    }
    string minusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '0' ? '9' : s[pos] - 1;
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadstring;
        unordered_set<string> visited;
        for (auto s : deadends) deadstring.insert(s);
        unordered_set<string> hashSet1;
        unordered_set<string> hashSet2;
        hashSet1.insert("0000");
        hashSet2.insert(target);
        int step = 0;
        while (!hashSet1.empty() && !hashSet2.empty()) {
            // if (hashSet1.size() > hashSet2.size())
            //     swap(hashSet1, hashSet2);
            unordered_set<string> temp;
            for (auto cur : hashSet1) {
                if (hashSet2.count(cur)) return step;
                if (deadstring.count(cur)) continue;
                visited.insert(cur);
                for (int i = 0; i < 4; ++i) {
                    string curUp = plusOne(cur, i);
                    if (!visited.count(curUp)) {
                        temp.insert(curUp);
                        //因为是交替搜索，如果此时将数值压入visited会造成两个hash无法重合
                        //visited.insert(curUp);
                    }
                    string curDown = minusOne(cur, i);
                    if (!visited.count(curDown)) {
                        temp.insert(curDown);
                        //visited.insert(curDown);
                    }
                }
            }
            ++step;
            hashSet1 = hashSet2;
            hashSet2 = temp;
        }
        return -1;
    }
};

int main() {
    vector<string> deadends = { "8887","8889","8878","8898","8788","8988","7888","9888" };
    string target = "8888";
    //string target = "2002";
    int step = Solution().openLock(deadends, target);
    cout << step << endl;
    return 0;
}

class Solution2 {
    string plusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '9' ? '0' : s[pos] + 1;
        return res;
    }
    string minusOne(const string& s, int pos) {
        string res(s);
        res[pos] = s[pos] == '0' ? '9' : s[pos] - 1;
        return res;
    }
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadstring;
        unordered_set<string> visited;
        for (auto s : deadends) deadstring.insert(s);
        unordered_set<string> hashSet1;
        unordered_set<string> hashSet2;
        hashSet1.insert("0000");
        hashSet2.insert(target);
        int step = 0;
        while (!hashSet1.empty() && !hashSet2.empty()) {
            // if (hashSet1.size() > hashSet2.size())
            //     swap(hashSet1, hashSet2);
            unordered_set<string> temp;
            for (auto cur : hashSet1) {
                if (hashSet2.count(cur)) return step;
                if (deadstring.count(cur)) continue;
                visited.insert(cur);
                for (int i = 0; i < 4; ++i) {
                    string curUp = plusOne(cur, i);
                    if (!visited.count(curUp)) {
                        temp.insert(curUp);
                        //visited.insert(curUp);
                    }
                    string curDown = minusOne(cur, i);
                    if (!visited.count(curDown)) {
                        temp.insert(curDown);
                        //visited.insert(curDown);
                    }
                }
            }
            ++step;
            hashSet1 = hashSet2;
            hashSet2 = temp;
        }
        return -1;
    }
};