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
        cout << "������� -- ɽ������̬..." << endl;
    }
    void ability()override
    {
        cout << "���ֱ۱������ǵ���ʽ -- �����" << endl;
    }
};
// �����ħ��ʵ�� ʨ����̬
class LionSmile : public AbstractSmile
{
public:
    void transform()
    {
        cout << "������� -- ʨ������̬..." << endl;
    }
    void ability()
    {
        cout << "��ݡ� ������֮��..." << endl;
    }
};
// �����ħ��ʵ�� ������̬
class BatSmile: public AbstractSmile
{
public:
    void transform()
    {
        cout << "������� -- ��������̬..." << endl;
    }
    void ability()
    {
        cout << "��������֮�򽣹���..." << endl;
    }
};

/**
 * @brief ���幤����
 * @details
 * �ڼ򵥹�����Ļ����ϸĽ� ���Ͽ��ŷ��ԭ��
 *
 */
class SmileFactory
{
public:
    virtual AbstractSmile * createSmile() =0;
    virtual ~SmileFactory(){};
};
/**
 * ����������ʵ�Ĺ���
 */
class SheepFactory : public  SmileFactory
{
    AbstractSmile* createSmile()
    {
        return new SheepSmile;
    }
    ~SheepFactory()
    {
        cout<<"sheepFactory ������"<<endl;
    }
};
/**
 * ����ʨ�ӹ�ʵ�Ĺ���
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
        cout<<"LionFactory ������"<<endl;
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