class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        int min_odd = 0, min_even = 0, max_even = 0, max_odd = 0, sum = 0;
        int N = cards.size();
        sort(cards.rbegin(), cards.rend());
        for(int i = 0; i < cnt; ++i){
            sum += cards[i];
            if(cards[i] % 2 != 0) min_odd = cards[i];
            else min_even = cards[i];
        }
        for(int i = N - 1; i >= cnt; --i){
            if(cards[i] % 2 != 0) max_odd = cards[i];
            else max_even = cards[i];
        }
        if(sum % 2 != 0)
        {
            int t1 = max_odd - min_even;
            int t2 = max_even - min_odd;
            if(max_even && max_odd && min_even && min_odd) sum += max(t2, t1);
            else if(max_odd && min_even) sum += t1;
            else if(max_even && min_odd) sum += t2;
            else sum = 0;
        } 
        return sum;
    }
};