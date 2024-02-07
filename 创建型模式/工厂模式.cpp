//
// Created by Administrator on 2024/2/4.
//
#include <iostream>
using namespace std;
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile(){}
};
class SheepSmile : public AbstractSmile
{
    void transform()override
    {
        cout << "变成人兽 -- 山羊人形态..." << endl;
    }
    void ability()override
    {
        cout << "将手臂变成绵羊角的招式 -- 巨羊角" << endl;
    }
};
// 人造恶魔果实· 狮子形态
class LionSmile : public AbstractSmile
{
public:
    void transform()
    {
        cout << "变成人兽 -- 狮子人形态..." << endl;
    }
    void ability()
    {
        cout << "火遁· 豪火球之术..." << endl;
    }
};
// 人造恶魔果实· 蝙蝠形态
class BatSmile: public AbstractSmile
{
public:
    void transform()
    {
        cout << "变成人兽 -- 蝙蝠人形态..." << endl;
    }
    void ability()
    {
        cout << "声纳引箭之万剑归宗..." << endl;
    }
};

/**
 * @brief 定义工厂类
 * @details
 * 在简单工厂类的基础上改进 符合开放封闭原则
 *
 */
class SmileFactory
{
public:
    virtual AbstractSmile * createSmile() =0;
    virtual ~SmileFactory(){};
};
/**
 * 生产绵阳果实的工厂
 */
class SheepFactory : public  SmileFactory
{
    AbstractSmile* createSmile()
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout<<"sheepFactory 被析构"<<endl;
    }
};
/**
 * 生产狮子果实的工厂
 *
 */
class LionFactory :public  SmileFactory
{
    AbstractSmile* createSmile()
    {
        return new LionSmile;
    }
    ~LionFactory()
    {
        cout<<"LionFactory 被析构"<<endl;
    }
};
int main()
{
    SmileFactory* factory = new LionFactory;
    AbstractSmile* obj = factory->createSmile();
    obj->transform();
    obj->ability();

    delete obj;
    delete factory;
    cout<<"ddd"<<endl;
    return 0;
}