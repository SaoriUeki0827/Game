#pragma once

class MapChip;

/*!
* @brief	マップクラス。
*/
class Map{
public:

	Map();
	~Map();
	void Start();
	void Update();
	void Render();
private:
	std::vector<MapChip*> mapChipList;	//マップチップのリスト。
};
