#include "stdafx.h"
#include "UITools.h"


UITools::UITools()
{
}


UITools::~UITools()
{
}

char* UITools::OpenFileDialog()
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
		int i, length;
		char* strResult;
		length = filePath.GetLength();
		strResult = new char[length];
		for (i = 0; i < length; i++)
		{
			*(strResult + i) = filePath.GetAt(i);
		}
		*(strResult + length) = NULL;
		return strResult;
	}
	catch (CString &e)
	{
		return (LPSTR)(LPCSTR)e.GetBuffer();
	}
}

void UITools::DebugMessageBox(HWND hWnd, LPCWSTR info)
{
	MessageBox(hWnd, info, L"Debug Info", MB_OK);
}