
using System;

public class Solution
{
    private struct Job
    {
        public int difficulty;
        public int profit;
        public Job(int difficulty, int profit)
        {
            this.difficulty = difficulty;
            this.profit = profit;
        }
    }
    public int MaxProfitAssignment(int[] jobDifficulty, int[] jobProfit, int[] maxDifficultyPerWorker)
    {
        int totalJobs = jobDifficulty.Length;
        Job[] jobs = new Job[totalJobs];
        for (int i = 0; i < totalJobs; ++i)
        {
            jobs[i] = new Job(jobDifficulty[i], jobProfit[i]);
        }

        Array.Sort(jobs, (x, y) => x.difficulty - y.difficulty);
        Array.Sort(maxDifficultyPerWorker);

        int index = 0;
        int totalMaxProfit = 0;
        int currentMaxProfit = 0;

        foreach (var difficulty in maxDifficultyPerWorker)
        {
            while (index < totalJobs && jobs[index].difficulty <= difficulty)
            {
                currentMaxProfit = Math.Max(currentMaxProfit, jobs[index].profit);
                ++index;
            }
            totalMaxProfit += currentMaxProfit;
        }

        return totalMaxProfit;
    }
}
