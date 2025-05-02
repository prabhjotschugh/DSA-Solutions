class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        vector<int> task_requirements = tasks;
        vector<int> worker_strengths = workers;
        int total_pills = pills;
        int pill_boost = strength;
        sort(task_requirements.begin(), task_requirements.end());
        sort(worker_strengths.begin(), worker_strengths.end());

        auto can_assign = [&](int k) {
            vector<int> avail(worker_strengths.end() - k, worker_strengths.end());
            int pills_remain = total_pills;
            for (int i = k - 1; i >= 0; --i) {
                int req = task_requirements[i];
                if (!avail.empty() && avail.back() >= req) {
                    avail.pop_back();
                } else {
                    if (pills_remain <= 0) return false;
                    int threshold = req - pill_boost;
                    auto it = lower_bound(avail.begin(), avail.end(), threshold);
                    if (it == avail.end()) return false;
                    avail.erase(it);
                    --pills_remain;
                }
            }
            return true;
        };

        int low = 0, high = min((int)tasks.size(), (int)workers.size()), completed = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (can_assign(mid)) {
                completed = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return completed;
    }
};