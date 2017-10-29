//// ------------------------------------------------------------------------------------------------ //
//// @ file	 : Direct3D.h                                                                           //
//// @ brief	 : DirectX�֘A�̃N���X                                                                  //
//// @ date	 : 2017/10/29                                                                           //
//// @ author  : Madoka Nakajima                                                                      //
//// @ note	 :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//
///* ���d�C���N���[�h�̖h�~ */
//#pragma once
//
///* Direct3D 11�֘A���C�u�����̃����N */
//#pragma region LinkLibrary
//// �uDirect3D 11�v�p���C�u����
//#pragma comment(lib,"d3d11.lib")
//// �f�o�b�O�r���h���H
//#if defined(DEBUG)||defined(_DEBUG)
//// �f�o�b�O�ł́uD3DX 11�v�p���C�u�����������N
//#pragma comment(lib,"d3dx11d.lib")
//#else
//// �����[�X�ł́uD3DX 11�v�p���C�u�����������N
//#pragma comment(lib,"d3dx11.lib")
//#endif
//// �G���[�������[�e�B���e�B�E���C�u����
//#pragma comment(lib,"dxerr.lib")
//#pragma endregion Direct3D_11�֘A���C�u�����̃����N
//
///* �w�b�_�t�@�C���̃C���N���[�h */
//#pragma region IncludeHeaderFile
//// �^�`�F�b�N�������ɍs��
//#define STRICT
//// �w�b�_�[���炠�܂�g���Ȃ��֐����Ȃ�
//#define WIN32_LEAN_AND_MEAN
//// Windows.h
//#include <Windows.h>
//// Direct3D
//#include <d3d11.h>
//// Direct3D��D3DX�i�����Łud3d11.h�v���C���N���[�h���Ă���j
////#include <d3dx11.h>
//// DirectX�̃G���[�������[�e�B���e�B�E���C�u����
////#include <dxerr.h>
//// �uMBCS�i�}���`�E�o�C�g�E�L�����N�^�E�Z�b�g�j�����Z�b�g�v�ƁuUnicode�����Z�b�g�v�̗����ɑΉ��ł���
//#include <tchar.h>
//// Windows �����^�C�� C++ �e���v���[�g ���C�u����
//#include <WRL.h>
//#pragma endregion �w�b�_�t�@�C���̃C���N���[�h
//
//
///* �萔�̒�` */
///* �ϐ��̒�` */
///* �񋓑̂̒�` */
///* �\���̂̒�` */
///* �֐��̃v���g�^�C�v�錾 */
///* ���O��Ԃ̐錾 */
//// ���얼�O���
//namespace mnLib
//{
//	/* �N���X�̐錾 */
//	class Direct3D
//	{
//		/* �����o�ϐ� */
//	private:
//		// �E�C���h�E�n���h��
//		HWND mHwnd;
//		//// �f�o�C�X
//		//Microsoft::WRL::ComPtr<ID3D11Device> pDevice;
//		//// �f�o�C�X�R���e�L�X�g
//		//Microsoft::WRL::ComPtr<ID3D11DeviceContext> pContext;
//		//// �X���b�v�`�F�C��
//		//Microsoft::WRL::ComPtr<IDXGISwapChain> pSwapChain;
//		//// �����_�[�^�[�Q�b�g�r���[
//		//Microsoft::WRL::ComPtr<ID3D11RenderTargetView> pRenderTargetView;
//		//// �o�b�N�o�b�t�@
//		//Microsoft::WRL::ComPtr<ID3D11Texture2D> pBackBuffer;
//		//// �[�x�X�e���V��
//		//Microsoft::WRL::ComPtr<ID3D11Texture2D> pDepthStencil;
//		//// �[�x�X�e���V���r���[
//		//Microsoft::WRL::ComPtr<ID3D11DepthStencilView> pDepthStencilView;
//		//// �C���^�[�t�F�[�X
//		//Microsoft::WRL::ComPtr<IDXGIDevice1> pInterface;
//		//// �A�_�v�^
//		//Microsoft::WRL::ComPtr<IDXGIAdapter> pAdapter;
//		//// �t�@�N�g��
//		//Microsoft::WRL::ComPtr<IDXGIFactory1> pFactory;
//
//		// �f�o�C�X
//		ID3D11Device* pDevice;
//		// �f�o�C�X�R���e�L�X�g
//		ID3D11DeviceContext* pContext;
//		// �X���b�v�`�F�C��
//		IDXGISwapChain* pSwapChain;
//		// �����_�[�^�[�Q�b�g�r���[
//		ID3D11RenderTargetView* pRenderTargetView;
//		// �o�b�N�o�b�t�@
//		ID3D11Texture2D* pBackBuffer;
//		// �[�x�X�e���V��
//		ID3D11Texture2D* pDepthStencil;
//		// �[�x�X�e���V���r���[
//		ID3D11DepthStencilView* pDepthStencilView;
//		// �C���^�[�t�F�[�X
//		IDXGIDevice1* pInterface;
//		// �A�_�v�^
//		IDXGIAdapter* pAdapter;
//		// �t�@�N�g��
//		IDXGIFactory1* pFactory;
//
//
//		// ��ʂ̃T�C�Y�i���j
//		int mWidth;
//		// ��ʂ̃T�C�Y�i�����j
//		int mHeight;
//
//		/* �����o�֐� */
//	public:
//		// ����������
//		HRESULT Initialize(HWND windowHandle);
//		// �X�V����
//		void Update();
//		// �`�揈��
//		void Render();
//		// �I������
//		void CleanUp();
//
//		// �����_�[�^�[�Q�b�g�r���[�̐���
//		void CreateRenderTargetView();
//		// �[�x�o�b�t�@�̐���
//		void CreateDepthStencilView();
//		// �o�b�N�o�b�t�@�̃X���b�v
//		void SwapBackBaffer();
//
//#pragma region Setter
//		void SetWidth(int width) { mWidth = width; }
//		void SetHeight(int height) { mHeight = height; }
//#pragma endregion �����o�ϐ��̐ݒ�֐��Q
//
//#pragma region Getter
//		//HWND GetHandle() { return mHwnd; }
//		//ID3D11Device* GetDevice() { return pDevice.Get(); }
//		//ID3D11DeviceContext* GetContext() { return pContext.Get(); }
//		//IDXGISwapChain* GetSwapChain() { return pSwapChain.Get(); }
//		//ID3D11RenderTargetView* GetRenderTargetView() { return pRenderTargetView.Get(); }
//		//ID3D11Texture2D* GetBackBuffer() { return pBackBuffer.Get(); }
//		//ID3D11Texture2D* GetDepthStencil() { return pDepthStencil.Get(); }
//		//ID3D11DepthStencilView* GetDepthStencilView() { return pDepthStencilView.Get(); }
//		//IDXGIDevice1* GetInterface() { return pInterface.Get(); }
//		//IDXGIAdapter* GetAdapter() { return pAdapter.Get(); }
//		//IDXGIFactory1* GetFactory() { return pFactory.Get(); }
//
//		HWND GetHandle() { return mHwnd; }
//		ID3D11Device* GetDevice() { return pDevice; }
//		ID3D11DeviceContext* GetContext() { return pContext; }
//		IDXGISwapChain* GetSwapChain() { return pSwapChain; }
//		ID3D11RenderTargetView* GetRenderTargetView() { return pRenderTargetView; }
//		ID3D11Texture2D* GetBackBuffer() { return pBackBuffer; }
//		ID3D11Texture2D* GetDepthStencil() { return pDepthStencil; }
//		ID3D11DepthStencilView* GetDepthStencilView() { return pDepthStencilView; }
//		IDXGIDevice1* GetInterface() { return pInterface; }
//		IDXGIAdapter* GetAdapter() { return pAdapter; }
//		IDXGIFactory1* GetFactory() { return pFactory; }
//
//		int GetWidth() { return mWidth; }
//		int GetHeight() { return mHeight; }
//#pragma endregion �����o�ϐ��̎擾�֐��Q
//	};
//}
