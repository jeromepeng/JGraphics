#pragma once
class UITools
{
public:
	UITools();
	~UITools();
	static char* OpenFileDialog();
	static void DebugMessageBox(HWND hWnd, LPCWSTR info);
};

