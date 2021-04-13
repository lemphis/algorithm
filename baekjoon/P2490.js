/**
 * @see [윷놀이]{@link https://www.acmicpc.net/problem/2490}
 */
const readline = require("readline");

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
});

let throwCount = 1;
rl.on("line", line => {
    const arr = line.split(/\s*/);
    const count = arr.filter(predicate).length;
    let answer;
    switch (count) {
        case 0:
            answer = "D";
            break;
        case 1:
            answer = "C";
            break;
        case 2:
            answer = "B";
            break;
        case 3:
            answer = "A";
            break;
        case 4:
            answer = "E";
            break;
    }
    console.log(answer);
    throwCount === 3 && rl.close();
    throwCount++;
}).on("close", function () {
    process.exit();
});

const predicate = val => Number(val);
