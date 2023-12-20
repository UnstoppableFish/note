#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <fstream>
#include <ctime>
#include<deque>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<set>
#include<map>
#include<functional>
using namespace std;

//指针
// void test(){
//     int a = 0;
//     int *p = &a;
//     cout << sizeof(int * ) << endl;//32位操作系统中占四个字节，64位操作系统中占八个字节
// }

//结构体的初始化
// struct stu{
//     int age;
//     string name;
// };
// void test(){
//     //第一种初始化方法
//     struct stu p1;
//     p1.age = 10;
//     p1.name = "hello world!";
//     //第二种初始化
//     struct stu p2 = {20,"hello"};
//     cout << p2.age << endl;
// }


//结构体数组
// struct my{
//     int age;
//     char name[20];
// };
// void test(){
//     // 第一种初始化方法
//     my myst [2];
//     myst[0].age = 18;
//     cout << myst[0].age << endl;
//     // 第二种初始化方法
//     my a1 [2] = {{10,"sd"},{20,"hello"}};
//     cout << a1[0].name << endl;
// }

//结构体指针
//第一种声明
// struct student{
//     int age;
//     string name;
// };
// //第二种声明
// typedef struct{
//     int age;
//     string name;
// }per;

// void test(){
//     struct student a;
//     struct student *p = &a;
//     p->name = "xm";

//     per t;
//     per *b = &t;
//     b->name = "xl";
//     cout << b->name << endl;
    
// }

//结构体嵌套
// struct student{
//     int age;
//     string name;
// };

// //结构体嵌套
// typedef struct{
//     int age;
//     string name;
//     struct student an[20];//一个人带二十个学生
// }teacher;

// void test(){
//     struct student xm = {10,"xm"};
//     teacher cla [3];//三位老师
//     cla[0].an[0] = xm;
//     teacher *p = &cla[0];//结构体指针
//     cout << p->an[0].name << endl;
    
// }

//机构体作为函数参数
// typedef struct{
//     string name;
//     int age;
// }student;
// //引用传递
// void print1(student &a){
//     cout << a.age << endl;
// }
// //地址传递
// void print2(student *p){
//     cout << p->age << endl;
// }
// //值传递
// void print3(student p){
//     cout << p.age << endl;
// }
// void test(){
//     student a1 = {"xm",18};
//     print1(a1);
//     print2(&a1);
//     print3(a1);
// }

//const使用场景
//引用或者地址传递时防止在函数中误操作
// typedef struct{
//     string name;
//     int age;
// }student;
// //引用传递
// void print1(const student &a){
//     cout << a.age << endl;
//     // a.age = 12;无法修改
// }
// //地址传递
// void print2(const student *p){
//     cout << p->age << endl;
//     // a.age = 12;//无法修改
// }

// void test(){
//     student a1 = {"xm",18};
//     print1(a1);
//     print2(&a1);
// }

//结构体案例1
// typedef struct{
//     string name;
//     int score;
// }student;

// typedef struct{
//     string name;
//     student stu[5];
// }teacher;

// void getvalue(teacher an[],int len){
//     string name = "ABCDE";
//     for(int i = 0;i < len;i++){
//         an[i].name = "Teachaer_";
//         an[i].name += name[i];
//         for(int j = 0;j < 5;j++){
//             an[i].stu[j].name = "Student_";
//             an[i].stu[j].name += name[j];

//             int randi = rand() % 60 + 40;
//             an[i].stu[j].score = randi;
//         }
//     }
// }
// void printvalue(teacher an[],int len){
//     for(int i = 0;i < len;i++){
//         cout << "teacher:" << an[i].name << ",the students are:"<< endl;
//         for(int j = 0;j < 5;j++){
//             cout << an[i].stu[j].name << " got score of " << an[i].stu[j].score << endl;
//         }
//     }
// }

// void test(){
//     srand((unsigned int) time(NULL));
//     teacher tea[3];
//     int len = sizeof(tea) / sizeof(tea[0]);
//     getvalue(tea,len);
//     printvalue(tea,len);
// }

//案例2
// typedef struct{
//     string name;
//     int age;
//     string sex;
// }hero;

// void swapa(hero & a,hero &b){
//     hero temp;
//     temp  = a;
//     a = b;
//     b = temp;
// }

// void sorthero(hero an[],int len){
//     for(int i = 0;i < len;i++){
//         int max = i;
//         for(int j = i + 1;j < len;j++){
//             if(an[max].age < an[j].age){
//                 max = j;
//             }
//         }
//         if(max != i){
//             swapa(an[max],an[i]);
//         }
//     }
// }

// void showhero(const hero an[],int len){
//     for(int i = 0;i < len;i++){
//         cout << an[i].name << " : " << an[i].age << ",sex is :" << an[i].sex << endl;
//     }
// }

// void test(){
//     hero an[5] = {  {"lb",20,"male"},
//                     {"zf",18,"male"},
//                     {"gy",19,"male"},
//                     {"dc",16,"female"},
//                     {"zy",18,"male"}};
//     int len = sizeof(an) / sizeof(an[0]);
//     cout << len << endl;
//     sorthero(an,len);
//     showhero(an,len);      
// }

//通讯录管理系统
// const string FILENAME = "1.txt";
// typedef struct{
//     int number;
//     string name;
// }person;

// typedef struct{
//     person an[1000];
//     int len;
// }listr;

// void savefile(listr* p);

// void showmenu(){
//     cout << "********1.add********" << endl;
//     cout << "********2.show*******" << endl;
//     cout << "********3.del********" << endl;
//     cout << "********4.seek*******" << endl;

//     cout << "********5.change*****" << endl;
//     cout << "********6.clear******" << endl;
//     cout << "********0.out********" << endl;
// }

// void addmember(listr *p){
//     int i;
//     cout << "please enter the number :" << endl;
//     cin >> i;
//     if(i >= 0){
//         int temp = p->len;
//         i = i + p->len;
//         int number;
//         string name;
//         p->len += i;
//         for(int k = temp;k < i;k++){
//             cout << "please enter the number" << endl;
//             cin >> number;
//             cout << "please enter the name" << endl;
//             cin >> name;
//             p->an[k].name = name;
//             p->an[k].number = number;
//         }
//     }
//     else{
//         cout << "dont be child" << endl;
//     }
//     savefile(p);
//     system("pause");
//     system("cls");
// }

// void showmenber(listr *p){
//     if(p->len == 0){
//         cout << "no one exist" << endl;
//         return;
//     }
//     cout << "there have " << p->len << "person" << endl;
//     for(int i = 0;i < p->len;i++){
//         cout << p->an[i].name << "'s number is :" << p->an[i].number << endl;
//     }
//     system("pause");
//     system("cls");
// }

// void loadfile(listr* p) {
//     ifstream ifs;
//     ifs.open(FILENAME, ios::in);
//     int i = 0;
//     int id = 0;
//     string name;
//     while (ifs >> name && ifs >> id)
//     {
//         p->an[i].name = name;
//         p->an[i].number = id;
//         i++;
//     }
//     p->len = i;
//     cout << "load successful" << endl;
//     ifs.close();
// }

// void savefile(listr* p) {
//     ofstream ofs;
//     ofs.open(FILENAME, ios::out);
//     for (int i = 0; i < p->len; i++) {
//         ofs << p->an[i].name << " " << p->an[i].number << endl;
//     }
//     cout << "save successful" << endl;
//     ofs.close();

// }

// int seekm(listr *p) {
//     int id = 0;
//     string name;
//     cout << "enter the name you would to find" << endl;
//     cin >> name;
//     cout << "enter the id you would to find" << endl;
//     cin >> id;
//     for (int i = 0; i < p->len; i++) {
//         if (p->an[i].name == name && p->an[i].number == id) {
//             cout << "we found the member" << endl;
//             return i;
//         }
//     }
//     cout << name << "not exist" << endl;
//     return -1;
// }

// void delmember(listr *p) {
//     int temp = seekm(p);
//     for (int i = temp; i < p->len; i++) {
//         if (i != p->len - 1) {
//             p->an[i] = p->an[i + 1];
//         }
//     }
//     p->len--;
//     cout << "delete scuessful" << endl;
//     savefile(p);
// }

// void exits(){
//     exit(1);
// }

// void test(){
//     listr p;
//     p.len = 0;
//     int i = 0;
//     loadfile(&p);
//     while (true)
//     {
//         /* code */
//         showmenu();
//         cout << "please enter your choice" << endl;
//         cin >> i;
//         switch(i){
//             case 0:
//                 exits();
//                 break;
//             case 1:
//                 addmember(&p);
//                 break;
//             case 2:
//                 showmenber(&p);
//                 break;
//             case 3:
//                 delmember(&p);
//                 break;
//             case 4:
//                 seekm(&p);
//                 break;
//             case 5:
//                 break;
//             case 6:
//                 break;
//             default:
//                 break;
//         }
//     }
    
// }

//链表
//静态链表
// struct link{
//     int data;
//     struct link *next;
// };
// void test(){
//     link a1 = {10,NULL};
//     link a2 = {11,NULL};
//     link a3 = {12,NULL};
//     link a4 = {13,NULL};
//     a1.next = &a2;
//     a2.next = &a3;
//     a3.next = &a4;
//     //遍历链表
//     link *cur;
//     cur = &a1;
//     while (cur != NULL)
//     {
//         /* code */
//         cout << cur->data << endl;
//         cur = cur->next;

//     }
        
// }

//动态链表
// struct link{
//     int data;
//     struct link *next;
// };
// struct link * linkinit(){
//     //第一步，创建头结点
//     struct link *p = new struct link;
//     p->data = -1;
//     p->next = NULL;
//     //第二步，创建滑动指针
//     struct link *slid = p;
//     //第三步，用户输入新节点
//     while(true){
//         int a = 0;
//         cout << "please enter the link data" << endl;
//         cin >> a;
//         if(a == -1){
//             break;
//         }
//         link *newl = new link;
//         newl->data = a;
//         newl->next = NULL;
//         //将滑动节点当前指向的节点，指向新创建的节点，并且更新自身指向新节点
//         slid->next = newl;
//         slid = newl;
//     }
//     cout << endl;
//     return p;
// }

