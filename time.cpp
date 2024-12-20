//==============================
//
// �^�C������[time.cpp]
// Author:Nomoto Shouta
//
//==============================
#include "time.h"
#include "manager.h"
#include "object2D.h"
#include "renderer.h"
#include "enemy.h"

CTime* CTime::m_apTime = 0;
float m_aPosTIMETexV[1];

//===========================================
// �R���X�g���N�^
//===========================================
CTime::CTime()
{
	m_pVtxBuff = nullptr;
	m_pTexture = nullptr;
}

//===========================================
// �f�X�g���N�^
//===========================================
CTime::~CTime()
{

}

//===========================================
// �^�C�}�[�̏���������
//===========================================
HRESULT CTime::Init()
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntTime;
	m_nTime = TIME_RIMIT;
	m_fTimeX = START_TIME_POS;
	float m_fU = START_NUMBER;

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	// �e�N�X�`���̓ǂݍ���
	D3DXCreateTextureFromFile(pDevice, "data\\TEXTURE\\number_004.png", &m_pTextureTime);

	// �^�C�}�[�̏�����
	for (nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		m_aTime[nCntTime].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_aTime[nCntTime].bUse = false;
	}

	// ���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * 4 * MAX_TIME, D3DUSAGE_WRITEONLY, 4, D3DPOOL_MANAGED, &m_pVtxBuffTime, NULL);

	VERTEX_2D* pVtx;

	// ���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	m_pVtxBuffTime->Lock(0, 0, (void**)&pVtx, 0);

	for (nCntTime = 0; nCntTime < MAX_TIME; nCntTime++)
	{
		// ���_���W�̐ݒ�
		pVtx[0].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		pVtx[1].pos = D3DXVECTOR3(20.0f, 0.0f, 0.0f);
		pVtx[2].pos = D3DXVECTOR3(0.0f, 40.0f, 0.0f);
		pVtx[3].pos = D3DXVECTOR3(20.0f, 40.0f, 0.0f);

		// rhw�̐ݒ�
		pVtx[0].rhw = 1.0f;
		pVtx[1].rhw = 1.0f;
		pVtx[2].rhw = 1.0f;
		pVtx[3].rhw = 1.0f;

		// ���_�J���[�̐ݒ�
		pVtx[0].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[1].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[2].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
		pVtx[3].col = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(0.1f, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(0.1f, 1.0f);

		pVtx += 4;
	}

	// ���_�o�b�t�@���A�����b�N
	m_pVtxBuffTime->Unlock();

	for (int nTimeCount = 0; nTimeCount < MAX_DIGIT; nTimeCount++)
	{
		SetTimePos(D3DXVECTOR3(m_fTimeX, 50.0f, 0.0f), D3DXVECTOR2(m_fU, 0.0));
		m_fTimeX += 50.0f;
	}

	return S_OK;
}

//===========================================
// �^�C�}�[�̏I������
//===========================================
void CTime::Uninit()
{
	// �e�N�X�`���̔j��
	if (m_pTextureTime != NULL)
	{
		m_pTextureTime->Release();
		m_pTextureTime = NULL;
	}

	// ���_�o�b�t�@�̔j��
	if (m_pVtxBuffTime != NULL)
	{
		m_pVtxBuffTime->Release();
		m_pVtxBuffTime = NULL;
	}

	CObject::Release();
}

//===========================================
// �^�C�}�[�̍X�V����
//===========================================
void CTime::Update()
{
	m_nFrame++;

	int nTime = m_nFrame / 60;

	if (nTime == 1)
	{
		m_nTime--;
		m_nFrame = 0;
		SetTime();
	}

	if (m_nTime <= 60)
	{
		enemy::EnemyCreater();
	}

	if (m_nTime == 0)
	{
		CManager::SetScene(CScene::MODE_RESULT);
	}
}

