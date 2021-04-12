/**
 * @see [윤년]{@link http://github.com}
 */
const readline = require('readline')

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
})

rl.on('line', (year) => {
  const inputYear = parseInt(year)
  const isLeapYear = inputYear % 4 === 0 && inputYear % 100 !== 0 || inputYear % 400 === 0
  console.log(isLeapYear ? 1 : 0)
  rl.close()
}).on('close', function () {
  process.exit()
})
