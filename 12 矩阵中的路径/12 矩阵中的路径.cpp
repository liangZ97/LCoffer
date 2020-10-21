#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
* �����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ��
���һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
���磬�������3��4�ľ����а���һ���ַ�����bfce����·����·���е���ĸ�üӴֱ����
[["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]]
�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {//���û��ݷ��͵ݹ���
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
    bool dfs(vector<vector<char>>& board, string& word, int i, int j,unsigned int k) {//k��ʾ���ں�word[k]���бȽϣ�����k����word
        //�������Խ�磬�򷵻�false����Ϊ����ҪӦ�õݹ飬�������е��ж��������ﶼҪ����
        if (i < 0 || i >= board.size()
            || j < 0 || j >= board[0].size()
            || board[i][j] != word[k]) 
            return false;//��Ϊ����ֱ������k��Ϊword������������k��0��ʼ
        //�ж��Ƿ�ֻʣ��һ���ַ����ɹ�ֱ�ӷ���true�����ǵ����ַ��Ľ���������Ҳ�ǳɹ��ݹ�Ľ�������
        if (k == word.size() - 1) 
            return true;//�ɹ��ݹ�����
        //��Ϊ�����ٴη��ʸýڵ��ֵ����ʱ���ýڵ���Ϊ����ֵ
        char temp = board[i][j];
        board[i][j] = '\0';
        //�����������ĸ�����������������õݹ飩�����һ�������ҵ�����
        if (dfs(board, word, i - 1, j, k + 1)
            || dfs(board, word, i + 1, j, k + 1)
            || dfs(board, word, i, j - 1, k + 1)
            || dfs(board, word, i, j + 1, k + 1)) 
            return true;
        //�Ҳ������ýڵ�ָ�������������һ�����Ͻڵ�ı���
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
