#include <stdio.h>                          
#include <sys/types.h>
#include <unistd.h>                          

pid_t fork_2sec() {                          
pid_t tmp;     
sleep(1);                                 
tmp = fork();
sleep(1);                                 
return tmp;
}                                           

main(){                                      
int ii, jj, kk, ll;
ii = jj = kk = ll = (int) getpid();      
printf("   ii     jj     kk    ll\n");
printf("============================\n");
fork_2sec();
jj = (int) getpid();
fork_2sec();
kk = (int) getpid();
fork_2sec();
ll = (int) getpid();
printf("[%3.3d] [%3.3d] [%3.3d] [%3.3d]\n",
                     ii, jj, kk, ll);
wait(NULL);
wait(NULL);
wait(NULL);
}
