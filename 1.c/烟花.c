//#define  _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//
//// ��ʱ���������ڿ������ӵĸ����ٶ�
//void delay(unsigned int milliseconds) {
//    clock_t start_time = clock();
//    while (clock() < start_time + milliseconds);
//}
//
//int main() {
//    // ������������ӣ��Ա�ÿ�����г���ʱ���ɵ��������ͬ
//    srand(time(NULL));
//
//    // �������������ͱ�ը�뾶
//    int numParticles = 50;
//    int explosionRadius = 10;
//
//    // ѭ���������Ӳ�ģ���̻���ըЧ��
//    for (int i = 0; i < numParticles; i++) {
//        // Ϊÿ���������������ˮƽ�ٶȺʹ�ֱ�ٶ�
//        int xVelocity = (rand() % (2 * explosionRadius)) - explosionRadius;
//        int yVelocity = (rand() % (2 * explosionRadius)) - explosionRadius;
//
//        // �������ӵ�λ�ò���ӡ����
//        for (int j = 0; j < 50; j++) {
//            printf("Particle %d: x=%d, y=%d\n", i + 1, j * xVelocity, j * yVelocity);
//            // ������ʱ����ʹ����λ�ø����Լ���ӡ���ٶ�����
//            delay(50);
//        }
//    }
//
//    return 0;
//}