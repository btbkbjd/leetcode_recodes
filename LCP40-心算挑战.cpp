class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        // ÷2 单纯为了之后在sum里做加减法的时候不溢出。
        int min_ele[2] = {INT_MAX/2, INT_MAX/2};
        int max_ele[2] = {INT_MIN/2, INT_MIN/2};
        int N = cards.size();
        /* nth_element:使得某个元素位于其最终排序位置上，左侧的元素不大于它，右侧的元素不小于它。
         * 这里结合投影使用，就可以实现倒序。
         */
        ranges::nth_element(cards, cards.begin() + cnt, std::greater<int>()); 
        int sum = reduce(cards.begin(), cards.begin() + cnt, 0); // 最大的 cnt 个数之和
        if(sum % 2 == 0) return sum; 
        
        for(int i = 0; i < cnt; ++i){
            int v = cards[i];
            min_ele[v % 2] = min(min_ele[v % 2], v);// 最小的被替换掉的奇数为min_ele[1],偶数为min_ele[0]
        }
        for(int i = cnt; i < N; ++i){
            int v = cards[i];
            max_ele[v % 2] = max(max_ele[v % 2], v);// 最大的被替换进来的奇数为max_ele[1],偶数为max_ele[0]
        }

        // 如果没有出现max_ele[0]或max_ele[1]之一，则为0；如果没有出现min_ele[0]或min_ele[1]之一，则为0，很巧
        sum = max(sum + max(max_ele[0] - min_ele[1], max_ele[1] - min_ele[0]), 0);
        return sum;
    }
};