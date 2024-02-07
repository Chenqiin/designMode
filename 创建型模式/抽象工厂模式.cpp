//
// Created by Administrator on 2024/2/6.
//
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
//����
class ShipBody
{
public:
    virtual string getBody()=0;
    virtual ~ShipBody(){};
};
//ľͷ����
class WoodBody : public ShipBody
{
public:
    string getBody()override
    {
        return string("ʹ�á�ľ�ġ������������Ĵ���");
    }
};
class IronBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("��<����>�����ִ�����...");
    }
};

class MetalBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("��<�Ͻ�>�����ִ�����...");
    }
};
// ����
class Engine
{
public:
    virtual string getEngine() = 0;
    virtual ~Engine() {}
};

class Human : public Engine
{
public:
    string getEngine() override
    {
        return string("ʹ��<��������>...");
    }
};

class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return string("ʹ��<��ȼ������>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("ʹ��<��������>...");
    }
};

// ����
class Weapon
{
public:
    virtual string getWeapon() = 0;
    virtual ~Weapon() {}
};

class Gun : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<ǹ>");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<�Զ�������>");
    }
};

class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("�䱸��������<����>");
    }
};
//��
class Ship
{
public:
    Ship(ShipBody* body,Weapon* weapon,Engine* engine):
        m_body(body),m_engine(engine),m_weapon(weapon)
    {

    }
    string getProperty()
    {
        string info = m_body->getBody() + m_engine->getEngine() + m_weapon->getWeapon();
        return info;
    };
    ~Ship()
    {
        //��Ϲ�ϵ ��������ʱ�� ͬʱ���������Ӳ���
        delete m_weapon;
        delete m_engine;
        delete m_body;
    }
private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};
//���󹤳���
class AbstractFactory
{
public:
    virtual Ship* createShip() = 0;
    virtual ~AbstractFactory(){}
};

class BasicFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new WoodBody, new Gun, new Human);
        cout << "<������>ս���������, ������ˮ��..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<��׼��>ս���������, ������ˮ��..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        cout << "<�콢��>ս���������, ������ˮ��..." << endl;
        return ship;
    }
};

int main()
{
    AbstractFactory* factroy = new StandardFactory;
    Ship* ship = factroy->createShip();
    cout << ship->getProperty();
    delete ship;
    delete factroy;
    return 0;
}
