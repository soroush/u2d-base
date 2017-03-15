#!/bin/sh
flexc++ scanner.l
bisonc++ --thread-safe parser.y
