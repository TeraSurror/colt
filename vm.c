#include <stdio.h>

#include "common.h"
#include "vm.h"

VM vm;

static InterpretResult run() {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (*vm.ip++)

  for (;;) {
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
    case OP_CONSTANT:
      Value constant = READ_CONSTANT();
      printValue(constant);
      printf("\n");
      break;
    case OP_RETURN:
      return INTERPRET_OK;
    }
  }
}

void initVM() {}

void freeVM() {}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk = chunk;
  vm.ip = vm.chunk->code;
  return run();
}
