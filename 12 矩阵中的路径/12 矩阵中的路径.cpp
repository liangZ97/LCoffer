#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
* 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。
例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）
[["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]]
但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {//利用回溯法和递归做
        if (word.empty()) return false;
        //int rows = board.size();
        //int columns = board[0]. size();
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int i, int j,unsigned int k) {//k表示现在和word[k]进行比较，利用k访问word
        //如果访问越界，则返回false。因为这里要应用递归，所以所有的判断条件这里都要进行
        if (i < 0 || i >= board.size()
            || j < 0 || j >= board[0].size()
            || board[i][j] != word[k]) 
            return false;//因为这里直接用了k作为word的索引，所以k从0开始
        //判断是否只剩下一个字符，成功直接返回true，这是单个字符的结束条件，也是成功递归的结束条件
        if (k == word.size() - 1) 
            return true;//成功递归条件
        //因为不能再次访问该节点的值，暂时将该节点置为保护值
        char temp = board[i][j];
        board[i][j] = '\0';
        //对上下左右四个方向进行搜索（采用递归），随便一个方向找到即可
        if (dfs(board, word, i - 1, j, k + 1)
            || dfs(board, word, i + 1, j, k + 1)
            || dfs(board, word, i, j - 1, k + 1)
            || dfs(board, word, i, j + 1, k + 1)) 
            return true;
        //找不到将该节点恢复，继续进行下一个符合节点的遍历
        board[i][j] = temp;
        return false;
    }
};


int main() {
    vector<vector<char>> board = { {'A', 'B', 'C', 'E'} ,{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'} };
    string word = "ABCCED";
    if (Solution().exist(board, word)==true)
        cout << "test01 passed" << endl;
    else
        cout << "test01 failed" << endl;
    board = { {'a'} };
    word = "a";
    if (Solution().exist(board, word) == true)
        cout << "test02 passed" << endl;
    else
        cout << "test02 failed" << endl;
    return 0;
}
