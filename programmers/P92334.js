/**
 * @see [신고 결과 받기]{@link https://programmers.co.kr/learn/courses/30/lessons/92334}
 */
function solution(id_list, report, k) {
    const idMap = {};
    const resultMap = {};
    id_list.forEach((id) => {
        idMap[id] = resultMap[id] = 0;
    });

    const reportSet = new Set(report);
    reportSet.forEach((item) => (idMap[item.split(' ')[1]] += 1));
    const temp = Object.entries(idMap)
        .filter(([_, count]) => count >= k)
        .map(([dest, _]) => dest);

    [...reportSet]
        .filter((item) => temp.includes(item.split(' ')[1]))
        .forEach((item) => (resultMap[item.split(' ')[0]] += 1));

    return id_list.map((id) => resultMap[id]);
}
