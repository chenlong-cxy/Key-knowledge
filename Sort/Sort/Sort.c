#include "Sort.h"

//—°‘Ò≈≈–Ú
void InsertSort(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n - 1; i++)
	{
		int end = n - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (a[i] < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}