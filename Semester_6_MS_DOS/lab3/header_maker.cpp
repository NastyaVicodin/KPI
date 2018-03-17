#include "header_maker.h"

char	*prog_name;
char	*author;
char	*comment_type;
char	*header;

HWND	hProg_name;
HWND	hAuthor;
HWND	hComment_type;
HWND	hHeader;
HWND	hOpen;
HWND	hSave;
HWND	hFile_cont;

HMENU	hMenu;
HBITMAP	hSaveImg;
HBITMAP	hOpenImg;

int		WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow)
{
	WNDCLASSW wc = {0};
	
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW ;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hInstance = hInst;
	wc.lpszClassName = L"myWindowClass";
	wc.lpfnWndProc = WindowProcedure;
	
	if (!(RegisterClassW(&wc)))
		return -1;

	registerDialogClass(hInst);

	CreateWindowW(L"myWindowClass", L"Header Maker", WS_OVERLAPPEDWINDOW | WS_VISIBLE,
		120, 35, 1100, 680, NULL, NULL, NULL, NULL);
	MSG msg = {0};

	while(GetMessage(&msg, NULL, NULL, NULL))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}
