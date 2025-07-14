#pragma once

#include "ThreadCache.h"

// ��CentralCache����
void* ThreadCache::FetchFromCentralCache(size_t index, size_t size)
{
	// ......

	return nullptr;
}

// ����
// ��ThreadCache�����ڴ�ʱ������Ҫ֪����λ���Ǹ�Ͱ����������
// Ȼ������
// �����ͰΪ�գ�����Central��ȡ
// ��֮����ֱ������
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

// �ͷ�
void ThreadCache::Deallocate(void* ptr, size_t size)
{
	assert(ptr);
	assert(size <= MAX_BYTES);

	// �Ҷ�ӳ�����������Ͱ������������
	size_t index = SizeClass::Index(size);
	_freeLists[index].Push(ptr);
}
