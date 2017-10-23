/*
  Minimum Index Sum of Two Lists

  Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
Note:
The length of both lists will be in the range of [1, 1000].
The length of strings in both lists will be in the range of [1, 30].
The index is starting from 0 to the list length minus 1.
No duplicates in both lists.

 */

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    map<string, int> index1, index2;
    for(int i = 0; i < list1.size(); i++)
        index1[list1[i]] = i;
    for(int i = 0; i < list2.size(); i++)
        index2[list2[i]] = i;
    vector<string> res;
    int cnt = -1;
    for(auto item: index1) {
        if(index2.find(item.first) != index2.end()) {
            int tmp = item.second + index2[item.first];
            if(tmp == cnt)
                res.push_back(item.first);
            if(cnt == -1 || tmp < cnt){
                res = {item.first};
                cnt = tmp;
            }
        }
    }
    return res;
}
