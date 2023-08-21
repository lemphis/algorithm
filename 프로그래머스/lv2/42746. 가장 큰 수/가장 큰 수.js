function solution(numbers) {
    if (numbers.every(num => num === 0)) return "0";
    return numbers.sort(compare).join("");
}

function compare(a, b) {
    return formatToString(b) - formatToString(a);
}

function formatToString(num) {
    return num.toString().repeat(4).slice(0, 4);
}