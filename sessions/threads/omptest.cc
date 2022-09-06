#include <omp.h>

#include <cstdio>
#include <cstdint>

using namespace std;
int main() {
#pragma omp parallel num_threads(2)
#pragma omp parallel
	{
		int ID = omp_get_thread_num();
		printf(" hello(%d) ", ID);
		printf(" world(%d) \n", ID);
	}

	constexpr uint64_t N = 10000000000ULL;
#pragma omp for
	for (uint64_t i=0; i < N; i++){
		
	}
}
