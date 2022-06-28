/*
 * 成功测试时的输出：
 * "getdents success."
 */
#define __LIBRARY__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <assert.h>
#include <sys/types.h>
#include "new.h"

_syscall3(int,getdents,int,fd,struct linux_dirent *,dirp,unsigned long,len)

char buf[512];
void test_getdents(void){
    int fd, nread, bpos;
    struct linux_dirent *dirp, *tmp;
    dirp = (struct linux_dirent *)buf;
    fd = open(".", O_RDONLY);
    printf("open fd: %d\n", fd);

	nread = getdents(fd, dirp, 512);
	printf("getdents fd: %d\n", nread);
	assert(nread != -1);

	for(bpos = 0; bpos < nread;){
	    tmp = (struct linux_dirent *)(buf + bpos);
	    printf(  "%s\t", tmp->d_name);
	    bpos += tmp->d_reclen;
	}
    printf("\n");

	printf("getdents success.\n");
    close(fd);
}

int main(void){
    test_getdents();
    return 0;
}
