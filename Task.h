/**
 * @desc:   任务类基类 Task.h
 * @author: luosc
 * @date:   2025.4.10
 */

#ifndef TASK_H_
#define TASK_H_

class Task
{
public:
	Task() = default;
	~Task() = default;

public:
	virtual void doTask() = 0;
};

#endif // TASK_H_