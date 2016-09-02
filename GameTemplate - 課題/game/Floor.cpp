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
	light.SetDiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetDiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	//���f�������[�h�B
	modelData.LoadModelData("Assets/model/BackGround.X",NULL);

	model.Init(&modelData);
	model.SetLight(&light);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}
/*!
* @brief	�X�V�B
*/
void Floor::Update()
{
	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(10.0f, 10.0f, 10.0f));
}
/*!
* @brief	�`��B
*/
void Floor::Render()
{
	model.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
}