// void bianli(struct link *p){
//     struct link *a = p->next;
//     while (a != NULL)
//     {
//         /* code */
//         cout << a->data << " ";
//         a = a->next;
//     }
// }

// void linkinsret(link *p){
//     link *pre = p;
//     link *now = p->next;
//     link *newl = new link;
//     newl->data = 20;
//     newl->next = NULL;
//     while(true){
//         if(now->data == newl->data){
//             pre->next = newl;
//             newl->next = now;
//             cout << "insert successful" << endl;
//             break;
//         }
//         pre = now;
//         now = now->next;
//     }
// }
// void test(){
//     struct link *p = linkinit();
//     bianli(p);
//     linkinsret(p);
//     bianli(p);
// }
// union：每次只能存一个值，存储空间大小最大的那个数据
// 匿名联合：地址相同


// 数组指针的一个例子
// void test()
// {

//     int an[] = {1,2,3,45,6,7,2}; 
//     int *a = an;//普通指针，指向首地址的指针
//     int (*p)[sizeof(an)/sizeof(an[0])] = &an; //数组指针，指针可以代替数组

//     cout << *(a + 1) << endl;
//     cout << (*p)[0] << endl;
//     delete [] p;
// }

//动态内存分配的一个例子
// char *name(void){
//     char in[80];
//     cin.getline(in,80);
//     char *temp = new char [strlen(in) + 1];
//     strcpy(temp,in);
//     return temp;
// }
// void test()
// {
//     int *p = new int(6);//*p = 6
//     cout << *p << endl;

//     char *my;
//     my = name();
//     cout << my + 1 << endl;//从第my + 1个起
//     delete [] my;
// } // namespace name

//auto
// void test(){
//     struct myst
//     {
//         int age;
//         char name[20];

//     };
//     myst stu[3];
//     //指针数组
//     myst *p[3] = {&stu[0],&stu[1],&stu[2]};
//     p[0]->age = 10;
//     cout << p[0]->age << endl;
//     strcpy(p[1]->name,"hello");
//     cout << p[1]->name << endl;
//     stu[2].age = 10;
//     strcpy(p[2]->name,"he");
//     cout << p[2]->name<< endl;
//     //auto
//     auto vi = stu;
//     auto ci = p;
//     p[1]->age = 12;
//     cout << ci[1]->age << endl;
//     vi[0].age = 10;
//     cout << stu[0].age << endl;
// }

//vector
//长度调整
// void test(){
//     vector<int> vi(10);//10个int长度
//     array<int,5> v;//5个固定长度
//     vi[5] = 10;
//     cout << vi.at(5) << endl;
// }

//常量指针和指针常量
// void test(){
//     int age = 10;
//     const int * p = &age;//常量指针可以修改指向的对象，但不能修改指向的对象的值
//     //不能通过p修改age的值，但是age可以修改自己
//     age = 20;
//     cout << *p << endl;
//     int * const vi = & age;//指针常量可以修改指向的对象的值但不能修改指向的对象
//     *vi = 10;
//     cout << age << endl;
// }



//结构体指针

// struct stu{
//         int x;
//         int y;
//     };
// void change(stu *a,stu *b){
//     int temp;
//     temp = a->x;
//     a->x = b->x;
//     b->x = temp;

// }
// void test(){

//     stu vi;
//     stu p;
//     vi.x = 1;
//     p.x = 2;
//     change(&vi,&p);
//     cout << vi.x << " " << p.x << endl;

// }

//函数指针
// int * pint(int * a,char * b){
//     cout << *a << b << endl;
//     return a;
// }

// void test(){
//     int * (*p)(int *,char *) = &pint;//函数指针声明
//     auto pf = pint;//也可以这样用
//     int a = 10;
//     char an[10]= "hello";
//     int *vi = p(&a,an);
//     int * ci = (*p)(&a,an);//两种方式都可以
//     int * ti = pf(&a,an);
//     cout << *vi << " " << *ci << endl;
// }

//typedef用于简化函数指针
// int * pint(int * a,char * b){
//     cout << *a << b << endl;
//     return a;
// }
// void test(){
//     typedef int * (*p)(int *,char *);
//     p vi = pint;//可以利用p来初始化任何函数指针

//     int a = 10;
//     char an[10]= "hello";
//     int *b = vi(&a,an);

//     //函数数组指针和函数指针数组
//     p ti[3] = {pint,pint,pint};
//     int *c = ti[1](&a,an);
//     int *d = ti[2](&a,an);

//     p (*ci)[3] = &ti;//数组指针指向指针数组
//     int *e = ci[0][1](&a,an);//[0]代表行，只有一行,[1]代表列
// }

//指针数组和数组指针和二维数组的关系
// void test(){
//     int an[3][3] = {{1,1,1},{2,2,2},{3,3,3}};

//     int (*p)[3];//列需一致
//     p = an;
//     for(int i = 0;i < 3;i++){
//         for(int j = 0;j < 3;j++){
//             cout << *(*(p + i) + j) << " ";
//             cout << *(p[i] + j) << " ";
//         }
//     }
//     cout << endl;

//     int *vi[3] = {an[0],an[1],an[2]};
//     for(int i = 0;i < 3;i++){
//         for(int j = 0;j < 3;j++){
//             cout << *(vi[i] + j) << endl;
//         }
//     }
// }

//二维数组的数组名的含义
// void test(){
//     int an[2][2] = {{1,1},{2,2}};

//     cout << &an << " " << &an + 1 << endl;//相差16,说明&an取到整个数组的地址

//     cout << an << " " << (an + 1) << endl;//相差8，说明an取得是行地址

//     cout << an[0] <<  " " << an[0] + 1 << endl;//相差4，说明an[0]取到了第一行

// }

//引用作为函数参数传递
// void ch(int& a,int& b){
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// void test(){
//     int a = 10;
//     int b = 29;
//     ch(a,b);
//     cout << a << " " << b;
// }

//引用结构体参数
// struct stu{
//     int age;
//     char name[20];
//     float i;
// };
// stu & teststu(stu & vi){//引用
//     vi.age = 10;
//     cout << vi.age << endl;
//     return vi;
// }

// stu * test1(stu * ci){//指针
//     ci->age = 20;
//     return ci;
// }
// void test(){
//     typedef stu & (*p)(stu &);
//     typedef stu * (*fp)(stu *);
//     p pi = teststu;
//     fp ei = test1;

//     stu mystu;
//     stu mystu2;

//     stu * pt = &mystu2;
//     stu *ti1 = ei(pt);
//     cout << ti1->age << endl;
//     stu ti = pi(mystu);
//     cout << ti.age << endl;
// }

//函数重载，同名函数，同一作用域，参数的位置，个数和类型不同可以发生函数重载,仅通过返回值不能发生重载
// char *test2(char *an){
//     cout << "1" << endl;
//     return an;
// }
// void test2(int an){
//     cout << "2" << endl;
// }
// // int test2(int bn)//返回值不能重载
// // {
// //     cout << " " << endl;
// // }
// int test1(int an){
//     cout << "3" << endl;
//     return an;
// }
// char * test1(const char * an){
//     cout << "4" <<endl;
//     char *p = new char;
//     return p;
// }
// char * test1( char * an){
//     cout << "5" <<endl;
//     return an;
// }
// void test(){
//     int a = 10;
//     const char an[10] = "hello!";
//     const char *p = an;
//     char bn[10] = "world!";
//     test2(bn);//如果没有const会重载有const的函数中,常量兼容变量
//     test2(a);
//     test1(a);
//     char *vi = test1(p);
//     delete vi;
//     test1(bn);//如果有不带const的函数则重载不带const的函数中
// }

//函数模版
// template <typename T_,typename F_Ynem>
// void test1(T_ &a,T_ &b,F_Ynem *n);

// void test(){
//     int a = 10,b = 20;
//     char cn[] = "hello";
//     test1(a,b,cn);
//     cout << a << "\n" << b << endl;
// }

// template <typename T_,typename F_Ynem>
// void test1(T_ &a,T_ &b,F_Ynem *n){
//     cout << n << endl;
//     T_ temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// 头文件
// #ifdef A_H_
// #define A_H_

// #endif

// void test(){

//     class myclass

//     {
//     private:
//         /* data */
//         char sex[10] = "mail";
//     public:
//         myclass(const char *name,int age){
//             this->age = age;//this指向实例化的对象
//             strcpy(this->name,name);
//         }
//         void get_sex(){
//             cout << this->sex << endl;
//         }
//         void show() const//const 不修改调用对象
//         {
//             cout << "No change" << endl;
//         }
//         const myclass & comp(const myclass & vi)//返回年龄更大的那个对象
//         {
//             if(this->age > vi.age){
//                 return *this;
//             }
//             else
//             {
//                 return vi;
//             }
//         }
//         int age;
//         char name[10];
//     };
//     myclass stu[3] = {{"xm",10},{"xh",20},{"xl",21}};//类数组
//     cout << stu[0].age << endl;
//     myclass xm("xm",10);
//     myclass xl(xm);
//     myclass xh = myclass("xh",20);
//     cout << (xm.comp(xh)).name << endl;
//     xm.get_sex();
//     xm.show();
//     cout << xh.age << endl;
//     cout << xl.name << endl;
// }

// 运算符重载
// class person{
//     friend ostream & operator<<(ostream &cout,person p);//友元
//         public :

//             person(){
//                 this->a = 10;
//                 this->b = 10;
//                 this->c = 100;

//             }

//             person operator+(person & vi)//加法运算符重载
//             {
//                 person temp;
//                 temp.a = this->a + vi.a;
//                 temp.b = this->b + vi.b;
//                 return temp;
//             }

//             person operator-(person &vi)//减法运算符重载
//             {
//                 person temp;
//                 temp.a = this->a - vi.a;
//                 temp.b = this->b - vi.b;
//                 return temp;
//             }

//             person & operator++()//++前置重载
//             {
//                 ++this->c;
//                 return *this;
//             }

