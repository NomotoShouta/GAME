//==============================
//
// �u���b�N�}�l�[�W���[����[blockmanager.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _BLOCKMANAGER_H
#define _BLOCKMANAGER_H

//�u���b�N�Ǘ��N���X
class CBlockManager :public CObject
{
public:
	CBlockManager();
	~CBlockManager();
	HRESULT Init();
	void Uninit();
	void Update();
	void Draw();
private:
	//�Ǘ�����u���b�N���
	/*CBlock* m_apBlockList[5];*/
};
#endif
