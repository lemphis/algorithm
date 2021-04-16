/**
 * @see [윷놀이]{@link https://www.acmicpc.net/problem/2490}
 */
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

const predicate = val => Number(val);
const stick = ["D", "C", "B", "A", "E"];
let throwCount = 1;
rl.on("line", line => {
    const arr = line.split(/\s*/);
    const count = arr.filter(predicate).length;
    console.log(stick[count]);
    throwCount === 3 && rl.close();
    throwCount++;
}).on("close", function () {
    process.exit();
});
