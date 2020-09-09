class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int name_index = 0;
        int typed_index = 0;
        while (name_index < name.length() && typed_index < typed.length()) {
            if (name[name_index] != typed[typed_index]) {
                return false;
            }
            int cur_name_index = name_index;
            while (name_index < name.length() && name[name_index] == name[cur_name_index]) {
                name_index++;
            }
            int cur_typed_index = typed_index;
            while (typed_index < typed.length() && typed[typed_index] == typed[cur_typed_index]) {
                typed_index++;
            }
            if (typed_index - cur_typed_index < name_index - cur_name_index) {
                return false;
            }
        }
        return name_index == name.length() && typed_index == typed.length();
    }
};