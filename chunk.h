#ifndef colt_chunk_h
#define colt_chunk_h

#include "common.h"
#include "memory.h"
#include "value.h"

// Operation code corresponding to various operations
typedef enum {
  OP_CONSTANT, // Load constant for use
  OP_RETURN,   // Return from the current function
} OpCode;

// Defines series of instructions
typedef struct {
  int count;
  int capacity;
  uint8_t *code;
  int *lines;
  ValueArray constants;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte, int line);
int addConstant(Chunk *chunk, Value value);

#endif
