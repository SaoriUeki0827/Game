/*!
* @brief	�Q�[��
*/
#include "stdafx.h"
#include "Floor.h"


/*!
* @brief	�R���X�g���N�^�B
*/
Floor::Floor()
{
	D3DXMatrixIdentity(&mWorld);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
}
/*!
* @brief	�f�X�g���N�^�B
*/
Floor::~Floor()
{
}
/*!
* @brief	�Q�[�����N�����Ă����x�����Ă΂��֐��B
*/
void Floor::Start()
{
	//���f�������[�h�B
	modelData.LoadModelData("Assets/model/yuka.X",NULL);

	model.Init(&modelData);
	model.SetLight(&light);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}
/*!
* @brief	�X�V�B
*/
void Floor::Update()
{
	camera.Update();
	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}
/*!
* @brief	�`��B
*/
void Floor::Render()
{
	model.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
}
