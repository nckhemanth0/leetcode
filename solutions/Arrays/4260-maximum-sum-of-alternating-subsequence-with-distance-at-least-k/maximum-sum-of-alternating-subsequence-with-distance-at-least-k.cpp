class Solution {
public:
    using ll = long long;
    const ll NEG = -4e18;

    struct SegTree {
        int n;
        vector<ll> seg;

        SegTree(int n) {
            this->n = n;
            seg.assign(4 * n + 5, -4e18);
        }

        void update(int node, int l, int r, int idx, ll val) {
            if(l == r) {
                seg[node] = max(seg[node], val);
                return;
            }

            int mid = (l + r) / 2;

            if(idx <= mid) update(2 * node, l, mid, idx, val);
            else update(2 * node + 1, mid + 1, r, idx, val);

            seg[node] = max(seg[2 * node], seg[2 * node + 1]);
        }

        ll query(int node, int l, int r, int ql, int qr) {
            if(qr < l || r < ql) return -4e18;

            if(ql <= l && r <= qr) return seg[node];

            int mid = (l + r) / 2;

            return max(query(2 * node, l, mid, ql, qr),
                    query(2 * node + 1, mid + 1, r, ql, qr));
        }

        void update(int idx, ll val) {
            update(1, 0, n - 1, idx, val);
        }

        ll query(int l, int r) {
            if(l > r) return -4e18;
            return query(1, 0, n - 1, l, r);
        }
    };

    long long maxAlternatingSum(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        int m = vals.size();

        vector<ll> up(n), down(n);

        SegTree peakTree(m);   // stores dp where last relation was up/peak
        SegTree valleyTree(m); // stores dp where last relation was down/valley

        ll ans = NEG;

        for(int i = 0; i < n; i++) {
            if(i - k >= 0) {
                int j = i - k;
                int id = lower_bound(vals.begin(), vals.end(), nums[j]) - vals.begin();

                peakTree.update(id, up[j]);
                valleyTree.update(id, down[j]);
            }

            int id = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();

            up[i] = nums[i];
            down[i] = nums[i];

            // previous value < current value, so current becomes peak
            ll bestLess = valleyTree.query(0, id - 1);
            if(bestLess != NEG) {
                up[i] = max(up[i], bestLess + nums[i]);
            }

            // previous value > current value, so current becomes valley
            ll bestGreater = peakTree.query(id + 1, m - 1);
            if(bestGreater != NEG) {
                down[i] = max(down[i], bestGreater + nums[i]);
            }

            ans = max({ans, up[i], down[i]});
        }

        return ans;
    }
};