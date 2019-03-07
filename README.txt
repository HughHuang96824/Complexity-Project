This is the code file for the complexity project. The model is built in Oslo.hpp and Oslo.cpp.
To get more detail please refer to Instruction.pdf.


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
