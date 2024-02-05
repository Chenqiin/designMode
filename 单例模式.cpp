//
// Created by Administrator on 2024/2/5.
//
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
//����ģʽ-���������ʱ�򴴽���������
//���嵥��ģʽ���������
#if 0
class TaskQueue
{
public:
    TaskQueue() {};
    TaskQueue(const TaskQueue & t)= delete;
    TaskQueue& operator= (const TaskQueue& t) = delete;
    static TaskQueue * getInstance()
    {
        return m_taskQ;
    }
    void print()
    {
        cout<<"����һ����������ĳ�Ա����"<<endl;
    }
private:
    //��̬��Ա ͨ����������
    static  TaskQueue* m_taskQ;
};

TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

#if 1
//����ģʽ-��ʲôʱ��ʹ���������ʲôʱ�򴴽����ʵ��
//���嵥��ģʽ���������
class TaskQueue
{
public:
    TaskQueue() {};
    TaskQueue(const TaskQueue & t)= delete;
    TaskQueue& operator= (const TaskQueue& t) = delete;
    static TaskQueue * getInstance()
    {
        m_mutex.lock();
        if(m_taskQ == nullptr)
        {
            m_taskQ = new TaskQueue();
        }
        m_mutex.unlock();
        return m_taskQ;
    }
    void print()
    {
        cout<<"����һ����������ĳ�Ա����"<<endl;
    }
private:
    //��̬��Ա ͨ����������
    static  TaskQueue* m_taskQ;
    static mutex m_mutex;
};
TaskQueue* TaskQueue::m_taskQ = nullptr ;
#endif
int main()
{
    TaskQueue* taskQ = TaskQueue::getInstance();
    taskQ->print();
//    cout<<"ddd"<<endl;
    return 0;
}