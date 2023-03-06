#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd;
    char buf[100];

    //Создаем именованный канал
    mkfifo(argv[1], 0666);

    // Открываем канал для чтения
    fd = open(argv[1], O_RDONLY);

    while (1) {
        // Читаем сообщение из канала
        read(fd, buf, sizeof(buf));
        printf("Received message: %s", buf);
    }

    // Закрываем канал
    close(fd);
    unlink(argv[1]);

    return 0;
}
