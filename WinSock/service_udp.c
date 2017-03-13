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
    struct sockaddr_in ser_addr, cli_addr;
    int cliaddr_len = -1;
    char buff[256];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("sockfd error.");
    }

    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(7777);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (0 > bind(sockfd, (struct sockaddr*)&ser_addr, sizeof(ser_addr))) {
        perror("bind error");
    }

    int n = 0;
    while (1) {
        cliaddr_len = sizeof(cli_addr);
        n = recvfrom(sockfd, buff, 256, 0, (struct sockaddr *)&cli_addr, &cliaddr_len);
        printf("%s:%d ==> %s", inet_ntoa(cli_addr.sin_addr), cli_addr.sin_port, buff);
    }

    close(sockfd);
}
