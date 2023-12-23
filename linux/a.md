# 输出环境变量
1.将路径永久添加到环境变量中  
echo $PATH//查看有哪些文件夹在环境变量中，将文件复制进去就行  
2.修改bashrc  
gedit ~/.bashrc  
在最后一行添加  
export PATH=$PATH:/文件位置  
3.临时改变环境变量  
export PATH=$PATH:文件位置  
 
# Makefile
目标 ： 依赖项  
    命令  
当依赖项比目标新，则执行命令  
hello : a.o b.o  
    gcc a.o b.o -o hello  
a.o : a.c  
    gcc -c -o a.o a.c  
b.o : b.c  
    gcc -c -o b.o b.c  
## 通配符
所有以后缀.c .o结尾的文件  
%.c %.o  
//目标文件  
$@  
第一个依赖项  
$<  
所有依赖项  
$^  
hello : a.o b.o  
    gcc $^ -o $@  
%.o : %.c  
    gcc -o $@ $<  

## 赋值和变量
使用时赋值  
=  
定义时赋值  
:=    
a = $(c)  
b := $(c)  
c = 123  
hello:  
    @echo $(a)    
    @echo $(b)  
a = 空  
b = 123  
## 函数
### foreach 遍历A中元素
$(foreach var,list,text)
for each var in list, change it to text  
A = a b c  
B = $(foreach f,$(A),$(f).o)  
all :
    @echo B = $(B)  
```
a.o b.o c.o
```
### filter 取出符合A中格式的值
$(filter pattern,text)
C = a b c d/  
D = $(filter %/,$(C))  
hellp:  
	@echo $(D)  
```
d/
```
### wildcard在当前目录下查找符合条件的文件  
$(wildcard pattern)
files = $(wildcard *.c)  
hellp:  
	@echo $(files)   
```
a.c
```
### patsubst 替换
$(patsubst pattern,replacement,$(var))
file = a.c b.c c.c  
out = $(patsubst %.c,%.d,$(file))  
hellp:  
	@echo $(out)  
```
a.d b.d c.d
```
## 示例
gcc -M a.c 打印出a.c的所有依赖文件
gcc -M -MF c.d a.c 把依赖文件写入c.d中
gcc -c -o c.o c.c -MD -MF .c.d 编译c.o，把依赖写入文件.c.d中
### 常用参数
make[-f file] [options] [target]  
make 默认在当前目录中查找GUNmakefile、makefile 及 Makefile 文件作为make的输入文件  
-f 指定文件作为输入文件  
-v 显示版本号  
-n 只输出命令不执行， 一般作为测试  
-s 执行命令不显示命令，  
-w 显示执行前和执行后的路径  
-C dir 指定makefile 所在的目录  
# 文件IO
### 错误信息
errno：标准错误号，通过errno可以找到错误信息  #include <errno.h>  
perror：打印输入字符串后打印错误信息  #include <stdio.h> void perror(const char *s);    
strerror：输入错误号，得到错误信息 #include <string.h> char *strerror(int errnum);  
### 文件句柄
文件句柄（File Handle）是操作系统中用于访问文件的一种数据结构，通常是一个整数或指针。文件句柄用于标识打开的文件，每个打开的文件都有一个唯一的文件句柄。  
在 Linux 和 Unix 系统中，文件句柄是通过调用 open() 系统调用打开文件时返回的。当打开一个文件时，操作系统会为该文件分配一个文件句柄，并将其返回给应用程序。应用程序可以使用文件句柄来读取、写入、关闭文件等操作。  
```
include<stdio.h>
int main(){
    printf("hello world!);
}
```
在以上代码中，文件句柄：  
0 stdin  
1 stdout  
2 stderror  
### dup函数
int dup(int oldfd);复制原来的文件句柄，并返回
int dup2(int oldfd, int newfd);先关闭newfd，将newfd只想oldfd
例如将printf的文件句柄替换成打开文件的句柄
```
fd = open("1.txt",O_RDWR);
dup2(fd,1);
printf("hello world!");
```
将“hello world！”打印到文件中  
# 输入系统编程
![Alt text](image.png)  
## APP访问硬件的四种方式
int ioctl(int fd, unsigned long request, ...);  
可以获取设备的信息
### 查询方式  
在OPEN函数中传入O_NOBLOCK表示非阻塞，当驱动程序中有数据则返回数据，如果没有数据则返回错误。  
### 休眠-唤醒  
在OPEN函数中不传入O_NOBLOCK，当有数据时返回，没有数据时休眠   
### POLL/SELECT方式
使用poll或者select设置延时，当延时到时没有数据则休眠，当有数据时则返回  
当在休眠期间操作硬件，则唤醒APP  
poll/select可以检测多个文件  
```
struct pollfd fds[1];
int timeout_ms = 5000;
int ret;
fds[0].fd = fd;
fds[0].events = POLLIN;
ret = poll(fds, 1, timeout_ms);
if ((ret == 1) && (fds[0].revents & POLLIN))
{
read(fd, &val, 4);
printf("get button : 0x%x\n", val);
}
```
### 异步通知
当驱动程序有数据则主动通知APP  
编程步骤：
```
1.编写信号处理函数：
static void sig_func(int sig)
{
int val;
read(fd, &val, 4);
printf("get button : 0x%x\n", val);
}
2.注册信号处理函数:
signal(SIGIO, sig_func);
3.打开驱动：
fd = open(argv[1], O_RDWR);
4.把进程 ID 告诉驱动：
fcntl(fd, F_SETOWN, getpid());
5.使能驱动的 FASYNC 功能：
flags = fcntl(fd, F_GETFL);
fcntl(fd, F_SETFL, flags | FASYNC);
```
# 网络编程
## int socket(int domain, int type,int protocol);
创建一个套接字  
## int bind(int sockfd, struct sockaddr *my_addr, int addrlen);  
绑定IP  
## int listen(int sockfd,int backlog);
监听是否有请求输入  
## int accept(int sockfd, struct sockaddr *addr,int *addrlen);
接收请求  
## int connect(int sockfd, struct sockaddr * serv_addr,int addrlen);
建立连接  
## ssize_t send(int sockfd, const void *buf, size_t len, int flags);
客户端或者服务器发送数据  
## ssize_t recv(int sockfd, void *buf, size_t len, int flags);
客户端或者服务器接受数据  
## ssize_t recvfrom(int sockfd, void *buf, size_t len, int flags,struct sockaddr *src_addr, socklen_t *addrlen);
用于获得发送者的地址  
