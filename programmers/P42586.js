/**
 * @see [기능개발]{@link https://programmers.co.kr/learn/courses/30/lessons/42586}
 */
function solution(progresses, speeds) {
    let temp = 0;
    let count = 0;
    const days = progresses
            .map((progress, idx) => Math.ceil((100 - progress) / speeds[idx]))
            .reduce((acc, cur) => {
                // TODO: reducer 작성
            }, [])

    var answer = [];
    return answer;
}