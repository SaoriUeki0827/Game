/*!
* @brief	背景(床)クラス。
*/

#pragma once

class Floor{
public:
	Floor();
	~Floor();
	void Start();
	void Update();
	void Render();
private:
	Camera camera;
	SkinModel model;
	SkinModelData modelData;
	Light light;
	D3DXVECTOR3				position;		//座標。
	D3DXMATRIX				mWorld;			//ワールド行列。
};
extern Floor* g_floor;