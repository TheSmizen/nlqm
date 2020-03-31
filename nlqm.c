//nlqm.c
//n-lift queue manager
//# cat a.c //TODO what even is this?
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> //TODO understand pthread

typedef void (*pcb)(int a);
typedef struct parameter{
    int a ;
    pcb callback;
}parameter;

//int main(int argc, char* argv[]){

//}

void* callback_thread(void *p1)
{
    //do something
    parameter* p = (parameter*)p1 ;
    while(1)
    {
        printf("GetCallBack print! \n");
        sleep(3);//delay 3s
        p->callback(p->a);
    }
}

extern SetCallBackFun(int a, pcb callback)
{
    printf("SetCallBackFun print! \n");
    parameter *p = malloc(sizeof(parameter)) ;
    p->a  = 10;
    p->callback = callback;

    pthread_t thing1;
    pthread_create(&thing1,NULL,callback_thread,(void *) p);
    pthread_join(thing1,NULL);
}
//# cat b.c
//#include "a.c"
void fCallBack(int a)
{
    //do something
    printf("a = %d\n",a);
    printf("fCallBack print! \n");
}


int main(void)
{
    SetCallBackFun(4,fCallBack);

    return 0;
}