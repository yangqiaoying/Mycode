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
    int confd = -1;
    struct sockaddr_in ser_addr, cli_addr;
    int cliaddr_len = -1;
    char buff[256];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("sockfd error.");
    }

    bzero(&ser_addr, sizeof(ser_addr));
    ser_addr.sin_family = AF_INET;
    ser_addr.sin_port = htons(8888);
    ser_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (0 > bind(sockfd, (struct sockaddr *)&ser_addr, sizeof(ser_addr))) {
        perror("bind error");
    }

    if (0 > listen(sockfd, 5)) {
        perror("listen error");
    }

    cliaddr_len = sizeof(cli_addr);
    confd = accept(sockfd, (struct sockaddr *)&cli_addr, &cliaddr_len);
    if (confd == -1) {
         perror("accept error");
    }
    printf("client%d %s:%d\n", confd, inet_ntoa(cli_addr.sin_addr), cli_addr.sin_port);

    int n = 0;
    while (1) {
        n = read(confd, buff, 256);
        if (n == 0) {
            close(confd);
            printf("client %d is quit.\n", confd);
            break;
        }
        printf("buff = %s", buff);
        write(confd, "OK\n", 3);
    }

    close(sockfd);
}
