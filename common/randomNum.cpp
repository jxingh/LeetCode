#include <bits/stdc++.h>
using namespace std;

// c++ 11随机数
//    mt19937：随机数产生器，返回一个32位无符号随机数。
//    mt19937_64：返回一个64位无符号随机整数。
//    uniform_int_distribution：在指定区间内生成一个随机整数。

// int main()
// {
//     mt19937 u32Rnd(time(0));            //32位
//     cout << "32: " << u32Rnd() << endl; //打印一个无符号32位随机整数
//     cout << "32: " << u32Rnd() << endl; //再打印一个
//                                         //如果用printf打印，注意输出的格式
//     mt19937_64 u64Rnd(time(0));         //64位
//     cout << "64: " << u64Rnd() << endl; //打印一个无符号64位随机整数

//     uniform_int_distribution<> distrib(-100, 100); //设置随机数范围
//     cout << "[32]: " << distrib(u32Rnd) << endl;   //打印[-100,100]内的一个随机数
//     cout << "[64]: " << distrib(u64Rnd) << endl;

//     return 0;
// }

const int MAX = 1000000; //100万个数
const int MIN = 0;
int myhash[MAX] = {0}; //用hash查重
int mynum[MAX];        //记录去重后的随机数

int main()
{
    int big_rand; //大随机数
                  //本题需要不同的随机数，用hash的方法来去重
    int num = 0;  //去重后随机数的数量
    mt19937 u32Rnd(time(0));
    uniform_int_distribution<> distrib(MIN, MAX);

    for (int i = 0; i < MAX; i++)
    {                               //hash
        big_rand = distrib(u32Rnd); //[MIN,MAX]之间的一个随机数
        if (myhash[big_rand] == 0)
        {                          //用hash查重
            myhash[big_rand] = 1;  //数字big_rand，登记在big_rand这个位置
            mynum[num] = big_rand; //记录随机数
            num++;                 //最后产生 num 个随机数
        }
    }
    big_rand = distrib(u32Rnd);
    printf("%d %d\n", num, big_rand % (num + 1)); //case的第一行

    int k = 500000; //题目要求[-500000,500000]内的数字
    for (int i = 0; i <= num - 1; i++)
    {
        if (i < num - 1)
            printf("%d ", mynum[i] - k); //有正有负
        if (i == num - 1)
            printf("%d\n", mynum[i] - k); //最后一个，末尾没有空格
    }
    return 0;
}