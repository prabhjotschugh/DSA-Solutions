class Solution {
public:
    int partitionString(string s) {
        int partitions = 1;
        vector<int> last_seen(26, -1);
        int new_partition_idx = 0;
        for(int i = 0; i < s.size(); i++) { 
            int idx = s.at(i) - 'a';
            if(last_seen[idx] >= new_partition_idx) {
                partitions++;
                new_partition_idx = i;
            }
            last_seen[idx] = i;
        }
        return partitions;
    }
};