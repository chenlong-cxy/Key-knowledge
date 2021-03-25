#include <stdio.h>//“printf”未定义
extern int Add(int, int);//“Add”未定义，链接时每个源文件单独编译
int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	printf("%d\n", c);
	return 0;
}