#include <iostream>
#include <string>

bool isMatch(char* s, char* p) {
    if(*p == '\0')
        return *s == '\0';
    if(*(p + 1) != '*')
        return (*p == *s || *p == '.' && *s != '\0') && isMatch(s + 1, p + 1);
    else {
        while(*s != '\0' && (*p == '.' || *s == *p)) {
            if(isMatch(s, p + 2))
                return true;
            s += 1;
        }
        return isMatch(s, p + 2);
    }
}
