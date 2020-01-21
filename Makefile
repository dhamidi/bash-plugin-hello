INCLUDE := /usr/include/bash/builtins \
           /usr/include/bash/include \
           /usr/include/bash \
           /usr/lib/bash

hello.so: hello.c
	gcc $(foreach dir,$(INCLUDE),-I $(dir)) -shared -fPIC -o $@ $<
	
.PHONY: test
test: hello.so
	bash -c 'enable -f ./hello.so hello; printf "GREETING=%s\n" "$$GREETING"; hello'