//             person operator++(int)//++后置重载
//             {
//                 person vi = *this;
//                 this->c++;
//                 return vi;//返回局部变量的拷贝
//             }



//             int a;
//             int b;
//         private :
//             int c;
//     }; 

// ostream & operator<<(ostream &cout,const person p)//左移运算符重载
// {
//         cout << p.c ;
//         return cout;
// }
// void test(){
//     person xm;
//     person xh;
//     person xz;

//     person xl = xm + xh + xz;
//     person a = xm - xh;
//     // cout << a.a << endl;

//     // cout << ++xm << endl;
//     // cout << xm << endl;

//     cout << xm++ << endl;
//     cout << xm << endl;

// }

// 等号运算符重载
// class person{

//     public:
//         person(int age){
//             m = new int(age);
//         }
//         ~person(){
//             if(m != NULL){
//                 delete m;
//                 m = NULL;
//             }
//         }

//         person & operator=(person &p){
//             if(m != NULL){
//                 delete m;
//                 m = NULL;
//             }
//             m = new int(*p.m);
//             return *this;
//         }
//         int *m;
// };

// 关系运算符重载
// class person{
//     public:
//         person(int age,string name){
//             this->age = age;
//             this->name = name;
//         }

//         bool operator==(person &p){
//             if(this->name == p.name && this->age == p.age){
//                 return true;
//             }
//             else{
//                 return false;
//             }
//         }
//         int age;
//         string name;
// };
// void test(){
//     person xm(18,"xm");
//     person xh(18,"xm");
//     if(xm == xh){
//         cout << "they are the same" << endl;
//     }
// }
//小括号重载（仿函数）
// class myprint{

//     public :
//         void operator()(string text){
//           cout << text << endl;  
//         }

//         int operator()(int a,int b){
//             return a + b;
//         }
// };
// void test(){
//     myprint pr;
//     cout << pr(1,2) << endl;//仿函数调用
//     cout << myprint()(2,3) << endl;//匿名函数调用
//     pr("myname");
// }

//三种继承方式
// class farther{
//     public :
//         // string name;
//         // void setname(string name){
//         //     this->name = name;
//         // }
//         int a = 10;
//     protected:
//         int age;
//     private:
//         int sex;
// };
// class son1:public farther//public继承，继承的父类原属性不变，公共是公共，保护是保护，私有是私有
// {
//     public :
//         void func(){
//             a = 10;
//             age = 20;
//         }
// };
// class son2:protected farther//保护继承，父类的公共和保护都变成子类的保护属性，父类的私有属性子类不能访问
// {
//     public:
//         void fun(){
//             age = 20;
//         }
// };
// class son3:private farther//私有继承，父类的公共和保护变为子类的私有属性，父类的私有属性子类不能访问
// {};

// class gradeson:public son3{
//     void get(){
//         // a = 10;//not accessable
//     }
// };

// void test(){
//     farther a1;
//     // a1.setname("xm");//后初始化的属性不能继承
//     son1 s1;
//     // s1.age = 41；//访问不到

//     son2 s2;
//     cout << sizeof(s2) << endl;//父类的属性只是被隐藏而不是丢弃
// }

//在继承中类的构造和析构方式方式
// class fa{
//     public :
//         fa(){
//             cout << "start" <<endl;
//         }
//         ~fa(){
//             cout << " del far" << endl;
//         }
// };

// class son1:public fa {
//     public:
//         son1(){
//             cout << "son" << endl;
//         }
//         ~son1(){
//             cout << "del son" << endl;
//         }
// };
// void test(){
//     son1 a2;//创建子类的同时创建父类，会先生成父类的构造；析构则是先析构子类
// }

//类中同名函数的处理方式，需要调用父类的方法需要添加父类的作用域
//类继承中的函数重载
// class fa{
//     public :
//         void get()
//         {
//             cout << "get name" << endl;
//         }
//         void get(int){
//             cout << "get faname" << endl;
//         }
// };

// class son1 : public fa{
//     public :
//         void get(){
//             cout << "get son name" << endl;
//         }
//         // void get(int){
//         //     cout << "get intname" << endl;
//         // }
// };

// void test(){
//     fa a;
//     son1 s1;
//     s1.fa::get(10);//调用父类的方法
//     s1.get();//调用子类的方法
// }
// 静态成员变量和静态成员函数
// 静态成员变量：所有对象共用同一个静态数据的内存，类内声明类外初始化，程序运行之前分配内存；有访问权限
//静态成员函数：所有对象共用一个静态函数，静态成员函数只能访问静态成员变量；有访问权限
// class fa{
//     public :
//         int e = 10;
//         static int a;
//         static int c;
//         static void get(){
//             cout << a << endl;
//         }
//     private:
//         static int d;
// };
// class son1:public fa{
//     public :
//         static int b;
// };
// // 初始化放在函数外
// // 静态变量不属于实例
// int fa::a = 10;
// int fa::c = 20;
// int fa::d = 10;
// // int fa::a = 50;不可重定义
// void test(){
//     fa a1;
//     fa a2;
//     son1 s1;
//     son1 s2;
//     // cout << a1.d << endl;私有静态属性也不能访问
//     cout << a2.a <<" " << fa::a <<  endl;//获得了a1中的静态数据
//     cout << s1.c << " " << s2.a <<  endl;
//     a1.get();//实例访问
//     fa::get();//类访问
// }


//类拷贝构造函数
// class person{
//     public :
//         person(){
//             cout << "construct" << endl;
//         }

//         ~person(){  
//             cout << "del" << endl;
//         }
//         person(int age){
//             cout << "int construct" << endl;
//             this->age = age;
//         }
//         person(const person &p){
//             age = p.age;
//             cout << "copy" << endl;
//         }
//         int age;
// };
// //值传递给函数也会调用拷贝构造
// void co(person p){
//     cout << p.age << endl;
// }
// //返回局部对象的拷贝
// person work(){
//     person a2;
//     cout << (int * )&a2 << endl;
//     return a2;
// }
// void test(){
//     person a = person(20);
//     cout << a.age << endl;
//     // person a1(10);
//     // person a2(a1);//第一种调用方式，拷贝一个创建好的类对象

//     // co(a1);//第二种调用方式
//     // person a3 = a1;
//     person vi = work();//第三种调用方式
//     cout << (int *)&vi << endl;

// }

//如果不写构造函数，系统会自动提供
//如果自己写了拷贝构造，系统则不提供默认构造和有参构造
//如果自己写了有参构造，系统则不提供默认构造
// class person{
//     public:
//         person(int age){
//             age = age;
//         }
//         int age = 10;

// };
// void test(){
//     person a1(20);
//     person a2 = a1;//；利用系统提供的拷贝构造函数
//     cout << a2.age << endl;
// }
//深浅拷贝
// class person{
//     public:
//         person(int age,int height,string name,char *a){
//             this->age = age;
//             this->height = new int(height);
//             this->name = name;
//             strcpy(an,a);
//         }
//         person(person &p){
//             this->height = new int(*p.height);//深拷贝
//             this->age = p.age;
//             this->name = p.name;
//             strcpy(this->an,p.an);
//             cout << "del" << endl;
//         }
//         ~person(){
//             if(height !=NULL){
//                 delete height;
//                 height = NULL;
//             }
//         }


//     int age;
//     int *height;
//     string name;
//     char an[10];
// };

// void test(){
//     char an[10] = "hello";
//     person a1(10,160,"xm",an);
//     person a2(a1);
//     cout << *a2.height << endl;
// }

// 初始化列表
// class person{
//     public:
//     person(int a,int b,int c):a(a),b(b),c(c){

//     }
//     int a,b,c;
// };
// void test(){
//     person a1(1,1,1);
//     cout << a1.a << " " << a1.b << " " << a1.c << endl;
// }

// 类中类
// 先构造手机类
// class phone{
//     public:
//         phone(string t):type(t){
//             cout << "phone construct" << endl;
//         }
//         string type;
// };
// class person{
//     public:
//         person(int age,phone vi):m_age(age),m_vi(vi){
//             cout << "person construct" << endl;
//         }
//     int m_age;
//     phone m_vi;
// };
// void test(){
//     phone a1("huawei");
//     person a2(18,a1);
//     cout << a2.m_vi.type << endl;
// }

// 成员函数和成员变量分开存储
// 只有非静态成员变量存储在类上
// 空指针也能访问类对象
// class person{
//     public:

//         void work(){
//             cout << "test called" << endl;
//         }
//         void work2(){
//             if(this == NULL){
//                 cout << "you got none" << endl;
//             }
//             else{
//                 cout << "you got right" << endl;
//             }
//         }
//         int age;

// };
// void test(){
//     person *p = NULL;
//     p->work();
//     p->work2();
// }

// 常函数
// class person{
//     public:
//         person(int age){
//             mage = age;
//         }
//         void work(int age)const//不能修改成员变量，加上const相当于变成 const * const this
//         {
//             a = age;
//             cout << "const function called" << endl;
//         }

//         void work2(){
//             cout << "none const called" << endl;
//         }
//         mutable int a;//加上mutable可以在常函数中修改
//         int mage;

// };
// void test(){
//     const person a1(10);//常对象
//     a1.work(1);
//     a1.a = 20;
//     // a1.work2();常类对象不可调用非常函数

// }

// 友元
// class vi;
// class build{
//     friend class vi;//友元类
//     friend void visit(build &p);//友元函数
//     friend void vi::visti();//友元类函数
//     public:
//         build(){
//             sittingroom = "sittingroom";
//             beddingroom = "beddingroom";
//         }
//         string sittingroom;
//     private:
//         string beddingroom;
// };
// class vi{
//     public:
//         vi(string name):m_name(name){
//             building = new build;
//         }
//         ~vi(){
//             if(building !=  NULL){
//                 delete building;
//                 building = NULL;
//             }
//         }
//         void getin(){
//             cout << m_name << " "<< "is visiting " << building->sittingroom << endl;
//             cout << building->beddingroom << endl;//成为友元类之后可以访问私有属性
//         }

