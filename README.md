Lab Swapper
===========

[Usage](#usage) | [Customization](#customization)

This project is designed to help students swap into preferred lab sections, when used in tandem with a Google Form.  It was originally designed for the University of Virginia’s CS 2150 course but can be modified for any class.

The sole author is Austin Z. Chen.


<a name=“usage”></a>Usage
-------------------------

Included in the src folder is a Makefile that handles compilation of the entire project.  Using the make command in the src folder will create the requester executable, as well as relevant object files.  The executable reads in a .csv file that contains the students’ swap requests; the file name is specified as a command-line argument.  It then prints a list of possible swaps, highest priority first.


<a name=“customization”></a>Customization
-----------------------------------------

To customize this project for another class, the `user` class must be modified.  Specifically, the static integer `NUM_SECTIONS` and string array `SECTIONS` must be changed to reflect the number and names of the sections.  In addition, the names specified in the `SECTIONS` array must match those listed in the Google Form.


<a name="license"></a>License
-----------------------------

The material in this repository is released under the [MIT License](https://opensource.org/licenses/MIT).

Copyright (c) 2016 by Austin Z. Chen.
