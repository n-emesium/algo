#define RESTR 1000000007
int update(int *buckets, int n) {
    int ind = 31, ans = 0, t;
    while (n) {
        t = n & 1;
        buckets[ind--] += t;
        n >>= 1;
        ans += t;
    }
    return ans;
}
int maxSum(int* nums, int s, int k) {
    int t = s - 1, b, c, buckets[32] = {0};
    unsigned long long ans = 0ULL, tb = 0ULL;
    for (int i = 0; i < s; i++) {
        tb += update(buckets, nums[i]);
        nums[i] = 0;
    }
    while (tb) {
        b = 0;
        for (int i = 31; i > -1; i--) {
            c = !!buckets[i];
            b |= c << (31 - i);
            tb -= c;
            buckets[i] -= c;
        }
        nums[t--] = b;
    }
    t = s - 1;
    for (int i = 0; i < k; i++) {
        ans = (ans + ((tb = nums[t--]) * tb)) % RESTR;
    }
    return ans;
}

