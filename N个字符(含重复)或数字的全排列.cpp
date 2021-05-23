class Solution {
public:
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end()); //按照字典序输出

        vector<string> ret;
        set<string> uniq_set; //用于去掉重复结果
        string cur_ret = "";

        dfs(str, cur_ret, ret, uniq_set);
        
        return ret;
    }
    
    void dfs(string str, string cur_ret, vector<string> &ret, set<string> &uniq_set) {
        if (str.length() == 0 ) {
            if(find(uniq_set.begin(), uniq_set.end(), cur_ret) == uniq_set.end()){
                ret.push_back(cur_ret);
                uniq_set.insert(cur_ret);
            }
            return;
        }
        for (auto iter = str.begin(); iter != str.end(); iter++) {
            char t_char =  *iter;

            cur_ret = cur_ret + t_char;
            str.erase(iter); //下一级的递归中不能再有这个使用过的元素

            dfs(str, cur_ret, ret, uniq_set);

            cur_ret.pop_back();
            str.insert(iter, t_char); //再换下一个元素作为“开头”开始全排列，使用过的这个元素要重新加入
        }
    }
};