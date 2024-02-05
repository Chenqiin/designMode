//
// Created by Administrator on 2024/2/5.
//
#include <iostream>
#include <queue>
#include <mutex>
using namespace std;
//饿汉模式-》定义类的时候创建单例对象
//定义单例模式的任务队列
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
        cout<<"我是一个单例对象的成员函数"<<endl;
    }
private:
    //静态成员 通过类名访问
    static  TaskQueue* m_taskQ;
};

TaskQueue* TaskQueue::m_taskQ = new TaskQueue;
#endif

#if 1
//懒汉模式-》什么时候使用这个对象，什么时候创建这个实例
//定义单例模式的任务队列
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
        cout<<"我是一个单例对象的成员函数"<<endl;
    }
private:
    //静态成员 通过类名访问
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