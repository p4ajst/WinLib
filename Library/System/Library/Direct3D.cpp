//// ------------------------------------------------------------------------------------------------ //
//// @ file   : Direct3D.h                                                                           //
//// @ brief  : DirectX�֘A�̃N���X                                                                  //
//// @ date   : 2017/10/29                                                                           //
//// @ author : Madoka Nakajima                                                                      //
//// @ note   :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//
///* �w�b�_�t�@�C���̃C���N���[�h */
//// ����w�b�_�t�@�C��
//#include "Direct3D.h"
//#include "../../Utility/Color.h"
//
///* ���O��� */
//// ���얼�O���
//using namespace mnLib;
//
///* �}�N���̒�` */
//#pragma region DefinitionMacro
//// �J���p�}�N��
//#define SAFE_RELEASE(x){if(x){(x)->Releace();(x) = NULL}}
//#pragma endregion �}�N���̒�`
//
//
///* �萔�̒�` */
///* �ϐ��̒�` */
///* �񋓑̂̒�` */
///* �\���̂̒�` */
///* �����o�֐��̒�` */
///* �֐��̒�` */
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : ������                                                                               //
//// @ param   : HWND whandle....�E�C���h�E�n���h��                                                   //
//// @ return  : HRESULT....HRESULT���O�Ȃ琳��A����ȊO�̒l�Ȃ�ُ�B                               //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//HRESULT Direct3D::Initialize(HWND windowHandle)
//{
//	// �߂�l
//	HRESULT hrlt;
//#pragma region InitMemberVariable
//	mHwnd = windowHandle;
//	//pDevice.Reset();
//	//pContext.Reset();
//	//pSwapChain.Reset();
//	//pRenderTargetView.Reset();
//	//pBackBuffer.Reset();
//	//pDepthStencil.Reset();
//	//pDepthStencilView.Reset();
//	//pInterface.Reset();
//	//pAdapter.Reset();
//	//pFactory.Reset();
//	
//	pDevice = nullptr;
//	pContext = nullptr;
//	pSwapChain = nullptr;
//	pRenderTargetView = nullptr;
//	pBackBuffer = nullptr;
//	pDepthStencil = nullptr;
//	pDepthStencilView = nullptr;
//	pInterface = nullptr;
//	pAdapter = nullptr;
//	pFactory = nullptr;
//
//	mWidth = 0;
//	mHeight = 0;
//#pragma endregion �����o�ϐ��̏�����
//
//#pragma region SetScreenSize
//	// �N���C�A���g�̈���i�[����ϐ�
//	RECT rc;
//
//	// �N���C�A���g�̈�̎擾
//	GetClientRect(mHwnd, &rc);
//	// ���̌v�Z
//	mWidth = rc.right - rc.left;
//	// �����̌v�Z
//	mHeight = rc.bottom - rc.top;
//
//#pragma endregion �N���C�A���g�̈���擾���ĉ�ʃT�C�Y���Z�o
//
//#pragma region FunctionLevel
//	// �V�F�[�_�[���f���T�Ȃǂ�Direct3D 11.0 �ŃT�|�[�g����Ă���@�\���^�[�Q�b�g�Ƃ���
//	// �@�\���x���̔z��
//	D3D_FEATURE_LEVEL dfl[] =
//	{
//		D3D_FEATURE_LEVEL_11_1,
//		D3D_FEATURE_LEVEL_11_0,
//		D3D_FEATURE_LEVEL_10_1,
//		D3D_FEATURE_LEVEL_10_0,
//		D3D_FEATURE_LEVEL_9_3,
//		D3D_FEATURE_LEVEL_9_2,
//		D3D_FEATURE_LEVEL_9_1,
//	};
//	// �z��̗v�f��
//	UINT featurelefels = 7;
//	// �f�o�C�X�쐬���ɕԂ����@�\���x��
//	D3D_FEATURE_LEVEL dfl_Supported = D3D_FEATURE_LEVEL_11_1;
//#pragma endregion �@�\���x���̔z��
//
//#pragma region SetSwapChain
//
//	/* �f�o�C�X�ƃX���b�v�`�F�C���̐ݒ� */
//	DXGI_SWAP_CHAIN_DESC swapChainDesc;
//	// �\���̂̒l��������
//	SecureZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
//	// �o�b�N�o�b�t�@�̐�
//	swapChainDesc.BufferCount = 2;
//	/// �f�B�X�v���C���[�h��ݒ肷��\����
//	// �o�b�N�o�b�t�@�̕�
//	swapChainDesc.BufferDesc.Width = 640;
//	// �o�b�N�o�b�t�@�̍���
//	swapChainDesc.BufferDesc.Height = 480;
//	// �f�B�X�v���C�t�H�[�}�b�g
//	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
//	// ���t���b�V�����[�g�i���q�j
//	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
//	// ���t���b�V�����[�g�i����j
//	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
//	// �X�L�������C���`�惂�[�h
//	swapChainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
//	// �X�P�[�����O���[�h
//	swapChainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
//	/// �o�b�N�o�b�t�@�̎g�������w�肷��t���O
//	/// �o�b�N�o�b�t�@�̓V�F�[�_���͂܂��͕`��^�[�Q�b�g�Ƃ��Ďg�����Ƃ��ł���
//	// �o�b�N�o�b�t�@�̎g�p�@
//	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
//	/// �o�͐�E�C���h�E�̃n���h��
//	// �֘A�t����E�C���h�E
//	swapChainDesc.OutputWindow = windowHandle;
//	// �}���`�T���v���̐�
//	swapChainDesc.SampleDesc.Count = 1;
//	// �}���`�T���v���̃N�I���e�B
//	swapChainDesc.SampleDesc.Quality = 0;
//	/// �X���b�v���ʂ��w�肷��t���O
//	/// ��ʃ��[�h�̐ݒ�
//	/// �E�C���h�E���[�h�ł���΁uTRUE�v
//	/// �t���X�N���[�����[�h�ł���΁uFalse�v
//	// �E�C���h�E���[�h
//	swapChainDesc.Windowed = TRUE;
//	// �X���b�v����
//	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
//	// ���[�h�̎����؂�ւ�
//	swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
//
//#pragma endregion �X���b�v�`�F�C���̐ݒ�
//
//#pragma region CreateDeviceAndSwapChain
//	// @brief  : �uID3D11Device�C���^�[�t�F�[�X�v�ƁuID3D11DiveceContext�C���^�[�t�F�[�X�v�ƁuIDXGISwapChain�C���^�[�t�F�[�X�v�𓯎��ɍ쐬
//	// @param  : IDXGIAdapter* pAdapter....�\���Ɏg���f�B�X�v���C�f�o�C�X���w��
//	// @param  : D3D_DRIVER_TYPE DriverType....�f�o�C�X�̃h���C�o�^�C�v���w��
//	// @param  : HMODULE SoftWare....�\�t�g�E�F�A���X�^���C�U����������Ă���DLL�̃n���h�����w��
//	// @param  : UINT Flags....�g�p����Direct3D 11��API���C���[��񋓌^�̑g�ݍ��킹�Ŏw�肷��
//	// @param  : const D3D_FEATURE_LEVEL* pFeatureLevel....�쐬�����݂�@�\���x����D�揇�ʂ̍������ɕ��ׂ��z��
//	// @param  : UINT FeatureLevels....pFeatureLevel�Ŏw�肵���z��̗v�f��
//	// @param  : UINT SDKVersion....SDK�o�[�W�������w��
//	// @param  : const DXGI_SWAP_CHAIN_DESC* pSwapChainDesc....���X���b�v�`�F�C���̐ݒ���L�q����\���̂�n��
//	// @param  : IDXGISwapChain** ppSwapChain....���ꂽ�X���b�v�`�F�C���̃C���^�[�t�F�[�X���󂯎��ϐ��̃|�C���^��n��
//	// @param  : ID3D11Device ppDevice....������f�o�C�X�̃C���^�[�t�F�[�X���󂯎��ϐ��̃|�C���^��n��
//	// @param  : D3D_FEATURE_LEVEL* pFeatureLevel....�T�|�[�g����Ă���@�\���x�����󂯎��ϐ��̃|�C���^
//	// @param  : ID3D11DeviceContext** ppImmidiateContext....������f�o�C�X�R���e�L�X�g�̃C���^�[�t�F�[�X���󂯎��ϐ��̃|�C���^��n��
//
//
//
//#pragma endregion �f�o�C�X�ƃX���b�v�`�F�C���̍쐬
//
//
//
//#pragma region StencilTexture
//
//
//#pragma endregion �X�e���V���p�e�N�X�`��
//
//#pragma region StencelTarget
//
//#pragma endregion �X�e���V���^�[�Q�b�g
//
//#pragma region GetBackBuffer
//
//#pragma endregion �X���b�v�`�F�C���̃o�b�N�o�b�t�@���擾
//
//#pragma region CreateRenderTarget
//
//#pragma endregion �o�b�N�o�b�t�@����`��^�[�Q�b�g�𐶐�
//
//#pragma region SetContext
//
//#pragma endregion �`��^�[�Q�b�g���R���e�L�X�g�ɐݒ�
//
//#pragma region SetViewport
//
//#pragma endregion �r���[�|�[�g�̐ݒ�
//
//#pragma region GetInterface
//
//#pragma endregion �C���^�[�t�F�[�X���擾
//
//#pragma region GetAdapter
//
//#pragma endregion �t�@�N�g�����擾
//
//#pragma region ArrowFullScreen
//
//
//#pragma endregion �t���X�N���[��������
//
//
//
//
//
//	return hrlt;
//}
//
//void Direct3D::Update()
//{
//}
//
//void Direct3D::Render()
//{
//}
//
//void Direct3D::CleanUp()
//{
//	delete pDevice;
//	delete pContext;
//	delete pSwapChain;
//	delete pRenderTargetView;
//	delete pBackBuffer;
//	delete pDepthStencil;
//	delete pDepthStencilView;
//	delete pInterface;
//	delete pAdapter;
//	delete pFactory;
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : �����_�[�^�[�Q�b�g�r���[�̐���                                                       //
//// @ param   : �Ȃ�                                                                                 //
//// @ return  : �Ȃ�                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::CreateRenderTargetView()
//{
//	// ����
//	//pContext->ClearRenderTargetView(pRenderTargetView.Get(), DxColors::FloralWhite);
//	pContext->ClearRenderTargetView(pRenderTargetView, DxColors::FloralWhite);
//
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : �[�x�o�b�t�@�̐���                                                                   //
//// @ param   : �Ȃ�                                                                                 //
//// @ return  : �Ȃ�                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::CreateDepthStencilView()
//{
//	// ����
//	//pContext->ClearDepthStencilView(pDepthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//	pContext->ClearDepthStencilView(pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//}
//
//// ------------------------------------------------------------------------------------------------ //
//// @ brief   : �o�b�N�o�b�t�@�̃X���b�v                                                             //
//// @ param   : �Ȃ�                                                                                 //
//// @ return  : �Ȃ�                                                                                 //
//// @ note    :                                                                                      //
//// ------------------------------------------------------------------------------------------------ // 
//void Direct3D::SwapBackBaffer()
//{
//	// �o�b�N�o�b�t�@�̃X���b�v
//	pSwapChain->Present(0, 0);
//}
