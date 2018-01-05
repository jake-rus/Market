/*
 * main.c
 *
 *  Created on: 30.12.2017
 *      Author: jake
 */

#include "add.h"

int main(void)
{
	int stores[QUANTITY_OF_STORES];// массив магазинов
	int *pstores = stores; // указатель на массив
	int i;
	pthread_t tidLoader; //идентификатор потока-загрузчика
	pthread_t tidClient[QUANTITY_OF_CLIENTS]; //идентификаторы потоков-покупателей
	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_init(&mutexOut, NULL);

	for (i=0;i<QUANTITY_OF_STORES;i++)
		stores[i]=0; // обнуление товаров в магазинах

	pthread_create(&tidLoader, NULL, threadLoader, pstores); // создание потока-Загрузчика
	pthread_detach(tidLoader);

	for (i=0;i<QUANTITY_OF_CLIENTS;i++) // создание потоков-Покупателей
		pthread_create(tidClient+i, NULL, threadClient, pstores);

	for (i=0;i<QUANTITY_OF_CLIENTS;i++)
	pthread_join(tidClient[i], NULL); // завершение потока-Загрузчика

	printf("Остаток на складах\n");
	for (i=0;i<QUANTITY_OF_STORES;i++)
		printf("%d ",stores[i]);

	pthread_mutex_destroy(&mutex); // уничтожение мьютексов
	pthread_mutex_destroy(&mutexOut);
	return 0;
}
