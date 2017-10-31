// ------------------------------------------------------------------------------------------------ //
// @ file	 : WinMain.cpp                                                                          //
// @ brief	 : ウインドウを描画するためのエントリーポイント                                         //
// @ date	 : 2017/10/30                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ヘッダファイルのインクルード */
// 標準ライブラリ
#include <Windows.h>
// 自作ヘッダファイル
#include "../System/Library/Window.h"

/* 名前空間 */
// 自作名前空間
using namespace mnLib;

/* 定数の定義 */
// ウインドウサイズ
static const int windowWidth = 1280;
static const int windowHeight = 960;

/* 変数の定義 */
/* 列挙体の定義 */
/* 構造体の定義 */
/* 関数のプロトタイプ宣言 */
/* 名前空間の宣言 */
/* クラスの宣言 */
/* メンバ変数 */
/* メンバ関数 */
/* メンバ関数の定義 */
/* 関数の定義 */
// ----------------------------------------------------------------------------------------------- //
// @ brief  : メイン関数                                                                           //
// @ param  : HINSTANCE hInstance...アプリケーションの識別                                         //
// @ param  : HINSTANCE hPrevInstance                                                              //
// @ param  : LPSTR lpCmdLine...コマンドラインから受け取った引数                                   //
// @ param  : int nShowCmd...ウインドウの表示するための値                                          //
// @ return : int...整数値                                                                         //
// @ note   : WINAPI...Windowsの関数の呼び出し規約。Windowsの関数を呼び出すときは必ず頭につく      //
// ----------------------------------------------------------------------------------------------- // 
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// ウインドウクラスのインスタンス
	Window* window;
	// インスタンスを生成
	window = new Window();
	// 初期化
	window->WindowsInitialize(hInstance, nShowCmd, windowWidth, windowHeight);

	// メインループ
	while (window->MessageLoop() != false)
	{

	}


	// インスタンスを破棄
	delete window;
	// 正常終了
	return 0;
}
