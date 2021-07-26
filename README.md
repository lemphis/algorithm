# Algorithm

- 알고리즘 풀이 정리
  - language
     1. Java
     2. JavaScript
     3. C++
     4. Kotlin
  - 각 문제에 대해 간단히 Documentation해 두었음
  - **문제 이름**으로 검색하면 코드 금방 찾을 수 있을걸?

- Hypertext Reference
  - Online Judge
    - [baekjoon](https://www.acmicpc.net)
    - [programmers](https://programmers.co.kr)
    - [leetcode](https://leetcode.com/)
  - Workbook
    - [BaaaaaaaaaaarkingDog](https://github.com/encrypted-def/basic-algo-lecture/blob/master/workbook.md)

---

## Programmers

- Hash
  - 완주하지 못한 선수 (Lv. 1)
    - 1명만 완주하지 못함. 간단함
    - 넘어오는 배열 두 개 sort 후 각 element 비교해서 다르면 참가자 쪽 element 출력
    - 모두 같으면 참가자 쪽 마지막 element 출력
  - 전화번호 목록 (Lv. 2)
    - String 비교해서 하나라도 prefix에 해당하는 게 있으면 false : true
    - 효율성에서 살짝 난이도 있는 듯
    - sort된 array를 for 1회 반복으로 해결
  - 위장 (Lv. 2)
    - 서로 다른 옷 조합의 수 출력
    - 뽑지 않을 경우의 수 포함시켜서 경우의 수를 구함. 모두 뽑지 않는 경우는 없으므로 -1 해줌
  - 베스트앨범 (Lv. 3)
- Stack / Queue
  - 기능개발 (Lv. 2)
    - 각 작업의 남은 진도를 구하고 for문 돌리면서 계산
  - 프린터 (Lv. 2)
  - 다리를 지나는 트럭 (Lv. 2)
  - 주식가격 (Lv. 2)
- Heap
  - 더 맵게 (Lv. 2)
  - 디스크 컨트롤러 (Lv. 3)
  - 이중우선순위큐 (Lv. 3)
- Sort
  - K번째수 (Lv. 1)
    - 요구사항 그대로 배열 slice, sort, merge(concat) 실행
  - 가장 큰 수 (Lv. 2)
    - 숫자로 이루어진 배열의 원소들을 붙여서 만들 수 있는 가장 큰 수 출력
    - string으로 바꿔서 4번 반복하여 붙인 후 4자리를 잘라서 크기 비교 && join
  - H-Index (Lv. 2)
- Brute-Force Search
- Greedy
- DP (Dynamic Programming)
- DFS / BFS
- Binary Search
- Graph
