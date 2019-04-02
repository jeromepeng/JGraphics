#pragma once
class UITools
{
public:
	UITools();
	~UITools();
	static CString OpenFileDialog();
	static void DebugMessageBox(HWND hWnd, LPCWSTR info);
};

