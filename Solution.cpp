
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    struct Job {
        int difficulty;
        int profit;
        Job() = default;
        Job(int difficulty, int profit) : difficulty {difficulty}, profit {profit}{}
    };

public:
    int maxProfitAssignment(vector<int>& jobDifficulty, vector<int>& jobProfit, vector<int>& maxDifficultyPerWorker) const {
        int totalJobs = jobDifficulty.size();
        vector<Job>jobs(totalJobs);
        for (int i = 0; i < totalJobs; ++i) {
            jobs[i].difficulty = jobDifficulty[i];
            jobs[i].profit = jobProfit[i];
        }
        const auto compare = [](const Job& first, const Job& second) {return first.difficulty < second.difficulty;};
        //C++20: std::ranages::sort(jobs, compare) 
        //       std::ranages::sort(maxDifficultyPerWorker)  
        sort(jobs.begin(), jobs.end(), compare);
        sort(maxDifficultyPerWorker.begin(), maxDifficultyPerWorker.end());

        int index = 0;
        int totalMaxProfit = 0;
        int currentMaxProfit = 0;

        for (const auto& difficulty : maxDifficultyPerWorker) {
            while (index < totalJobs && jobs[index].difficulty <= difficulty) {
                currentMaxProfit = max(currentMaxProfit, jobs[index].profit);
                ++index;
            }
            totalMaxProfit += currentMaxProfit;
        }

        return totalMaxProfit;
    }
};
