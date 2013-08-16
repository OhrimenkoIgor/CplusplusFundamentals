#ifndef LINUXTHREADPOOL_H_
#define LINUXTHREADPOOL_H_

#if defined __linux__

#include <vector>

#include <pthread.h>

class Mutex {
	pthread_mutex_t mutex;
public:
	Mutex();
	~Mutex();
	void lock();
	void unlock();
};

class LinuxThreadPool: private Mutex {
public:
	typedef void* (*Worker)(void *);
	struct Task {
		enum class Status {
			Waiting, InProcess, Done
		} status;
		Worker task;
		void* param;
		Task(Status vstatus, Worker vtask, void* vparam) : status(vstatus), task(vtask), param(vparam) {}
	};
	std::vector<Task> tasks;
	//int numThreads;
	std::vector<pthread_t> threads;

	static void* poolThread(void* pLinuxThreadPool);

	LinuxThreadPool(int vnumThreads);
	~LinuxThreadPool();

	void add(LinuxThreadPool::Worker worker, void* param);
	void startProcessTasks();
	void waitAllTasks();
};

#endif //__linux__
#endif /* LINUXTHREADPOOL_H_ */
