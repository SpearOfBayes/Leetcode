/* 
*  作者：肖子洋
*  算法：先将字符串统一排序，再用一个map判断是否重复
*  运行效率：Runtime: 24 ms, faster than 75.39% of C++ online submissions for Group Anagrams.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        //用temp数组来保存排序后的字符串数组
        vector<string> temp(strs);
        
        //对所有单词排序
        for (auto it = temp.begin(); it != temp.end(); it++) {
            sort(it->begin(), it->end());
        }
        
        //用一个map作为映射，key值为已经存在的字符串，value值为第几个group
        map<string, int> m;
        int index = 0;
        for (int i = 0; i < temp.size(); i++) {
            auto it = m.find(temp[i]);
            //如果字符串不存在于map中
            if (it == m.end()) {
                vector<string> element;
                element.push_back(strs[i]);
                ans.push_back(element);
                m.insert(pair<string, int>(temp[i], index++));
            }
            //字符串已存在map中
            else {
                ans[it->second].push_back(strs[i]);
            }
        }
        
        return ans;
    }
};