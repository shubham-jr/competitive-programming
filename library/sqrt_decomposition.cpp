class Solution {
public:

    vector<long long>build(vector<int>&nums, int root) {
        if (nums.empty() || root == 0) return {};

        int temp = root;
        vector<long long>batch((nums.size() / root) + 1, 0ll);
        long long sum = 0ll;
        for (int i = 0; i < nums.size(); i++) {
            batch[i / root] += (long long)nums[i];
        }
        return batch;
    }

    void sqrt_decomposition(vector<int>&nums, vector<long long>&batch, int l, int r) {
        int len = nums.size();
        int root = sqrt(len);

        int batch_l = l / root;
        int batch_r = r / root;

        long long sum = 0ll;

        if (batch_l == batch_r) {
            for (int i = l; i <= r; i++)sum += (long long)nums[i];
        } else {
            // left
            for (int i = l; i < (batch_l + 1)*root; i++)sum += (long long)nums[i];
            // middle
            for (int i = (batch_l + 1); i < batch_r; i++)sum += (long long)batch[i];
            // right
            for (int i = (batch_r) * root; i <= r; i++)sum += (long long)nums[i];
        }

        cout << sum << endl;

    }
};
