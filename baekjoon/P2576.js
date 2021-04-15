/**
 * @see [홀수]{@link https://www.acmicpc.net/problem/2576}
 */
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let inputCount = 0;
let inputs = [];
rl.on("line", input => {
    inputCount++;
    inputs.push(Number(input));
    if (inputCount === 7) {
        const odds = inputs.filter(num => num % 2 === 1)
        if (odds.length === 0) {
            console.log(-1);
        } else {
            console.log(odds.reduce((acc, oddNum) => acc + oddNum, 0))
            console.log(Math.min.apply(Array, odds))
        }
        rl.close();
    }
}).on("close", process.exit);
