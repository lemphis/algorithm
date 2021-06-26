/**
 * @see [모의고사]{@link https://programmers.co.kr/learn/courses/30/lessons/42840}
 */
function solution(answers) {
    const firstDisclaimer = [1, 2, 3, 4, 5];
    const secondDisclaimer = [2, 1, 2, 3, 2, 4, 2, 5];
    const thirdDisclaimer = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];

    let status = [0, 0, 0];
    const length = answers.length;
    for (let i = 0; i < length; ++i) {
        if (answers[i] === firstDisclaimer[i % 5]) status[0]++;
        if (answers[i] === secondDisclaimer[i % 8]) status[1]++;
        if (answers[i] === thirdDisclaimer[i % 10]) status[2]++;
    }

    let result = [];
    const max = Math.max.apply(null, status);
    for (let i = 0; i < 3; ++i) {
        if (status[i] === max) result.push(i + 1);
    }

    return result;
}
