#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


int main(int argc, char const *argv[])
{
    int sockfd = -1;
    char buff[256];
    int n = 0;
    struct sockaddr_in ser_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("sockfd error.");
    }
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(8888);
    /* ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); */
    inet_pton(AF_INET, "127.0.0.1", &ser_addr.sin_addr);
    connect(sockfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr));

    while (1) {
        n = read(0, buff, 255);
        if (!strncmp(buff, "quit", 4)) {
            close(sockfd);
            break;
        }
        buff[n] = '\0';
        write(sockfd, buff, n+1);
        n = read(sockfd, buff, 256);
        write(1, buff, n);
    }
    printf("client quit.\n");

    return 0;
}
