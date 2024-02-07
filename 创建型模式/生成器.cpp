//
// Created by Administrator on 2024/2/6.
//
#include <iostream>
#include <queue>
#include <mutex>
#include <map>
#include <vector>
using namespace std;
//1.定义船相关的类
//2.定义生成器相关的类
//3.管理者类-》建造不同规格的船
/**
 * @brief 桑尼号船
 */
 class SunnyShip
 {
 public:
     void addParts(string name)
     {
         m_parts.push_back(name);
     }
     void showParts()
     {
         for(const auto & item:m_parts)
         {
             cout<<item<<" ";
         }
         cout << endl;
     }
 private:
     vector<string> m_parts;
 };

/**
* @brief 梅丽号船
*/
class MerryShip
{
public:
    void assemble(string name,string parts)
    {
        m_parts.insert(make_pair(parts,name));
    }
    void showParts()
    {
        for(const auto & item:m_parts)
        {
            cout<<item.first<<" :"<<item.second;
        }
        cout << endl;
    }
private:
    map<string ,string> m_parts;
};
/**
 * @brief   基类 建造者模式
 * @details 工厂模式 在创建对象时不专注细节
 * 建造者模式更专注创建的步骤
 */
class MerryBuilder;
class ShipBuilder
{
public:
    virtual void reset()=0;
    virtual void buildBody()=0;
    virtual void buildWeapon()=0;
    virtual void buildEngine()=0;
    virtual void buildInterior()=0;
    virtual MerryShip* getMerry(){};
    virtual ~ShipBuilder(){}
};
class SunnyBuilder : public ShipBuilder
{
public:
    SunnyBuilder():m_sunny(new SunnyShip)
    {
        reset();
    }
     void reset()
     {
        if(m_sunny == nullptr)
        {
            m_sunny = new SunnyShip;
        }
     }
     SunnyShip * getSunnyShip()
     {
        SunnyShip* ship = m_sunny;
        m_sunny = nullptr;
        return ship;
     }
     void buildBody()
     {
        m_sunny->addParts("船是神树亚当");
     }
     void buildWeapon()
     {
        m_sunny->addParts("狮吼炮");
     }
     void buildEngine()
     {
         m_sunny->addParts("可乐驱动的内燃机");
     }
     void buildInterior()
     {
         m_sunny->addParts("豪华内饰");
     }
     ~SunnyBuilder(){
         if(m_sunny)
         {
             delete m_sunny;
         }
     }
private:
    SunnyShip *m_sunny;
};


// 梅利号生成器
class MerryBuilder : public ShipBuilder
{
public:
    MerryBuilder()
    {
        reset();
    }
    ~MerryBuilder()
    {
        if (m_merry != nullptr)
        {
            delete m_merry;
        }
    }
    void reset() override
    {
        m_merry = new MerryShip;
    }
    void buildBody() override
    {
        m_merry->assemble("船体", "优质木材");
    }
    void buildWeapon() override
    {
        m_merry->assemble("武器", "四门大炮");
    }
    void buildEngine() override
    {
        m_merry->assemble("动力", "蒸汽机");
    }
    void buildInterior() override
    {
        m_merry->assemble("内室", "精装");
    }
    MerryShip* getMerry()override
    {
        MerryShip* ship = m_merry;
        m_merry = nullptr;
        return ship;
    }

private:
    MerryShip* m_merry = nullptr;
};
// 主管类
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }
    // 简约型
    void builderSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // 标准型
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // 豪华型
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};
// 建造桑尼号
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    SunnyShip* sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;
    delete builder;
    delete director;
}

// 建造梅利号
void builderMerry()
{
    Director* director = new Director;
    ShipBuilder * builder = new MerryBuilder;
    // 简约型
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = static_cast<MerryShip*>(builder->getMerry());
    merry->showParts();
    delete merry;

    // 标准型
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = static_cast<MerryShip*>(builder->getMerry());
    merry->showParts();
    delete merry;

    // 豪华型
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    merry = static_cast<MerryShip*>(builder->getMerry());
    merry->showParts();
    delete merry;
    delete builder;
    delete director;
}

int main()
{
    builderSunny();
    cout << "=====================================" << endl;
    builderMerry();
}
