#!/bin/bash
./eleanora-map -v -m 20 -n 4 -r 500 -k 18 -o ab.pos a.fasta b.fasta
./eleanora-visual -v -l $1 -w 36 -s 90 -c 1 -o out.svg ab.pos
