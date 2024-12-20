//==============================
//
// ブロックマネージャー処理[blockmanager.h]
// Author:Nomoto Shouta
//
//==============================

#ifndef _BLOCKMANAGER_H
#define _BLOCKMANAGER_H

//ブロック管理クラス
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
	//管理するブロック情報
	/*CBlock* m_apBlockList[5];*/
};
#endif
