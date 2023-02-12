class Solution {
    enum State { INIT, SIGN, DOT, DIGIT };
public:
    bool isNumber(string s) {
        State state = INIT;
        bool before_e = true, is_integer = true;
        for (int i = 0; i < s.length(); i++) {
            switch (state) {
                case INIT:
                    if (s[i] == '+' || s[i] == '-') {
                        state = SIGN;
                    } else if (before_e && s[i] == '.') {
                        state = DOT;
                    } else if (isdigit(s[i])) {
                        state = DIGIT;
                    } else {
                        return false;
                    }
                    break;
                case SIGN:
                    if (isdigit(s[i])) {
                        state = DIGIT;
                    } else if (before_e && s[i] == '.') {
                        state = DOT;
                    } else {
                        return false;
                    }
                    break;
                case DOT:
                    if (isdigit(s[i])) {
                        state = DIGIT;
                        is_integer = false;
                    } else {
                        return false;
                    }
                    break;
                case DIGIT:
                    if (before_e && (s[i] == 'e' || s[i] == 'E')) {
                        state = INIT;
                        before_e = false;
                    } else if (is_integer && before_e && s[i] == '.') {
                        is_integer = false;
                    } else if (!isdigit(s[i])) {
                        return false;
                    }
                    break;
            }
        }
        return state == DIGIT;
    }
};

class Solution {
public:
    bool isNumber(string s) {
        bool dot_seen = false, digit_seen = false, e_seen = false, sign_seen = false;
        for (int i = 0; i < s.length(); i++) {
            if (isdigit(s[i])) {
                digit_seen = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (sign_seen || digit_seen || dot_seen) {
                    return false;
                }
                sign_seen = true;
            } else if (s[i] == '.') {
                if (dot_seen || e_seen) {
                    return false;
                }
                dot_seen = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (e_seen || !digit_seen) {
                    return false;
                }
                e_seen = true;
                digit_seen = sign_seen = dot_seen = false;
            } else {
                return false;
            }
        }
        return digit_seen;
    }
};
