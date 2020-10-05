# chemFoam_mesh
![OpenFOAM 8](https://img.shields.io/badge/OpenFOAM-8-brightgreen)

A variation of OpenFOAM's chemFoam solver that runs on a full mesh instead of a single cell mesh.

## Why do I need this?

* If you want to freeze the flow in your reactive simulation and run 0D reactors on your cell data. Two published work using such analysis are  [[1]](#1) and  [[2]](#2)

* If you have any sort of application where you transfer your (Y,p,T) data from your OpenFOAM simulation to a chemistry solver such as Cantera or CHEMKIN, this lets you do it in OpenFOAM instead.

* By configuring the simulation case you can even do parameter sweeps in OpenFOAM. Example: Keep concentrations constant, vary the temperature in domain and use this solver for a temperature sweep on a certain mixture.

## References
<a id="1">[1]</a> 
H. Kahila, O. Kaario, Z. Ahmad, M. Ghaderi Masouleh, B. Tekgül, M. Larmi, V. Vuorinen (2019). 
[A large-eddy simulation study on the influence of diesel pilot spray quantity on methane-air flame initiation.](https://www.sciencedirect.com/science/article/pii/S001021801930238X)
Combustion and Flame, 206, 506-521.

<a id="2">[1]</a> 
Sage L. Kokjohn, Mark P.B. Musculus, Rolf D. Reitz (2015). 
[Evaluating temperature and fuel stratification for heat-release rate control in a reactivity-controlled compression-ignition engine using optical diagnostics and chemical kinetics modeling.](http://www.sciencedirect.com/science/article/pii/S0010218015001200)
Combustion and Flame, 162(6), 2729-2742.

## Usage

Check the given example case.
