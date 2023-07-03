#include "Memory.h"
#include <iostream>

using namespace std;

shadow::MemoryTracker shadow::g_memoryTracker;

void* operator new (size_t size) {
	void* p = malloc(size);

	shadow::g_memoryTracker.Add(p, size);

	return p;
}

void operator delete (void* address, size_t size) {
	shadow::g_memoryTracker.Remove(address, size);
	free(address);
}

namespace shadow {

	void shadow::MemoryTracker::Add(void* address, size_t size)
	{
		m_bytesAllocated += size;
		m_numAllocations++;
	}

	void MemoryTracker::Remove(void* address, size_t size)
	{
		m_bytesAllocated -= size;
		m_numAllocations--;
	}

	void shadow::MemoryTracker::DisplayInfo()
	{
		cout << "Current bytes allocated: " << m_bytesAllocated << endl;
		cout << "Current number allocations: " << m_numAllocations << endl;
	}
}
