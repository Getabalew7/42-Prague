#!/bin/bash
export FT_LINE1=11
export FT_LINE2=17

cat /etc/passwd | sed '/^#/d; n; d' | cut -d ':' -f 1 | rev | sort -r | sed -n $FT_LINE1,$FT_LINE2'p' | tr '\n' ', ' | sed 's/,$/./' | tr -d '\n'
