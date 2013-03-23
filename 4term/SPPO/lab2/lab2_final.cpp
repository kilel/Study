#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <time.h>

// Global variables
bool cap = false;
LPPOINT po;
int shift;
short l,r,u,d;
int time_flag = 0;
bool sw_b = false;
bool show_c = true;
bool clip_c = false;
bool lock_m = false;
// The main window class name.
static TCHAR szWindowClass[] = _T("win32app");

// The string that appears in the application's title bar.
static TCHAR szTitle[] = _T("lab2");

HINSTANCE hInst;

// Forward declarations of functions included in this code module:
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void print_message(HDC hdc);

int WINAPI WinMain(HINSTANCE hInstance,
                   HINSTANCE hPrevInstance,
                   LPSTR lpCmdLine,
                   int nCmdShow)
{
    WNDCLASSEX wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

    if (!RegisterClassEx(&wcex))
    {
        MessageBox(NULL,
            _T("Call to RegisterClassEx failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    hInst = hInstance; // Store instance handle in our global variable

    HWND hWnd = CreateWindow(
        szWindowClass,
        szTitle,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT,
        500, 400,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (!hWnd)
    {
        MessageBox(NULL,
            _T("Call to CreateWindow failed!"),
            _T("Win32 Guided Tour"),
            NULL);

        return 1;
    }

    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int) msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	RECT rc; 
    POINT aptStar[6] = {50,2, 2,98, 98,33, 2,33, 98,98, 50,2};
    PAINTSTRUCT ps;
    HDC hdc;
	
    switch (message)
    {
	case WM_KEYDOWN:
		
		l = GetAsyncKeyState(VK_LEFT), r = GetAsyncKeyState(VK_RIGHT), u = GetAsyncKeyState(VK_UP), d = GetAsyncKeyState(VK_DOWN);
		po = new POINT;
		shift = 10;
		if(GetAsyncKeyState(VK_CONTROL))
			shift = 100;
		GetCursorPos(po);
		SetCursorPos(po->x - shift*r/32768 + shift*l/32768, po->y  - shift*d/32768 + shift*u/32768);
		InvalidateRect(hWnd, 0, TRUE);
		break;
	case WM_MOUSEMOVE:
		InvalidateRect(hWnd, 0, TRUE);
		break;
	case  WM_CREATE:
		cap = GetKeyState(VK_CAPITAL);
			CreateWindow(_T("button"),_T("Refresh"),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,5,80,20,hWnd,(HMENU)1,NULL,NULL);
			CreateWindow(_T("button"),_T("Swap b."),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,30,80,20,hWnd,(HMENU)2,NULL,NULL);
			CreateWindow(_T("button"),_T("Show curs."),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,55,80,20,hWnd,(HMENU)3,NULL,NULL);
			CreateWindow(_T("button"),_T("Clip curs."),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,80,80,20,hWnd,(HMENU)4,NULL,NULL);
			CreateWindow(_T("button"),_T("lock mouse"),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,105,80,20,hWnd,(HMENU)5,NULL,NULL);
			CreateWindow(_T("button"),_T("delete"),WS_CHILD|BS_PUSHBUTTON|WS_VISIBLE,
		410,130,80,20,hWnd,(HMENU)6,NULL,NULL);
	case WM_COMMAND:
		switch( LOWORD(wParam))
		{
		case 1:
			InvalidateRect(hWnd, 0, TRUE);
			break;
		case 2:
			sw_b = !sw_b;
			SwapMouseButton(sw_b);
			break;
		case 3:
			show_c  = !show_c;
			ShowCursor(show_c);
			break;
		case 4:
			//GetUpdateRect(hWnd, &rc, true);
			GetClientRect(hWnd, &rc);
			clip_c = !clip_c;
			if(clip_c)
				ClipCursor(&rc);
			else
				ClipCursor(NULL);
			break;
		case 5:
			lock_m = !lock_m;
			if(lock_m)
				SystemParametersInfo(SPI_SETMOUSECLICKLOCK,0, &lock_m, 0);
			else
				SystemParametersInfo(SPI_SETMOUSECLICKLOCK,0, NULL, 0);
			break;
		case 6:
			static PBYTE key_state = new BYTE[256];
			GetKeyboardState(key_state);
			key_state[VK_DELETE] = 129;
			SetKeyboardState(key_state);

			break;
		}
		DefWindowProc(hWnd, WM_ERASEBKGND,NULL, NULL);
		break;
    case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);        
		print_message(hdc);
		
        EndPaint(hWnd, &ps);
		
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        break;
    }
    return 0;
}

TCHAR* itos(int a);
void kb_type(HDC hdc);
void cursor(HDC hdc);
void print_message(HDC hdc)
{
	itos(990990);
	kb_type(hdc);
	cursor(hdc);
}
TCHAR* itos(int a)
{
	TCHAR *b = new TCHAR[9];
	int ten[10] = {1,10,100,1000,10000,100000,1000000, 10000000,100000000, 1000000000};
	int i = 10, k = 0;
	while(a%ten[i] == a && i > 0)
	{
		i--;
		continue;
	}
	b[i+1] = 0;
	while (i > -1)
	{	
		b[i] = _T('0' + a%10);
			a = a/10;
			i--;
	}
	//b[k] = 0;
	return b;
}
int len(wchar_t *h)
{
	int i = 0;
	while(h[i] != 0) i++;
	return i;
}
TCHAR* concat(wchar_t *a, wchar_t *b)
{
	int n,m;
	n = len(a);
	m = len(b);
	TCHAR *c = new TCHAR[n+m];
	for(int i = 0; i <= n+m; i++)
	{
		if(i < n)
			c[i] = a[i];
		else 
			c[i] = b[i-n];
	}
	return c;
}
void kb_type(HDC hdc)
{
	TCHAR *kb[9] ;	
	kb[1] =	_T("IBM PC/XT or compatible (83-key) keyboard"); 
	kb[2] =	_T("Olivetti \"ICO\" (102-key) keyboard");
	kb[3] =	_T("IBM PC/AT (84-key) or similar keyboard");
	kb[4] =	_T("IBM enhanced (101- or 102-key) keyboard");
	kb[5] =	_T("Nokia 1050 and similar keyboards");
	kb[6] = _T("Nokia 9140 and similar keyboards"); 
	kb[7] =	_T("Japanese keyboard");
	kb[8] =	_T("Functional keys: ");
	int n = GetKeyboardType(0);
	int i = _tclen(kb[n]);
	TextOut(hdc, 5, 15, kb[n], len(kb[n]));
	TextOut(hdc, 5, 40, kb[8], len(kb[8]));
	TextOut(hdc, 120, 40, itos(GetKeyboardType(2)), len(itos(GetKeyboardType(2))));
}
void cursor(HDC hdc)
{
	TCHAR *pr[9] = {_T("Mouse installed"), _T("No mouse installed"), _T("Buttons swapped"), _T("Buttons not swapped"), _T("Caps Lock "), _T("on"), _T("off"), _T("Shift"), _T("Ctrl")};
	LPPOINT p = new POINT;
	GetCursorPos(p);
	//cout << p->x << " " << p->y << endl;
	TCHAR *k = concat(_T("Cursor position: x = "), concat(itos(p->x), concat(_T(", y = "),itos(p->y))));
	TextOut(hdc,5, 60, k, len(k));
	if(GetSystemMetrics(SM_MOUSEPRESENT))
		TextOut(hdc,5, 80, pr[0], len(pr[0]));
	else
		TextOut(hdc,5, 80, pr[1], len(pr[1]));
	if(GetSystemMetrics(SM_SWAPBUTTON))
		TextOut(hdc,5, 100, pr[2], len(pr[2]));
	else
		TextOut(hdc,5, 100, pr[3], len(pr[3]));
	bool a = GetKeyState(VK_CAPITAL);
	static PBYTE key_state = new BYTE[256];
	GetKeyboardState(key_state);
	//cap = a||cap;
	if(key_state[VK_CAPITAL] != 0)
	{
		TextOut(hdc, 50, 120, concat(pr[4], pr[5]), len(pr[4]) + len(pr[5]));
		return;
	}
	{
		TextOut(hdc, 5, 140, concat(pr[4], pr[6]), len(pr[4]) + len(pr[6]));
	}
	if(GetAsyncKeyState(VK_LSHIFT))
		TextOut(hdc, 5, 160, pr[7], len(pr[7]) );
	if(GetAsyncKeyState(VK_RSHIFT))
		TextOut(hdc, 100, 160, pr[7], len(pr[7]) );
	if(GetAsyncKeyState(VK_LCONTROL))
		TextOut(hdc, 5, 180, pr[8], len(pr[8]) );
	if(GetAsyncKeyState(VK_RCONTROL))
		TextOut(hdc, 100, 180, pr[8], len(pr[8]) );
}