//         void visti(){
//             cout << m_name << " "<< "is visiting " << building->sittingroom << endl;
//             cout << building->beddingroom << endl;//成为友元类之后可以访问私有属性
//         }
//         string m_name;
//         build *building;
// };

// void visit(build &p){
//     cout << p.beddingroom << endl;
// }

// void test(){
//     vi a1("xm");
//     a1.visti();

//     build ci;
//     visit(ci);
// }

//多继承
// class base{
//     public:
//         int a;
// };
// class vi{
//     public:
//         int b;
//         int a;
// };
// class son:public base,public vi
// {
//     public:
//         int d;
// };
// void test(){
//     son a1;
//     cout << a1.base::a << endl;
// }

// 菱形继承
// class animal{
//     public :
//         int age;
// };
// // 虚继承,消除菱形继承中的继承同一个属性的问题
// class sheep:public virtual animal{};
// class tuo:public virtual animal{};
// class son:public sheep,public tuo{
//     public:
//         int a;
// };
// void test(){
//     son a1;
//     a1.sheep::age = 18;
//     a1.tuo::age = 28;
//     cout << a1.sheep::age << endl;
// }

// 多态
// class animal{
//     public:
//         virtual void speak(){
//             cout << "animal speaks" << endl;
//         }
// };
// class cat:public animal{
//     public:
//         void speak(){//重写父类方法，返回值，名称和参数完全一致
//             cout << "cat speak" << endl;
//         }
// };
// class dog:public animal{
//     public:
//         void speak(){
//             cout << " dog speak" << endl;
//         }
// };
// void speak(animal &p)//动态多态：用父类的指针或者引用来执行子类对象
// {
//     p.speak();
// }
// void test(){
//     dog a1;
//     animal a2;
//     speak(a1);
// }

//多态：计算器类
// class Calculator{
//     public:
//         virtual int calcu(){
//             return 0;
//         }
//     int m_a;
//     int m_b;

// };

// class AddCalcu:public Calculator{
//     public:
//         int calcu(){
//             return m_a + m_b;
//         }
// };

// class SubCalcu:public Calculator{
//     public:
//         int calcu(){
//             return m_a - m_b;
//         }
// };

// void test(){
//     Calculator * p = new AddCalcu;//父类指针指向子类对象实现多态
//     p->m_a = 10;
//     p->m_b = 10;
//     cout << p->calcu() << endl;
//     delete p;

//     p = new SubCalcu;

// }

//抽象类
// class farther{
//     public:
//         virtual int calu() = 0;//纯虚函数，会使类变为抽象类，无法实例化
// };

// class son:public farther{
//     public:
//         son(int a1,int b1):a(a1),b(b1){
//         }
//         virtual int calu()//子类必须重写父类的虚函数，否则也是抽象类
//         {
//             return a + b;
//         }
//     int a;
//     int b;
// };
// void test(){
//     son s1(10,10);
//     cout << s1.calu() << endl;

// }
//例子
// class makeeat{
//     public:
//         virtual void fry() = 0;
//         virtual void toeast() = 0;
//         virtual void boil() = 0;
//         virtual void water() = 0;
//         virtual void getincup() = 0;

//         void maketea(){
//             fry();
//             toeast();
//             boil();
//             water();
//             getincup();
//         }
// };

// class wulong:public makeeat
// {
//     public:
//         void fry(){
//             cout << "小火10分钟" << endl;
//         }
//         void toeast(){
//             cout << "小火烘焙20分钟" << endl;
//         }
//         void boil(){
//             cout << "开水煮沸" << endl;
//         }
//         void water(){
//             cout << "加入山泉水" << endl;
//         }
//         void getincup(){
//             cout << "装入茶具" << endl;
//         }
// };
// void make(makeeat & p){
//     p.maketea();
// }
// void test(){
//     wulong a1;
//     make(a1);
// }

//纯虚析构，解决父类指针无法释放子类堆区空间的问题
// class farther{
//     public:
//         virtual void speak() = 0;

//         //虚析构函数，需要声明也需要实现
//         // virtual ~farther()//父类的虚析构函数可以让指向子类的父类指针调用子类的析构函数，释放子类堆区空间
//         // {
//         //     cout << "farther delete" << endl;
//         // }
//         //纯虚析构，类内声明内外实现
//         //如果存在纯虚析构函数，则类为抽象类，无法实例化
//         virtual ~farther() = 0;
// };
// farther::~farther(){
//     cout << "pure virtual delete" << endl;
// }
// class son:public farther{
//     public :
//         son(string name){
//             //开辟到子类中的堆区
//             m_name = new string(name);
//         }
//         void speak(){
//             cout << *m_name << " is speaking" << endl;
//         }
//         ~son(){
//             cout << "son delete called" << endl;
//             if(m_name != NULL){
//                 delete m_name;
//                 m_name = NULL;  
//             }
//         }
//         string *m_name;
// };

// void test(){
//     farther *p = new son("xm");
//     p->speak();
//     delete p;
// }

//电脑组装
// class cpu{
//     public:
//         virtual void cpus() = 0;
// };

// class vc{
//     public:
//         virtual void vcs() = 0;
// };

// class screen{
//     public:
//         virtual void screens() = 0;
// };

// class inter:public cpu{
//     public:
//         void cpus(){
//             cout << "made by inter" << endl;
//         }
// };

// class nvdia:public vc{
//     public:
//         void vcs(){
//             cout << " made by nvdia" << endl;
//         }
// };

// class computer{
//     public:
//         computer(cpu *p1,vc *p2){
//             cpu = p1;
//             vc = p2;
//         }
//         void work(){
//             cpu->cpus();
//             vc->vcs();
//         }
//         ~computer(){
//             cout << "computer delete" << endl;
//             if(cpu != NULL){
//                 delete cpu;
//                 cpu = NULL;
//             }
//             if(vc != NULL){
//                 delete vc;
//                 vc = NULL;
//             }
//         }
//         cpu *cpu;
//         vc * vc;
// };
// void test(){
//     cpu *p1 = new inter;
//     vc *p2 = new nvdia;
//     computer *p3 = new computer(p1,p2);
//     p3->work();
//     delete p3;
// }

// 1.包含头文件
// 2.创建流对象
// 3.打开文件
// 4.写
// 5.关闭文件
// 写文件
// void test(){
//     ofstream ofs;
//     ofs.open("1.txt",ios::out);
//     ofs << "please help" << endl;
//     ofs.close();
// }
// 读文件
// void test(){
//     ifstream ifs;
//     ifs.open("1.txt",ios::in);
//     if(!ifs.is_open()){
//         cout << "fail" << endl;
//         return;
//     }
//     //读取方式1
//     // char buf[1024];
//     // while (ifs >> buf)
//     // {
//     //     /* code */
//     //     cout << buf << endl;
//     // }
//     //读取方式2
//     // char buf[1024];
//     // while (ifs.getline(buf,sizeof(buf)))
//     // {
//     //     /* code */
//     //     cout << buf << endl;
//     // }
//     //第三种
//     char c;
//     while ((c = ifs.get()) != EOF)//EOF 是 end of file
//     {
//         cout << c;
//     }
//     ifs.close();
// }


// 二进制读写
// class person{
//     public:
//         int age;
//         char an[20];
// };

// void test(){
//     ofstream p1;
//     p1.open("1.txt",ios::out | ios::binary);
//     person a1 = {18,"xm"};
//     p1.write((const char *)&a1,sizeof(person));
//     p1.close(); 
// }
// class person{
//     public:
//         person ** an;
// };
// void test(){
//     person p;
//     p.an = new person *[3];
// }

//函数模版
// template <typename T>//template <class T>class = typename
// void swapa(T &a,T &b){
//     T temp = a;
//     a = b;
//     b = temp;
// }
// void test(){
//     int a = 0;
//     int b = 19;
//     //第一种使用方法：自动类型推导,数据类型必须一致
//     swapa(a,b);
//     // 第二种使用方法：指定类型,可以发生隐式类型转换，建议使用
//     swapa<int>(a,b);
//     cout << b << " " << a << endl;
// }

// 排序模版
// template <typename A_>
// void swapa(A_ &a,A_ &b){
//     A_ temp;
//     temp = a;
//     a = b;
//     b = temp;
// }
// template <typename T_>
// void sort(T_ an[],int len){
//     for(int i = 0;i < len;i++){
//         int max = i;
//         for(int j = i + 1;j < len;j++){
//             if(an[max] > an[j]){
//                 max = j;
//             }
//         }
//         if(max != i){
//             swapa(an[i],an[max]);
//         }
//     }
// }
// void test(){
//     char an[] = "badcfe";
//     int bn[] = {1,2,3,2,3,2,3,2,4,5};
//     int len1 = sizeof(bn) / sizeof(bn[0]);
//     int len = sizeof(an) / sizeof(char);
//     sort(an,len);
//     sort(bn,len1);
//     for(int i =0;i < len1;i++){
//         cout << bn[i] << endl;
//     }

// }

//函数模版与重载
//优先调用普通函数
// void myprint(int a,int v){
//     cout << a << endl;
// }
// template <class T>
// void myprint(T a,T b){
//     cout << a << endl;
// }
//通过空模板可以强制调用函数模板
// myprint<>(a,b);
//函数模板可以重载，
// template <class T>//函数模板必须跟随函数名一起使用
// void myprint(T a,T b,T c){
//     cout << a << endl;
// }
// template <class T>
// void myprint(T a,T b){
//     cout << a << endl;
// }
// void test(){
//     int a = 10,b = 29;
//     myprint(a,b);
// }
//如果函数模版更匹配则优先调用
// void myprint(int a,int b){
//     cout << "function" << endl;
// }
// template <class t>
// void myprint(t a,t b){
//     cout << "template" << endl;
// }
// void test(){
//     char a = 'a';
//     char b = 'b';
//     myprint(a,b);
// }

//第五天
//模板的局限性
// class person{
//     public:
//         person(int age){
//             this->age = age;
//         }

