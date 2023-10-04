#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/user.h"

int main(int argc, char *argv[]){
    struct uptime_info info;

    if(uptime(&info) < 0){
        fprintf(2, "Error: Unable to get uptime info.\n");
        exit(1);
        }

    printf("up %d clock ticks\n", info.uptime);
    exit(0);
}
