/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct comparator {
    bool operator()(const Interval& a, const Interval& b) const {
        if (a.start != b.start) {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
};

int cmp(const Interval &a, const Interval b) {
}

vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    sort(A.begin(), A.end(), comparator());
    Interval current = A[0];
    vector<Interval> merged;
    for (int i = 1; i < A.size(); ++i) {
        if (A[i].start <= current.end) {
            if (A[i].end > current.end) {
                current.end = A[i].end;
            }
        } else {
            merged.push_back(current);
            current = A[i];
        }
    }
    merged.push_back(current);
    return merged;
}