//         // bool operator==(person &a){
//         //     if(this->age == a.age){
//         //         return true;
//         //     }
//         //     else{
//         //         return false;
//         //     }
//         // }
//         int age;
// };


// template <class t_>
// bool camp(t_ &a,t_ &b){
//     if(a == b){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// //利用具体化的类的模版
// template <>bool camp(person &a,person &b){
//     if(a.age == b.age){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
// void test(){
//     int a = 19;
//     int b = 19;
//     cout << camp(a,b) << endl;
//     person a1(10);
//     person a2(10);
//     cout << camp(a1,a2) << endl;//可以调用类的模版函数
// }

//类模板函数
// template<typename tname,typename tage>
// class per{
//     public:
//         per(tname name,tage age){
//             this->m_name = new tname(name);
//             this->m_age = new tage(age);
//         }

//         void show(){
//             cout << "name is " << *this->m_name << " age is " << *this->m_age << endl;
//         }
//         per(per &a)//深拷贝
//         {
//             m_name = new tname(*a.m_name);
//             m_age= new tage(*a.m_age);
//             cout << " deepcopy called" << endl;
//         }

//         ~per(){
//             if(m_age != NULL){
//                 cout << "delete function called" << endl;
//                 delete m_age;
//                 m_age = NULL;
//             }
//             if(m_name != NULL){
//                 delete m_name;
//                 m_name = NULL;
//             }
//         };
//         tname *m_name;
//         tage *m_age;
// };

// void test(){
//     per<string,int> a1("xl",10);
//     per<string,int> a2(a1);
//     a2.show();
// }
//类模版与函数模板的区别
//类模版没有自动推导的使用方式
//

// template<class tname,class tage = int >//可以提前声明类模版参数的类型，不会报错
// class per{
//     public:
//         per(tname name,tage age){
//             this->name = name;
//             this->age = age;
//         }

//         void show(){
//             cout << "age is " << age << " name is " << name << endl;
//         }
//         tage age;
//         tname name;
// };

// void test(){
//     per<string> a1("xn",20);//类模板没有自动参数推导，必须指定参数类型
//     per<string> a2("xn",20);//类模板没有自动参数推导，必须指定参数类型
//     a1.show();
// }

//类模板中成员函数的创建时机
// class a1a{
//     public:
//         void fun1(){
//             cout << "a1 called" << endl;
//         }
// };

// class a2a{
//     public:
//         void fun2(){
//             cout << "a1 called" << endl;
//         }
// };

// template<class t>
// class per{
//     public:
//         t obj;
//     //类模版中的成员函数创建时机在实例化之后，实例化后才会检查语法错误
//     void fun(){
//         obj.fun1();
//         // obj.fun2();
//     }
// };

// void test(){
//     per<a1a> a1;
//     a1.fun();
// }

//类模版对象做函数参数的三种方式
//1.直接传入
// template <class t>
// class per{
//     public:
//         per(t age){
//             this->mage = age;
//         }
//         void show(){
//             cout << mage << endl;
//         }
//         t mage;
// };
// //第一种调用方法，直接传入指定类型
// void test1(per<int> & a1){
//     a1.show();
// }
// //第二种调用方法：参数模版化
// template <class t>
// void test2(per<t> & a){
//     cout << typeid(t).name() << endl;
//     a.show();
// }
// // 第三种：类模板化
// template<class t>
// void test3(t &a){
//     cout << typeid(t).name() << endl;
//     a.show();
// }
// void test(){
//     per<int> a1(10);

//     // test1(a1);

//     test2(a1);

//     // test3(a1);
// }

//类模板与继承
// template<class t>//父类的模板
// class base{
//     public:
//         t m;
// };
// template <class t1,class t2>
// class son1:public base<t2>//指定父类中的模板
// {

//     public:
//         son1(){
//             cout << typeid(t1).name() << endl;
//             cout << typeid(t2).name() << endl;
//         }
//         t1 m;
// };

// void test(){
//     son1<int,string> a1;
//     a1.base::m = "xm";
//     cout << a1.base::m << endl;
// }

// 模版函数的类外实现
// template<class t1,class t2>
// class per{
//     public:
//         per(t1 name,t2 age);//只是函数声明
//         void show();
//         t1 mname;
//         t2 mage;

// };
// template<class t1,class t2>
// per<t1,t2>::per(t1 name,t2 age)//函数的类外声明
// {
//     this->mname = name;
//     this->mage = age;
// }

// template<class t1,class t2>
// void per<t1,t2>::show(){
//     cout << "show the name :" << mname << endl;
// }

// void test(){
//     per<string,int> a1("xm",12);
//     a1.show();
// }

//类模板分开编写时：把类定义和类外实现写在一个文件中并且把文件后缀名改为.hpp（约定的类模板名称）

//友元的类外实现
// template<class t>//提前让编译器知道类的存在
// class per;

// template <class t>//运行上友元上方
// void getage(per<t> &a1){
//     a1.age = 20;
//     cout << a1.age << endl;
// }
// template<class t>
// class per{
//     // friend void getage(per<t> &a1)//友元函数全局的类内实现
//     // {
//     //     a1.age = 29;
//     //     cout << a1.age << endl;
//     // };
//     friend void getage<>(per<t> &a1);//类外实现的声明；需要添加<>来告诉函数这个是一个类模板实现而不是模板函数实现
//     public:
//         per(t age){
//             this->age = age;
//         }
//     private:
//         t age;
// };
// void test(){
//     per<int> a1(10);
//     getage<>(a1);

// }

//模板的深拷贝
// template <class t>
// class per {
// public:
//     per(int cap) {
//         // cout << "para construct called" << endl;
//         m_size = 0;
//         m_capacity = cap;
//         this->m_address = new t[this->m_capacity];
//     }
//     ~per() {
//         // cout << "del construct called" << endl;
//         if (m_address != NULL) {
//             delete[] m_address;
//             m_address = NULL;
//         }
//     }
//     per(const per& a) {
//         // cout << "copy construct called" << endl;
//         this->m_size = a.m_size;
//         this->m_capacity = a.m_capacity;
//         this->m_address = new t[a.m_capacity];

//         for (int i = 0; i < a.m_size; i++) {
//             this->m_address[i] = a.m_address[i];
//         }
//     }

//     per& operator=(const per& a) {
//         // cout << "operator construct called" << endl;
//         if (this->m_address != NULL) {
//             delete[] this->m_address;
//             m_address = NULL;
//             this->m_capacity = 0;
//             this->m_size = 0;
//         }

//         this->m_size = a.m_size;
//         this->m_capacity = a.m_capacity;
//         this->m_address = new t[a.m_capacity];
//         for (int i = 0; i < a.m_size; i++) {
//             this->m_address[i] = a.m_address[i];
//         }
//         return *this;
//     }

//     void pushback(const t& a) //尾插法
// {
//         if (this->m_size == this->m_capacity) {
//             return;
//         }
//         this->m_address[m_size] = a;
//         m_size++;
//     }

//     void pop() //尾删法
// {
//         m_size--;
//     }

//     t& operator[](int a) {
//         return this->m_address[a];
//     }

//     int getsize() {
//         return this->m_size;
//     }

//     int getcap() {
//         return this->m_capacity;
//     }
// private:
//     t* m_address;
//     int m_size;
//     int m_capacity;
// };

// void printarr(per<int>& a1) {
//     for (int i = 0; i < a1.getsize(); i++) {
//         cout << a1[i] << " ";
//     }
// }

// template<class t1, class t2>
// class care {
// public:
//     care() {};//还需要提供默认构造函数创建new空间
//     care(t1 name, t2 age) {
//         this->m_name = name;
//         this->m_age = age;
//     }

//     t1 m_name;
//     t2 m_age;
// };

// void printcls(per<care<string, int>>& a) {
//     for (int i = 0; i < a.getsize(); i++) {
//         cout << a[i].m_name << endl;
//     }
// }

// void test() {
//     // per<int> a1(5);
//     // for(int i = 0;i < 5;i++){
//     //     a1.pushback(i);
//     // }

//     // printarr(a1);
//     // a1.pop();
//     // cout << endl;
//     // printarr(a1);
//     // per<int> a2(a1);
//     // per<int> a3(1);
//     // a3 = a1;

//     //自定义数据测试
//     per<care<string, int>> a4(5);

//     care<string, int> p1("xm", 1);
//     care<string, int> p2("xl", 2);
//     care<string, int> p3("xk", 3);
//     care<string, int> p4("xj", 4);
//     care<string, int> p5("xh", 6);
//     //插入
//     a4.pushback(p1);
//     a4.pushback(p2);
//     a4.pushback(p3);
//     a4.pushback(p4);
//     a4.pushback(p5);
//     //打印
//     printcls(a4);

// }

//函数和指针的关系
// void test(){
//     int an[] = {1,2,3,4,5};
//     int *p = an;
//     for (int i = 0;i < (sizeof(an) / sizeof(an[0]));i++){
//         cout << p[i] << endl;
//     }
// }


//第六天
//结构体，通讯录管理系统

//第七天 STL
//vector for_each inerator

// void myprint(int val){
//         cout << val << endl;
//     }

// void test(){
//     vector<int> vi;
//     vi.push_back(10);
//     vi.push_back(20);
//     vi.push_back(30);

    // vector<int>::iterator vibegin = vi.begin();
    // vector<int>::iterator viend = vi.end();//容器中元素最后一个元素的下一个位置
    //第一种遍历方法
    // while (vibegin != viend)
    // {
    //     /* code */
    //     cout << *vibegin << endl;
    //     vibegin++;
    // }
    //第二种遍历算法
//     for(vector<int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << endl;
//     }
// }
    //第三种算法
//     for_each(vi.begin(),vi.end(),myprint);//调用myprint的回调函数
// }

//自定义数据存放
// class person{
//     public:
//         person(int age,string name){
//             this->age = age;
//             this->name = name;
//         }
        
//         string name;
//         int age;
// };
// //输出运算符重载
// ostream & operator<<(ostream &cout,const person a){
//     cout << a.age << endl;
//     return cout;
// }
//存放数据
// void test(){
//     vector<person> vi;
//     person a1(10,"xn");
//     person a2(30,"xm");
//     vi.push_back(a1);
//     vi.push_back(a2);
//     for(vector<person>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << endl;
//     }
// }

