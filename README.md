The Lightroom Keywords Project
========

Collection of miscellaneous, large keyword files that I search for tagging in Lightroom.


# Introduction

The purpose of this project is to store large controlled vocabulary keyword files for Lightroom photo tagging. Rather than hand-generate keyword files, the goal of this project is to use athoritative sources of data to generate the files.

The keyword files themselves are stored in the `keyword` directory. The `src` directory contains a tool to dump a keyword file out in a format appropriate for pasting into lightroom.

##keywords/Life.txt

This is a keyword file that contains over 35,000 species and families in the biological taxonomy. The file was generated from taxanomic data found on the ftp server of the National Center for Biotechnology Information (NCBI). Specifically ftp://ftp.ncbi.nih.gov/pub/taxonomy/taxdmp.zip.

For each entry, the common name is displayed first, with the scientific name given in parentheses. Specific species with multiple common names are broken into separate entries.

##keywords/states

This directory contains a keyword file for census data for each of the 50 states and 10 outlying territories of the United States. The data was generated from US census data.

##src

This directory contains the source code for `kwdump` and a `Makefile` to build the utility.

##kwdump
The `kwdump` program dumps Lightroom keyword files out in a format for copying and pasting into Lightroom. This is the recommended method of importing a keyword into Lighroom, as importing the files directly will bring Lightroom to a grinding halt.

To build the program, cd into `src` and type `make`.

To use `kwdump`, hand it one or more keyword files as arguments and it will send its results to standard out.
