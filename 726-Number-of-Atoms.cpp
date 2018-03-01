/*
  Number of Atoms

  Given a chemical formula (given as a string), return the count of each atom.

  An atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.

  1 or more digits representing the count of that element may follow if the count is greater than 1. If the count is 1, no digits will follow. For example, H2O and H2O2 are possible, but H1O2 is impossible.

  Two formulas concatenated together produce another formula. For example, H2O2He3Mg4 is also a formula.

  A formula placed in parentheses, and a count (optionally added) is also a formula. For example, (H2O2) and (H2O2)3 are formulas.

  Given a formula, output the count of all elements as a string in the following form: the first name (in sorted order), followed by its count (if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

  Example 1:
  Input: 
  formula = "H2O"
  Output: "H2O"
  Explanation: 
  The count of elements are {'H': 2, 'O': 1}.
  Example 2:
  Input: 
  formula = "Mg(OH)2"
  Output: "H2MgO2"
  Explanation: 
  The count of elements are {'H': 2, 'Mg': 1, 'O': 2}.
  Example 3:
  Input: 
  formula = "K4(ON(SO3)2)2"
  Output: "K4N2O14S4"
  Explanation: 
  The count of elements are {'K': 4, 'N': 2, 'O': 14, 'S': 4}.
  Note:

  All atom names consist of lowercase letters, except for the first character which is uppercase.
  The length of formula will be in the range [1, 1000].
  formula will only consist of letters, digits, and round parentheses, and is a valid formula as defined in the problem.

 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef pair<string, map<string, int>> mypair;

string fetch(const string& formula, int& pos) {
    char c = formula[pos];
    if(c - 'A' >= 0 && c - 'A' < 26) {
        int cur = pos;
        pos += 1;
        while(pos < formula.size() && formula[pos] - 'a' >= 0 && formula[pos] - 'a' < 26)
            pos += 1;
        return formula.substr(cur, pos - cur);
    }
    else if(c - '0' >= 0 && c - '0' < 10) {
        int cur = pos;
        pos += 1;
        while(pos < formula.size() && formula[pos] - '0' >= 0 && formula[pos] - '0' < 10)
            pos += 1;
        return formula.substr(cur, pos - cur);
    }
    else
        return "";
}

vector<string> split(string formula) {
    int pos = 0;
    vector<string> res;
    while(pos < formula.length())
        res.push_back(fetch(formula, pos));
    return res;
}

bool isNum(string s) {
    if(s.empty())
        return false;
    return s[0] - '0' >= 0 && s[0] - '0' < 10;
}

vector<string> preprocessing(string formula) {
    int pos = 0;
    vector<string> res;
    formula = "(" + formula + ")1";
    while(pos < formula.length()) {
        int end = formula.find_first_of("()", pos);
        if(end == -1)
            end = formula.length();
        string atom = formula.substr(pos, end - pos);
        if(!atom.empty())
            res.push_back(atom);
        if(end < formula.length()) {
            if(formula[end] == '(') {
                res.push_back("(");
                end += 1;
            }
            else {
                res.push_back(")");
                end += 1;
                int tmp = end;
                while(end < formula.length() && formula[end] - '0' >= 0 && formula[end] - '0' < 10)
                    end += 1;
                res.push_back(formula.substr(tmp, end - tmp));
            }
        }
        pos = end;
    }
    return res;
}

map<string, int> count(string formula) {
    map<string, int> cnt;
    vector<string> atoms = split(formula);
    int i = 0;
    while(i < atoms.size()) {
        string atom = atoms[i];
        int k = 1;
        i += 1;
        if(i < atoms.size() && isNum(atoms[i])) {
            k = stoi(atoms[i]);
            i += 1;
        }
        if(cnt.find(atom) != cnt.end())
            cnt[atom] += k;
        else
            cnt[atom] = k;
    }
    return cnt;
}

string countOfAtoms(string formula) {
    vector<string> formulas = preprocessing(formula);
    /*
      for(auto item: formulas)
      cout << item << " ";
      cout << endl;
    */
    stack<mypair> stk;
    int i = 0;
    while(i < formulas.size()) {
        if(formulas[i] == "(") {
            stk.push(mypair("(", {}));
            i += 1;
        }
        else if(formulas[i] == ")") {
            int k = stoi(formulas[i + 1]);
            map<string, int> tmp;
            while(!stk.empty() && stk.top().first != "(") {
                for(auto item: stk.top().second) {
                    if(tmp.find(item.first) != tmp.end())
                        tmp[item.first] += k * item.second;
                    else
                        tmp[item.first] = k * item.second;
                }
                stk.pop();
            }
            stk.pop();
            stk.push(mypair("+", tmp));
            i += 2;
        }
        else {
            map<string, int> cnt = count(formulas[i]);
            stk.push(mypair("+", cnt));
            i += 1;
        }
    }
    map<string, int> res = stk.top().second;
    string s = "";
    for(auto item: res) {
        s += item.first;
        if(item.second > 1)
            s += to_string(item.second);
    }
    return s;
}
