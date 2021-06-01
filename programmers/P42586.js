/**
 * @see [기능개발]{@link https://programmers.co.kr/learn/courses/30/lessons/42586}
 */
function solution(progresses, speeds) {
    let temp = 0;
    let count = 0;
    const days = progresses.map((progress, idx) => Math.ceil((100 - progress) / speeds[idx]));
    temp = days[0];

    let length = days.length;
    let answer = [];
    for (let i = 0; i < length; ++i) {
        if (days[i] > temp) {
            answer.push(count);
            count = 1;
            temp = days[i];
        } else {
            count++;
        }
    }
    answer.push(count);
    return answer;
}
