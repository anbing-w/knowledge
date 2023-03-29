
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 14
#define MAX_SCORE 100000

int n; // 篮球队员数量
int scores[2 * MAX_N]; // 篮球队员分数
int used[2 * MAX_N]; // 标记篮球队员是否已分组
int min_diff; // 最小差值

// 计算两组队员分数差值
void calculate_diff(int a_sum, int b_sum) {
    int diff = abs(a_sum - b_sum);
    if (diff < min_diff) {
        min_diff = diff;
    }
}
// 递归函数，将篮球队员分为两组
void divide(int a_sum, int b_sum, int a_cnt, int b_cnt, int idx) {
    // 所有队员都已分组，则计算分组差值并更新最小值
    if (idx == n) {
        int diff = abs(a_sum - b_sum);
        min_diff = ((min_diff < diff) ? (min_diff) : (diff));
        //min(min_diff, diff);
        return;
    }
    // 将当前队员分入 A 组
    divide(a_sum + scores[idx], b_sum, a_cnt + 1, b_cnt, idx + 1);
    // 将当前队员分入 B 组
    divide(a_sum, b_sum + scores[idx], a_cnt, b_cnt + 1, idx + 1);
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
        scanf("%d", &scores[i]);
    }

    min_diff = MAX_SCORE * n;
    divide(0, 0, 0, 0, 0);

    printf("%d\n", min_diff);

    return 0;
}
