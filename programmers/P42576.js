/**
 * @see [완주하지 못한 선수]{@link https://programmers.co.kr/learn/courses/30/lessons/42576}
 */
function solution(participant, completion) {
    participant.sort();
    completion.sort();
    let completionLength = completion.length;
    for (let i = 0; i < completionLength; ++i) {
        if (participant[i] !== completion[i]) {
            return participant[i];
        }
    }
    return participant[participant.length - 1];
}
