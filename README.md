# Mini_Project_C

Sample project:  Develop a Linked list using C or C++

Objective     :  Understand the project structure, build system, and basic coding.

Requirements  :

# The linked list should be able to build a list with LINEAR or QUEUE, STACK formats.

# Operations allowed in LINEAR list (linear_list.c, linear_list.h)

      -Add node

      -Print node data

      -Delete node

      -Reverse list

# Operations allowed in QUEUE list (queue_list.c, queue_list.h)

      -Push node

      -Pop node

      -Print node data

# Operations allowed in STACK list (stack_list.c, stack_list.h)

      -Push node

      -Pop node

      -Print node data

# Create 3 .c file, 3 .h file and 1 main file (nagra_list.c)  -> all the file names mentioned above.

# Compile time option (Macro) must be defined to compile the list either QUEUE or STACK or LINEAR (Default LINEAR list is created)

# The 3 .c and .h file should be built as static/dynamic library (nagra_list.a / nagra_list.so) using make file options.

# The Main c file (nagra_list.c) should use the static/dynamic library (nagra_list.a / nagra_list.so) and perform the linked list operations mentioned.

# Use custom memory allocation method (wrapper function for malloc)

# Register a callback (function pointer) to notify empty list  - Call this callback when, all the nodes got deleted , and print status inside the callback.

# On termination of the program, print the memory statistics

         - Total memory allocated in bytes

         - Number of times malloc called

         - Number of times free called


- To run on Windows platform you need to change the makefile (change deb to exe wherever found)         