//
// Created by Administrator on 2024/2/4.
//
#include <iostream>
using namespace std;
/**
 * @brief 抽象的Smile果实
 */
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile(){}
};
/**
 * @brief 山羊Smile果实
 */
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

/**】
 * @brief 定义工厂类
 * @details 用来创建 山羊果实、狮子果实、蝙蝠果实
 */
enum class Type:char{SHEEP, LION , BAT};
class SmileFactory
{
public:
    AbstractSmile * createSmile(Type type)
    {
        AbstractSmile* ptr = nullptr;
        switch (type)
        {
            case Type::SHEEP:
                ptr = new SheepSmile;
                break;
            case Type::LION:
                ptr = new LionSmile;
                break;
            case Type::BAT:
                ptr = new BatSmile;
                break;
            default:
                break;
        }
        return ptr;
    }
};
int main()
{
    SmileFactory* factory = new SmileFactory;
    AbstractSmile* obj = factory->createSmile(Type::LION);
    obj->transform();
    obj->ability();
    cout<<"ddd"<<endl;
    return 0;
}