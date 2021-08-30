/**
 * @see [위장]{@link https://programmers.co.kr/learn/courses/30/lessons/42578}
 */
function solution(clothes) {
    const kindObj = {};
    clothes.forEach((element) => {
        const kind = element[1];
        if (kindObj.hasOwnProperty(kind)) kindObj[kind]++;
        else kindObj[kind] = 1;
    });

    const answer = Object.values(kindObj)
        .map((val) => (val += 1))
        .reduce((acc, cur) => acc * cur, 1);

    return answer - 1;
}
