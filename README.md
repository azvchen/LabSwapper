Lab Swapper
===========

[Usage](#usage) | [Customization](#customization) | [Implementation](#implementation)

This project is designed to help students swap into preferred lab sections, when used in tandem with a Google Form.  It was originally designed for the University of Virginia’s CS 2150 course but can be modified for any class.

The sole author is Austin Z. Chen.


<a name=“usage”></a>Usage
-------------------------

Included in the src folder is a Makefile that handles compilation of the entire project.  Using the make command in the src folder will create the requester executable, as well as relevant object files.  The executable reads in a .csv file that contains the students’ swap requests; the file name is specified as a command-line argument.  It then prints a list of possible swaps, highest priority first.

This program is intended to be used alongside a Google Form; an example form can be found [here](https://docs.google.com/forms/d/1OhTzNV8GCWn-Np6NX0_js5LjAk9ymwqlM6n2dJLLF5o/viewform).  The .csv file must then be downloaded from the linked spreadsheet (not the form-editing page!).  This .csv file will work with the executable.  One example .csv file is shown in the testfiles folder.


<a name=“customization”></a>Customization
-----------------------------------------

To customize this project for another class, the `user` class must be modified.  Specifically, the static integer `NUM_SECTIONS` and string array `SECTIONS` must be changed to reflect the number and names of the sections.  In addition, the names specified in the `SECTIONS` array must match those listed in the Google Form.


<a name=“implementation”></a>Implementation
-------------------------------------------

This project models the students as flows in a flow graph and proceeds to find a maximum flow using the [Ford-Fulkerson algorithm](https://en.wikipedia.org/wiki/Ford–Fulkerson_algorithm).  The graph consists of a source vertex; a vertex for each student, each connected to the source by an edge of capacity 1; a vertex for each lab section, each connected to every student who wants to swap into that lab by an edge of capacity 1, or who is already in that lab; and a sink, connected to each lab section by an edge with capacity equal to the number of students currently in that lab.

This approach allows multiple-way swaps to occur, and it is not limited to only finding direct two-way swaps.  In addition, the depth-first nature of the Ford-Fulkerson algorithm causes this program to respect priority, i.e., the order in which students submitted the request form.


<a name="license"></a>License
-----------------------------

The material in this repository is released under the [MIT License](https://opensource.org/licenses/MIT).

Copyright (c) 2016 by Austin Z. Chen.
