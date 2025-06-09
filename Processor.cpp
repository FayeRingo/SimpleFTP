#include "Processor.h"

#include <condition_variable>
#include <memory>
#include <mutex>
#include <functional>
#include <thread>

bool Processor::init(int8_t threadCount /* = 4*/)
{
	//TODO: threadCount 进行校验
	for (int i = 0; i < threadCount; i++)
	{
		auto spThread = std::make_shared<std::thread>(
			std::bind(&Processor::threadFunc, this));
		m_threads.push_back(std::move(spThread));

	}
	return true;
}

bool Processor::uninit()
{
	size_t threadCount = m_threads.size();
	for (size_t i = 0; i < threadCount; i++)
	{
		m_threads[i]->join();
	}
	return false;
}

void Processor::threadFunc()
{
	while (true)
	{
		std::unique_lock<std::mutex> lock(m_mutex);
		while (m_tasks.empty())
		{
			m_cv.wait(lock);
		}

		Task* pTask = m_tasks.front();
		//m_tasks.pop_front();

		if (pTask == nullptr)
			continue;
		pTask->doTask();
		delete pTask;
		pTask = nullptr;
	}
}
