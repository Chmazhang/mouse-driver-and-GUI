/*
 * 测试成功则输出：
 * "I am test_echo."
 * 测试失败则输出：
 * "execve error."
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void test_execve(void){
    char *argv[] = {"./echo", "I am test_echo.\n", NULL};
    char *env[] = {NULL};
    execve("./echo", argv, env);
    printf("execve error.\n");
}

int main(void){
    test_execve();
    return 0;
}
