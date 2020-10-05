# chemFoam_mesh
![OpenFOAM 8](https://img.shields.io/badge/OpenFOAM-8-brightgreen)

A variation of OpenFOAM's chemFoam solver that runs on a full mesh instead of a single cell mesh.

## Why do I need this?

* If you want to freeze the flow in your reactive simulation and run 0D reactors on your cell data. Two published work using such approach are  [[1]](#1) and  [[2]](#2)



## References
<a id="1">[1]</a> 
H. Kahila, O. Kaario, Z. Ahmad, M. Ghaderi Masouleh, B. Tekgül, M. Larmi, V. Vuorinen, (2019). 
A large-eddy simulation study on the influence of diesel pilot spray quantity on methane-air flame initiation.
Combustion and Flame, 206, 506-521.

<a id="2">[1]</a> 
Dijkstra, E. W. (1968). 
Go to statement considered harmful. 
Communications of the ACM, 11(3), 147-148.