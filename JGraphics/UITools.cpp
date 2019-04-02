#include "stdafx.h"
#include "UITools.h"


UITools::UITools()
{
}


UITools::~UITools()
{
}

CString UITools::OpenFileDialog()
{
	BOOL isOpen = TRUE;
	CString defaultDir = L"C:\\";
	CString filePath = L"";
	CString fileName = L"";
	CString filter = L"Image File (*.BMP; *.bmp)|*.BMP; *.bmp||";
	try
	{
		if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
		{
			filePath = "";
		}
		CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY | OFN_READONLY, filter, NULL);
		INT_PTR result = openFileDlg.DoModal();		
		if (result == IDOK)
		{
			filePath = openFileDlg.GetPathName();
		}
		return filePath;
	}
	catch (CString &e)
	{
		return e;
	}
}

void UITools::DebugMessageBox(HWND hWnd, LPCWSTR info)
{
	MessageBox(hWnd, info, L"Debug Info", MB_OK);
}