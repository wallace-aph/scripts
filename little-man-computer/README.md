A LMC simulator I made when I was bored. From the --help:
------------

Little Man Computer simulator v1.0
All command line arguments trigger this help.

When you start, you will get a ? prompt.
Enter your data as:

? ADDRESS DATA

Addresses can be between 1 and 99, data can be between 0 and 999.
Two special editor commands exist, enter them in the ? prompt as:

? COMMAND ARGUMENT

100: Run program, enter any number as the argument (nescessary).

101: Print address, enter the address as the argument. 0 prints all stored data.


Data stored in memory addresses are interpreted as commands if reached by the counter during runtime.
These commands are the fundamentals of the LMC computer, and are different than the previously mentioned editor commands.

You can store actual data in addresses after the 000 command.


1XX: ADD: Add data from memory bank XX to calculator.

2XX: SUB: Subtract data from memory bank XX from calculator.

3XX: STO: Store data from calculator in memory bank XX.

5XX: LDA: Load data from memory bank XX into calculator.

6XX: BR:  Branch (jump) to memory bank XX.

7XX: BRZ: Branch (jump) to memory bank XX when calculator is ZERO.

8XX: BRP: Branch (jump) to memory bank XX when calculator is POSITIVE.

901: IN:  Ask user for input to be set as calculator value.

902: OUT: Output calculator value.

000: ZZZ: Coffee break, end execution.

When your program is running, input prompts triggered with 901 will appear as: *
