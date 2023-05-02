#ifndef CONFIG_H
#define CONFIG_H

#define LINEAR_LIST_DEFAULT

#if defined(LINEAR_LIST_DEFAULT)
#include "linear_list.h"
#elif defined(STACK_DEFAULT)
#include "stack.h"
#elif defined(QUEUE_DEFAULT)
#include "queue.h"
#endif


#endif
