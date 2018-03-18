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

void	loadImages()
{
	hOpenImg = (HBITMAP)LoadImageW(NULL, L"open.bmp", IMAGE_BITMAP, 40, 40, LR_LOADFROMFILE);
	hSaveImg = (HBITMAP)LoadImageW(NULL, L"save.bmp", IMAGE_BITMAP, 40, 40, LR_LOADFROMFILE);
}

void	AddMenus(HWND hWnd)
{
	hMenu = CreateMenu();
	HMENU hFileMenu = CreateMenu();
	
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_OPEN, "Open");
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_SAVE, "Save");
	AppendMenu(hFileMenu, MF_SEPARATOR, NULL, NULL);
	AppendMenu(hFileMenu, MF_STRING, FILE_MENU_EXIT, "Exit");
	
	AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, "File");
	AppendMenu(hMenu, MF_STRING, FILE_MENU_HELP, "Help");

	SetMenu(hWnd, hMenu);
}
