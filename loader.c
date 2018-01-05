/*
 * loader.h
 *	Загрузчик товара по складам магазинов
 *  Created on: 05.01.2018
 *      Author: jake
 */


#include "add.h"

void* threadLoader(void* pthreadData) // поток - загрузчик товара
{
	int i;
	int * pstores = (int *)pthreadData;
	while(*pstores<SIZE_OF_DEMAND){//защита от переполнения складов
	i = rand()%QUANTITY_OF_STORES;
	pthread_mutex_lock(&mutex);
	*(pstores+i) += SIZE_OF_LOAD;
	pthread_mutex_unlock(&mutex);
	usleep(30);
	}
	pthread_exit(0);
}
