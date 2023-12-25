#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// product関数の定義
int product(int X[], int Y[], int n);

int main() {
    // 配列のサイズnを定義
    int n = 4; // 任意のサイズに変更してください

    // ２つの配列 X[], Y[] を定義
    int X[] = {1, 2, 3, 4}; // 仮のデータ、適宜変更してください
    int Y[] = {5, 6, 7, 8}; // 仮のデータ、適宜変更してください

    // product関数を呼び出し、計算結果を出力
    int result = product(X, Y, n);
    printf("Product: %d\n", result);

    return 0;
}

// product関数の定義
int product(int X[], int Y[], int n) {
    if (n == 1) {
        // 配列のサイズが1の場合、単純な積を返す
        return X[0] * Y[0];
    } 
    
    else {
        // 配列を半分に分割
        int half = n / 2;

        // 配列X, Yをそれぞれ半分ずつの2つの配列に分割
        int* X1 = malloc(half * sizeof(int));
        int* X2 = malloc(half * sizeof(int));
        int* Y1 = malloc(half * sizeof(int));
        int* Y2 = malloc(half * sizeof(int));

        for (int i = 0; i < half; i++) {
            X1[i] = X[i];
            X2[i] = X[i + half];
            Y1[i] = Y[i];
            Y2[i] = Y[i + half];
        }

        // 再帰的に計算
        int a = product(X2, Y2, half);
        int b = product(X1, Y1, half);
        int c = product(X1 + half, Y1 + half, half); // X1+X2, Y1+Y2

        // 部分結果を組み合わせて返す
        int result = a * (int)pow(10, n) + (b - (a + c)) * (int)pow(10, n/2) + c;

        // 動的に確保されたメモリを解放
        free(X1);
        free(X2);
        free(Y1);
        free(Y2);

        return result;
    }
}
