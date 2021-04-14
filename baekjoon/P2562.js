/**
 * @see [최댓값]{@link https://www.acmicpc.net/problem/2562}
 */
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let inputCount = 0;
let inputs = [];
rl.on("line", line => {
    inputCount++;
    inputs.push(Number(line));
    if (inputCount === 9) {
        const max = Math.max.apply(Array, inputs);
        console.log(max);
        console.log(inputs.indexOf(max) + 1);
        rl.close();
    }
}).on("close", function () {
    process.exit();
});
