#include "header_maker.h"

void	displayDialog(HWND hWnd)
{
	HWND hDlg = CreateWindowW(L"myDialogClass", L"Help", WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		300, 100, 300, 250, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"1. Open file", WS_VISIBLE | WS_CHILD,
		30, 10, 100, 20, hDlg, NULL, NULL, NULL);
	CreateWindowW(L"static", L"2. Enter header parameters", WS_VISIBLE | WS_CHILD,
		30, 40, 200, 20, hDlg, NULL, NULL, NULL);
	CreateWindowW(L"static", L"3. Make Header", WS_VISIBLE | WS_CHILD,
		30, 70, 200, 20, hDlg, NULL, NULL, NULL);
	CreateWindowW(L"static", L"4. Copy header to file", WS_VISIBLE | WS_CHILD,
		30, 100, 200, 20, hDlg, NULL, NULL, NULL);
	CreateWindowW(L"static", L"5. Save", WS_VISIBLE | WS_CHILD,
		30, 130, 100, 20, hDlg, NULL, NULL, NULL);

	CreateWindowW(L"button", L"Ok", WS_VISIBLE | WS_CHILD,
		110, 160, 80, 35, hDlg, (HMENU)1, NULL, NULL);
}

void	registerDialogClass(HINSTANCE hInst)
{
	WNDCLASSW dialog = {0};
	
	dialog.hbrBackground = (HBRUSH)COLOR_WINDOW ;
	dialog.hCursor = LoadCursor(NULL, IDC_CROSS);
	dialog.hInstance = hInst;
	dialog.lpszClassName = L"myDialogClass";
	dialog.lpfnWndProc = DialogProcedure;
	
	RegisterClassW(&dialog);
}
