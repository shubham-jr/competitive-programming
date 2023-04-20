class FenwickTree {
public:
    vector<int>ft;

    FenwickTree(int n) {
        ft.resize(n);
    }

    void update(int index, int val) {
        while (index < ft.size()) {
            ft[index] += val;
            index += (index & (-index));
        }
    }

    int sum(int index) {
        int s = 0;
        while (index) {
            s += ft[index];
            index -= (index & (-index));
        }
        return s;
    }

    int rangeSum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void getTreeVector() {
        debug(ft);
    }
};