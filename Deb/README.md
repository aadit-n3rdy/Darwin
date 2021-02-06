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
  - Method void update:
	- Calculates the output from the networks, using a getOrganismsWithinVision callback
	- Basic physics to move the organism
	- Check if energy levels are too low, if so die
	- Generate random number, if < mutatition chance then mutate:
		- Use RNG to determine type of mutation and network or feature to be modified
		- Check if organism is close enough to same species, if not create as new species, update species tree
