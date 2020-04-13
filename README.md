# OS_homework5_massage_queue_linux
OS_homework5_massage_queue_linux

----------
### How to use ###
Using "gcc common.c consumer.c producer.c main.c -o main -lpthread" to generate a runnable file.

### How dose it worked ###
This project call a linux system function to generate a message queue, the consumer will get a "good" every second while the producer will produce a "good" in a random time.

### What dose it look like ###
 If everything goes will you will get the similar result following:
                生产了一个商品
取走了一个商品
                                暂时没有商品
                                暂时没有商品
                生产了一个商品
取走了一个商品
                生产了一个商品
取走了一个商品
                                暂时没有商品
                生产了一个商品
                生产了一个商品
取走了一个商品
取走了一个商品
                                暂时没有商品
                生产了一个商品
                生产了一个商品
取走了一个商品
                生产了一个商品
取走了一个商品
取走了一个商品
                生产了一个商品
取走了一个商品
                                暂时没有商品
                                暂时没有商品
                                暂时没有商品
                生产了一个商品
取走了一个商品
                生产了一个商品
取走了一个商品
                                暂时没有商品
                生产了一个商品
取走了一个商品
                                暂时没有商品
                生产了一个商品
                生产了一个商品
取走了一个商品
取走了一个商品
                                暂时没有商品
