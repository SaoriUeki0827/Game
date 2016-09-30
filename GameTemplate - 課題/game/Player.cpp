/*!
 * @brief	ゲーム
 */
#include "stdafx.h"
#include "Player.h"


/*!
 * @brief	コンストラクタ。
 */
Player::Player()
{
	D3DXMatrixIdentity(&mWorld);
	D3DXMatrixIdentity(&mRotation);
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
}
/*!
 * @brief	デストラクタ。
 */
Player::~Player()
{
}
/*!
 * @brief	ゲームが起動してから一度だけ呼ばれる関数。
 */
void Player::Start()
{
	//カメラ初期化。

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
	modelData.LoadModelData("Assets/model/Unity.X", &animation);
	
	model.Init(&modelData);
	model.SetLight(&light);
	animation.PlayAnimation(0);
	position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	rotate = D3DXQUATERNION(0.0f, 0.0f, 0.0f, 1.0f);
	animeFlg = false;

}
/*!
 * @brief	更新。
 */
void Player::Update()
{
		if (GetAsyncKeyState(VK_LEFT))
		{
			if (!animeFlg){
				animation.PlayAnimation(1, 0.1f);
				animeFlg = true;
			}
			position.x += 0.2f;
			D3DXQuaternionRotationAxis(&rotate, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(90.0f));
		}
		else if (GetAsyncKeyState(VK_RIGHT))
		{
			if (!animeFlg){
				animation.PlayAnimation(1, 0.1f);
				animeFlg = true;
			}
			position.x -= 0.2f;
			D3DXQuaternionRotationAxis(&rotate, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(-90.0f));
		}
		else if (GetAsyncKeyState(VK_DOWN))
		{
			if (!animeFlg){
				animation.PlayAnimation(1, 0.1f);
				animeFlg = true;
			}
			position.z += 0.2f;
			D3DXQuaternionRotationAxis(&rotate, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(0.0f));
		}
		else if (GetAsyncKeyState(VK_UP))
		{
			if (!animeFlg){
				animation.PlayAnimation(1, 0.1f);
				animeFlg = true;
			}
			position.z -= 0.2f;
			D3DXQuaternionRotationAxis(&rotate, &D3DXVECTOR3(0.0f, 1.0f, 0.0f), D3DXToRadian(180.0f));
		}
		else
		{
			if (animeFlg){
				animation.PlayAnimation(0, 0.1f);
				animeFlg = false;
			}
		}
	animation.Update(1.0f / 60.0f);
	model.UpdateWorldMatrix(position, rotate, D3DXVECTOR3(1.0f, 1.0f, 1.0f));
}
/*!
 * @brief	描画。
 */
void Player::Render()
{
	model.Draw(&camera->GetViewMatrix(), &camera->GetProjectionMatrix());
}
