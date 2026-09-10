#include <DX3D/Window/Window.h>
#include <Windows.h>
#include <stdexcept>


static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

dx3d::Window::Window(const WindowDesc& desc) : Base(desc.base)
{
	auto registerWindowClassFunction = []()
		{
			WNDCLASSEX wc{};
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.lpszClassName = L"DX3DWindow";
			wc.lpfnWndProc = &WindowProc;
			return RegisterClassEx(&wc);
		};



	static const auto windowClassId = std::invoke(registerWindowClassFunction);


	if (!windowClassId)
	{
		getLogger().log(Logger::LogLevel::error, "RegisterClassEx: Failed ");
		throw std::runtime_error("RegisterClassEx: Failed ");
	}

	RECT rc = { 0, 0, 1280, 720 };
	AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, FALSE);

	m_handle = CreateWindowEx(NULL, MAKEINTATOM(windowClassId), L"JK engine", WS_OVERLAPPEDWINDOW | WS_CAPTION | WS_SYSMENU, CW_USEDEFAULT, CW_USEDEFAULT, rc.right - rc.left, rc.bottom - rc.top, NULL, NULL, NULL, NULL);

	if (!m_handle)
	{
		getLogger().log(Logger::LogLevel::error, " CreateWindowEx: Failed ");
		throw std::runtime_error("CreateWindowEx: Failed ");
	}

	ShowWindow(static_cast<HWND>(m_handle), SW_SHOW);

}


dx3d::Window::~Window()
{
	DestroyWindow(static_cast<HWND>(m_handle));
}
