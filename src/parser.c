#include <string.h>
#include "parser.h"
#include "mem.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CREATE PARSER
//
PARSER *CreateParser(void){
  PARSER *PA = (PARSER *) Calloc(1, sizeof(PARSER));
  PA->sym    = 0;
  PA->header = 0;
  PA->nRead  = 0;
  return PA;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PARSE SYM
//
int32_t ParseSym(PARSER *PA, uint8_t sym){
      
  switch(sym){
    case '>':  
      PA->header = 1; 
      ++PA->nRead;  
      return -1;
    case '\n': 
      if(PA->header == 0){
        PA->header = 0;               
        return -99;
        }
      else{
        PA->header = 0;               
        return -2;
        }
    default:   
      if(PA->header == 1)             
        return -3;
    }

  // NUCLEOTIDE PARSE
  if(sym != 'A' && sym != 'C' && sym != 'G' && sym != 'T')
    return 'N'; // MAP EXTRA INTO 'N'

  return sym;
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// REMOVE PARSER
//
void RemoveParser(PARSER *PA){
  Free(PA);
  }

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
