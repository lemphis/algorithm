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
    if (inputCount === 3) {
        const total = heights.reduce((acc, cur) => acc + cur, 0);
        const extra = total - 100;
        // TODO
        rl.close();
    }
}).on("close", function () {
    process.exit();
});
