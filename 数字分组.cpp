// 数字分组求偶数和
// 问题描述
// 小M面对一组从 1 到 9 的数字，这些数字被分成多个小组，并从每个小组中选择一个数字组成一个新的数。
// 目标是使得这个新数的各位数字之和为偶数。任务是计算出有多少种不同的分组和选择方法可以达到这一目标。

// numbers: 一个由多个整数字符串组成的列表，每个字符串可以视为一个数字组。小M需要从每个数字组中选择一个数字。
// 例如对于[123, 456, 789]，14个符合条件的数为：147 149 158 167 169 248 257 259 268 347 349 358 367 369。


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int countEvenSumCombinations(const vector<string>& numbers, int index, int currentSum) {
    // 如果已经遍历完所有数字组
    if (index == numbers.size()) {
        // 检查当前和是否为偶数
        return (currentSum % 2 == 0) ? 1 : 0;
    }

    int count = 0;
    // 遍历当前数字组中的每个数字
    for (char digit : numbers[index]) {
        // 将字符转换为数字
        int num = digit - '0';
        // 递归调用，选择下一个数字组
        count += countEvenSumCombinations(numbers, index + 1, currentSum + num);
    }

    return count;
}

int solution(vector<string> numbers) {
    // 从第一个数字组开始，初始和为0
    return countEvenSumCombinations(numbers, 0, 0);
}

int main() {
    // 测试样例
    cout << (solution({"123", "456", "789"}) == 14) << endl;
    cout << (solution({"123456789"}) == 4) << endl;
    cout << (solution({"14329", "7568"}) == 10) << endl;
    return 0;
}