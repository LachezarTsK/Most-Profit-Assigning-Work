
/**
 * @param {number[]} jobDifficulty
 * @param {number[]} jobProfit
 * @param {number[]} maxDifficultyPerWorker
 * @return {number}
 */
var maxProfitAssignment = function (jobDifficulty, jobProfit, maxDifficultyPerWorker) {
    const totalJobs = jobDifficulty.length;
    const jobs = new Array(totalJobs);
    for (let i = 0; i < totalJobs; ++i) {
        jobs[i] = new Job(jobDifficulty[i], jobProfit[i]);
    }

    jobs.sort((x, y) => x.difficulty - y.difficulty);
    maxDifficultyPerWorker.sort((x, y) => x - y);

    let index = 0;
    let totalMaxProfit = 0;
    let currentMaxProfit = 0;

    for (let difficulty of maxDifficultyPerWorker) {
        while (index < totalJobs && jobs[index].difficulty <= difficulty) {
            currentMaxProfit = Math.max(currentMaxProfit, jobs[index].profit);
            ++index;
        }
        totalMaxProfit += currentMaxProfit;
    }

    return totalMaxProfit;
};

function Job(difficulty, profit) {
    this.difficulty = difficulty;
    this.profit = profit;
}
