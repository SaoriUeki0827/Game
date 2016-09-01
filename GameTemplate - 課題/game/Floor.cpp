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
	//モデルをロード。
	modelData.LoadModelData("Assets/model/yuka.X",NULL);

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
