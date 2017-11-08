/*============================//
	Name:		Chen Yu			
	Admin ID:	p1626063
	Assignment:	IGRA CA1
	Year:		AY 2017/2018	
//============================*/

// IGRA_LAB.cpp : Defines the entry point for the application.
#include "stdafx.h"
#include "IGRA_LAB.h"
//For IGRA - OPENGL
#include <gl\GL.h>
#include <gl\GLU.h>
//STD Dependencies
#include <stdio.h>
#include <vector>

#pragma region Configuration Fields

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst; // current instance
WCHAR szTitle[MAX_LOADSTRING]; // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING]; // the main window class name

									 // Added for IGRA
int width = 400;
int height = 400;
HWND hWnd = NULL;
HDC hDC = NULL;
HGLRC hRC = NULL;

bool IsLBottonHold = false;
Shape::ShapeType shapeType = Shape::ShapeType::SQURE;
Colour shapecolour = Colour::BLACK;
Shape::Fill shapefillMode = Shape::Fill::FILLED;
Shape::Size shapeSize = Shape::Size::SMALL;
bool holdmode = false;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

GLuint PixelFormat;

#pragma endregion

#pragma region Function Decorations

int InitOpenGL();
void InitMenu();
void DrawGLScene();
void ReSizeGLScene(GLsizei width, GLsizei height);

#pragma endregion

#pragma region Setup Functions

static PIXELFORMATDESCRIPTOR pfd
{
	sizeof(PIXELFORMATDESCRIPTOR),
	1,// Version Number
	PFD_DRAW_TO_WINDOW | // Format Must Support Window
	PFD_SUPPORT_OPENGL | // Format Must Support OpenGL
	PFD_DOUBLEBUFFER,// Must Support Double Buffering
	PFD_TYPE_RGBA, // Request An RGBA Format
	16, // Select Our Color Depth = 16
	0, 0, 0, 0, 0, 0, // Color Bits Ignored
	0,// No Alpha Buffer
	0,// Shift Bit Ignored
	0,// No Accumulation Buffer
	0, 0, 0, 0, // Accumulation Bits Ignored
	32, // 32 Bit Z-Buffer (Depth Buffer)
	0,// No Stencil Buffer
	0,// No Auxiliary Buffer
	PFD_MAIN_PLANE,// Main Drawing Layer
	0,// Reserved
	0, 0, 0// Layer Masks Ignored
};

int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_IGRALAB, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_IGRALAB));
	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			DrawGLScene();
			SwapBuffers(hDC);
		}
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_IGRALAB));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable
					   //Changed for IGRA
	hWnd = CreateWindowW(szWindowClass, szTitle, (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX), 560, 140, width, height, nullptr, nullptr, hInstance, nullptr);

	InitOpenGL();

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	ReSizeGLScene(width, height);

	return TRUE;
}

#pragma endregion

#pragma region OpenGL Initialisation

