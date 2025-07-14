#pragma once

#include "ThreadCache.h"

// 向CentralCache申请
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	// ......

	return nullptr;
}

// 申请
// 向ThreadCache申请内存时，首先要知道其位于那个桶的自由链表
// 然后申请
// 如果该桶为空，就向Central获取
// 反之可以直接申请
void* ThreadCache::Allocate(size_t size)
{
	assert(size <= MAX_BYTES);

	 size_t alignSize = SizeClass::RoundUp(size);
	 size_t index = SizeClass::Index(size);

	if (!_freeLists[index].Empty())
	{
		return _freeLists[index].Pop();
	}
	else
	{
		return FetchFromCentralCache(index, alignSize);
	}
}

// 释放
void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(ptr);
	assert(size <= MAX_BYTES);

	// 找对映射的自由链表桶，对象插入进入
	size_t index = SizeClass::Index(size);
	_freeLists[index].Push(ptr);
}
