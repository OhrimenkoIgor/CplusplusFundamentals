#if defined __linux__

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include "LinuxThreadPool.h"

Mutex::Mutex() {
	int s = pthread_mutex_init(&mutex, NULL);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_init");
		exit(EXIT_FAILURE);
	}
}

Mutex::~Mutex() {
	int s = pthread_mutex_destroy(&mutex);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_destroy");
		exit(EXIT_FAILURE);
	}
}

void Mutex::lock() {

	int s = pthread_mutex_lock(&mutex);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_lock");
		exit(EXIT_FAILURE);
	}
}

void Mutex::unlock() {
	int s = pthread_mutex_unlock(&mutex);
	if (s != 0) {
		errno = s;
		perror("pthread_mutex_unlock");
		exit(EXIT_FAILURE);
	}
}

LinuxThreadPool::LinuxThreadPool(int vnumThreads) :
		threads(vnumThreads) {

}

LinuxThreadPool::~LinuxThreadPool() {

}

void* LinuxThreadPool::poolThread(void* pLinuxThreadPool) {
	LinuxThreadPool * param =
			reinterpret_cast<LinuxThreadPool *>(pLinuxThreadPool);
	Task* task;
	bool noWaitingTasks = false;
	for (; !noWaitingTasks;) {
		param->lock();
		auto it = param->tasks.begin();
		for (; it != param->tasks.end(); ++it) {
			if (it->status == Task::Status::Waiting) {
				it->status = Task::Status::InProcess;
				task = &(*it);
				break;
			}
		}
		if (it != param->tasks.end()) {
			param->unlock();
			task->task(task->param);
			task->status = Task::Status::Done;
		} else {
			param->unlock();
			noWaitingTasks = true;
		}
	}
	return NULL;
}

void LinuxThreadPool::add(LinuxThreadPool::Worker worker, void* param) {
	lock();
	tasks.push_back(
			Task(LinuxThreadPool::Task::Status::Waiting, worker, param));
	unlock();
}

void LinuxThreadPool::startProcessTasks() {
	int s;
	for (auto it = threads.begin(); it != threads.end(); ++it) {
		s = pthread_create(&(*it), NULL, LinuxThreadPool::poolThread,
				reinterpret_cast<void*>(this));
		if (s != 0) {
			errno = s;
			perror("pthread_create");
			exit(EXIT_FAILURE);
		}
	}
}

void LinuxThreadPool::waitAllTasks() {
	int s;
	for (auto it = threads.begin(); it != threads.end(); ++it) {
		s = pthread_join(*it, NULL);
		if (s != 0) {
			errno = s;
			perror("pthread_join");
			exit(EXIT_FAILURE);
		}
	}
}

#endif //__linux__
