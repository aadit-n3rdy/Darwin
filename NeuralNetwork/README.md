# Neural Network

NEAT model of Deep learning

## Classes:

- ### Connection:
  - Contains 2 Node pointers and 2 doubles
  - Node pointers are to and from
  - Doubles are weight and bias
- ### Node:
  - Virtual class
  - Has vector of connection pointers to and vector of connection pointers from
  - Child classes are nodes with various functions
  - Function is applied to each of the inputs
  - Results of return vals of the functions are added to give the output
  - Has a boolean which determines if it is a fundamental node (input or output node)
- ### NeuralNetwork:
  - Contains vector of Node pointers and vector of Connection pointers
  - Has a calculate function which takes input of vector of double and returns vector of double
  - Output is restricted to (-1, 1)
  - Can evolve from parent (NeuralNetwork pointer):
	- Small chance for mutations
	- If condition for small chance is satisfied, random number is generated
	- Number is evaluated to determine type of mutation
	- New random number is generated to determine involved Nodes, connections etc.
	- List of possible mutations:
		- Add connection
		- Remove connection (Must remove loose non-fundamental nodes after removing connection)
		- Modify connection weight
		- Add Node on connection
		- Modify node type
		- Remove node
