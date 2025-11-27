#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#define OK 0
#define WRONG_ANSWER 1

void run_judge() {
    // 打开管道文件。注意打开顺序，否则会造成死锁！
    int in = open("u2j.fifo", O_RDONLY);
    int out = open("j2u.fifo", O_WRONLY);

    // 重定向标准输入输出
    dup2(in, 0);
    dup2(out, 1);
    close(in);
    close(out);

    // 执行裁判程序
    execl("judge", "judge", NULL);
}

void run_user() {
    // 打开管道文件。注意打开顺序，否则会造成死锁！
    int out = open("u2j.fifo", O_WRONLY);
    int in = open("j2u.fifo", O_RDONLY);

    // 重定向标准输入输出
    dup2(in, 0);
    dup2(out, 1);
    close(in);
    close(out);

    // 执行用户程序
    execl("user", "user", NULL);
}
LPCSTR pipe_namej2u = "\\\\.\\Pipe\\j2u";
string pstrj2u = "\\\\.\\Pipe\\j2u";


int main() {
    // 创建管道文件
    HANDLE pipej2u = CreateNamedPipe(pipe_name, PIPE_ACCESS_DUPLEX, PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT
		, PIPE_UNLIMITED_INSTANCES, 0, 0, NMPWAIT_WAIT_FOREVER, 0);
    mkfifo("j2u.fifo", 0644);
    mkfifo("u2j.fifo", 0644);

    pid_t pid_j, pid_u;

    // 创建裁判进程
    pid_j = fork();
    if (pid_j < 0) {
        printf("Fail to create judge process.\n");
        return 1;
    } else if (pid_j == 0) {
        run_judge();
        return 0;
    }

    // 创建用户进程
    pid_u = fork();
    if (pid_u < 0) {
        printf("Fail to create user process.\n");
        return 1;
    } else if (pid_u == 0) {
        run_user();
        return 0;
    }

    // 等待进程运行结束，并判定结果
    int stat_j, stat_u;
    waitpid(pid_j, &stat_j, 0);
    waitpid(pid_u, &stat_u, 0);
    verdict(stat_j, stat_u);

    return 0;
}
