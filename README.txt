This is the code file for the complexity project. The model is built in the Oslo.hpp and Oslo.cpp.

The data should be obtained by running main.cpp and plotted in the py file.
The instruction of recording data is written in main.cpp and the instruction of 
reading the data is in each task file. To understand the format of the output data
please see ReadColumnFile.py. The path of the data file needs to be determined by
the user.



The functions in Oslo.hpp/cpp that can get particular data:

Oslo object_name(L, p):
Create a system of size L and probability to set threshold slope to 1 is p

object_name.InsertGrain():
Add one grain to the system

object_name.Height():
Return the current height

object_name.AvalancheSize():
Return the avalanche size in the last iteration

object_name.Configuration():
Print and return the configuration of the system

object_name.GetConfiguration():
Return the configuration of the system

object_name.Amount():
Return the number of grains in the system

object_name.Tc():
Return the cross-over time of this simulation (if applicable)



Location of each task:

TASK 1: 
In main.cpp

TASK 2a, 2c
In 2a,2c.py

TASK 2b
Answered in the report

TASK 2d
In 2d.py

TASK 2e
In 2e.py

TASK 2f
In 2f.py

TASK 2g
In 2g.py

TASK 3a, 3b
In 3a,3b.py

TASK 2c
In 2c.py