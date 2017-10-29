//// ------------------------------------------------------------------------------------------------ //
//// @ file	 : Window.h                                                                                     //
//// @ brief	 : �E�C���h�E�̐����Ɋւ���N���X                                                                                     //
//// @ date	 : 2017/10/28                                                                                     //
//// @ author  : Madoka Nakajima                                                                                     //
//// @ note	 :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//
///* ���d�C���N���[�h�̖h�~ */
//#pragma once
///* �w�b�_�t�@�C���̃C���N���[�h */
//// �W�����C�u����
//#include <Windows.h>
//
///* ���O��Ԃ̐錾 */
//// ���얼�O���
//namespace mnLib
//{
//	/* �N���X�̐錾 */
//	class Window
//	{
//		/* �����o�ϐ� */
//		// �E�C���h�E�n���h��
//		HWND mHwnd;
//		// ���g�̃|�C���^
//		Window* mSelf;
//		/* �����o�֐� */
//		// �R���X�g���N�^
//		Window() = default;
//		// �f�X�g���N�^
//		~Window() = default;
//		// ������
//		HRESULT WindowsInitialize(HINSTANCE hInstance, int nShowCmd);
//		HRESULT WindowsInitialize(HINSTANCE hInstance, int nShowCmd, int width, int height);
//		// �E�C���h�E�v���V�[�W��
//		LRESULT CALLBACK WindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
//		// �ÓI�E�C���h�E�v���V�[�W��
//		static LRESULT CALLBACK BaseWindowProcedure(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);
//		// ���b�Z�[�W���[�v
//		bool MessageLoop();
//		// �l�̐ݒ�
//		void SetPointer(HWND hwnd);
//		// �E�C���h�E�n���h�����擾
//		HWND GetWindowHandle();
//		// �I������
//		void Finalize(HINSTANCE hInstance);
//	};
//}
