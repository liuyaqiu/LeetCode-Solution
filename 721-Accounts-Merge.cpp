/*
  Accounts Merge

  Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

  Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

  After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

  Example 1:
  Input: 
  accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
  Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
  Explanation: 
  The first and third John's are the same person as they have the common email "johnsmith@mail.com".
  The second John and Mary are different people as none of their email addresses are used by other accounts.
  We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
  ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
  Note:

  The length of accounts will be in the range [1, 1000].
  The length of accounts[i] will be in the range [1, 10].
  The length of accounts[i][j] will be in the range [1, 30].

 */

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct Node {
    string name;
    string email;  //define different node
    unordered_set<string> neighbor;

    Node(string _name, string _email): name(_name), email(_email) {}
};

void dfs(vector<string>& account, unordered_set<string>& visit, unordered_map<string, Node*>& refer, Node* node) {
    if(visit.find(node->email) != visit.end())
        return;
    visit.insert(node->email);
    account.push_back(node->email);
    for(auto nb: node->neighbor) {
        auto nb_node = refer[nb];
        dfs(account, visit, refer, nb_node);
    }
}

vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_set<string> dict;
    unordered_map<string, Node*> refer;
    for(auto account: accounts) {
        string name = account[0];
        for(int i = 1; i < account.size(); i++) {
            if(refer.find(account[i]) == refer.end()) {
                refer[account[i]] = new Node(name, account[i]);
                dict.insert(account[i]);
            }
        }
        for(int i = 1; i < account.size(); i++) {
            auto node = refer[account[i]];
            for(int j = 1; j < account.size(); j++) {
                if(account[j] != account[i])
                    node->neighbor.insert(account[j]);
            }
        }
    }
    vector<vector<string>> result;
    unordered_set<string> visit;
    for(auto item: dict) {
        if(visit.find(item) != visit.end())
            continue;
        auto node = refer[item];
        vector<string> emails;
        dfs(emails, visit, refer, node);
        sort(emails.begin(), emails.end());
        vector<string> account;
        account.push_back(node->name);
        for(auto email: emails)
            account.push_back(email);
        result.push_back(account);
    }
    return result;
}
