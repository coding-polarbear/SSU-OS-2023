#include "types.h"
#include "user.h"

#define PARENT_PRIORITY 1
#define CHILD_PRIORITY 5
int main(int argc, char *argv[]) {
  printf(1, "Test priority scheduler\n");
  
  int pid;
  if((pid = fork()) != 0) // parent
  {
    set_proc_priority(getpid(), PARENT_PRIORITY);
	printf(1, "parent, pid: %d, priority: %d\n", getpid(), get_proc_priority(getpid()));
    
	while(1);
  }
  else if((pid = fork()) != 0) 
  {
	set_proc_priority(getpid(), CHILD_PRIORITY);
	sleep(10);
	printf(1, "child, pid: %d, priority: %d\n", getpid(), get_proc_priority(getpid()));
	while(1);
  }
  
  exit();
}