//存放地址
// void test(){
//     vector<person *> vi;
//     person a1(10,"xn");
//     person a2(30,"xm");
//     vi.push_back(&a1);
//     vi.push_back(&a2);
//     for(vector<person *>::iterator i = vi.begin();i != vi.end();i++){
//         cout << **i << endl;
//     }
// }

//容器嵌套
// void test(){
//     vector<int> vi;
//     vector<vector<int>> ci;
//     for(int i = 0;i < 5;i++){
//         vi.push_back(i);
//     }
//     ci.push_back(vi);
//     for(vector<vector<int>>::iterator i = ci.begin();i != ci.end();i++){
//         for(vector<int>::iterator j = (*i).begin();j != (*i).end();j++){
//             cout << *j << endl;
//         }
//     }
// }

//string C++风格类
//string构造函数
// void test(){
//     //默认构造
//     string a1;
//     //有参构造
//     const char *an = "hello world!";
//     string a2(an);
//     //拷贝构造
//     string a3(a2);
//     //多字符
//     string a4(10,'a');
// }

//string 和char *an（char an[]的区别
// void test(){
//     string a1 = "hello world!";
//     const char * an = "hello world!";
//     const char a2[20] = "hello world!";
//     cout << a1.size() << endl;
//     cout << sizeof(an)/sizeof(an[0]) << endl;//指针的大小
//     cout << sizeof(a2)/sizeof(a2[0]) << endl;//数组的大小

//     cout << a1.length() << endl;//字符串长度
//     cout << strlen(an) << endl;//字符串长度
//     cout << strlen(a2) << endl;//字符串长度

// }

//string赋值

// void test(){
//     //string & operator=(const char *s);
//     string a1;
//     a1 = "hello world!";
//     //string & operator=(const string &s);
//     string a2;
//     a2 = a1;
//     //string & operator=(char c);
//     string a3;
//     a3 = 'a';
//     //string & assign(const char *s);
//     string a4;
//     a4.assign("hello c++");
//     //string & assing(const char *s,n);n是赋前n个字符
//     string a5;
//     a5.assign("hello",2);
//     //string & assing(const string &s);
//     string a6;
//     a6.assign(a5);
//     //string & assign(int n,char c)；赋n个c
//     string a7;
//     a7.assign(5,'c');
// }
//string拼接
// void test(){
//     //string & operator+=(const char *str);
//     string a1 = "hello";
//     a1 += "world";
    
//     //string &operator+=(const char c);
//     string a2 = "hello";
//     char c = 'h';
//     a2 += c;

//     //string & operator+=(const string &str)
//     string a3 = "hello";
//     a3 += a2;

//     //stirng & append(const char *s)
//     string a4 = "hello";
//     a4.append("world");

//     //string &append(const char *s,int n)
//     string a5 = "hello";
//     a5.append("hellow",5);

//     //string &append(const string &s)
//     string a6 = "hello";
//     a6.append(a2);

//     //string &append(const string &s,int pos,int n)从s中第pos开始的n个字符添加到末尾
//     string a7 = "hello";
//     a7.append("hellow",1,3);
    
// }

//string 字符查找和替换
// void test(){
//     string a1 = "hello world!lo";
    //从左往右查找
    // int i = a1.find("lo");
    // if(i == -1){
    //     cout << "we cant find" << endl;
    // }
    // else{
    //     cout << "we found" << endl;
    //     cout << "pos is " << i << endl;
    // }
    // //从右往左查，但输出的位置还是从中往右
    // int j = a1.rfind("lo");
    // cout << j << endl;

    //替换
//     a1.replace(1,3,"1111");//从第1个到第3个字符替换为“1111”
//     cout << a1 << endl;
// }

//string 字符串比较 ASCII逐个比较，主要用于判断相等
// void test(){
//     string a1 = "hello world!";
//     string a2 = "hello world!";
//     if(a1.compare(a2) == 0){
//         cout << "=" << endl;
//     }
//     else if(a1.compare(a2) > 0){
//         cout << ">" << endl;
//     }
//     else
//     {
//         cout << " <" << endl;
//     }
// }

//string字符存取
// void test(){
//     string a1 = "hello world!";
//     for(int i = 0;i < a1.size();i++){
//         cout << a1[i] << " ";
//     }
//     cout << endl;
//     for(int i = 0;i < a1.size();i++){
//         cout << a1.at(i) << " ";
//     }

//     //修改单个字符
//     a1[0] = 'c';
//     a1.at(1) = 'b';
//     cout << a1 << endl;
// }

//string插入和删除
// void test(){
//     string a1 = "hello";
//     a1.insert(1,"111");
//     cout << a1 << endl;
//     a1.erase(1,3);擦除3个
//     cout << a1 << endl;
// }

//字符子串
//和python中的split很相似
// void test(){
//     string email = "1150@163.com";
//     int i = email.find("@");
//     string name = email.substr(0,i);//获取区间内的字符串
//     cout << name << endl;
// }

//vector容器
//模板
// class person{
//     public:
//         person(int age,string name){
//             this->age = age;
//             this->name = name;
//         }
//         int age;
//         string name;
// };

// ostream & operator<<(ostream &cout ,const person a){
//     cout << a.age << endl;
//     return cout;
// }

// template<class t>
// void printa(t vi){
//     for(class t::iterator i = vi.begin();i != vi.end();i++)//必须写成class t::iterator的形式
//     {
//         cout << *i << endl;
//     }
// }

// void test(){
//     person a1(10,"xm");
//     person a2(12,"xk");
//     vector<person> vi;
//     vi.push_back(a1);
//     vi.push_back(a2);
//     printa<vector<person>>(vi);
    
// }

//vector的构造方式
// void test(){
//     //第一种赋值方式
//     vector<int> vi;
//     for(int i = 0;i < 10;i++){
//         vi.push_back(i);
//     }
//     printa(vi);
//     //第二种，区间构造
//     vector<int> ci(vi.begin(),vi.end());
//     printa(ci);
//     //第三种，n个m构造
//     vector<int> ti(10,100);
//     printa(ti);
//     //第四种，拷贝构造
//     vector<int>a1(vi);
//     printa(a1);
// }

//vector赋值
//vector & operator=(const vector &vec)
//assign(begin,end)
//assign(n,m)
// template <class t>
// void showvi(t &vi){
//     for(class t::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
// }
// void test(){
//     vector<int> a1;
//     for(int i = 0;i < 4;i++){
//         a1.push_back(i);
//     }
//     printvi<vector<int>>(a1);

//     //assign
//     vector<int> a2;
//     a2.assign(a1.begin(),a1.end());

//     vector<int> a3;
//     a3.assign(10,100);
//     printvi<vector<int>>(a3);
    
// }

//容量和大小
//empty(),capacity(),size(),resize(),

// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 5;i++){
//         vi.push_back(i);
//     }
//     cout << vi.empty() << endl;
//     cout << vi.capacity() << " " << vi.size() << endl;
//     vi.resize(15);//如果重新指定超过原来的长度，会用0来填充
//     cout << vi.capacity() << " " << vi.size() << endl;
//     vi.resize(3);//比原来短超出的部分会删掉,容量不变
//     cout << vi.capacity() << " " << vi.size() << endl;

// }

//vector 删除和插入
// void test(){
//     vector<int> vi;

//     vi.push_back(1);
//     vi.push_back(2);
//     vi.push_back(3);
//     vi.push_back(4);

//     //插入
//     vi.insert(vi.begin(),100);//第一参数是迭代器
//     vi.insert(vi.begin(),2,3);//两个3

//     //删除
//     vi.erase(vi.begin());
//     vi.erase(vi.begin(),vi.end());//清空
// }

//vector数据存取
// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 4;i++){
//         vi.push_back(i);
//     }
//     //两种访问方式
//     cout << vi[2] << endl;
//     cout << vi.at(3) << endl;
// }

//vector互换
// void test(){
//     // vector<int> vi;
//     // for(int i = 0;i < 4;i++){
//     //     vi.push_back(i);
//     // }

//     // vector<int> v2;
//     // for(int i = 4;i > 0;i--){
//     //     v2.push_back(i);
//     // }
//     // vi.swap(v2);
//     // showvi(vi);

//     //实际用途，收缩内存空间
//     vector<int> v;
//     for(int i = 0;i < 1000;i++){
//         v.push_back(i);
//     }
//     cout << v.capacity() << " " << v.size() << endl;
//     v.resize(3);
//     cout << v.capacity() << " " << v.size() << endl;
    
//     //利用匿名对象交换空间
//     //vector<int>(v)是匿名对象，系统会自动回收空间
//     vector<int>(v).swap(v);
//     cout << v.capacity() << " " << v.size() << endl;
// }

//预留空间reserve
// void test(){
//     vector<int> vi;
//     vi.reserve(100);//预留100大小空间，减少开辟空间的次数

// }


//deque容器：双端数组，vector是单端数组
// void showdeque(const deque<int> & vi)//只读状态的迭代器
// {
//     for(deque<int>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " " ;
//     }
//     cout << endl;
// }

//构造函数
// void test(){
//     deque<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     //构造方法和vector相似
//     deque<int> v1(vi);
//     showdeque(v1);

//     deque<int> v2;
//     v2.assign(v1.begin(),v1.end());

//     deque<int> v3;
//     v3.assign(2,3);

// }

//deque大小操作
//deque没有容量这个说法
// void test(){
//     deque<int> vi;
//     for(int i = 0;i < 10;i++){
//         vi.push_back(i);
//     }
//     cout << vi.empty() << endl;
//     cout << vi.size() << endl;
//     vi.resize(15,1);//利用1来填充多余的空间
//     cout << vi.size() << endl;
// }

//deque的插入和删除
// void test(){
//     deque<int> vi;
//     for(int i = 0;i < 4;i++){
//         vi.push_back(i);
//     }
//     //两端操作
//     vi.push_front(10);
//     showdeque(vi);
//     //头删
//     vi.pop_front();
//     showdeque(vi);

