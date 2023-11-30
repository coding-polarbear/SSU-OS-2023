#include "types.h"
#include "user.h"


int foo=0;

int main(int argc, char *argv[])
{
	printf(1, "starting test...\n");
	int pid;
	
	printf(1, "getNumfreepages: %d\n", get_num_freepages());
	
	if((pid = fork()) != 0) // parent 
	{
		printf(1, "getNumfreepages in parent: %d\n", get_num_freepages());
		wait();
	}
	else if(pid != -1)			// child
	{
		printf(1, "getNumfreepages in child: %d\n", get_num_freepages());
		foo = 1;
		printf(1, "getNumfreepages in child: %d\n", get_num_freepages());
	}
	return 0;
}