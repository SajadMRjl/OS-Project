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





int main(){
    int data[] = {1,2,3};
    int argc = 1;
    int pid = thread_create(&f1, (void*)&argc, (void*)data);
    thread_join();

    if (pid < 0)
        printf("test 1 fail\n");
    else
        printf("test 1 succeed\n");
    
    
    return 0;
}