//     //插入
//     vi.insert(vi.begin() + 1,100);
//     showdeque(vi);
//     //区间插入
//     deque<int> v1;
//     v1.push_back(1);
//     //在v1的头部插入vi的数据
//     v1.insert(v1.begin(),vi.begin(),vi.end());
//     showdeque(v1);

//     //删除
//     deque<int>::iterator i = v1.begin();
//     i++;
//     v1.erase(i);
//     showdeque(v1);
// }

//数据存取
// void test(){
//     deque<int> vi;
//     vi.push_back(1);
//     vi.push_back(2);

//     cout << vi.at(0) << endl;
//     cout << vi[0] << endl;
// }

//vector排序
// void showvector(const vector<int> &a){
//     for(vector<int>::const_iterator i = a.begin();i != a.end();i++){
//         cout << *i << endl;
//     }
// }

// void intswap(int &a,int &b){
//     int temp;
//     temp = a;
//     a = b;
//     b = temp;
// }

// void sortve(vector<int> &vi){
//     for(int i = 0;i < vi.size();i++){
//         int max = i;
//         for(int j = i + 1;j <vi.size();j++){
//             if(vi[j] < vi[max]){
//                 max = j;
//             }
//         }
//         if(i != max){
//             intswap(vi[max],vi[i]);
//         }
//     }
// }

// void test(){
//     vector<int> vi;
//     vi.push_back(3);
//     vi.push_back(3);
//     vi.push_back(1);
//     vi.push_back(2);
//     sortve(vi);
//     showvector(vi);
// }

//deque排序
// void test(){
//     deque<int> vi;
//     vi.push_back(2);
//     vi.push_back(3);
//     vi.push_back(1);
//     //从小到大,vector 也支持排序
//     sort(vi.begin(),vi.end());
//     showdeque(vi);
// }

// 案例
// class person{
//     public:
//         person(int score,string name){
//             this->score = score;
//             this->name = name;
//         }
//         int score;
//         string name;
// };

// void showvec(const vector<person> &vi){
//     for(vector<person>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).name << "'s score is " << (*i).score <<  endl;
//     }
// }

// void creatve(vector<person> & vi){
//     string name = "ABCDE";
//     for(int i = 0;i < 5;i++){
//         string t = "player_";
//         t += name[i];
//         person p(0,t);
//         vi.push_back(p);
//     }
// }

// void dafen(vector<person> &vi){
//     for(vector<person>::iterator i = vi.begin();i != vi.end();i++){
//         //假设10个评委
//         deque<int> ti;
//         for(int i = 0;i < 10;i++){
//             int score = rand() % 41 + 60;
//             ti.push_back(score);
//         }
//         sort(ti.begin(),ti.end());
//         ti.pop_back();
//         ti.pop_front();
//         int sum = 0;
//         for(int i = 0;i < ti.size();i++){
//             sum += ti[i];
//         }
//         int average = sum / ti.size();
//         i->score = average;
//     }
// }
// void test(){
//     srand((unsigned int) time(NULL));
//     vector<person> vi;
//     creatve(vi);
//     dafen(vi);
//     showvec(vi);
// }

//stack栈容器，先进后出，栈不允许遍历
// void test(){
//     //构造
//     stack<int> vi;
//     for(int i = 0;i < 4;i++){
//         vi.push(i);
//     }
//     while (!vi.empty())
//     {
//         cout << vi.top() << endl;//返回栈顶元素
//         /* code */
//         vi.pop();
//     }
//     cout << vi.size() << endl;    
// }

//queue 先进先出FIFO
//不允许遍历
// void test(){
//     queue<int> vi;
//     for(int i = 0;i < 4;i++){
//         vi.push(i);
//     }
//     while (!vi.empty())
//     {
//         /* code */
//         cout << vi.front() << " ";
//         cout << vi.size() << " ";
//         vi.pop();
//     }
// }

//list链表
// void showlist(const list<int> vi){
//     for(list<int>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
// }
// 赋值方法
// void test(){
//     //第一种构造方法
//     list<int> vi;
//     vi.push_back(10);
//     vi.push_back(20);
//     vi.push_back(30);
//     shwolist(vi);

//     //区间构造
//     list<int> v1(vi.begin(),vi.end());
//     shwolist(vi);

//     //拷贝构造
//     list<int> v2(v1);
//     shwolist(vi);
// }

//赋值与交换
// void test(){
//     list<int> vi;
//     vi.push_back(10);
//     vi.push_back(20);
//     vi.push_back(30);

//     list<int> v1;
//     v1.assign(10,100);
//     vi.swap(v1);
//     showlist(vi);
// }

//大小操作
// void test(){
//     list<int> vi;
//     vi.push_back(10);
//     vi.push_back(20);
//     vi.push_back(30);

//     cout << vi.empty() << endl;
//     cout << vi.size() << endl;
//     vi.resize(10);
//     showlist(vi);
// }

//插入和删除
//除了remove其他和vector相似
// * push_back(elem);//在容器尾部加入一个元素
// * pop_back();//删除容器中最后一个元素
// * push_front(elem);//在容器开头插入一个元素
// * pop_front();//从容器开头移除第一个元素
// * insert(pos,elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
// * insert(pos,n,elem);//在pos位置插入n个elem数据，无返回值。
// * insert(pos,beg,end);//在pos位置插入[beg,end)区间的数据，无返回值。
// * clear();//移除容器的所有数据
// * erase(beg,end);//删除[beg,end)区间的数据，返回下一个数据的位置。
// * erase(pos);//删除pos位置的数据，返回下一个数据的位置。
// * remove(elem);//删除容器中所有与elem值匹配的元素。
// void test(){
//     list<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }

//     //头删
//     vi.pop_front();
//     //尾删
//     vi.pop_back();
//     // insert
//     list<int>::iterator i = vi.begin();
//     i++;//不能用i += 1
//     vi.insert(i,10);
//     showlist(vi);
//     //erase
//     vi.erase(--i);
//     showlist(vi);

//     //remove删掉所有与值匹配的函数
//     vi.remove(1);
//     showlist(vi);
// }

//数据存储
//list不支持用at和中括号访问
// void test(){
//     list<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }

//     //验证迭代器是不支持随机访问的

// }

//翻转
// void test(){
//     list<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     showlist(vi);
//     //翻转链表
//     vi.reverse();
//     showlist(vi);
//     //排序列表
//     vi.sort();
//     showlist(vi);

// }

//排序案例
// class person{
//     public:
//         person(int age,int height){
//             this->age = age;
//             this->height = height;
//         }
//         int age;
//         int height;
// };

// bool callback(person &a1,person &a2){
//     if(a1.age == a2.age){
//         return a1.height < a2.height;
//     }
//     // 大于是升序，小于是降序
//     return a1.age < a2.age;
// }

// void test(){
//     person a1(35,175);
//     person a2(45,180);
//     person a3(40,170);
//     person a4(25,190);
//     person a5(35,160);
//     person a6(35,200);

//     list<person> vi;
//     vi.push_back(a1);
//     vi.push_back(a2);
//     vi.push_back(a3);
//     vi.push_back(a4);
//     vi.push_back(a5);
//     vi.push_back(a6);

//     // for(list<person>::iterator i = vi.begin();i != vi.end();i++){
        
//     // }
//     //需要使用回调函数
//     vi.sort(callback);
//     for(list<person>::iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).age << " " << (*i).height << endl;    
//     }
// }

// 第八天
//set容器、二叉树
// void showset(const set<int> & vi){
//     for(set<int>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
// }
//不允许插入重复的数据，插入的数据可以自动排序
// void test(){
//     set<int> vi;
//     vi.insert(10);
//     vi.insert(9);
//     vi.insert(11);
//     showset(vi);
//     //拷贝构造
//     set<int> v1(vi);
//     showset(v1);
// }
//大小和交换
// void test(){
//     set<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.insert(i);
//     }
//     showset(vi);
//     cout << vi.empty() << endl;
//     cout << vi.size() << endl;
//     set<int> ti;
//     ti.insert(110);
//     vi.swap(ti);
//     showset(vi);
// }
//插入和删除
// void test(){
//     set<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.insert(i);
//     }
//     //删除
//     vi.erase(vi.begin());
//     //删除指定数据
//     vi.erase(2);
//     showset(vi);
// }

//查找函数
// void test(){
//     set<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.insert(i);
//     }
//     //查找,没找到会返回最后一个位置
//     set<int>::iterator i = vi.find(2);
//     cout << *i << endl;
//     //统计
//     int num = vi.count(2);
//     cout << num << endl;
// }

//set和mulset:mulset可以插入重复的值
// void test(){
//     set<int> vi;
//     pair<set<int>::iterator,bool>ret = vi.insert(10);
//     cout << ret.second << endl;

//     multiset<int> ti;
//     ti.insert(10);
//     ti.insert(10);
//     for(multiset<int>::iterator i = ti.begin();i != ti.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
// }

//pair对组
// void test(){
//     pair<string,int> vi("xm",10);
//     cout << vi.first << endl;
//     cout << vi.second << endl;
// }
//set排序
//案例一
// class ci{
//     public:
//         bool operator()(int v1,int v2){
//             return v1 > v2;
//         }
// };
// void test(){
//     set<int> vi;
//     vi.insert(19);
//     vi.insert(24);
//     showset(vi);
//     //指定排序规则在插入之前,利用仿函数实现
//     set<int,ci> ti;
//     ti.insert(19);
//     ti.insert(24);
//     for(set<int,ci>::iterator i = ti.begin();i != ti.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
// }
//set存放自定义数据类型
// class person{
//     public:
//         person(int age,string name){
//             this->age = age;
//             this->name = name;
//         }
//         int age;
//         string name;
// };
// class acamp{
//     public:
//         bool operator()(const person a1,const person a2){
//             return a1.age < a2.age;
//         }
// };
// void test(){
//     //自定义数据类型需要指定规则
//     set<person,acamp> vi;
//     person a1(10,"xm");
//     person a2(20,"xs");
//     vi.insert(a1);
//     vi.insert(a2);
//     for(set<person,acamp>::iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).age << " " ;
//     }
//     cout << endl;

