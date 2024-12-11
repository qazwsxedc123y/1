#define  _CRT_SECURE_NO_WARNINGS


//#include <stdio.h>                                                                                                                         
//#include <string.h>
//int main(int argc, char* argv[])
//{
//	if (argc > 1)
//	{
//		if (strcmp(argv[1], "-a") == 0)
//		{
//			printf("you used -a option...\n");
//		}
//		else if (strcmp(argv[1], "-b") == 0)
//		{
//			printf("you used -b option...\n");
//		}
//		else
//		{
//			printf("you used unrecognizable option...\n");
//		}
//	}
//	else
//	{
//		printf("you did not use any option...\n");
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int g_unval;  // 未初始化的全局变量
//int g_val = 100;  // 已初始化的全局变量
//
//int main(int argc, char* argv[], char* envp[]) {
//    int i;
//
//    // 打印代码段地址
//    printf("code addr: %p\n", main);  // main函数的地址
//
//    // 打印只读常量区地址
//    char* str = "hello world";  // 字符串字面量，存储在只读数据区
//    printf("read only addr: %p\n", str);  // 字符串常量的地址
//
//    // 打印已初始化数据段的地址
//    printf("init addr: %p\n", &g_val);  // 已初始化全局变量g_val的地址
//
//    // 打印未初始化数据段的地址
//    printf("uninit addr: %p\n", &g_unval);  // 未初始化全局变量g_unval的地址
//
//    // 打印堆区地址
//    int* p = (int*)malloc(10 * sizeof(int));  // 动态分配10个int类型的内存
//    if (p == NULL) {
//        printf("Memory allocation failed!\n");
//        return 1;  // 如果内存分配失败，则退出
//    }
//    printf("heap addr: %p\n", p);  // 堆区的地址
//
//    // 打印栈区地址
//    printf("stack addr: %p\n", &str);  // 栈上局部变量str的地址
//    printf("stack addr: %p\n", &p);    // 栈上局部变量p的地址
//
//    // 打印命令行参数的地址
//    for (i = 0; i < argc; i++) {
//        printf("args addr: %p\n", argv[i]);  // 打印每个命令行参数的地址
//    }
//
//    // 打印环境变量的地址
//    i = 0;
//    while (envp[i]) {
//        printf("env addr: %p\n", envp[i]);  // 打印每个环境变量的地址
//        i++;
//    }
//
//    // 释放动态分配的内存
//    free(p);
//
//    return 0;
//}

//   g_val = 200;  // 子进程修改全局变量
//         sleep(3);  // 父进程暂停3秒，等待子进程输出

//#include <stdio.h>
//#include <stdlib.h>
//#include <sys/types.h>
//#include <unistd.h>
//
//int g_val = 100;
//
//int main() {
//    pid_t id = fork();  // 创建一个新的进程
//
//    if (id == 0) {  // 子进程
//        printf("child: PID: %d, PPID: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//    }
//    else if (id > 0) {  // 父进程
//        printf("father: PID: %d, PPID: %d, g_val: %d, &g_val: %p\n", getpid(), getppid(), g_val, &g_val);
//    }
//    else {  // fork失败
//        perror("fork failed");
//        exit(1);
//    }
//    return 0;
//}