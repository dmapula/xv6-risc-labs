#include "types.h"
#include "sem.h"

int sys_sem_init(void) {
    int value;
    struct semaphore *s;
    sem_t *uaddr;

    if(argaddr(0, (uint64*)&uaddr) < 0 || argint(1, &value) < 0)
        return -1;

    int index = semalloc();
    if(index < 0)
        return -1;

    s = &semtable.sem[index];
    s->count = value;
    s->valid = 1;

    return copyout(myproc()->pagetable, (uint64)uaddr, (char*)&index, sizeof(index));
}

int sys_sem_destroy(void) {
    sem_t sem_index;

    if(argint(0, &sem_index) < 0)
        return -1;

    semdealloc(sem_index);
    return 0;
}

int sys_sem_wait(void) {
    sem_t sem_index;

    if(argint(0, &sem_index) < 0)
        return -1;

    acquire(&semtable.sem[sem_index].lock);
    semtable.sem[sem_index].count--;
    if(semtable.sem[sem_index].count < 0) {
        // Sleep on the semaphore's address to be woken up by sem_post
        sleep(&semtable.sem[sem_index], &semtable.sem[sem_index].lock);
    } else {
        release(&semtable.sem[sem_index].lock);
    }
    return 0;
}

int sys_sem_post(void) {
    sem_t sem_index;

    if(argint(0, &sem_index) < 0)
        return -1;

    acquire(&semtable.sem[sem_index].lock);
    semtable.sem[sem_index].count++;
    if(semtable.sem[sem_index].count <= 0) {
        // Wake up one process sleeping on the semaphore
        wakeup(&semtable.sem[sem_index]);
    }
    release(&semtable.sem[sem_index].lock);
    return 0;
}
