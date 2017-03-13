#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <time.h>

int main(int argc, char const* argv[])
{
    int money = 1000;   //游戏本金1000元
    int bet = 0;
    int status, sum, myPoint, i, j;

    srand((unsigned int)time(NULL));  //以机器当前的时间来构造生成伪随机数的种子

    for (i = 0;  i < 100; i++) {
        sum = 1 + (rand()%6) + 1 + (rand()%6);  //随机掷筛子
        bet = 50;   //一注金额为50元
        switch(sum){
            case 7:case 11:
                status = 1;     //第一回合为7点或11点则赢
                money += bet;
                break;
            case 2:case 3:case 12:
                status = 2;     //第一回合为2,3,12则输
                money -= bet;
                break;
            default:
                status = 0;     //其他点作为游戏者的点数，继续投掷
                myPoint = sum;
                break;
        }
    }

    /* 不停的投注，直到分出输赢  */
    for (j = 1; status == 0; j++){
         bet += 50 * 2^j;   //每次掷筛子都要压注且金额翻翻
        sum = 1 + (rand()%6) + 1 + (rand()%6);
        if (sum == myPoint) {
             status = 1;    //若与自己手中点数相同则赢
             money += bet;
             bet = 0;
        } else if (sum == 7) {
            status = 2;     //若掷出7点则输
            money -= bet;
            bet = 0;
        }

        if (status == 1) {
            printf("Congratulation, you win!\n");
        } else if (status == 2) {
            printf("Unfortunately, you lost!\n");
        }
    }

    if (money >= 1000)
        printf("Principal %d yuan, you won %d yuan!\n", 1000, money - 1000);
    else if (money >= 0)
        printf("Principal %d yuan, the remaining %d yuan\n", 1000, 1000 - money);
    else
        printf("Principal %d yuan, you lost %d yuan\n", 1000, - money);
    return 0;
}
