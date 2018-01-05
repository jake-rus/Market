/*
 * client.h
 *	Покупатели магазинов
 *  Created on: 05.01.2018
 *      Author: jake
 */

#include "add.h"

void* threadClient(void* pthreadData) // поток - покупатель
{
	int i;
	int demandClient = (SIZE_OF_DEMAND-3000)+rand()%(SIZE_OF_DEMAND);
	int sizeClient; // корзина покупателя
	int * pstores = (int *)pthreadData;
	while(sizeClient < demandClient){
		i = rand()%QUANTITY_OF_STORES;
		pthread_mutex_lock(&mutex);
		sizeClient += *(pstores+i); // забирает товар из магазина
		*(pstores+i) = 0;
		pthread_mutex_unlock(&mutex);
		usleep(20);
		}
	pthread_mutex_lock(&mutexOut);
	printf("%d\n", sizeClient);
	pthread_mutex_unlock(&mutexOut);

	pthread_exit(0);
}
