/**
 * @see [K번째수]{@link https://programmers.co.kr/learn/courses/30/lessons/42748}
 */
function solution(array, commands) {
    return commands.reduce((acc, cur) => {
        return acc.concat(array.slice(cur[0] - 1, cur[1]).sort((a, b) => a - b)[cur[2] - 1])
    }, [])
}