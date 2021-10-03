#include <cstdio>
#include <string>

using namespace std;

void dfs(int n, int depth);

/**
 * @see [재귀함수가 뭔가요?](https://www.acmicpc.net/problem/17478)
 */
int main() {
    int N;
    scanf("%d", &N);
    puts("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");
    dfs(N, 0);
    return 0;
}

void dfs(int n, int depth) {
    string underscores = "";
    for (int i = 0; i < depth; ++i) {
        underscores += "____";
    }
    printf("%s", underscores.c_str());
    puts("\"재귀함수가 뭔가요?\"");
    if (n == depth) {
        printf("%s", underscores.c_str());
        puts("\"재귀함수는 자기 자신을 호출하는 함수라네\"");
        printf("%s", underscores.c_str());
        puts("라고 답변하였지.");
        return;
    } else {
        printf("%s", underscores.c_str());
        puts("\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
        printf("%s", underscores.c_str());
        puts("마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
        printf("%s", underscores.c_str());
        puts("그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
        dfs(n, depth + 1);
    }
    printf("%s", underscores.c_str());
    puts("라고 답변하였지.");
}