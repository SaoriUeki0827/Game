#pragma once

class MapChip;

/*!
* @brief	�}�b�v�N���X�B
*/
class Map{
public:

	Map();
	~Map();
	void Start();
	void Update();
	void Render();
private:
	std::vector<MapChip*> mapChipList;	//�}�b�v�`�b�v�̃��X�g�B
};
