string convert(string email) {
    int at_index = email.find_first_of('@');
    int plus_index = email.find_first_of('+');
    if (plus_index == -1 || plus_index > at_index) {
        plus_index = at_index;
    }
    string res;
    for (int i = 0; i < plus_index; i++) {
        if (email[i] != '.') {
            res += email[i];
        }
    }
    return res + email.substr(at_index, email.length() - at_index);
}
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> unique_emails;
        for (const string& email : emails) {
            unique_emails.insert(convert(email));
        }
        return unique_emails.size();
    }
};