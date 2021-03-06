#ifndef CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_THREADPOOL_H
#define CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_THREADPOOL_H

/**
 *  @brief
 *  @date 09.03.19
 *  @author Stoyan Lupov
 */

//Corresponding header

//C system headers

//C++ system headers
#include <condition_variable>
#include <functional>
#include <thread>
#include <vector>
#include <queue>

//Other libraries headers

//Own components headers

class ThreadPool
{
    public:
        using Task = std::function<void()>;

        explicit ThreadPool(std::size_t threadsCount)
        {
            start(threadsCount);
        }

        ~ThreadPool()
        {
            stop();
        }

        void enqueue(Task task);

    private:

        void start(std::size_t threadsCount);

        void stop();

        //holds the tasks that need to be executed by the threads
        std::queue<Task> _tasks;

        std::vector<std::thread> _threads;
        std::condition_variable _event;

        std::mutex _mutex;
        bool _stopping = false;
};

#endif //CODELAB_STUDIES_MKK_ALGORITHMS_HOMEWORK_3_THREADPOOL_H
