#include <iostream>
using namespace std;
int main(int argc, char* argv[], char* envp[])
{
	int i = 0;
	while (envp[i])
	{
		printf("%s\n", envp[i]);
		i++;
	}

	//for (int i = 0; i < argc; i++)
	//{
	//	cout << argv[i] << endl;
	//}

	//int i = 0;
	//while (argv[i])
	//{
	//	cout << argv[i] << endl;
	//	i++;
	//}
	return 0;
}