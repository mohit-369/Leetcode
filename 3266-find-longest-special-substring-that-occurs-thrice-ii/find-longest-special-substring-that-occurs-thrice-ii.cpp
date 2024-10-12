class Solution {
public:
    int maximumLength(string s) {
    int lo = -1, hi = s.size();
    while (lo < hi) {
        int mid = lo + (hi - lo + 1 >> 1), len = 0, last = 0;
        array<int, 128> cnt{};
        for (char c : s) {
            len = c == last ? len + 1 : 1;
            last = c;
            if (len >= mid)
                cnt[c]++;
        }
        bool valid = false;
        for (char c = 'a'; !valid && c <= 'z'; c++)
            if (cnt[c] >= 3)
                valid = true;
        if (valid)
            lo = mid;
        else
            hi = mid - 1;
    }
    return lo;
}
};