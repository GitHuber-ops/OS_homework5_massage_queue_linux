#include "common.h"

int main(){
    pthread_t consumer_t;
    pthread_t producer_t;

    
    pthread_create(&consumer_t, NULL, consumer, NULL); 
    
    pthread_create(&producer_t, NULL, producer, NULL); 
    pthread_join(consumer_t,NULL); 
    pthread_join(producer_t,NULL); 
}