/**
 * @desc:   µÇÂ¼ÈÎÎñÀà LogOnTask.h
 * @author: luosc
 * @date:   2025.4.10
 */

#ifndef LOGONTASK_H_
#define LOGONTASK_H_

#include "Task.h"

class LogOnTask final : public Task
{
public:
	LogOnTask() = default;
	~LogOnTask() = default;
public:
	virtual void doTask() override;
};
#endif // LOGONTASK_H_