/*
 * 测试通过时的输出：
 * "sleep success."
 * 测试失败时的输出：
 * "sleep error."
 */
#define __LIBRARY__
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

_syscall1(unsigned int,sleep,unsigned int,seconds)

void test_sleep() {
	time_t time1, time2;
	int ret;
	time(&time1);
	assert(time1 >= 0);
	ret = sleep(1);
	assert(ret == 0);
	time(&time2);
	assert(time2 >= 0);

	if(time2 - time1 >= 1){	
		printf("time passwd: %d\n", time2-time1);
		printf("sleep success.\n");
	}else{
		printf("sleep error.\n");
	}
}

int main(void) {
	test_sleep();
	return 0;
}
