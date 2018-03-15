#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

typedef struct{
  uint8_t  sym;
  uint8_t  header;
  uint64_t nRead;
  }
PARSER;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

PARSER   *CreateParser (void);
int32_t  ParseSym      (PARSER *, uint8_t);
void     RemoveParser  (PARSER *);

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

#endif
