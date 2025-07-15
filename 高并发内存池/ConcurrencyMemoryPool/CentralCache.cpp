#define  _CRT_SECURE_NO_WARNINGS

#include "CentralCache.h"

CentralCache CentralCache::_sInst;  // ��̬��Ա�����Ķ���


// ��ȡһ���ǿյ�span
// ��Centralû��ʱ������Ҫ��PageCache����
Span* CentralCache::GetOneSpan(SpanList& list, size_t byte_size)
{
	// ...
	return nullptr;
}

// �����Ļ����ȡһ�������Ķ����thread cache
size_t CentralCache::FetchRangeObj(void*& start, void*& end, size_t batchNum, size_t size)
{
	size_t index = SizeClass::Index(size);
	_spanLists[index]._mtx.lock();

	Span* span = GetOneSpan(_spanLists[index], size);
	assert(span);
	assert(span->_freeList);

	// ��span�л�ȡbatchNum������
	// �������batchNum�����ж����ö���
	start = span->_freeList;
	end = start;
	size_t i = 0;
	size_t actualNum = 1;
	while (i < batchNum - 1 && NextObj(end) != nullptr)
	{
		end = NextObj(end);
		++i;
		++actualNum;
	}
	// ʵ��ֻ�������뵽 actualNum ���ڴ��

	// �������Ҫ�޸�ԭ��CentralCache�� span
	span->_freeList = NextObj(end);
	NextObj(end) = nullptr;

	_spanLists[index]._mtx.unlock();
	
	return actualNum;
}