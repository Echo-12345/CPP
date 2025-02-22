#include<iostream>
using namespace std;

// 定义全局变量
// n 表示目标总和，即所有配料数值相加需要达到的值
int n;
// kind 用于记录满足总和为 n 的配料组合的种类数
int kind = 0;
// m1 是一个二维数组，用于存储所有满足条件的配料组合，最多可存储 10000 种组合，每种组合有 10 个配料值
int m1[10000][10];
// m2 是一个一维数组，用于临时存储当前正在尝试的配料组合
int m2[10];

// 递归函数，用于生成所有可能的配料组合并检查是否满足条件
// total 表示当前已经累加的配料值总和
// a 表示当前正在处理的配料序号（从 0 到 9）
void peiliao(int total, int a) {
    // 当已经处理完 10 个配料时
    if (a == 10) {
        // 检查当前累加的总和是否等于目标值 n
        if (total == n) {
            // 如果满足条件，将当前临时存储的配料组合 m2 复制到二维数组 m1 中
            for (int j = 0; j < 10; j++)
                m1[kind][j] = m2[j];
            // 满足条件的组合种类数加 1
            kind++;
        }
    }
    // 如果当前累加的总和已经大于或等于目标值 n，不再继续递归，这是一个小优化
    else if (total >= n) {
        ;
    }
    // 否则，继续尝试不同的配料值
    else {
        // 每个配料的值可以是 1 到 3 中的任意一个
        for (int i = 1; i <= 3; i++) {
            // 将当前尝试的配料值存储到临时数组 m2 中
            m2[a] = i;
            // 递归调用 peiliao 函数，更新累加的总和为 total + i，并处理下一个配料（a + 1）
            peiliao(total + i, a + 1);
        }
    }
}

int main() {
    // 从标准输入读取目标总和 n
    cin >> n;
    // 调用 peiliao 函数，初始时累加总和为 0，从第一个配料（序号为 0）开始处理
    peiliao(0, 0);
    // 输出满足条件的配料组合的种类数
    cout << kind << endl;
    // 遍历所有满足条件的配料组合
    for (int j = 0; j < kind; j++) {
        // 输出每种配料组合的具体值，每个值之间用空格分隔
        for (int i = 0; i < 10; i++)
            cout << m1[j][i] << " ";
        // 输出完一种配料组合后换行
        cout << endl;
    }
    return 0;
}