/**
 *  @brief
 *  @date 09.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header
#include "ThreadPool.h"

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers

void ThreadPool::start(std::size_t threadsCount)
{
    _threads.reserve(threadsCount);

    for(uint32_t i = 0; i < threadsCount; ++i)
    {
        _threads.emplace_back([=] {
            while(true)
            {
                Task task;

                /** separate scope to keep the critical section as small as
                 *  possible we dont want the mutex to be locked while the task
                 *  is executing
                 **/
                {
                    std::unique_lock<std::mutex> lock(_mutex);

                    _event.wait(lock, [=] {
                        return _stopping || !_tasks.empty();
                    });

                    if (_stopping && _tasks.empty()) //shared state
                    {
                        break;
                    }

                    task = std::move(_tasks.front());
                    _tasks.pop(); //shared state
                }

                task();
            }
        });
    }
}

void ThreadPool::stop()
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _stopping = true;
    }

    //notify threads that the stop has happened
    _event.notify_all();

    for (std::thread & thread: _threads)
    {
        thread.join();
    }
}

void ThreadPool::enqueue(ThreadPool::Task task)
{
    {
        std::unique_lock<std::mutex> lock(_mutex);
        _tasks.emplace(std::move(task));
    }

    _event.notify_one();
}