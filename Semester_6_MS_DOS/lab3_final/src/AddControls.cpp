//################################################
//
//    #             
//    #  #           Program: HeaderMaker
//    #  #          
//    ####   #       Author: Anastasia Lukyanenko
//    #  ## ##      
//    #  # # #       Created By HeaderMaker 
//       #   #      
//           #      
//
//################################################

#include "header_maker.h"

void	AddControls(HWND hWnd)
{
	hOpen = CreateWindowW(L"button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
		30, 30, 40, 40, hWnd, (HMENU)FILE_MENU_OPEN, NULL, NULL);
	SendMessageW(hOpen, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hOpenImg);

	hSave = CreateWindowW(L"button", L"", WS_VISIBLE | WS_CHILD | BS_BITMAP,
		80, 30, 40, 40, hWnd, (HMENU)FILE_MENU_SAVE, NULL, NULL);
	SendMessageW(hSave, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hSaveImg);

	hFile_cont = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER |
		WS_HSCROLL | WS_VSCROLL | ES_MULTILINE,
		30, 90, 550, 500, hWnd, NULL, NULL, NULL);
	SendMessageW(hOpen, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hOpenImg);

	CreateWindowW(L"static", L"HEADER PARAMETERS:", WS_VISIBLE | WS_CHILD,
		735, 30, 200, 30, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"program_name:", WS_VISIBLE | WS_CHILD,
		630, 90, 100, 30, hWnd, NULL, NULL, NULL);
	hProg_name = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
		740, 90, 250, 20, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"author name:", WS_VISIBLE | WS_CHILD,
		630, 120, 100, 30, hWnd, NULL, NULL, NULL);
	hAuthor = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
		740, 120, 250, 20, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"static", L"comment type:", WS_VISIBLE | WS_CHILD,
		630, 150, 100, 30, hWnd, NULL, NULL, NULL);
	hComment_type = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER,
		740, 150, 13, 20, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"button", L"MAKE HEADER", WS_VISIBLE | WS_CHILD | WS_BORDER,
		735, 180, 200, 30, hWnd, (HMENU)MAKE_HEADER, NULL, NULL);

	hHeader = CreateWindowW(L"edit", L"", WS_VISIBLE | WS_CHILD | WS_BORDER
		| ES_MULTILINE, 630, 220, 400, 200, hWnd, NULL, NULL, NULL);

	CreateWindowW(L"button", L"Clear", WS_VISIBLE | WS_CHILD | WS_BORDER,
		630, 430, 100, 30, hWnd, (HMENU)CLEAR_FIELD, NULL, NULL);

	CreateWindowW(L"button", L"Paste into file", WS_VISIBLE | WS_CHILD | WS_BORDER,
		740, 430, 200, 30, hWnd, (HMENU)PASTE_INTO_FILE, NULL, NULL);
}
