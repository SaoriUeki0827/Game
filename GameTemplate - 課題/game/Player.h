/*!
 * @brief	ゲームクラス。
 */

#pragma once


/*!
 * @brief	ゲームクラス。
 */
class Player{
public:
	Player();
	~Player();
	void Start();
	void Update();
	void Render();
	D3DXVECTOR3 GetPos(){ return position; }
private:
	SkinModel model;
	SkinModelData modelData;
	Animation animation;
	Light light;
	D3DXVECTOR3				position;		//座標。
	D3DXQUATERNION			rotate;		//回転座標。
	D3DXMATRIX				mWorld;			//ワールド行列。
	D3DXMATRIX				mRotation;		//回転行列。
	bool animeFlg;
};

extern Player* player;
extern Camera* camera;