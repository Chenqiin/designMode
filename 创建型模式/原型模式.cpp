//
// Created by Administrator on 2024/2/7.
//
#include <iostream>
#include <queue>
#include <mutex>
#include <string>
using namespace std;
//父类
class GermaSoldier
{
public:
    virtual GermaSoldier*  clone()=0;
    virtual string whoAmI()=0;
    virtual ~GermaSoldier(){};
};

//子类
class Soldier66 :public GermaSoldier
{
public:
     GermaSoldier*  clone() {
        return new Soldier66(*this);
    }
     string whoAmI()
    {
        return "我是 66";
    }
//    virtual ~GermaSoldier(){};
};
class Soldier67 :public GermaSoldier
{
public:
    GermaSoldier*  clone() {
        //使用深拷贝
        return new Soldier67(*this);
    }
    string whoAmI()
    {
        return "我是 67";
    }
//    virtual ~GermaSoldier(){};
};
int main()
{
    GermaSoldier* obj = new Soldier66;
    GermaSoldier* soldier = obj->clone();
    cout<<soldier->whoAmI();
    delete soldier;
    delete obj;
    return 0;
}