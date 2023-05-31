
import java.util.Arrays;

public class Solution {

    private record Job(int difficulty, int profit) {}

    public int maxProfitAssignment(int[] jobDifficulty, int[] jobProfit, int[] maxDifficultyPerWorker) {
        int totalJobs = jobDifficulty.length;
        Job[] jobs = new Job[totalJobs];
        for (int i = 0; i < totalJobs; ++i) {
            jobs[i] = new Job(jobDifficulty[i], jobProfit[i]);
        }

        Arrays.sort(jobs, (x, y) -> x.difficulty - y.difficulty);
        Arrays.sort(maxDifficultyPerWorker);

        int index = 0;
        int totalMaxProfit = 0;
        int currentMaxProfit = 0;

        for (int difficulty : maxDifficultyPerWorker) {
            while (index < totalJobs && jobs[index].difficulty <= difficulty) {
                currentMaxProfit = Math.max(currentMaxProfit, jobs[index].profit);
                ++index;
            }
            totalMaxProfit += currentMaxProfit;
        }

        return totalMaxProfit;
    }
}
