/*
 * Test the cntcharkernel system call (#325)
 */
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>

#define SYS_cntcharkernel 335

int main(int argc, char **argv)
{
	if(argc <= 1){
		printf("Must provide a string to give to system call.\n");
		return -1;
	}
	char *arg = argv[1];
	printf("Making system call with \"%s\".\n", arg);
	long res = syscall(SYS_cntcharkernel, arg);
	printf("System call returned %ld.\n", res);
	return res;
}

