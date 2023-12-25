#include <stdio.h>

int main() {
    // 配列のサイズnを定義
    int n = 3; // 任意のサイズに変更してください

    // ２つの配列 x[], y[] を定義
    int X[] = {1, 2, 3}; // 仮のデータ、適宜変更してください
    int Y[] = {4, 5, 6}; // 仮のデータ、適宜変更してください

    int sum = 0;
    int power = 1;

    for (int i = 0; i < n; i++) {
        int s = 0;
        int p = power; // 10の冪乗

        for (int j = 0; j < n; j++) {
            s = s + p * X[i] * Y[j];
            p = p * 10; //Yの桁上がり
        }

        sum = sum + s;
        power = power * 10; //Xの桁上がり
    }

    // 計算結果を出力
    printf("sum = %d\n", sum);

    return 0;
}
