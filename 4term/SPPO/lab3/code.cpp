#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void foo(LPCWSTR dir)
	{
		DWORD d, s,t, w;
		if(GetDiskFreeSpace(dir, &d, &s,&t,&w))
				cout << " \n\tsectors per cluster: " << d << " \n\tbytes per sector: " << s << " \n\tfree clusters: " << t << " \n\ttotal clusters: " << w << " \n\tfree space: " << (long long)(w-t)*2*d;
	}

int main()
{
	DWORD d, s,t, w;
	int two[30] = {0}, n, i, j;
	wchar_t dir[5] = L"A:\\";
	wchar_t a[MAX_PATH] = {0}, b[MAX_PATH] = {0};
	
	
	two[0] = 1;
	d = GetLogicalDrives();
	cout << "logical drives: \n";
	for(int i = 0; i < 27; i++)
	{
		two[i+1] = two[i]*2;
		if(d&two[i] )
		{
			cout << (char)(i+'A') << " ";
			dir[0] = i+ 'A';
			n = GetDriveType(dir);
			if(GetVolumeInformation(dir, a, sizeof(a), &d, &s,&t, b, MAX_PATH+1))
			{
				//printf("%ls",b);
				cout << "\tserial number: " << d; printf( "\n\tname: %ls \n\tfile system: %ls", a,b);
			}
			foo(dir);
				cout << " \n\ttype: ";
			switch(n)
			{
			case 0:
				cout << "unknown type";
				break;
			case 1:
				cout << "not a directory";
				break;
			case 2:
				cout << "removable drive";
				break;
			case 3:
				cout << "fixed drive";
				break;
			case 4:
				cout << "remote drive";
				break;
			case 5:
				cout << "CD-rom";
				break;
			case 6:
				cout << "ram disk";
				break;
			}
			cout << "\n\n";

		}
	}
	
	cout << "\npress any key to exit";
	getch();
	return 0;

}

