//==============================
//
// �G�t�F�N�g����[effect.h]
// Author:Nomoto Shouta
//
//==============================
#include <vector>
#ifndef _EFFECT_H_
#define _EFFECT_H_

class Effect 
{
protected:
    Effect(unsigned int deleteFrame) :
        mDeleteFrame(deleteFrame),
        mFrame(0)
    {
    }
public:
    virtual ~Effect() = default;
private:
    //��������̃t���[����
    unsigned int mFrame;

protected:
    //��������̃t���[����
    unsigned int frame() 
    {
        return mFrame;
    }

    //�폜�܂ł̃t���[����
    const unsigned int mDeleteFrame;

public:
    //�폜���鎞��true��Ԃ�
    virtual bool update() 
    {
        mFrame++;
        return false;
    }

    virtual void draw() const = 0;
};

class EffectManager 
{
public:
    EffectManager() 
    {

    }

    ~EffectManager() 
    {
        clear(); //���Œ�`
    }

private:
    std::vector<Effect*> mEffect;

public:
    void update() 
    {
        auto itr = std::remove_if(mEffect.begin(), mEffect.end(),
            [](Effect* t) 
            {
                t->Effect::udpate();
                bool flag = t->update();
                if (flag) delete t;
                return flag;
            }
        );
        mEffect.erase(itr, mEffect.end());
    }

    void draw() const 
    {
        for (const auto& i : mEffect) 
        {
            i->draw();
        }
    }

    //�v�f��ǉ�
    void add(Effect* effect) 
    {
        mEffect.emplace_back(effect);
    }

    //�G�t�F�N�g�S����
    void clear() 
    {
        for (const auto& i : mEffect) 
        {
            delete i;
        }
        mEffect.clear();
    }
};

#endif