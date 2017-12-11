// ------------------------------------------------------------------------------------------------ //
// @ file	 : Color.h                                                                              //
// @ brief	 : DirectXの色に関するヘッダファイル                                                    //
// @ date	 : 2017/10/29                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* 多重インクルードの防止 */
#pragma once

/* マクロの定義 */
#define DELETE_COPY_AND_ASSIGN(name)         \
/* コピーコンストラクタと代入演算子の削除 */ \
name(const name&) = delete;                  \
name& operator = (const name&) = delete;     \


#define PROPERTY(type,name,setFunc,getFunc)                      \
/* 変数の設定と取得のための（C＃でいうプロパティ） */            \
private;                                                         \
/* ## 値の連結 */                                                \
type m##name;                                                    \
public;                                                          \
_declspec(property(get = getFunc.put = setFunc)) type m##name;   \
void setFunc(type value){m##name = value;}                       \
type getFunc(){return m##name;}                                  \


/* ヘッダファイルのインクルード */


