
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 14
#define MAX_SCORE 100000

int n; // �����Ա����
int scores[2 * MAX_N]; // �����Ա����
int used[2 * MAX_N]; // ��������Ա�Ƿ��ѷ���
int min_diff; // ��С��ֵ

// ���������Ա������ֵ
void calculate_diff(int a_sum, int b_sum) {
    int diff = abs(a_sum - b_sum);
    if (diff < min_diff) {
        min_diff = diff;
    }
}
// �ݹ麯�����������Ա��Ϊ����
void divide(int a_sum, int b_sum, int a_cnt, int b_cnt, int idx) {
    // ���ж�Ա���ѷ��飬���������ֵ��������Сֵ
    if (idx == n) {
        int diff = abs(a_sum - b_sum);
        min_diff = ((min_diff < diff) ? (min_diff) : (diff));
        //min(min_diff, diff);
        return;
    }
    // ����ǰ��Ա���� A ��
    divide(a_sum + scores[idx], b_sum, a_cnt + 1, b_cnt, idx + 1);
    // ����ǰ��Ա���� B ��
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
