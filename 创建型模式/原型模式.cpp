//
// Created by Administrator on 2024/2/7.
//
#include <iostream>
#include <queue>
#include <mutex>
#include <string>
using namespace std;
//����
class GermaSoldier
{
public:
    virtual GermaSoldier*  clone()=0;
    virtual string whoAmI()=0;
    virtual ~GermaSoldier(){};
};

//����
class Soldier66 :public GermaSoldier
{
public:
     GermaSoldier*  clone() {
        return new Soldier66(*this);
    }
     string whoAmI()
    {
        return "���� 66";
    }
//    virtual ~GermaSoldier(){};
};
class Soldier67 :public GermaSoldier
{
public:
    GermaSoldier*  clone() {
        //ʹ�����
        return new Soldier67(*this);
    }
    string whoAmI()
    {
        return "���� 67";
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