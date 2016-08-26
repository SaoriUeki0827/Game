/*!
* @brief	ゲーム
*/
#include "stdafx.h"
#include "Floor.h"


/*!
* @brief	コンストラクタ。
*/
Floor::Floor()
{
	D3DXMatrixIdentity(&mWorld);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
}
/*!
* @brief	デストラクタ。
*/
Floor::~Floor()
{
}
/*!
* @brief	ゲームが起動してから一度だけ呼ばれる関数。
*/
void Floor::Start()
{
	//カメラ初期化。
	camera.Init();
	camera.SetEyePt(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();

	//ライトを初期化。
	light.SetDiffuseLightDirection(0, D3DXVECTOR4(0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(1, D3DXVECTOR4(-0.707f, 0.0f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(2, D3DXVECTOR4(0.0f, 0.707f, -0.707f, 1.0f));
	light.SetDiffuseLightDirection(3, D3DXVECTOR4(0.0f, -0.707f, -0.707f, 1.0f));

	light.SetDiffuseLightColor(0, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(1, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetDiffuseLightColor(2, D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));
	light.SetDiffuseLightColor(3, D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f));
	light.SetAmbientLight(D3DXVECTOR4(0.3f, 0.3f, 0.3f, 1.0f));

	//モデルをロード。
	modelData.LoadModelData("Assets/model/BackGround.x");

	model.Init(&modelData);
	model.SetLight(&light);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

}
/*!
* @brief	更新。
*/
void Floor::Update()
{
	camera.Update();
	model.UpdateWorldMatrix(position, D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}
/*!
* @brief	描画。
*/
void Floor::Render()
{
	model.Draw(&camera.GetViewMatrix(), &camera.GetProjectionMatrix());
}
