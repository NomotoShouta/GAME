//==============================
//
// エフェクト処理[effect.h]
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
    //発生からのフレーム数
    unsigned int mFrame;

protected:
    //発生からのフレーム数
    unsigned int frame() 
    {
        return mFrame;
    }

    //削除までのフレーム数
    const unsigned int mDeleteFrame;

public:
    //削除する時にtrueを返す
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
        clear(); //下で定義
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

    //要素を追加
    void add(Effect* effect) 
    {
        mEffect.emplace_back(effect);
    }

    //エフェクト全消去
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