//
// Created by Administrator on 2024/2/4.
//
#include <iostream>
using namespace std;
/**
 * @brief �����Smile��ʵ
 */
class AbstractSmile
{
public:
    virtual void transform() = 0;
    virtual void ability() = 0;
    virtual ~AbstractSmile(){}
};
/**
 * @brief ɽ��Smile��ʵ
 */
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

/**��
 * @brief ���幤����
 * @details �������� ɽ���ʵ��ʨ�ӹ�ʵ�������ʵ
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