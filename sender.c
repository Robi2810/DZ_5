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

    // Создаем именованный канал
    mkfifo(argv[1], 0666);

    // Открываем канал для записи
    fd = open(argv[1], O_WRONLY);

    while (1) {
        // Запрашиваем сообщение у пользователя
        printf("Enter message: ");
        fgets(buf, sizeof(buf), stdin);

        // Отправляем сообщение в канал
        write(fd, buf, strlen(buf) + 1);
    }

    // Закрываем канал
    close(fd);
    unlink(argv[1]);

    return 0;
}
