override TARGET := sunekits

define DEFAULT_VAR =
	ifeq ($(origin $1),default)
		override $(1) := $(2)
	endif
	ifeq ($(origin $1),undefined)
		override $(1) := $(2)
	endif
endef

$(eval $(call DEFAULT_VAR,CC,gcc))
$(eval $(call DEFAULT_VAR,LD,ld))
$(eval $(call DEFAULT_VAR,WASMLD,wasm-ld-10))

override MAINFILE := $(shell find -type f -name "main.c" | grep -v "system/" | grep "src/")
override CFILES := $(shell find -type f -name "*.c" | grep -v "system/" | grep -v "tests/" | grep -v "main.c")
override TESTS := $(shell find -type f -name "*.c" | grep -v "system/" | grep "tests/")
override OTHER := $(shell find -name "bin" | grep -v "system/")

.PHONY: all
all: $(TARGET)

$(TARGET):
	mkdir -p bin
	$(CC) $(MAINFILE) $(CFILES) -o ./bin/$@

.PHONY: clean
clean:
	rm -rf $(OTHER) || true

.PHONY: test
test:
	$(CC) $(CFILES) $(TESTS) -o test_exec
	./test_exec
	rm -f test_exec