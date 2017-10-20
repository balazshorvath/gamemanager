#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>

#include "containers/light_queue.h"

int init_suite(){
	
}

int clean_suite(){
	
}

void speed_test(){
	long start, end;
	Queue* q = lq_create(20);
	int i, totalPuts = 0;
	
	srand(time(NULL));
	printf("Start measurement.");
	
	start = get_long_time();
	for(i = 0; i < 10000; i++){
		int r = rand() % 20 + 1;
		totalPuts += r;
		while(r--){
			lq_put(q, r);
		}
		while(lq_peek(q)){
		
		}
	}
	end = get_long_time();
	printf("Amount of insertions: %ld ms\n", totalPuts);
	printf("Run time was: %ld ms\n", (end - start));
}


int main() {
	CU_pSuite pSuite = NULL;

	if (CUE_SUCCESS != CU_initialize_registry()) {
		return CU_get_error();
	}
	
	pSuite = CU_add_suite("LightQueueTest", init_suite, clean_suite);
	if (NULL == pSuite) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	if ((NULL == CU_add_test(pSuite, "", ))) {
		CU_cleanup_registry();
		return CU_get_error();
	}

	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();
	CU_cleanup_registry();

	return CU_get_error();
}