void ReSizeGLScene(GLsizei width, GLsizei height)
{
	if (height == 0)// Prevent A Divide By Zero By
	{
		height = 1; // Making Height Equal One
	}
	// Reset The Current Viewport
	glViewport(0, 0, width, height);
	// Select The Projection Matrix
	glMatrixMode(GL_PROJECTION);
	// Reset The Projection Matrix
	glLoadIdentity();
	//2D
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int InitOpenGL()
{
	//Default menu options
	InitMenu();

	// Get Device Dontext
	if (!(hDC = GetDC(hWnd)))
	{
		MessageBox(NULL, L"Can't Create A GL Device Context.",
			L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Check if Windows can find a matching Pixel Format
	if (!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
	{
		MessageBox(NULL, L"Can't Find A Suitable PixelFormat.",
			L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Try to set pixel format
	if (!SetPixelFormat(hDC, PixelFormat, &pfd))
	{
		MessageBox(NULL, L"Can't Set The PixelFormat.", L"ERROR",
			MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Get a Rendering context
	if (!(hRC = wglCreateContext(hDC)))
	{
		MessageBox(NULL, L"Can't Create A GL Rendering Context.",
			L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	// Activate Rendering Context
	if (!wglMakeCurrent(hDC, hRC))
	{
		MessageBox(NULL, L"Can't Activate The GL Rendering Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return 0;
	}
	return 1;
}

#pragma endregion

#pragma region MenuControls

vector<int> shapeMenuList = { ID_SHAPE_SQURE, ID_SHAPE_TRIANGLE , ID_SHAPE_CIRCLE , ID_SHAPE_RANDOM };
vector<int> colourMenuList = { ID_COLOUR_BLACK, ID_COLOUR_BLUE, ID_COLOUR_GREEN, ID_COLOUR_RANDOM, ID_COLOUR_RANDOMANY, ID_COLOUR_RED, ID_COLOUR_YELLOW};
vector<int> fillMenuList = { ID_FILL_FILLED, ID_FILL_WIREFRAME, ID_FILL_RANDOM };
vector<int> sizeMenuList = { ID_SIZE_LARGE, ID_SIZE_MEDIUM, ID_SIZE_RANDOM, ID_SIZE_RANDOMANY, ID_SIZE_SMALL};
vector<int> controlMenuList = { ID_CONTROL_CLICK, ID_CONTROL_HOLD};

void UnCheckMenuList(vector<int> menulist)
{
	for (size_t i = 0; i < menulist.size(); i++)
	{
		CheckMenuItem(GetMenu(hWnd), menulist[i], MF_UNCHECKED);
	}
}

#pragma endregion

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_COMMAND:
		{// Parse the menu selections:
			int wmId = LOWORD(wParam);
			switch (wmId)
				{
					{
					case ID_SHAPE_SQURE:
						UnCheckMenuList(shapeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						shapeType = Shape::ShapeType::SQURE;
						break;

					case ID_SHAPE_TRIANGLE:
						UnCheckMenuList(shapeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SHAPE_CIRCLE:
						UnCheckMenuList(shapeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SHAPE_RANDOM:
						UnCheckMenuList(shapeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;
					}
					{
					case ID_COLOUR_BLACK:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_RED:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_GREEN:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_BLUE:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_YELLOW:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_RANDOM:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_COLOUR_RANDOMANY:
						UnCheckMenuList(colourMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;
					}
					{
					case ID_FILL_FILLED:
						UnCheckMenuList(fillMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_FILL_WIREFRAME:
						UnCheckMenuList(fillMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_FILL_RANDOM:
						UnCheckMenuList(fillMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;
					}
					{
					case ID_SIZE_SMALL:
						UnCheckMenuList(sizeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SIZE_MEDIUM:
						UnCheckMenuList(sizeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SIZE_LARGE:
						UnCheckMenuList(sizeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SIZE_RANDOM:
						UnCheckMenuList(sizeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_SIZE_RANDOMANY:
						UnCheckMenuList(sizeMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;
					}
					{
					case ID_CONTROL_CLICK:
						UnCheckMenuList(controlMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;

					case ID_CONTROL_HOLD:
						UnCheckMenuList(controlMenuList);
						CheckMenuItem(GetMenu(hWnd), wmId, MF_CHECKED);
						break;
					}

					default:
						return DefWindowProc(hWnd, message, wParam, lParam);
				}
			break;
		}
		case WM_PAINT:
		{
			PAINTSTRUCT ps;
			HDC hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code that uses hdc here...
			EndPaint(hWnd, &ps);
			break;
		}
		case WM_SIZE:
		{// Added for IGRA
			ReSizeGLScene(LOWORD(lParam), HIWORD(lParam));
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			IsLBottonHold = true;
			break;
		}
		case WM_LBUTTONUP:
		{// Get the left mouse press coordinates
			int mouseX = LOWORD(lParam);
			int mouseY = HIWORD(lParam);
			Vector2f::ConvertMouseCoordinates(mouseX, mouseY, width, height);
			Shape shapetodraw = Shape(shapeType, shapecolour, shapefillMode, shapeSize);
			IsLBottonHold = false;
			break;
		}
		case WM_MOUSEMOVE:
		{
			if (IsLBottonHold)
			{
				int mouseX = LOWORD(lParam);
				int mouseY = HIWORD(lParam);
				Vector2f::ConvertMouseCoordinates(mouseX, mouseY, width, height);
			}
			break;
		}

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void InitMenu()
{
	CheckMenuItem(GetMenu(hWnd), ID_SHAPE_SQURE, MF_CHECKED);
	CheckMenuItem(GetMenu(hWnd), ID_COLOUR_BLACK, MF_CHECKED);
	CheckMenuItem(GetMenu(hWnd), ID_FILL_FILLED, MF_CHECKED);
	CheckMenuItem(GetMenu(hWnd), ID_SIZE_SMALL, MF_CHECKED);
	CheckMenuItem(GetMenu(hWnd), ID_CONTROL_CLICK, MF_CHECKED);
}

void DrawGLScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(1, 1, 1, 1);

	for (size_t i = 0; i < Square::List.size(); i++)
	{
		Square::List[i].Draw();
	}

	glLoadIdentity();
}

