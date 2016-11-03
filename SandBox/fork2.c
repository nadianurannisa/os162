/* main8.c (c) 2012 Rahmat M. Samik-Ibrahim  v120330
* getpid() = get the current PID (Process ID).
* fork()   = creates a new process by duplicating.
* wait()   = wait until one of its children terminates.
* GFDLike License */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#define  STRING1 "PID[%5.5d] starts.\n"
#define  STRING2 "PID[%5.5d] passes.\n"
#define  STRING3 "PID[%5.5d] terminates.\n"

void main(void)
{
printf(STRING1, (int) getpid());
fflush(stdout);
for (int ii=0; ii<2; ii++) {
pid_t pid1=fork();
wait(NULL);
if (pid1 != 0) {
fork();
 wait(NULL);
 }
printf(STRING2, (int) getpid());
}
 printf(STRING3, (int) getpid());
}