//===========================================
// �^�C�}�[�̕`�揈��
//===========================================
void CTime::Draw()
{
	LPDIRECT3DDEVICE9 pDevice;
	int nCntTime;

	CRenderer* pRenderer = CManager::GetRenderer();

	//�f�o�C�X�̎擾
	pDevice = pRenderer->GetDevice();

	// ���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuffTime, 0, sizeof(VERTEX_2D));

	// ���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_2D);

	// �e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, m_pTextureTime);

	for (nCntTime = 0; nCntTime < MAX_DIGIT; nCntTime++)
	{
		if (m_aTime[nCntTime].bUse == true)
		{// �^�C�}�[���g�p����Ă�����
			// �|���S���̕`��
			pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 4 * nCntTime, 2);
		}
	}
}

//===========================================
// Object2D�̎擾
//===========================================
CTime* CTime::GetObject2D()
{
	return m_apTime;
}

//===========================================
// Object2D����
//===========================================
CTime* CTime::Create()
{
	if (m_apTime == nullptr)
	{
		m_apTime = new CTime;
		m_apTime->Init();
	}
	return  m_apTime;
}

void CTime::SetTimePos(D3DXVECTOR3 pos, D3DXVECTOR2 tex)
{
	int nCntTime;
	VERTEX_2D* pVtx;

	m_pVtxBuffTime->Lock(0, 0, (void**)&pVtx, 0);

	// ���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	for (nCntTime = 0; nCntTime < MAX_DIGIT; nCntTime++)
	{
		if (m_aTime[nCntTime].bUse == false)
		{
			m_aTime[nCntTime].pos = pos;

			pVtx += (nCntTime * 4);

			if (nCntTime == 0)
			{
				pVtx[0].tex.x = 0.6f;
				pVtx[1].tex.x = 0.7f;
				pVtx[2].tex.x = 0.6f;
				pVtx[3].tex.x = 0.7f;
			}
			else if (nCntTime == 1)
			{
				pVtx[0].tex.x = 0.0f;
				pVtx[1].tex.x = 0.1f;
				pVtx[2].tex.x = 0.0f;
				pVtx[3].tex.x = 0.1f;
			}

			pVtx[0].pos.x = pos.x - 20;
			pVtx[0].pos.y = pos.y - 40;
			pVtx[1].pos.x = pos.x + 20;
			pVtx[1].pos.y = pos.y - 40;
			pVtx[2].pos.x = pos.x - 20;
			pVtx[2].pos.y = pos.y + 40;
			pVtx[3].pos.x = pos.x + 20;
			pVtx[3].pos.y = pos.y + 40;

			m_aTime[nCntTime].bUse = true;
			break;
		}
		// ���_�o�b�t�@���A�����b�N
		m_pVtxBuffTime->Unlock();
	}
}

//===========================================
// �^�C�}�[�̐ݒ菈��
//===========================================
void CTime::SetTime(void)
{
	int a_PosTexU[MAX_DIGIT];
	int One = 1;
	int nCnt;
	for (nCnt = 0; nCnt < MAX_DIGIT; nCnt++)
	{
		a_PosTexU[nCnt] = m_nTime / One % 10;
		One *= 10;
	}

	VERTEX_2D* pVtx;

	//���_�o�b�t�@�����b�N�����_���ւ̃|�C���^���擾
	m_pVtxBuffTime->Lock(0, 0, (void**)&pVtx, 0);

	for (nCnt = MAX_DIGIT - 1; nCnt >= 0; nCnt--)
	{
		float fDigit0, fDigit1;
		fDigit0 = a_PosTexU[nCnt] * 0.1f;
		fDigit1 = fDigit0 + 0.1f;

		// �e�N�X�`�����W�̐ݒ�
		pVtx[0].tex = D3DXVECTOR2(fDigit0, 0.0f);
		pVtx[1].tex = D3DXVECTOR2(fDigit1, 0.0f);
		pVtx[2].tex = D3DXVECTOR2(fDigit0, 1.0f);
		pVtx[3].tex = D3DXVECTOR2(fDigit1, 1.0f);

		pVtx += 4;
	}
	m_pVtxBuffTime->Unlock();
}

int CTime::GetTime(void)
{
	return m_nTime;
}