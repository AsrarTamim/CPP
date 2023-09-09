class Solution {
public:
    set<string> st;  // Change set<int> to set<string>
    int n;
    string s;

    void f(int i) {
        if (i == n) {
            st.insert(s);
            return;
        }

        if (s[i] >= '0' && s[i] <= '9') {
            f(i + 1);
        }

        f(i + 1);

        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else {
            s[i] = toupper(s[i]);
        }

        f(i + 1);
        return;
    }

    vector<string> letterCasePermutation(string ss) {
        n = ss.size();
        s = ss;
        f(0);
        vector<string> v;
        for (auto x : st) v.push_back(x);
        return v;
    }
};
