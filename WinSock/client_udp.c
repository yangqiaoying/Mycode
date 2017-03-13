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

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("sockfd error.");
    }
    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(7777);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (1) {
        n = read(0, buff, 256);
        buff[n] = '\0';
        sendto(sockfd, buff, n+1, 0, (struct sockaddr*)&ser_addr, sizeof(ser_addr));
    }

    return 0;
}
