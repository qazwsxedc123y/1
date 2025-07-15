#pragma once

#include "Common.h"
#include "ThreadCache.h"

// 封装，当有线程/进程申请内存时
// 会向ThreaCache上获取内存块
// 其会调用Allocate
static void* ConcurrentAlloc(size_t size)
{
	// 通过TLS 每个线程无锁的获取自己的专属的ThreadCache对象
	// 如果是第一次，那么此时的pTLSThreadCache为空，创建一个
	// 后续就不需要创建了，因为已经存在了
	if (pTLSThreadCache == nullptr)
	{
		pTLSThreadCache = new ThreadCache;
	}

	cout << std::this_thread::get_id() << ":" << pTLSThreadCache << endl;
	return pTLSThreadCache->Allocate(size);
}

// 其该函数也是封装
// 其会调用Deallocate，其作用是当有线程/进程释放用tcmalloc申请的内存时
// 会调用该函数，还给ThreadCache
// 传参传 size 是为了计算其桶的位置
static void ConcurrentFree(void* ptr, size_t size)
{
	assert(pTLSThreadCache);

	pTLSThreadCache->Deallocate(ptr, size);
}