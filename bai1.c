#include<stdio.h>
#include<fcntl.h>
#include <unistd.h>
#include<string.h>

int main() {

    int fd = -1;
    int ret = 0;
    char data[128];
    
    fd =open("./data", O_RDONLY);

    if(fd > 0) {
        memset (data, 0, sizeof(data));
        ret = read(fd, data, sizeof(data)-1);

        if(ret > 0) {
            printf("data : %s\n", data);            
        }
        close(fd);
    }
    return 0;
}
