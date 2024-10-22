#ifndef colt_chunk_h
#define colt_chunk_h

#include "common.h"
#include "memory.h"

// Operation code corresponding to various operations
typedef enum
{
    OP_RETURN, // Return from the current function
} OpCode;

// Defines series of instructions
typedef struct
{
    int count;
    int capacity;
    uint8_t *code;
} Chunk;

void initChunk(Chunk *chunk);
void freeChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, uint8_t byte);

#endif