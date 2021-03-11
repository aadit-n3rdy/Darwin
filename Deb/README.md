#D.E.B

Darwin's Evolving Buggers

##Class:

- ###Deb:
  - Class representing the D.E.Bs
  - Contains 4 doubles for position and velocity
  - Contains 2 NEAT networks:
	- Interaction network:
		- Interaction network
		- Processes individual organisms within visual range.
		- Inputs:
			- Relative x pos
			- Relative y pos
			- Size as relative to own
			- Distance of species from self's species, on the species tree
		- Outputs - 4, tentatively
	- Decision network
		- Decisionmaking network
		- Combines self's traits with outputs from second network
		- Inputs:
			- velocity x
			- velocity y
			- Size
			- Energy
			- <Any other details needed to be included>
			- Outputs from interaction network
		- Outputs:
			- acceleration x
			- acceleration y
			- eat
			- attack
			- reproduce
  - Alternative network configuration:
  	- Pass each food item in visual range through food network
	- Take weighted average of outputs
	- Take output from 
  	- Food network:
		- Takes an object within visual range
		- Inputs:
			- Relative x pos
			- Relative y pos
			- Food Quality
		- Outputs:
			- Torque
			- Acceleration
			- Weight
			- Eat
	- Combiner network:
		- Takes food network output from 5 closest objects within visual range
		- If < 5 inputs, set all 3 arguments for respective objects to 0
		- Takes energy and other necessary object details
		- Inputs:
			- 15 from 5 food networks
			- Energy level
			- Velocity X
			- Velocity Y
		- Outputs:
			- Acceleration X
			- Acceleration Y
			- Eat (tries eating if > 0)
  	- Single NEAT network:
		- Takes 5 nearest objects as input
		- If < than 5 objects, distance is set to 0, and foodQuality is set to 0
		- Inputs:
			- Velocity X
			- Velocity Y


  - Method void update:
	- Calculates the output from the networks, using a getOrganismsWithinVision callback
	- Basic physics to move the organism
	- Check if energy levels are too low, if so die
	- Generate random number, if < mutatition chance then mutate:
		- Use RNG to determine type of mutation and network or feature to be modified
		- Check if organism is close enough to same species, if not create as new species, update species tree
