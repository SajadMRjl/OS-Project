#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "user.h"
#include "stat.h"
#include "fcntl.h"
#include "x86.h"

int shared_data[] = {5, 8, 10};

void f1(void* argc, void* argv){
    int* data = (int*)argv;
    for (int i = 0; i < 3; i++)
        printf(1,"data: %d\n", data[i]);
    exit();
}

mutexlock lock;
int rsl;
int cnt;
int op1 = 1;
int op2 = -1;

void f2(void *arg1, void *arg2)
{
    int cnt = *(int *)arg1;
    int op = *(int *)arg2;
    for (int i = 0; i < cnt; i++)
    {
        lock_acquire(&lock);
        rsl += op;
        lock_release(&lock);
    }
    exit();
}

int main()
{
    int data[] = {1,2,3};
    int argc = 1;
    int pid = thread_create(&f1, (void*)&argc, (void*)data);
    thread_join();

    if (pid < 0)
        printf(1, "test 1 fail\n");
    else
        printf(1, "test 1 succeed\n");
    
    rsl = 0;
    cnt = 1000;
    lock_init(&lock);
    thread_create(&f2, (void *)&cnt, (void *)&op1);
    thread_create(&f2, (void *)&cnt, (void *)&op2);

    thread_join();
    thread_join();

    if (rsl != 0)
        printf(1, "test 2 fail\n");
    else
        printf(1, "test 2 succeed\n");
    

    exit();
}