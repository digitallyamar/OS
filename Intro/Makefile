all: 001_virt_cpu 002_virt_mem 003_concurrency

001_virt_cpu: 001_virt_cpu.c
	gcc -o $@ $<

002_virt_mem: 002_virt_mem.c
	gcc -o $@ $<

003_concurrency: 003_concurrency.c
	gcc -o $@ $< -lpthread

clean:
	rm -rf *.o
	rm -rf 001_virt_cpu 002_virt_mem 003_concurrency