// }

//map容器，和字典相似
// void showmap(const map<string,int> vi){
//     for(map<string,int>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).first << " ";
//     }
//     cout << endl;
// }
//构造和赋值
// void test(){
//     map<string,int> vi;
//     vi.insert(pair<string,int>("xm",12));
//     vi.insert(pair<string,int>("xl",10));
//     vi.insert(pair<string,int>("xg",22));
//     //会按照key值自动排序
//     for(map<string,int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).first << " ";
//     }
//     cout << endl;
//     //拷贝构造
//     map<string,int> ti(vi);
// }

//大小和交换
// void test(){
//     map<string,int> vi;
//     vi.insert(pair<string,int>("xn",10));
//     vi.insert(pair<string,int>("xl",15));
//     cout << vi.empty() << endl;
//     cout << vi.size() << endl;
//     //交换
//     map<string,int> ci;
//     ci.swap(vi);
//     cout << vi.empty() << endl;
//     for(map<string,int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << (*i).first << endl;
//     }

// }
//插入和删除
// void test(){
//     map<string,int> vi;
//     //第一种插入方式
//     vi.insert(pair<string,int>("xm",10));
//     //第二种插入方式
//     vi.insert(make_pair("xg",23));
//     //第三种插入方式
//     vi.insert(map<string,int>::value_type("sk",20));
//     //第四种,不建议插入，但是可以用于访问
//     vi["xl"] = 13;
//     showmap(vi);

//     //删除
//     vi.erase("xm");
//     showmap(vi);
//     //
//     vi.erase(vi.begin(),vi.end());
    
// }

//map文件的统计和查找
// void test(){
//     map<string,int> vi;
//     vi.insert(make_pair("xm",10));
//     vi.insert(make_pair("xj",11));
//     vi.insert(make_pair("xl",10));
//     map<string,int>::iterator pos = vi.find("xm");
//     cout << (*pos).first << endl;
//     //统计
//     int i = vi.count("xm");
//     cout << i << endl;
// }
//map排序
// class student{
//     public:
//         student(int age,string name){
//             this->age = age;
//             this->name = name;
//         }
//         int age;
//         string name;
// };
// class acamp{
//     public:
//         bool operator()(const student a1,const student a2){
//             return a1.age < a2.age;
//         }
// };
// void test(){
//     //student类属性需要放在第一位
//     map<student,int,acamp> vi;
//     student a1(15,"xm");
//     student a2(12,"sd");
//     student a3(20,"xj");
//     vi.insert(make_pair(a1,1));
//     vi.insert(make_pair(a2,2));
//     vi.insert(make_pair(a3,3));
//     for(map<student,int,acamp>::iterator i = vi.begin();i != vi.end();i++){
//         cout << i->first.name << " ";
//     }
//     cout << endl;

// }

//案例
// class worker{
//     public:
//         worker(int salary,string name){
//             this->name = name;
//             this->salary = salary;
//         }
//         string name;
//         int salary;
// };

// void creatworker(vector<worker> &vi){
//     string id = "ABCDEFGHIJ";
//     string name;
//     int salary;
//     for(int i = 0;i < 10;i++){
//         name = "worker_";
//         name += id[i];
//         salary = rand() % 10001 + 10000;
//         worker wi(salary,name);
//         vi.push_back(wi);
//     }
// }

// void divideworker(const vector<worker> &vi,multimap<int,worker> &ti){
//     for(vector<worker>::const_iterator i = vi.begin();i != vi.end();i++){
//         int group = rand() % 3;
//         ti.insert(make_pair(group,*i));
//     }
// }

// void mapshow(const multimap<int,worker> vi){
//     for(multimap<int,worker>::const_iterator i = vi.begin();i != vi.end();i++){
//         cout <<"department's id :" << (*i).first <<  ", name : "<< 
//         (*i).second.name << " 's salary is : " << (*i).second.salary << endl;
//     }
// }
// #define CEHUA 0
// #define JISHU 1
// #define YUNYING 2
// void showcehua(multimap<int,worker> vi){
//     cout << "----------cehua---------" << endl;
//     multimap<int,worker>::iterator i = vi.find(CEHUA);
//     int num = vi.count(CEHUA);
//     int j = 0;
//     while (j < num && i != vi.end())
//     {
//         /* code */
//         cout << (*i).second.name << endl;
//         j++;
//         i++;
//     }
// }

// void showjishu(multimap<int,worker> vi){
//     cout << "----------JISHU---------" << endl;
//     multimap<int,worker>::iterator i = vi.find(JISHU);
//     int num = vi.count(JISHU);
//     int j = 0;
//     while (j < num && i != vi.end())
//     {
//         /* code */
//         cout << (*i).second.name << endl;
//         j++;
//         i++;
//     }
// }
// void showyunying(multimap<int,worker> vi){
//     cout << "----------YUNYING---------" << endl;
//     multimap<int,worker>::iterator i = vi.find(YUNYING);
//     int num = vi.count(YUNYING);
//     int j = 0;
//     while (j < num && i != vi.end())
//     {
//         /* code */
//         cout << (*i).second.name << endl;
//         j++;
//         i++;
//     }
// }

// void test(){
//     srand((unsigned int)time(NULL));
//     vector<worker> vi;
//     creatworker(vi);
//     // for(vector<worker>::iterator i = vi.begin();i != vi.end();i++){
//     //     cout << (*i).name << " ";
//     // }
//     // cout << endl;

//     multimap<int,worker> ti;
//     divideworker(vi,ti);
//     mapshow(ti);
//     showcehua(ti);
//     showjishu(ti);
//     showyunying(ti);
// }

//函数对象，仿函数
//加法仿函数
// class addme{
//     public:
//         int operator()(int a,int b){
//             return a + b;
//         }
//         void operator()(string name){
//             cout << name << endl;
//         }
// };
// //函数对象可以作为参数传递
// void test1(addme &vi,string name){
//     vi(name);
// }
// void test(){
//     addme a1;
     
//     test1(a1,"hello");
// }

//谓词，返回类型为bool的仿函数
//一元谓词
// class showi{
//     public:
//         bool operator()(int a){
//             return a > 5;
//         }
// };
// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     showi ti;
//     vector<int>::iterator pos = find_if(vi.begin(),vi.end(),ti);
//     while(pos != vi.end()){
//         cout << *pos << endl;
//         pos++;
//     }
// }

//二元谓词
// class mycamp{
//     public:
//         bool operator()(int a,int b){
//             return a > b;
//         }
// };
// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     mycamp a;
//     //二元谓词的仿函数
//     sort(vi.begin(),vi.end(),a);
//     for(vector<int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << endl;
//     }
// }

//内建函数
//算术仿函数
// void test(){
//     //取反
//     negate<int> n;
//     cout << n(50) << endl;
//     plus<int>p;
//     cout << p(1,2) << endl;
// }

//关系仿函数
// class mycamp{
//     public:
//         bool operator()(int a,int b){
//             return a > b;
//         }
// };

// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 5;i++){
//         vi.push_back(rand() %5 + 5);
//     }
//     for(vector<int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
//     mycamp a1;
//     sort(vi.begin(),vi.end(),a1);
//     for(vector<int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
//     cout << endl;
//     //系统提供的内建仿函数
//     sort(vi.begin(),vi.end(),less<int>());//greater《int》
//     for(vector<int>::iterator i = vi.begin();i != vi.end();i++){
//         cout << *i << " ";
//     }
// }

//STL算法
//for_each()
// void printa(int a){
//     cout << a << endl;
// }
// class showi{
//     public:
//         void operator()(int a){
//             cout << a << endl;
//         }
// };
// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 10;i++){
//         vi.push_back(i);
//     }
//     // 第一种
//     for_each(vi.begin(),vi.end(),printa);
//     //第二种
//     for_each(vi.begin(),vi.end(),showi());

// }

//搬运函数
// class transformer{
//     public:
//         int operator()(int a){
//             return a;
//         }
        
// };
// void print1(int a){
//     cout << a << endl;
// }
// void test(){
//     vector<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     vector<int> ti;
//     需要提前开辟空间不然会崩溃
//     ti.resize(vi.size());
//     transform(vi.begin(),vi.end(),ti.begin(),transformer());
//     for_each(ti.begin(),ti.end(),print1);

// }

//查找算法
//find
// class person{
//     public:
//         person(int age,string name){
//             this->age = age;
//             this->name = name;
//         }        
//         bool operator==(const person a){
//             if(this->age == a.age && this->name == a.name){
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }
//         int age;
//         string name;
// };
// void test()
// {
//     vector<int> vi;
//     for(int i = 0;i < 9;i++){
//         vi.push_back(i);
//     }
//     //返回值是迭代器
//     vector<int>::iterator i = find(vi.begin(),vi.end(),50);
//     cout << *i << endl;
//     //自定义数据的查找
//     person a1(10,"xm");
//     person a2(10,"xm");
//     vector<person> ti;
//     ti.push_back(a1);
//     ti.push_back(a2);
//     查找一下有没有和a2一样的人
//     vector<person>::iterator j = find(ti.begin(),ti.end(),a2);
//     cout << (*j).name << endl;
// }

//find_if()
class fina{
    public:
        fina(int age,string name){
            this->age = age;
            this->name = name;
        }
        bool operator()(const fina a){
            return a.age == 5;
        }
        int age;
        string name;
};
void test(){
    // vector<int> vi;
    // for(int i = 0;i < 9;i++){
    //     vi.push_back(i);
    // }
    vector<fina> ti;
    fina a1(10,"x");
    fina a2(9,"xs");
    fina a3(5,"sd");
    ti.push_back(a1);
    ti.push_back(a2);
    ti.push_back(a3);
    fina an(5,"xm");
    vector<fina>::iterator a = find_if(ti.begin(),ti.end(),an);
    cout << (*a).age << endl;
}

int main()
{
    test();

    return 0;
} // namespace name


