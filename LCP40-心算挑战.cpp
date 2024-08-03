class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        int min_odd = INT_MAX, min_even = INT_MAX, max_even = INT_MIN, max_odd = INT_MIN;
        int N = cards.size();
        ranges::sort(cards, greater());
        int sum = reduce(cards.begin(), cards.begin() + cnt, 0);
        
        if(sum % 2 == 0) return sum; 
        
        for(int i = 0; i < cnt; ++i){
            if(cards[i] % 2 != 0) min_odd = cards[i];
            else min_even = cards[i];
        }
        for(int i = N - 1; i >= cnt; --i){
            if(cards[i] % 2 != 0) max_odd = cards[i];
            else max_even = cards[i];
        }

        int t1 = max_odd != INT_MIN && min_even != INT_MAX ? sum - min_even + max_odd : 0;
        int t2 = max_even != INT_MIN && min_odd != INT_MAX ? sum - min_odd + max_even : 0;
        sum = max(t1, t2);

        return sum;
    }
};