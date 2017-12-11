// ------------------------------------------------------------------------------------------------ //
// @ file	 : Color.h                                                                              //
// @ brief	 : DirectX�̐F�Ɋւ���w�b�_�t�@�C��                                                    //
// @ date	 : 2017/10/29                                                                           //
// @ author  : Madoka Nakajima                                                                      //
// @ note	 :                                                                                      //
// ------------------------------------------------------------------------------------------------ // 

/* ���d�C���N���[�h�̖h�~ */
#pragma once

/* �}�N���̒�` */
#define DELETE_COPY_AND_ASSIGN(name)         \
/* �R�s�[�R���X�g���N�^�Ƒ�����Z�q�̍폜 */ \
name(const name&) = delete;                  \
name& operator = (const name&) = delete;     \


#define PROPERTY(type,name,setFunc,getFunc)                      \
/* �ϐ��̐ݒ�Ǝ擾�̂��߂́iC���ł����v���p�e�B�j */            \
private;                                                         \
/* ## �l�̘A�� */                                                \
type m##name;                                                    \
public;                                                          \
_declspec(property(get = getFunc.put = setFunc)) type m##name;   \
void setFunc(type value){m##name = value;}                       \
type getFunc(){return m##name;}                                  \


/* �w�b�_�t�@�C���̃C���N���[�h */


