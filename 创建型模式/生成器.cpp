//
// Created by Administrator on 2024/2/6.
//
#include <iostream>
#include <queue>
#include <mutex>
#include <map>
#include <vector>
using namespace std;
//1.���崬��ص���
//2.������������ص���
//3.��������-�����첻ͬ���Ĵ�
/**
 * @brief ɣ��Ŵ�
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
* @brief ÷���Ŵ�
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
 * @brief   ���� ������ģʽ
 * @details ����ģʽ �ڴ�������ʱ��רעϸ��
 * ������ģʽ��רע�����Ĳ���
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
        m_sunny->addParts("���������ǵ�");
     }
     void buildWeapon()
     {
        m_sunny->addParts("ʨ����");
     }
     void buildEngine()
     {
         m_sunny->addParts("������������ȼ��");
     }
     void buildInterior()
     {
         m_sunny->addParts("��������");
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


// ÷����������
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
        m_merry->assemble("����", "����ľ��");
    }
    void buildWeapon() override
    {
        m_merry->assemble("����", "���Ŵ���");
    }
    void buildEngine() override
    {
        m_merry->assemble("����", "������");
    }
    void buildInterior() override
    {
        m_merry->assemble("����", "��װ");
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
// ������
class Director
{
public:
    void setBuilder(ShipBuilder* builder)
    {
        m_builder = builder;
    }
    // ��Լ��
    void builderSimpleShip()
    {
        m_builder->buildBody();
        m_builder->buildEngine();
    }
    // ��׼��
    void builderStandardShip()
    {
        builderSimpleShip();
        m_builder->buildWeapon();
    }
    // ������
    void builderRegalShip()
    {
        builderStandardShip();
        m_builder->buildInterior();
    }
private:
    ShipBuilder* m_builder = nullptr;
};
// ����ɣ���
void builderSunny()
{
    Director* director = new Director;
    SunnyBuilder* builder = new SunnyBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->builderSimpleShip();
    SunnyShip* sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;

    // ������
    builder->reset();
    director->setBuilder(builder);
    director->builderRegalShip();
    sunny = builder->getSunnyShip();
    sunny->showParts();
    delete sunny;
    delete builder;
    delete director;
}

// ����÷����
void builderMerry()
{
    Director* director = new Director;
    ShipBuilder * builder = new MerryBuilder;
    // ��Լ��
    director->setBuilder(builder);
    director->builderSimpleShip();
    MerryShip* merry = static_cast<MerryShip*>(builder->getMerry());
    merry->showParts();
    delete merry;

    // ��׼��
    builder->reset();
    director->setBuilder(builder);
    director->builderStandardShip();
    merry = static_cast<MerryShip*>(builder->getMerry());
    merry->showParts();
    delete merry;

    // ������
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
