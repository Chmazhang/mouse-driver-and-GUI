/*
 * 测试成功则输出：
 * "I am test_echo."
 * 测试失败则输出：
 * "execve2 error."
 */
#define __LIBRARY__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

_syscall3(int,execve2,const char *,file,char **,argv,char **,envp)

void test_execve2(void){
    char *argv[] = {"./echo", "I am test_echo.\n", NULL};
    char *env[] = {NULL};
    execve2("./echo", argv, env);
    printf("execve2 error.\n");
}

int main(void){
    test_execve2();
    return 0;
}
