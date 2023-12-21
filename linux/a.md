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
### 