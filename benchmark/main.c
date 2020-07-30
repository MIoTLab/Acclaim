#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <zconf.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define BUF_SIZE 4096

char rand_char(int no){
    return 'A' + no;
}

int write_page(const char * fname, int blkcount, float ratio){
    int i, j;
    if(fname == NULL){
        printf("arg error\n");
        return -1;
    }
    srand((unsigned int)time(0));
    int fd = open(fname, O_RDWR | O_CREAT, 0666);
    for(i = 0; i < blkcount; i++){

        char cbuf[BUF_SIZE];

        if(ratio > 0) {
            char lastch = 'a';

            for (j = 0; j < BUF_SIZE; j++) {
                float ra = (float) rand() / RAND_MAX;
                if (ra > ratio) {
                    int rdd = rand() % 60;
                    cbuf[j] = rand_char(rdd);
                    lastch = cbuf[j];
                } else {
                    cbuf[j] = lastch;
                }
            }
        }else{
            memset(cbuf, 'a', BUF_SIZE);
        }

        if(write(fd, cbuf, BUF_SIZE) == -1){
            printf("write error\n");
            return -1;
        }
    }
	fsync(fd);
    close(fd);
}

int read_page(const char * fname, int blkcount){
    char buffer[BUF_SIZE];
    int i;
    if(fname == NULL){
        printf("arg error\n");
        return -1;
    }
    int fd = open(fname, O_RDWR);
    for(i = 0; i < blkcount; i++){
        if(read(fd, buffer, BUF_SIZE) == -1){
            printf("error error\n");
            return -1;
        }
    }
    close(fd);
}

int main(int argc, char* argv[]){
    int blkcount, rw;
    float ratio;
    long long delta_time;
    struct timeval start, end;
    if(argv[1] == NULL || argv[2] == NULL || argv[3] == NULL || argv[4] == NULL){
        printf("arg error\n");
        return -1;
    }
    blkcount = atoi(argv[2]); // requested page number
    rw = atoi(argv[3]); // rw， rw = 1 write， rw = 0 read
    ratio = atof(argv[4]); // you can ignore this

    if(rw == 1){
        gettimeofday(&start, NULL);
        write_page(argv[1], blkcount, ratio);
        gettimeofday(&end, NULL);
        delta_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        printf("[benchmark] write cost = %lld\n", delta_time);
    }else{
        gettimeofday(&start, NULL);
        read_page(argv[1], blkcount);
        gettimeofday(&end, NULL);
        delta_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
        printf("[benchmark] read cost = %lld\n", delta_time);
    }

    return 0;
}
