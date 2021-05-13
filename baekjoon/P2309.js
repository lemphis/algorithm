/**
 * @see [일곱 난쟁이]{@link https://www.acmicpc.net/problem/2309}
 */
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let inputCount = 0;
let heights = [];
rl.on("line", line => {
    inputCount++;
    heights.push(Number(line));
    if (inputCount === 9) {
        const total = heights.reduce((acc, cur) => acc + cur, 0);
        const extra = total - 100;
        for (let i = 0; i < inputCount; ++i) {
            for (let j = i + 1; j < inputCount; ++j) {
                if (i === j) continue;
                if (heights[i] + heights[j] === extra) {
                    const firstTarget = heights[i];
                    const secondTarget = heights[j];
                    heights.splice(heights.indexOf(firstTarget), 1);
                    /**
                     * 위에서 heights[j]를 따로 보관하지 않고 indexOf의 argument로 heights[j]를 그대로 사용하면
                     * 25번째 line에서 이미 element를 하나 삭제하여 height[j]의 값이 변경되어 이상한 결과가 나옴
                     */
                    heights.splice(heights.indexOf(secondTarget), 1);
                    break;
                }
            }
            if (heights.length === 7) break;
        }
        heights.sort((a, b) => a - b).forEach(height => console.log(height));
        rl.close();
    }
}).on("close", function () {
    process.exit();
});
