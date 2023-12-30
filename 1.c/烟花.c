//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// 延时函数，用于控制粒子的更新速度
//void delay(unsigned int milliseconds) {
//    clock_t start_time = clock();
//    while (clock() < start_time + milliseconds);
//}
//
//int main() {
//    // 设置随机数种子，以便每次运行程序时生成的随机数不同
//    srand(time(NULL));
//
//    // 定义粒子数量和爆炸半径
//    int numParticles = 50;
//    int explosionRadius = 10;
//
//    // 循环生成粒子并模拟烟花爆炸效果
//    for (int i = 0; i < numParticles; i++) {
//        // 为每个粒子生成随机的水平速度和垂直速度
//        int xVelocity = (rand() % (2 * explosionRadius)) - explosionRadius;
//        int yVelocity = (rand() % (2 * explosionRadius)) - explosionRadius;
//
//        // 更新粒子的位置并打印出来
//        for (int j = 0; j < 50; j++) {
//            printf("Particle %d: x=%d, y=%d\n", i + 1, j * xVelocity, j * yVelocity);
//            // 调用延时函数使粒子位置更新以及打印的速度适中
//            delay(50);
//        }
//    }
//
//    return 0;
//}