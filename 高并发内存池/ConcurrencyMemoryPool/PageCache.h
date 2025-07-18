#pragma once

#include "Common.h"

// 1.page cache是一个以页为单位的span自由链表
// 2.为了保证全局只有唯一的page cache，这个类被设计成了单例模式。
class PageCache
{
public:
	static PageCache* GetInstance()
	{
		return &_sInst;
	}

	// 获取一个K页的span
	Span* NewSpan(size_t k);

	std::mutex _pageMtx;
private:
	SpanList _spanLists[NPAGES];

	PageCache()
	{ }
	PageCache(const PageCache&) = delete;

	static PageCache _sInst;
};