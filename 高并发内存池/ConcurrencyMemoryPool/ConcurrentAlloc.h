#pragma once

#include "Common.h"
#include "ThreadCache.h"

// ��װ�������߳�/���������ڴ�ʱ
// ����ThreaCache�ϻ�ȡ�ڴ��
// ������Allocate
static void* ConcurrentAlloc(size_t size)
{
	// ͨ��TLS ÿ���߳������Ļ�ȡ�Լ���ר����ThreadCache����
	// ����ǵ�һ�Σ���ô��ʱ��pTLSThreadCacheΪ�գ�����һ��
	// �����Ͳ���Ҫ�����ˣ���Ϊ�Ѿ�������
	if (pTLSThreadCache == nullptr)
	{
		pTLSThreadCache = new ThreadCache;
	}

	cout << std::this_thread::get_id() << ":" << pTLSThreadCache << endl;
	return pTLSThreadCache->Allocate(size);
}

// ��ú���Ҳ�Ƿ�װ
// ������Deallocate���������ǵ����߳�/�����ͷ���tcmalloc������ڴ�ʱ
// ����øú���������ThreadCache
// ���δ� size ��Ϊ�˼�����Ͱ��λ��
static void ConcurrentFree(void* ptr, size_t size)
{
	assert(pTLSThreadCache);

	pTLSThreadCache->Deallocate(ptr, size);
}