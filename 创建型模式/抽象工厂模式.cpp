//
// Created by Administrator on 2024/2/6.
//
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
//船体
class ShipBody
{
public:
    virtual string getBody()=0;
    virtual ~ShipBody(){};
};
//木头船体
class WoodBody : public ShipBody
{
public:
    string getBody()override
    {
        return string("使用《木材》制作海贼船的船体");
    }
};
class IronBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("用<钢铁>制作轮船船体...");
    }
};

class MetalBody : public ShipBody
{
public:
    string getBody() override
    {
        return string("用<合金>制作轮船船体...");
    }
};
// 动力
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
        return string("使用<人力驱动>...");
    }
};

class Diesel : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<内燃机驱动>...");
    }
};

class Nuclear : public Engine
{
public:
    string getEngine() override
    {
        return string("使用<核能驱动>...");
    }
};

// 武器
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
        return string("配备的武器是<枪>");
    }
};

class Cannon : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<自动机关炮>");
    }
};

class Laser : public Weapon
{
public:
    string getWeapon() override
    {
        return string("配备的武器是<激光>");
    }
};
//船
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
        //组合关系 析构船的时候 同时析构船的子部件
        delete m_weapon;
        delete m_engine;
        delete m_body;
    }
private:
    ShipBody* m_body;
    Engine* m_engine;
    Weapon* m_weapon;
};
//抽象工厂类
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
        cout << "<基础型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class StandardFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new IronBody, new Cannon, new Diesel);
        cout << "<标准型>战船生产完毕, 可以下水啦..." << endl;
        return ship;
    }
};

class UltimateFactory : public AbstractFactory
{
public:
    Ship* createShip() override
    {
        Ship* ship = new Ship(new MetalBody, new Laser, new Nuclear);
        cout << "<旗舰型>战船生产完毕, 可以下水啦..." << endl;
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
