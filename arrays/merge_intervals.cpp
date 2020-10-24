/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

void fixInterval(Interval& a) {
    if (a.start > a.end) {
        swap(a.start, a.end);
    }
}
bool isDisjoint(const Interval& a, const Interval& b) {
    return a.end < b.start || b.end < a.start;
}
bool tryMerge(Interval& a, Interval toMerge) {
    if (isDisjoint(a, toMerge)) {
        return false;
    } else {
        a.start = min(a.start, toMerge.start);
        a.end = max(a.end, toMerge.end);
        return true;
    }
}

vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    int size = intervals.size();
    int pos = 0;
    vector<Interval> ans;
    for (int i = 0; i < size; ++i) {
        fixInterval(intervals[i]);
    }
    fixInterval(newInterval);
    while (pos < size && intervals[pos].start < newInterval.start && isDisjoint(intervals[pos], newInterval)) {
        ans.push_back(intervals[pos++]);
    }
    while (pos < size && !isDisjoint(intervals[pos], newInterval)) {
        tryMerge(newInterval, intervals[pos++]);
    }
    ans.push_back(newInterval);
    while (pos < size) {
        ans.push_back(intervals[pos++]);
    }
    return ans;
}
