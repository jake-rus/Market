/*
 * add.h
 *
 *  Created on: 05.01.2018
 *      Author: jake
 */

#ifndef ADD_H_
#define ADD_H_


#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define QUANTITY_OF_STORES 5 // количество магазинов
#define QUANTITY_OF_CLIENTS 3 // количество покупателей
#define SIZE_OF_LOAD 500 // размер загрузки товара в магазин
#define SIZE_OF_DEMAND 10000 // средний размер спроса покупателей

pthread_mutex_t mutex; // мьютекс на работу с массивом
pthread_mutex_t mutexOut;//мьютекс вывода

void* threadLoader(void* pthreadData); // поток - загрузчик товара
void* threadClient(void* pthreadData); // поток - покупатель

#endif /* ADD_H_ */
