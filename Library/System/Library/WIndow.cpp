// ------------------------------------------------------------------------------------------------ //
// @ file	 : Window.h                                                                             //
// @ brief	 : �E�C���h�E�̐����Ɋւ���N���X                                                       //
// @ date	 : 2017/10/29                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* �w�b�_�t�@�C���̃C���N���[�h */
// ����w�b�_�t�@�C��
#include "Window.h"

/* ���O��� */
// ���얼�O���
using namespace mnLib;

/* �����o�֐��̒�` */
// ----------------------------------------------------------------------------------------------- //
// @ brief	: �E�C���h�E�̏�����                                                                   //
// @ param	: HINSTANCE hInstance....�E�C���h�E�̃C���X�^���X                                      //
// @ param	: int nShowCmd....�V���[�R�}���h                                                       //
// @ return : HRESULT....HRESULT���O�Ȃ琳��A����ȊO�̒l�Ȃ�ُ�B                               //
// @ note	: ����                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HRESULT Window::WindowsInitialize(HINSTANCE hInstance, int nShowCmd)
{
	// �E�C���h�E�̏����i�[�����\����
	WNDCLASSEX wce;

	// �\���̂̑S�Ă̍��ڂ��O�ŏ���������
	SecureZeroMemory(&wce, sizeof(wce));
	// �\���̂̌��ɓ��I�Ɋm�ۂ����]���ȃ������B�O�ŏ�����
	wce.cbClsExtra = 0;
	// �\���̂̑傫��
	wce.cbSize = sizeof(wce);
	// �E�B���h�E�C���X�^���X�̌��ɓ��I�Ɋm�ۂ����]���ȃ������B�O�ŏ�����
	wce.cbWndExtra = 0;
	// �w�i�F(���ɐݒ�)
	wce.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	// �}�E�X�J�[�\��
	wce.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	// �A�C�R��(�f�X�N�g�b�v���ɕ`�悳���)
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// �A�C�R��(�^�X�N�o�[�Ȃǂɕ\�������)
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// �A�v���P�[�V�����̃C���X�^���X�n���h��
	wce.hInstance = hInstance;
	// ���b�Z�[�W���󂯎��WinProc�֐��ւ̃|�C���^��n���B
	wce.lpfnWndProc = BaseWindowProcedure;
	// �E�C���h�E�N���X�̖��O
	wce.lpszClassName = L"Window";
	// �E�C���h�E�����f�t�H���g�̃��j���[�̃��\�[�X��
	wce.lpszMenuName = NULL;
	// �E�B���h�E�̊�{������ݒ�
	wce.style = CS_HREDRAW | CS_VREDRAW;

	// WNDCLASSEX�̓o�^
	if (!RegisterClassEx(&wce))
	{
		// �ł��Ȃ�������0��Ԃ�
		return 0;
	}

	// �E�C���h�E�n���h��
	HWND windowHandle;

	// @brief  : ���C���̃E�C���h�E���쐬����
	// @param  : DWORD dwExStyle....�g������E�B���h�E�̌����ڂׂ̍��ȃX�^�C��
	// @param  : LPCTSTR lpClassName....�E�B���h�E�N���X�œo�^�������O
	// @param  : LPCTSTR lpWindowName....�쐬����E�B���h�E�ɕt�����閼�O
	// @param  : DWORD dwStyle....�쐬����E�B���h�E�̌����ڂׂ̍��ȃX�^�C��
	// @param  : int x....�E�B���h�E�̍���̈ʒu
	// @param  : int y....�E�B���h�E�̍���̈ʒu
	// @param  : int nWidth....�E�B���h�E�̕�
	// @param  : int nHeight....�E�B���h�E�̍���
	// @param  : HWND hWndParent....�e�E�C���h�E
	// @param  : HWND hMenu....�E�C���h�E�ɂ����j���[�n���h��
	// @param  : HINSTANCE hInstance....�A�v���P�[�V�����̃C���X�^���X�n���h��
	// @param  : LPVOID lpParam....�}���`�h�L�������g�C���^�[�t�F�[�X�E�C���h�E���쐬����Ƃ��Ɏg�p(�V���O���h�L�������g�C���^�[�t�F�[�X�̃E�C���h�E�̏ꍇ��NULL�ɂ���)
	windowHandle = CreateWindowEx
	(NULL
		, TEXT("Window")
		, TEXT("���C���E�C���h�E")
		, WS_OVERLAPPEDWINDOW | WS_VISIBLE
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, 640
		, 480
		, NULL
		, NULL
		, hInstance
		, this);
	if (windowHandle != NULL)
	{
		ShowWindow(windowHandle, SW_SHOW);
	}

	// �E�C���h�E�n���h��
	mHwnd = windowHandle;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �E�C���h�E�̏�����                                                                   //
// @ param	: HINSTANCE hInstance....�E�C���h�E�̃C���X�^���X                                      //
// @ param	: int nShowCmd....�V���[�R�}���h                                                       //
// @ param	: int width....�E�C���h�E�̕�                                                          //
// @ param	: int height....�E�C���h�E�̍���                                                       //
// @ return : HRESULT....HRESULT���O�Ȃ琳��A����ȊO�̒l�Ȃ�ُ�B                               //
// @ note	: ����                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HRESULT Window::WindowsInitialize(HINSTANCE hInstance, int nShowCmd, int width, int height)
{

	// �E�C���h�E�̏����i�[�����\����
	WNDCLASSEX wce;

	// �\���̂̑S�Ă̍��ڂ��O�ŏ���������
	SecureZeroMemory(&wce, sizeof(wce));
	// �\���̂̌��ɓ��I�Ɋm�ۂ����]���ȃ������B�O�ŏ�����
	wce.cbClsExtra = 0;
	// �\���̂̑傫��
	wce.cbSize = sizeof(wce);
	// �E�B���h�E�C���X�^���X�̌��ɓ��I�Ɋm�ۂ����]���ȃ������B�O�ŏ�����
	wce.cbWndExtra = 0;
	// �w�i�F(���ɐݒ�)
	wce.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);
	// �}�E�X�J�[�\��
	wce.hCursor = LoadCursor(NULL, IDI_APPLICATION);
	// �A�C�R��(�f�X�N�g�b�v���ɕ`�悳���)
	wce.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	// �A�C�R��(�^�X�N�o�[�Ȃǂɕ\�������)
	wce.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	// �A�v���P�[�V�����̃C���X�^���X�n���h��
	wce.hInstance = hInstance;
	// ���b�Z�[�W���󂯎��WinProc�֐��ւ̃|�C���^��n���B
	wce.lpfnWndProc = BaseWindowProcedure;
	// �E�C���h�E�N���X�̖��O
	wce.lpszClassName = L"Window";
	// �E�C���h�E�����f�t�H���g�̃��j���[�̃��\�[�X��
	wce.lpszMenuName = NULL;
	// �E�B���h�E�̊�{������ݒ�
	wce.style = CS_HREDRAW | CS_VREDRAW;

	// WNDCLASSEX�̓o�^
	if (!RegisterClassEx(&wce))
	{
		// �ł��Ȃ�������0��Ԃ�
		return 0;
	}

	// �E�C���h�E�n���h��
	HWND windowHandle;

	// @brief  : ���C���̃E�C���h�E���쐬����
	// @param  : DWORD dwExStyle....�g������E�B���h�E�̌����ڂׂ̍��ȃX�^�C��
	// @param  : LPCTSTR lpClassName....�E�B���h�E�N���X�œo�^�������O
	// @param  : LPCTSTR lpWindowName....�쐬����E�B���h�E�ɕt�����閼�O
	// @param  : DWORD dwStyle....�쐬����E�B���h�E�̌����ڂׂ̍��ȃX�^�C��
	// @param  : int x....�E�B���h�E�̍���̈ʒu
	// @param  : int y....�E�B���h�E�̍���̈ʒu
	// @param  : int nWidth....�E�B���h�E�̕�
	// @param  : int nHeight....�E�B���h�E�̍���
	// @param  : HWND hWndParent....�e�E�C���h�E
	// @param  : HWND hMenu....�E�C���h�E�ɂ����j���[�n���h��
	// @param  : HINSTANCE hInstance....�A�v���P�[�V�����̃C���X�^���X�n���h��
	// @param  : LPVOID lpParam....�}���`�h�L�������g�C���^�[�t�F�[�X�E�C���h�E���쐬����Ƃ��Ɏg�p(�V���O���h�L�������g�C���^�[�t�F�[�X�̃E�C���h�E�̏ꍇ��NULL�ɂ���)
	windowHandle = CreateWindowEx
	(WS_EX_COMPOSITED
		, TEXT("Window")
		, TEXT("���C���E�C���h�E")
		, WS_OVERLAPPEDWINDOW | WS_VISIBLE
		, CW_USEDEFAULT
		, CW_USEDEFAULT
		, width
		, height
		, NULL
		, NULL
		, hInstance
		, this);
	if (windowHandle != NULL)
	{
		ShowWindow(windowHandle, SW_SHOW);
	}

	// �E�C���h�E�n���h��
	mHwnd = windowHandle;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �R�[���o�b�N�֐�                                                                     //
// @ param	: HWND hwnd....�E�C���h�E�n���h��                                                      //
// @ param	: UINT messege = unsigned int messege....�E�C���h�E���b�Z�[�W���i�[                    //
// @ param	: WPARAM wparam....�E�C���h�E���b�Z�[�W���ƂɐF��Ȓl������                            //
// @ param	: LPARAM lparam....�E�C���h�E���b�Z�[�W���ƂɐF��Ȓl������                            //
// @ return : HRESULT....HRESULT���O�Ȃ琳��A����ȊO�̒l�Ȃ�ُ�B                               //
// @ note	: CALLBACK....CALLBACK�֐��Ƃ��Ē�`���邽��                                           //
// ----------------------------------------------------------------------------------------------- // 
LRESULT CALLBACK Window::WindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	switch (message)
	{
		// ����
	case WM_CREATE:
		break;
		// �I������
	case WM_QUIT:
		break;
		// �E�C���h�E�����i�~�{�^���������ꂽ��Ăяo�����j
	case WM_CLOSE:
		break;
		// �E�C���h�E�����iWM_CLOSE�̏������I�������Ăяo�����j
	case WM_DESTROY:
		// �E�C���h�E�����
		PostQuitMessage(0);
		// �v���O�������I��������
		exit(0);
		break;
		// �L�[�������ꂽ�Ƃ�
	case WM_KEYDOWN:
		break;
		// �V�X�e���L�[�������ꂽ�Ƃ�
	case WM_SYSKEYDOWN:
		break;
		// ���N���b�N�����ꂽ��
	case WM_LBUTTONDOWN:
		break;
		// �E�N���b�N�����ꂽ��
	case WM_RBUTTONDOWN:
		break;
		// �^�񒆂̃{�^���������ꂽ��
	case WM_MBUTTONDOWN:
		break;
		// �E�C���h�E���ŃJ�[�\���ړ�
	case WM_SETCURSOR:
		break;
	default:
		break;
	}
	return DefWindowProc(hwnd, message, wparam, lparam);
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �R�[���o�b�N�֐�                                                                     //
// @ param	: HWND hwnd....�E�C���h�E�n���h��                                                      //
// @ param	: UINT messege = unsigned int messege....�E�C���h�E���b�Z�[�W���i�[                    //
// @ param	: WPARAM wparam....�E�C���h�E���b�Z�[�W���ƂɐF��Ȓl������                            //
// @ param	: LPARAM lparam....�E�C���h�E���b�Z�[�W���ƂɐF��Ȓl������                            //
// @ return : HRESULT....HRESULT���O�Ȃ琳��A����ȊO�̒l�Ȃ�ُ�B                               //
// @ note	: CALLBACK....CALLBACK�֐��Ƃ��Ē�`���邽��                                           //
// ----------------------------------------------------------------------------------------------- // 
LRESULT Window::BaseWindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam)
{
	// ���g�̃|�C���^
	Window* window;
	/*
		�E�C���h�E��������Ƃ��ɐݒ肵���l���󂯎��
		(Window*)....���g�̃|�C���^�^�ŃL���X�g
		(GetWindowLongPtr(hwnd, GWLP_USERDATA)....CreateWindowEx�̍Ō�̈���(�����̃|�C���^)���擾
	 */
	window = (Window*)(GetWindowLongPtr(hwnd, GWLP_USERDATA));
	// ���g�̃|�C���^�ɒl�������Ă��Ȃ�������
	if (window == nullptr)
	{
		// ���b�Z�[�W���m�F(WM_CREATE��������)
		if (message == WM_CREATE)
		{
			// lparam�̒l�����炤
			window = (Window*)(((LPCREATESTRUCT)lparam)->lpCreateParams);
		}
		// ���g�̃|�C���^�ɒl�������Ă�����
		if (window != nullptr)
		{
			// �E�C���h�E�n���h���̒l��ݒ肷��
			window->SetPointer(hwnd);
		}
	}
	// ���g�̃|�C���^�ɒl�������Ă�����
	if (window != nullptr)
	{
		// �I�[�o�[���C�h�����E�C���h�E�v���V�[�W��
		return window->WindowProcedure(hwnd, message, wparam, lparam);
	}
	else
	{
		// �f�t�H���g�̃E�C���h�E�v���V�[�W��
		return DefWindowProc(hwnd, message, wparam, lparam);
	}
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: ���b�Z�[�W���[�v                                                                     //
// @ param	: �Ȃ�                                                                                 //
// @ return : bool�^                                                                               //
// @ note	: �Ȃ�                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
bool Window::MessageLoop()
{
	/*
		���b�Z�[�W���[�v���󂯎��
		LPMSG lpMesg....���b�Z�[�W���(MSG�\���̂̃|�C���^)
		HWND hWnd....�E�C���h�E�n���h��
		UINT wMsgFilterMin....�擾�Ώۃ��b�Z�[�W�̍ŏ��l(�O���w�肷��)
		Uint wMsgFilterMax....�擾�Ώۃ��b�Z�[�W�̍ő�l(�O���w�肷��)
	*/

	// ���b�Z�[�W���[�v�̍\����
	MSG msg;

	// �\���̂��O�ŏ�����
	ZeroMemory(&msg, sizeof(msg));

	// �擾�������b�Z�[�W���[�v���I������Ȃ�������
	if (PeekMessage(&msg, mHwnd, 0, 0, PM_REMOVE) != WM_QUIT)
	{
		// ���b�Z�[�W�̖|��
		TranslateMessage(&msg);
		// �擾�������b�Z�[�W���E�C���h�E�v���V�[�W���ɑ���
		DispatchMessage(&msg);
		return true;
	}
	else
	{
		return false;
	}
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �l��ݒ肷��                                                                         //
// @ param	: HWND hwnd....�E�C���h�E�n���h��                                                      //
// @ return : �Ȃ�                                                                                 //
// @ note	: �Ȃ�                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
void Window::SetPointer(HWND hwnd)
{
	/*
	�l��ݒ�
	hwnd....�E�C���h�E�n���h��
	GWLP_USERDATA....CreateWindowEx�̍Ō�̈���(�����̃|�C���^)
	reinterpret_cast<LONG_PTR>(this)....�����I��LONG_PTR�^�ɃL���X�g���ꂽ�����̃|�C���^
	*/
	SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(this));

	// �����ł�������E�C���h�E�n���h���������o�ϐ��̃E�C���h�E�n���h���ɑ��
	this->mHwnd = hwnd;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �E�C���h�E�n���h���̎擾                                                             //
// @ param	: �Ȃ�                                                                                 //
// @ return : HWND hwnd....�E�C���h�E�n���h��                                                      //
// @ note	: �Ȃ�                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
HWND Window::GetWindowHandle()
{
	return mHwnd;
}

// ----------------------------------------------------------------------------------------------- //
// @ brief	: �I������                                                                             //
// @ param	: HINSTANCE hInstance...����������E�C���h�E�N���X�̃C���X�^���X                       //
// @ return : �Ȃ�                                                                                 //
// @ note	: �Ȃ�                                                                                 //
// ----------------------------------------------------------------------------------------------- // 
void Window::Finalize(HINSTANCE hInstance)
{
	// �E�C���h�E�N���X���
	UnregisterClass(L"Window", hInstance);
}
/* �֐��̒�` */
