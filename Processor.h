/**
 * @desc:   数据处理类，有自己的线程池，Processor.h
 * @author: luosc
 * @date:   2025.4.10
 */

#include <cstdint>

#ifndef PROCESSOR_H_
#define PROCESSOR_H_

#include <mutex>
#include <vector>
#include <condition_variable>

#include "Task.h"

class Processor final
{
public:
	Processor() = default;
	~Processor() = default;

public:
	bool init(int8_t threadCount = 4);
	bool uninit();

private:
	void threadFunc();

private:
	std::vector<std::shared_ptr<std::thread>> m_threads;
	std::mutex m_mutex;
	std::vector<Task *> m_tasks;
	std::condition_variable m_cv;
};

#endif // PROCESSOR_H_


