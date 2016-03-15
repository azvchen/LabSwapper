Lab Swapper
===========

[Usage](#usage) | [Customization](#customization) [Future Additions](#future)

This project is designed to help students swap into preferred lab sections, when used in tandem with a Google Form.  It was originally designed for the University of Virginia’s CS 2150 course but can be modified for any class.

The sole author is Austin Z. Chen.


<a name=“usage”></a>Usage
-------------------------

Included in the src folder is a Makefile that handles compilation of the entire project.  Using the make command in the src folder will create the requester executable, as well as relevant object files.  The executable reads in a .csv file that contains the students’ swap requests; the file name is specified as a command-line argument.  It then prints a list of possible swaps, highest priority first.

This program is intended to be used alongside a Google Form; an example form can be found [here](https://docs.google.com/forms/d/1OhTzNV8GCWn-Np6NX0_js5LjAk9ymwqlM6n2dJLLF5o/viewform).  The .csv file must then be downloaded from the form-editing page (not from the linked spreadsheet!).  This .csv file will work with the executable.


<a name=“customization”></a>Customization
-----------------------------------------

To customize this project for another class, the `user` class must be modified.  Specifically, the static integer `NUM_SECTIONS` and string array `SECTIONS` must be changed to reflect the number and names of the sections.  In addition, the names specified in the `SECTIONS` array must match those listed in the Google Form.


<a name=“future”></a>Future Additions
-------------------------------------

Currently, this project only swaps in pairs; three-way swaps are not supported.  I plan to add support for multiple-person swaps.


<a name="license"></a>License
-----------------------------

The material in this repository is released under the [MIT License](https://opensource.org/licenses/MIT).

Copyright (c) 2016 by Austin Z. Chen.
